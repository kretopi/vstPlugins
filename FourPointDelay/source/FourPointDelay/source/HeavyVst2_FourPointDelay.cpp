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

#include "HeavyVst2_FourPointDelay.hpp"
#include "HvUtils.h"

#define HV_VST2_NUM_PARAMETERS 18

extern "C" {
  HV_EXPORT AEffect *VSTPluginMain(audioMasterCallback audioMaster) {
    // Get VST Version of the Host, return NULL if old version
    if (!audioMaster(0, audioMasterVersion, 0, 0, 0, 0)) return NULL;

    // Create the AudioEffect
    AudioEffect* effect = new HeavyVst2_FourPointDelay(audioMaster);
    if (effect == NULL) return NULL;

    // Return the VST AEffect structure
    return effect->getAeffect();
  }
}

HeavyVst2_FourPointDelay::HeavyVst2_FourPointDelay(audioMasterCallback amCallback) :
    AudioEffectX(amCallback, 0, HV_VST2_NUM_PARAMETERS) {
  setUniqueID(0x6D9990A7);
  setNumInputs(2);
  setNumOutputs(2);
  isSynth(false);
  programsAreChunks(true);
  canProcessReplacing(true);
  canDoubleReplacing(false);
  // initialise parameters with defaults
  _parameters[0] = 0.222222222222f; // 1feed
  _parameters[1] = 0.00450225112556f; // 1point
  _parameters[2] = 0.02f; // 1time
  _parameters[3] = 0.5f; // 1vol
  _parameters[4] = 0.222222222222f; // 2feed
  _parameters[5] = 0.0145072536268f; // 2point
  _parameters[6] = 0.02f; // 2time
  _parameters[7] = 0.5f; // 2vol
  _parameters[8] = 0.222222222222f; // 3feed
  _parameters[9] = 0.0345172586293f; // 3point
  _parameters[10] = 0.02f; // 3time
  _parameters[11] = 0.5f; // 3vol
  _parameters[12] = 0.222222222222f; // 4feed
  _parameters[13] = 0.0995497748874f; // 4point
  _parameters[14] = 0.02f; // 4time
  _parameters[15] = 0.5f; // 4vol
  _parameters[16] = 0.5f; // dry
  _parameters[17] = 0.5f; // wet
  _context = nullptr;
  this->sampleRate = 0.0f; // initialise sample rate
  setSampleRate(44100.0f); // set sample rate to some default
}

HeavyVst2_FourPointDelay::~HeavyVst2_FourPointDelay() {
  delete _context;
}

void HeavyVst2_FourPointDelay::setSampleRate(float sampleRate) {
  if (this->sampleRate != sampleRate) {
    this->sampleRate = sampleRate;
    delete _context;

    _context = new Heavy_FourPointDelay(sampleRate, 10, 18, 2);
    // ensure that the new context has the current parameters
    for (int i = 0; i < HV_VST2_NUM_PARAMETERS; ++i) {
      setParameter(i, _parameters[i]);
    }
  }
}

void HeavyVst2_FourPointDelay::processReplacing(float** inputs, float** outputs, VstInt32 sampleFrames) {
  _context->process(inputs, outputs, sampleFrames);
}

VstInt32 HeavyVst2_FourPointDelay::processEvents(VstEvents* events) {
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
    case 0: return (0.9f*value) + 0.0f; // 1feed
    case 1: return (19990.0f*value) + 10.0f; // 1point
    case 2: return (5000.0f*value) + 0.0f; // 1time
    case 3: return (1.0f*value) + 0.0f; // 1vol
    case 4: return (0.9f*value) + 0.0f; // 2feed
    case 5: return (19990.0f*value) + 10.0f; // 2point
    case 6: return (5000.0f*value) + 0.0f; // 2time
    case 7: return (1.0f*value) + 0.0f; // 2vol
    case 8: return (0.9f*value) + 0.0f; // 3feed
    case 9: return (19990.0f*value) + 10.0f; // 3point
    case 10: return (5000.0f*value) + 0.0f; // 3time
    case 11: return (1.0f*value) + 0.0f; // 3vol
    case 12: return (0.9f*value) + 0.0f; // 4feed
    case 13: return (19990.0f*value) + 10.0f; // 4point
    case 14: return (5000.0f*value) + 0.0f; // 4time
    case 15: return (1.0f*value) + 0.0f; // 4vol
    case 16: return (1.0f*value) + 0.0f; // dry
    case 17: return (1.0f*value) + 0.0f; // wet
    default: return 0.0f;
  }
}

