/**
 * Copyright (c) 2018 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "HeavyVst2_Panoramizer.hpp"
#include "HvUtils.h"

#define HV_VST2_NUM_PARAMETERS 4

extern "C" {
  HV_EXPORT AEffect *VSTPluginMain(audioMasterCallback audioMaster) {
    // Get VST Version of the Host, return NULL if old version
    if (!audioMaster(0, audioMasterVersion, 0, 0, 0, 0)) return NULL;

    // Create the AudioEffect
    AudioEffect* effect = new HeavyVst2_Panoramizer(audioMaster);
    if (effect == NULL) return NULL;

    // Return the VST AEffect structure
    return effect->getAeffect();
  }
}

HeavyVst2_Panoramizer::HeavyVst2_Panoramizer(audioMasterCallback amCallback) :
    AudioEffectX(amCallback, 0, HV_VST2_NUM_PARAMETERS) {
  setUniqueID(0xC26F50C9);
  setNumInputs(2);
  setNumOutputs(2);
  isSynth(false);
  programsAreChunks(true);
  canProcessReplacing(true);
  canDoubleReplacing(false);
  // initialise parameters with defaults
  _parameters[0] = 0.0f; // dry
  _parameters[1] = 0.5f; // mono
  _parameters[2] = 0.25f; // time
  _parameters[3] = 1.0f; // wet
  _context = nullptr;
  this->sampleRate = 0.0f; // initialise sample rate
  setSampleRate(44100.0f); // set sample rate to some default
}

HeavyVst2_Panoramizer::~HeavyVst2_Panoramizer() {
  delete _context;
}

void HeavyVst2_Panoramizer::setSampleRate(float sampleRate) {
  if (this->sampleRate != sampleRate) {
    this->sampleRate = sampleRate;
    delete _context;

    _context = new Heavy_Panoramizer(sampleRate, 10, 4, 2);
    // ensure that the new context has the current parameters
    for (int i = 0; i < HV_VST2_NUM_PARAMETERS; ++i) {
      setParameter(i, _parameters[i]);
    }
  }
}

void HeavyVst2_Panoramizer::processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames) {
  _context->process(inputs, outputs, sampleFrames);
}

VstInt32 HeavyVst2_Panoramizer::processEvents(VstEvents* events) {
  for (int i = 0; i < events->numEvents; ++i) {
    VstEvent *vste = events->events[i];
    switch (vste->type) {
      case kVstMidiType: {
        VstMidiEvent *vstme = (VstMidiEvent *) vste;

        const unsigned char command = vstme->midiData[0] & 0xF0;
        const unsigned char channel = vstme->midiData[0] & 0x0F;
        const unsigned char data0   = vstme->midiData[1] & 0x7F;
        const unsigned char data1   = vstme->midiData[2] & 0x7F;

        switch (command) {
          case 0x80:   // note off
          case 0x90: { // note on
            _context->sendMessageToReceiverV(0x67E37CA3, // __hv_notein
                1000.0*vste->deltaFrames/sampleRate, "fff",
                (float) data0, // pitch
                (float) data1, // velocity
                (float) channel);
            break;
          }
          case 0xB0: { // control change
            _context->sendMessageToReceiverV(0x41BE0F9C, // __hv_ctlin
                1000.0*vste->deltaFrames/sampleRate, "fff",
                (float) data1, // value
                (float) data0, // controller number
                (float) channel);
            break;
          }
          case 0xC0: { // program change
            _context->sendMessageToReceiverV(0x2E1EA03D, // __hv_pgmin,
                1000.0*vste->deltaFrames/sampleRate, "ff",
                (float) data0,
                (float) channel);
            break;
          }
          case 0xD0: { // aftertouch
            _context->sendMessageToReceiverV(0x553925BD, // __hv_touchin
                1000.0*vste->deltaFrames/sampleRate, "ff",
                (float) data0,
                (float) channel);
            break;
          }
          case 0xE0: { // pitch bend
            hv_uint32_t value = (((hv_uint32_t) data1) << 7) | ((hv_uint32_t) data0);
            _context->sendMessageToReceiverV(0x3083F0F7, // __hv_bendin
                1000.0*vste->deltaFrames/sampleRate, "ff",
                (float) value,
                (float) channel);
            break;
          }
          default: break;
        }
        break;
      }
      case kVstSysExType: {
        // not handling this case at the moment, VstMidiSysexEvent *vstmse;
        break;
      }
      default: break;
    }
  }
  return 1;
}

static float scaleParameterForIndex(VstInt32 index, float value) {
  switch (index) {
    case 0: return (1.0f*value) + 0.0f; // dry
    case 1: return (50.0f*value) + 0.0f; // mono
    case 2: return (4.0f*value) + 1.0f; // time
    case 3: return (1.0f*value) + 0.0f; // wet
    default: return 0.0f;
  }
}

void HeavyVst2_Panoramizer::setParameter(VstInt32 index, float value) {
  switch (index) {
    case 0: {
      _context->sendFloatToReceiver(
          Heavy_Panoramizer::Parameter::In::DRY,
          scaleParameterForIndex(index, value));
      break;
    }
    case 1: {
      _context->sendFloatToReceiver(
          Heavy_Panoramizer::Parameter::In::MONO,
          scaleParameterForIndex(index, value));
      break;
    }
    case 2: {
      _context->sendFloatToReceiver(
          Heavy_Panoramizer::Parameter::In::TIME,
          scaleParameterForIndex(index, value));
      break;
    }
    case 3: {
      _context->sendFloatToReceiver(
          Heavy_Panoramizer::Parameter::In::WET,
          scaleParameterForIndex(index, value));
      break;
    }
    default: return;
  }
  _parameters[index] = value;
}

float HeavyVst2_Panoramizer::getParameter(VstInt32 index) {
  return _parameters[index];
}

void HeavyVst2_Panoramizer::getParameterName(VstInt32 index, char* text) {
  switch (index) {
    case 0: strncpy(text, "dry", kVstMaxParamStrLen); break;
    case 1: strncpy(text, "mono", kVstMaxParamStrLen); break;
    case 2: strncpy(text, "time", kVstMaxParamStrLen); break;
    case 3: strncpy(text, "wet", kVstMaxParamStrLen); break;
    default: text[0] = '\0'; break;
  }
  text[kVstMaxParamStrLen-1] = '\0';
}

void HeavyVst2_Panoramizer::getParameterDisplay(VstInt32 index, char* text) {
  snprintf(text, kVstMaxParamStrLen, "%0.3f", scaleParameterForIndex(index, _parameters[index]));
  text[kVstMaxParamStrLen-1] = '\0';
}

bool HeavyVst2_Panoramizer::string2parameter(VstInt32 index, char* text) {
  setParameter(index, (float) atof(text));
  return true;
}

bool HeavyVst2_Panoramizer::getEffectName(char* name) {
  strncpy(name, "Panoramizer", kVstMaxEffectNameLen);
  name[kVstMaxEffectNameLen-1] = '\0';
  return true;
}

bool HeavyVst2_Panoramizer::getVendorString(char* text) {
  strncpy(text, "Enzien Audio, Ltd.", kVstMaxVendorStrLen);
  text[kVstMaxVendorStrLen-1] = '\0';
  return true;
}

VstInt32 HeavyVst2_Panoramizer::canDo(char *text) {
  if (!strcmp(text, "receiveVstEvents")) return 1; // PlugCanDos::canDoReceiveVstEvents
  if (!strcmp(text, "receiveVstMidiEvent")) return 1; // PlugCanDos::canDoReceiveVstMidiEvent
  return 0;
}

VstInt32 HeavyVst2_Panoramizer::getChunk(void **data, bool isPreset) {
  const VstInt32 numBytes = HV_VST2_NUM_PARAMETERS * sizeof(float);
  float *chunk = (float *) malloc(numBytes);
  memcpy(chunk, _parameters, numBytes);
  *data = chunk;
  return numBytes;
}

VstInt32 HeavyVst2_Panoramizer::setChunk(void *data, VstInt32 byteSize, bool isPreset) {
  float *const chunk = (float *) data;
  for (int i = 0; i < HV_VST2_NUM_PARAMETERS; ++i) {
    setParameter(i, chunk[i]);
  }
  return byteSize;
}