void HeavyVst2_FourPointDelay::setParameter(VstInt32 index, float value) {
  switch (index) {
    case 0: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_1FEED,
          scaleParameterForIndex(index, value));
      break;
    }
    case 1: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_1POINT,
          scaleParameterForIndex(index, value));
      break;
    }
    case 2: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_1TIME,
          scaleParameterForIndex(index, value));
      break;
    }
    case 3: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_1VOL,
          scaleParameterForIndex(index, value));
      break;
    }
    case 4: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_2FEED,
          scaleParameterForIndex(index, value));
      break;
    }
    case 5: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_2POINT,
          scaleParameterForIndex(index, value));
      break;
    }
    case 6: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_2TIME,
          scaleParameterForIndex(index, value));
      break;
    }
    case 7: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_2VOL,
          scaleParameterForIndex(index, value));
      break;
    }
    case 8: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_3FEED,
          scaleParameterForIndex(index, value));
      break;
    }
    case 9: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_3POINT,
          scaleParameterForIndex(index, value));
      break;
    }
    case 10: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_3TIME,
          scaleParameterForIndex(index, value));
      break;
    }
    case 11: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_3VOL,
          scaleParameterForIndex(index, value));
      break;
    }
    case 12: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_4FEED,
          scaleParameterForIndex(index, value));
      break;
    }
    case 13: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_4POINT,
          scaleParameterForIndex(index, value));
      break;
    }
    case 14: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_4TIME,
          scaleParameterForIndex(index, value));
      break;
    }
    case 15: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::_4VOL,
          scaleParameterForIndex(index, value));
      break;
    }
    case 16: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::DRY,
          scaleParameterForIndex(index, value));
      break;
    }
    case 17: {
      _context->sendFloatToReceiver(
          Heavy_FourPointDelay::Parameter::In::WET,
          scaleParameterForIndex(index, value));
      break;
    }
    default: return;
  }
  _parameters[index] = value;
}

float HeavyVst2_FourPointDelay::getParameter(VstInt32 index) {
  return _parameters[index];
}

void HeavyVst2_FourPointDelay::getParameterName(VstInt32 index, char* text) {
  switch (index) {
    case 0: strncpy(text, "1feed", kVstMaxParamStrLen); break;
    case 1: strncpy(text, "1point", kVstMaxParamStrLen); break;
    case 2: strncpy(text, "1time", kVstMaxParamStrLen); break;
    case 3: strncpy(text, "1vol", kVstMaxParamStrLen); break;
    case 4: strncpy(text, "2feed", kVstMaxParamStrLen); break;
    case 5: strncpy(text, "2point", kVstMaxParamStrLen); break;
    case 6: strncpy(text, "2time", kVstMaxParamStrLen); break;
    case 7: strncpy(text, "2vol", kVstMaxParamStrLen); break;
    case 8: strncpy(text, "3feed", kVstMaxParamStrLen); break;
    case 9: strncpy(text, "3point", kVstMaxParamStrLen); break;
    case 10: strncpy(text, "3time", kVstMaxParamStrLen); break;
    case 11: strncpy(text, "3vol", kVstMaxParamStrLen); break;
    case 12: strncpy(text, "4feed", kVstMaxParamStrLen); break;
    case 13: strncpy(text, "4point", kVstMaxParamStrLen); break;
    case 14: strncpy(text, "4time", kVstMaxParamStrLen); break;
    case 15: strncpy(text, "4vol", kVstMaxParamStrLen); break;
    case 16: strncpy(text, "dry", kVstMaxParamStrLen); break;
    case 17: strncpy(text, "wet", kVstMaxParamStrLen); break;
    default: text[0] = '\0'; break;
  }
  text[kVstMaxParamStrLen-1] = '\0';
}

void HeavyVst2_FourPointDelay::getParameterDisplay(VstInt32 index, char* text) {
  snprintf(text, kVstMaxParamStrLen, "%0.3f", scaleParameterForIndex(index, _parameters[index]));
  text[kVstMaxParamStrLen-1] = '\0';
}

bool HeavyVst2_FourPointDelay::string2parameter(VstInt32 index, char* text) {
  setParameter(index, (float) atof(text));
  return true;
}

bool HeavyVst2_FourPointDelay::getEffectName(char* name) {
  strncpy(name, "FourPointDelay", kVstMaxEffectNameLen);
  name[kVstMaxEffectNameLen-1] = '\0';
  return true;
}

bool HeavyVst2_FourPointDelay::getVendorString(char* text) {
  strncpy(text, "Enzien Audio, Ltd.", kVstMaxVendorStrLen);
  text[kVstMaxVendorStrLen-1] = '\0';
  return true;
}

VstInt32 HeavyVst2_FourPointDelay::canDo(char *text) {
  if (!strcmp(text, "receiveVstEvents")) return 1; // PlugCanDos::canDoReceiveVstEvents
  if (!strcmp(text, "receiveVstMidiEvent")) return 1; // PlugCanDos::canDoReceiveVstMidiEvent
  return 0;
}

VstInt32 HeavyVst2_FourPointDelay::getChunk(void **data, bool isPreset) {
  const VstInt32 numBytes = HV_VST2_NUM_PARAMETERS * sizeof(float);
  float *chunk = (float *) malloc(numBytes);
  memcpy(chunk, _parameters, numBytes);
  *data = chunk;
  return numBytes;
}

VstInt32 HeavyVst2_FourPointDelay::setChunk(void *data, VstInt32 byteSize, bool isPreset) {
  float *const chunk = (float *) data;
  for (int i = 0; i < HV_VST2_NUM_PARAMETERS; ++i) {
    setParameter(i, chunk[i]);
  }
  return byteSize;
}
