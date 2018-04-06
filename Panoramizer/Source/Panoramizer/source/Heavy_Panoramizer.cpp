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

#include "Heavy_Panoramizer.hpp"

#define Context(_c) reinterpret_cast<Heavy_Panoramizer *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_Panoramizer_new(double sampleRate) {
    return new Heavy_Panoramizer(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_Panoramizer_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_Panoramizer(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_Panoramizer::Heavy_Panoramizer(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sCPole_init(&sCPole_IgNfH7rJ);
  numBytes += sLine_init(&sLine_CuqrGXEv);
  numBytes += sCPole_init(&sCPole_CT7FbXRB);
  numBytes += sLine_init(&sLine_OBW7HPwg);
  numBytes += sCPole_init(&sCPole_8O8SAtQ8);
  numBytes += sLine_init(&sLine_6IpjrVLG);
  numBytes += sCPole_init(&sCPole_FEbliNND);
  numBytes += sLine_init(&sLine_PwvaKAuJ);
  numBytes += sCPole_init(&sCPole_MbNHaWs6);
  numBytes += sLine_init(&sLine_LQy9vOAf);
  numBytes += sCPole_init(&sCPole_G1QAVZbi);
  numBytes += sLine_init(&sLine_o0gZgzLz);
  numBytes += sCPole_init(&sCPole_r8jtVWjr);
  numBytes += sLine_init(&sLine_BGOwlXRv);
  numBytes += sCPole_init(&sCPole_MPMPRzse);
  numBytes += sLine_init(&sLine_M1XQKarV);
  numBytes += sCPole_init(&sCPole_FZoywQ0j);
  numBytes += sLine_init(&sLine_fH1Ocu9h);
  numBytes += sCPole_init(&sCPole_aGLcYNmy);
  numBytes += sLine_init(&sLine_lLnI9Nmg);
  numBytes += sEnv_init(&sEnv_vIzZ7sP9, 1024, 512);
  numBytes += sCPole_init(&sCPole_U5QzBXjM);
  numBytes += sLine_init(&sLine_MUZbgaOJ);
  numBytes += sCPole_init(&sCPole_TGkn9NyC);
  numBytes += sLine_init(&sLine_gYdlB2qX);
  numBytes += sCPole_init(&sCPole_ojIuU6rA);
  numBytes += sLine_init(&sLine_mBK8HTmp);
  numBytes += sCPole_init(&sCPole_QqefG4sW);
  numBytes += sLine_init(&sLine_UAKgNdSl);
  numBytes += sCPole_init(&sCPole_KRlFHXtJ);
  numBytes += sLine_init(&sLine_MCh6dNEm);
  numBytes += sCPole_init(&sCPole_RdRh1yjF);
  numBytes += sLine_init(&sLine_JF2WlRsy);
  numBytes += sCPole_init(&sCPole_RlH9LWfB);
  numBytes += sLine_init(&sLine_MXwWIheG);
  numBytes += sCPole_init(&sCPole_teiSqXL2);
  numBytes += sLine_init(&sLine_nfcCtHIb);
  numBytes += sCPole_init(&sCPole_M6AxxG2t);
  numBytes += sLine_init(&sLine_yvNSvGVa);
  numBytes += sCPole_init(&sCPole_alxKqtgX);
  numBytes += sLine_init(&sLine_t6mH6GZI);
  numBytes += sVarf_init(&sVarf_xRn2VEfP, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_INzAl95R, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_XNaD9zXd, 0.0f);
  numBytes += cBinop_init(&cBinop_OWIYNtha, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_eRbx0nWe, 200.0f);
  numBytes += sVarf_init(&sVarf_APBMFKji, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9LVe71wa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TY1eTrWJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Ry1IebOM, 0.0f);
  numBytes += sVarf_init(&sVarf_LA6VwDJJ, 1.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_eQw886Zy, false);
  numBytes += cBinop_init(&cBinop_sCiRCSuX, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_Uk7dL6UX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ny2wrpUd, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_V10nx0dc, false);
  numBytes += sVarf_init(&sVarf_l9QXFGs6, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HtsEBYby, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_L2GX4vgF, 0.0f);
  numBytes += sVarf_init(&sVarf_VSfB8RMv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BSDGpvoj, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_BgNhb75u, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_BwmQzwqe, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_ow0bPaLg, 0.0f);
  numBytes += sVarf_init(&sVarf_NaVGb5do, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_HDdgk1Dw, false);
  numBytes += sVarf_init(&sVarf_Vb2RNPC4, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q8tLslKo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ObIvSq7R, 1.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_zeNM9NzY, 0.0f);
  numBytes += cVar_init_f(&cVar_4QuNDreE, 200.0f);
  numBytes += cBinop_init(&cBinop_COw4KCc9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QvD7MZxU, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_n8a9SdAy, 1, 1);
  numBytes += cRandom_init(&cRandom_hVm1krXV, 428795679);
  numBytes += cBinop_init(&cBinop_FrHyOmBI, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_lVvm4Bfp, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_xonWnJsw, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_nmYMGEPc, 1, 1);
  numBytes += cRandom_init(&cRandom_eCoZEmAV, -1807236224);
  numBytes += cBinop_init(&cBinop_qjt0yr59, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_F0FoFR6Y, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_RZYHKoS9, 200.0f);
  numBytes += cDelay_init(this, &cDelay_obgqjZ53, 0.0f);
  numBytes += cVar_init_f(&cVar_d4qmomJn, 200.0f);
  numBytes += cBinop_init(&cBinop_i9BX3s0u, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_Yc38ukDv, 0.0f);
  numBytes += cPack_init(&cPack_VZ4Vbe6z, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_TVWxQJAX, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_kf3lpcIY, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_uzQrrCIU, 1, 1);
  numBytes += cRandom_init(&cRandom_dYR6iJ7D, -58011232);
  numBytes += sVarf_init(&sVarf_wtRFW9Kf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6chEvmhY, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Mb8Q91v0, 0.0f);
  numBytes += sVarf_init(&sVarf_cwZOkSiK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2iHG6fD0, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_xyvdJNLa, false);
  numBytes += sVarf_init(&sVarf_QvSVkke0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lOTUctdd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_y1RscVmb, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TEwGdxac, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_WupUb8Hi, false);
  numBytes += sVarf_init(&sVarf_IrhOuGAu, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NBo1cCkI, 0.0f);
  numBytes += cBinop_init(&cBinop_I2Cst5QV, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_gBDlFIes, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ncXHOsBv, 0.0f);
  numBytes += sVarf_init(&sVarf_7PbISZrq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_RIzHLBIO, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_05ysRCaA, false);
  numBytes += sVarf_init(&sVarf_j9RWhhvD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XTVcualp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Wt1s3EGB, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_q0b2lD0f, 2, 0.0f, 0.0f);
  numBytes += cDelay_init(this, &cDelay_aFnQdcZC, 0.0f);
  numBytes += cBinop_init(&cBinop_l48pxDQs, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_XVRLW315, 200.0f);
  numBytes += cBinop_init(&cBinop_DATbBqaY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aPlxu1RT, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_39lz6YKo, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_lc1diS7u, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_L03k4Str, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_vgP8Ispp, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_t8i9MwWv, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_peZVejpU, 0.0f);
  numBytes += cRandom_init(&cRandom_YN2OBmzm, -1387807999);
  numBytes += cSlice_init(&cSlice_LBMfyPuJ, 1, 1);
  numBytes += sVarf_init(&sVarf_qZCovVpH, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_X16S9ub0, 1, 1);
  numBytes += cRandom_init(&cRandom_ha4Wryad, 184959031);
  numBytes += sVarf_init(&sVarf_TndXOlKD, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_GXoQXGUE, 0.0f);
  numBytes += sVarf_init(&sVarf_pA5d4SXT, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QWhW5F3n, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kjcgFWTw, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_sUJGH7O5, false);
  numBytes += cRandom_init(&cRandom_wILdCJaD, -1403774752);
  numBytes += cBinop_init(&cBinop_3OoWfQLc, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_N1x3Iji9, 1, 1);
  numBytes += cBinop_init(&cBinop_YY41R8Sr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UxgnROXQ, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_P2L6qI5n, 1, 1);
  numBytes += cRandom_init(&cRandom_di5vk2Zt, 663133212);
  numBytes += cRandom_init(&cRandom_C0TkFIHi, 1783661565);
  numBytes += cSlice_init(&cSlice_Bsr4sObD, 1, 1);
  numBytes += cSlice_init(&cSlice_D7IXq6HN, 1, 1);
  numBytes += cRandom_init(&cRandom_qohdRP5P, 38895252);
  numBytes += cBinop_init(&cBinop_5ol0oTBW, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_SaBo3uD2, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_JvCuTRYh, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_fRddS6aP, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_WdujqZ8v, 0.0f);
  numBytes += cSlice_init(&cSlice_vU2DZ5vC, 1, 1);
  numBytes += cBinop_init(&cBinop_JBZW2Z7Z, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_ijtw164q, 154277182);
  numBytes += cSlice_init(&cSlice_AIiAYNqM, 1, 1);
  numBytes += cRandom_init(&cRandom_5uppe6ap, 1634874714);
  numBytes += cSlice_init(&cSlice_3LVHPzGM, 1, 1);
  numBytes += cRandom_init(&cRandom_rS6QuLTU, -1112780106);
  numBytes += cSlice_init(&cSlice_0wvJdhVq, 1, 1);
  numBytes += cRandom_init(&cRandom_TiPYYwmY, -1720616896);
  numBytes += sVarf_init(&sVarf_VyShZwls, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_rmecuPeh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_T0yWIMsZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_gHos0r4b, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_B2JxT1Ml, 200.0f);
  numBytes += cDelay_init(this, &cDelay_sKnsqGEA, 0.0f);
  numBytes += sVarf_init(&sVarf_tqq9DMNI, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_da8Focxb, 1, 1);
  numBytes += cRandom_init(&cRandom_q4D1VO6Z, 846580006);
  numBytes += cBinop_init(&cBinop_3smKgX7A, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_STP9tAAw, 1, 1);
  numBytes += cRandom_init(&cRandom_jLhQqqxF, 1840905853);
  numBytes += cBinop_init(&cBinop_ngxOPElX, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_uqT0Bx1s, -1921311498);
  numBytes += cSlice_init(&cSlice_qob4azKm, 1, 1);
  numBytes += cBinop_init(&cBinop_34dBe6RY, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_bY2d9KZ4, 0.0f);
  numBytes += cVar_init_f(&cVar_uQ7KsflP, 1000.0f);
  numBytes += cRandom_init(&cRandom_zoFF6Bh7, 986752535);
  numBytes += cSlice_init(&cSlice_7mKQokqs, 1, 1);
  numBytes += sVarf_init(&sVarf_uP69yyM9, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_HmczneGH, 1902162864);
  numBytes += cSlice_init(&cSlice_7PZqJn12, 1, 1);
  numBytes += cSlice_init(&cSlice_e2jXOQhO, 1, 1);
  numBytes += cRandom_init(&cRandom_jb7Zvpds, 1250992814);
  numBytes += cPack_init(&cPack_qE8tcMdh, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_YeKC8aju, 1, 1);
  numBytes += cRandom_init(&cRandom_mDH1jwGX, -545404750);
  numBytes += cSlice_init(&cSlice_qvK2IP6I, 1, 1);
  numBytes += cRandom_init(&cRandom_wVD1LshN, 934909791);
  numBytes += cVar_init_f(&cVar_OXINzLAu, 200.0f);
  numBytes += cDelay_init(this, &cDelay_j2Utk1De, 0.0f);
  numBytes += cBinop_init(&cBinop_W5PA71uj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_klqNpYro, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_WHQVrgc5, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_bQ0BxPrl, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lUQxK12K, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_WF39Yf3E, 0.0f);
  numBytes += cBinop_init(&cBinop_0dlKewJy, 0.0f); // __add
  numBytes += cPack_init(&cPack_84oBoStL, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_8yGGlh9B, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_tpVxd9gd, 0.0f);
  numBytes += cBinop_init(&cBinop_eQy3g7lz, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_3QIz6LKN, 1000.0f);
  numBytes += cBinop_init(&cBinop_WYe2ajYZ, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_4jJ4jzOx, 1142680774);
  numBytes += cSlice_init(&cSlice_Vak1o6Ar, 1, 1);
  numBytes += sVarf_init(&sVarf_IWBimtcf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fpzG3h0q, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_qxLj5ypj, false);
  numBytes += sVarf_init(&sVarf_ecKAvRmN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_y41LITa6, 0.0f);
  numBytes += sVarf_init(&sVarf_1FMmiAdi, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Jl2LlAW6, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_a1MQHw8q, 0.0f); // __sub
  numBytes += cPack_init(&cPack_pwmPsK8A, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_Lr6cuGEp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1MJVepyB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_U0UbiIz3, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_dUHWd6kN, -282615018);
  numBytes += cSlice_init(&cSlice_MsocogV3, 1, 1);
  numBytes += sVarf_init(&sVarf_QFtGY4tK, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_NDgelykv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DWBFMdnH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4ibIl6qy, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_fYWVh1H5, 0.0f);
  numBytes += cBinop_init(&cBinop_hc58jTNf, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_2AZHogX9, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_HHfcoYqo, 0.0f);
  numBytes += cBinop_init(&cBinop_EGyEzwMU, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_frKFCl06, 1000.0f);
  numBytes += cBinop_init(&cBinop_thACoG9f, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_sekSb42a, 0.0f);
  numBytes += cBinop_init(&cBinop_114xhnGv, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_yx1vvfwy, 1000.0f);
  numBytes += cRandom_init(&cRandom_JOquYozD, -1491208331);
  numBytes += cSlice_init(&cSlice_uARTRu70, 1, 1);
  numBytes += sVarf_init(&sVarf_VtKcETzo, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vAT1Sc6s, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6gSnK3a4, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_QmihQWOH, 0.0f);
  numBytes += sVarf_init(&sVarf_a45I1UQC, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_hWHTgEMO, false);
  numBytes += cSlice_init(&cSlice_bPsOOox8, 1, 1);
  numBytes += cRandom_init(&cRandom_z5P6JA65, -1326644927);
  numBytes += cBinop_init(&cBinop_HPHV9kAx, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_Xzipk2Eu, -1455055913);
  numBytes += cSlice_init(&cSlice_tNCBmBkX, 1, 1);
  numBytes += cBinop_init(&cBinop_BXIWhcdC, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_YCICLslS, 1, 1);
  numBytes += cRandom_init(&cRandom_C89777LO, -1900144557);
  numBytes += cBinop_init(&cBinop_BNJinA05, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_kF44AayX, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_cDeNJ6qF, 0.0f);
  numBytes += cVar_init_f(&cVar_4uPYedz8, 200.0f);
  numBytes += cPack_init(&cPack_HGjeKzLl, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_SOuaIdcL, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_B6FSUic1, 1000.0f);
  numBytes += cBinop_init(&cBinop_7OssKohg, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_nShzcxQq, 0.0f);
  numBytes += sVarf_init(&sVarf_iBOpglHC, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_R5e3gV2r, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_6VecmVOr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_1kTAQ7Qc, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_NVTbk0K8, 0.0f);
  numBytes += cBinop_init(&cBinop_HwtyS3UC, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ZKT2nqf4, 200.0f);
  numBytes += cBinop_init(&cBinop_F3yTcxQZ, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_w3JvETUq, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KZvASSsv, 0.0f);
  numBytes += cIf_init(&cIf_Fyv85DDS, false);
  numBytes += sVarf_init(&sVarf_K4x2IeDj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vBEQvp1O, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OElDt3zM, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_A9TcDwvM, 0.0f); // __add
  numBytes += cRandom_init(&cRandom_SKv9LBW0, 409128626);
  numBytes += cSlice_init(&cSlice_MhEKCcfp, 1, 1);
  numBytes += cRandom_init(&cRandom_2wPN5fSY, 756488526);
  numBytes += cBinop_init(&cBinop_jBtL4bWS, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_xBMkfulY, 1, 1);
  numBytes += cDelay_init(this, &cDelay_wKJ7HQKm, 0.0f);
  numBytes += cBinop_init(&cBinop_YHPoY7m3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_PPLuPCJU, 1000.0f);
  numBytes += cBinop_init(&cBinop_TzIe9iOX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_dvJKNU5d, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_xpgkkHjf, 200.0f);
  numBytes += cDelay_init(this, &cDelay_k6c3m4lO, 0.0f);
  numBytes += cSlice_init(&cSlice_TKJvWyra, 1, 1);
  numBytes += cBinop_init(&cBinop_BSZgQTvN, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_5MoneVVx, -520097588);
  numBytes += sVarf_init(&sVarf_TmrXnmvZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TVNMH30m, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_bh7YHVce, 0.0f);
  numBytes += cVar_init_f(&cVar_s0u2ZXpi, 1000.0f);
  numBytes += cBinop_init(&cBinop_GIp8r6nT, 0.0f); // __mul
  numBytes += cIf_init(&cIf_Ar9ob9A7, false);
  numBytes += sVarf_init(&sVarf_rhjj9ynC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BUiWrmHJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ca8rHNVn, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_oatzeytR, 0.0f);
  numBytes += sVarf_init(&sVarf_8Kus44jV, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_qvjVO1Py, 1, 1);
  numBytes += cRandom_init(&cRandom_ppAOwXEY, 1069590965);
  numBytes += cBinop_init(&cBinop_2hUueL2P, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lUs941mW, 200.0f);
  numBytes += cDelay_init(this, &cDelay_8yzCTDmm, 0.0f);
  numBytes += cPack_init(&cPack_7Zx6qeCt, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_ny0Wd1XB, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_BKkMQAUQ, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_pyDXEoxS, 0.0f);
  numBytes += cVar_init_f(&cVar_Ligl3cRK, 200.0f);
  numBytes += cBinop_init(&cBinop_6et0sILy, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lrzLcuGv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_W4fPNaDc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_NplCOnrK, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_xtIEhuqP, 1, 1);
  numBytes += cRandom_init(&cRandom_qSHco09j, -1727617819);
  numBytes += cBinop_init(&cBinop_9yqUaKxW, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_xQkmb5FQ, 0.0f);
  numBytes += cVar_init_f(&cVar_sLZajxVK, 200.0f);
  numBytes += cBinop_init(&cBinop_kaQWyuBL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HIEFQgpn, 0.0f); // __mul
  numBytes += cPack_init(&cPack_wsbThzCO, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_HSey0fsc, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_rwkD9zCv, 0.0f);
  numBytes += cBinop_init(&cBinop_tLcgRKHs, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_wEgJgGmd, 1000.0f);
  numBytes += cSlice_init(&cSlice_Dv36PfEJ, 1, 1);
  numBytes += cRandom_init(&cRandom_KaHYrfRZ, -319150185);
  numBytes += cBinop_init(&cBinop_GgJUFsrq, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_sHZwBGrw, -215998643);
  numBytes += cSlice_init(&cSlice_xIrMWCWM, 1, 1);
  numBytes += cRandom_init(&cRandom_bEjZJI67, 153979415);
  numBytes += cBinop_init(&cBinop_M9IEeWwJ, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_0rHTX0bR, 1, 1);
  numBytes += cBinop_init(&cBinop_4Lxy3j8H, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_OMhsTQkM, 359996396);
  numBytes += cSlice_init(&cSlice_bDQDG5UO, 1, 1);
  numBytes += cBinop_init(&cBinop_7NKFoctD, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_qfvtd4IN, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Iy0cNPij, 200.0f);
  numBytes += cBinop_init(&cBinop_bL74sB1r, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_JUXYOtkt, 0.0f);
  numBytes += cRandom_init(&cRandom_UmC5DNG0, 973553555);
  numBytes += cSlice_init(&cSlice_i5KHXFpp, 1, 1);
  numBytes += cBinop_init(&cBinop_ZzHRje5A, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_kAKmpfEa, 200.0f);
  numBytes += cDelay_init(this, &cDelay_9DKYXLTM, 0.0f);
  numBytes += cBinop_init(&cBinop_JW0PiAFd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_MAgZq37l, 0.0f);
  numBytes += sVarf_init(&sVarf_9hCFhEwX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_t7XgPdmt, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_P2GpWQVs, false);
  numBytes += sVarf_init(&sVarf_tsdoN062, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vNvYVNXY, 1.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_L2FWCXEX, 1, 1);
  numBytes += cRandom_init(&cRandom_eeCjt6O1, -169888441);
  numBytes += cBinop_init(&cBinop_GFrqeqUu, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_ScgZ8xs3, 1.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_rcYxDyUj, false);
  numBytes += sVarf_init(&sVarf_lHTedkk6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_qApCAyFA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cODWyoZT, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_2o3UhK8K, 0.0f);
  numBytes += cRandom_init(&cRandom_hZwI10Ld, 1863203340);
  numBytes += cSlice_init(&cSlice_3BmYfj6m, 1, 1);
  numBytes += cBinop_init(&cBinop_vpkbrOwk, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_us1XHbtO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FMhkvfZ7, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_UbwVENHw, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_3OY8NESs, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_4umZrSag, 0.0f);
  numBytes += cVar_init_f(&cVar_mln0cGd3, 1000.0f);
  numBytes += cBinop_init(&cBinop_dgYWkrdj, 0.0f); // __add
  numBytes += cRandom_init(&cRandom_CL3gDiaQ, 710148530);
  numBytes += cSlice_init(&cSlice_zf76qCSR, 1, 1);
  numBytes += cBinop_init(&cBinop_z2HFqNHF, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_h2miBKEr, 200.0f);
  numBytes += cDelay_init(this, &cDelay_ujx2N0xJ, 0.0f);
  numBytes += cPack_init(&cPack_m9u76HZ6, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_SweHyKWc, 1, 1);
  numBytes += cRandom_init(&cRandom_t3eISuR8, 402090845);
  numBytes += cBinop_init(&cBinop_8iAKC7BB, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_9RsbCDIF, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_FcXgKvar, 0.0f);
  numBytes += cVar_init_f(&cVar_5XuGwcVF, 1000.0f);
  numBytes += cBinop_init(&cBinop_6s29cxKt, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_pS4aubSM, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_iSxEbKGI, 1, 1);
  numBytes += cRandom_init(&cRandom_kE2NLWBW, 633823251);
  numBytes += cSlice_init(&cSlice_5O9sjZ7P, 1, 1);
  numBytes += cRandom_init(&cRandom_lWrsQ6wH, 331597363);
  numBytes += sVarf_init(&sVarf_MNFdG1jD, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UPsbO0T2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_jtRRuezc, 0.0f);
  numBytes += sVarf_init(&sVarf_aaVRPfmI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_cbJvSfsf, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_5V3vbmcm, false);
  numBytes += sVarf_init(&sVarf_tQcxlbFo, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_8O94vyKG, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_ofybVYen, 1, 1);
  numBytes += cRandom_init(&cRandom_7isTfxNo, -1021529998);
  numBytes += cRandom_init(&cRandom_ZcA9krHz, 1876096094);
  numBytes += cSlice_init(&cSlice_APyhOSYD, 1, 1);
  numBytes += cPack_init(&cPack_Hm2D2lw5, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_iyT2qVeO, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_onGiMVtz, 0.0f);
  numBytes += cBinop_init(&cBinop_rv3flOzT, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_q8chZZpl, 200.0f);
  numBytes += cPack_init(&cPack_PVf041un, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_h9Sk51H8, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WggwOBSz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MNW0v8sE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4F1cSXrH, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_nWdmkfeQ, false);
  numBytes += cVar_init_f(&cVar_Wnx1Ss4v, 0.0f);
  numBytes += cPack_init(&cPack_2ywB6kJi, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_WSJfHmoD, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_38EyO6at, 1135742873);
  numBytes += cBinop_init(&cBinop_I8qij9Me, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_35xlwrHY, 1, 1);
  numBytes += sVarf_init(&sVarf_81vSDxJr, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_6WgHO88X, 1, 1);
  numBytes += cRandom_init(&cRandom_uNDE4LkA, -856832604);
  numBytes += cBinop_init(&cBinop_uXZaLFd3, 0.0f); // __add
  numBytes += cSlice_init(&cSlice_mVnuSSR2, 1, 1);
  numBytes += cRandom_init(&cRandom_yR1Cuzdt, 694199948);
  numBytes += sVarf_init(&sVarf_TwduOrwB, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VvolOUfR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_kuHgA7TB, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5QtG5Wbl, 0.0f);
  numBytes += sVarf_init(&sVarf_AI0Kz9tK, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_raz1Kjex, false);
  numBytes += cRandom_init(&cRandom_l5OvXg7K, -462562917);
  numBytes += cSlice_init(&cSlice_KNHMEglg, 1, 1);
  numBytes += cBinop_init(&cBinop_ldKjfdjd, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_YvGIMVwV, 1, 1);
  numBytes += cRandom_init(&cRandom_LYttnEdx, -728575662);
  numBytes += cDelay_init(this, &cDelay_05C4gqS9, 0.0f);
  numBytes += cBinop_init(&cBinop_hnaECZdj, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_PYb9Xvc9, 1000.0f);
  numBytes += cPack_init(&cPack_WhjWB6Uw, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_oSPt4QwQ, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_RemScvzi, 2020309904);
  numBytes += cSlice_init(&cSlice_5iw5Ces2, 1, 1);
  numBytes += sVarf_init(&sVarf_78Fk8XkG, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_LQHU6Ojn, 1, 1);
  numBytes += cRandom_init(&cRandom_XkJZjj94, -1241562577);
  numBytes += cSlice_init(&cSlice_1Wbm2c7y, 1, 1);
  numBytes += cBinop_init(&cBinop_j2DfUNHv, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_8AMWl9oR, 1607836818);
  numBytes += cBinop_init(&cBinop_fvy9phU4, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_N8m2qIRq, 1, 1);
  numBytes += cRandom_init(&cRandom_1JCHZQaT, 95841246);
  numBytes += cBinop_init(&cBinop_cpCeVm84, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_jEnjtf5P, 1, 1);
  numBytes += cRandom_init(&cRandom_ZuB3CFG2, 1531582557);
  numBytes += sVarf_init(&sVarf_aBjHetzF, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_l41vCFsR, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_ZF5I7Tr7, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_P4HtOh27, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_4zXjaq6V, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_BAqxZwh8, false);
  numBytes += sVarf_init(&sVarf_eCKXgizN, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_vYYQjND0, 0.0f);
  numBytes += sVarf_init(&sVarf_7bMqtRaW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yR2Twobv, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SrQfCTl3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mUYmoWiJ, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_Bmqm0w4H, 1, 1);
  numBytes += cRandom_init(&cRandom_DSVrZ535, 332974037);
  numBytes += cPack_init(&cPack_udwhr5qK, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_u2FoeDmB, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_n0qS0I41, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_qiC7WEyl, 0.0f);
  numBytes += cBinop_init(&cBinop_bnCaMEka, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_GlFGFJVw, 200.0f);
  numBytes += cPack_init(&cPack_KIZvesAc, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_Ta339XnH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tgGjVpBg, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_oYneyoBN, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_RMsbSsAm, 1, 1);
  numBytes += cRandom_init(&cRandom_Px1GNWtq, 1185175719);
  numBytes += sVarf_init(&sVarf_Y66a1Hxy, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_XfA1tl8a, -1385444682);
  numBytes += cSlice_init(&cSlice_SIhymDH9, 1, 1);
  numBytes += cBinop_init(&cBinop_fWB0R7qI, 100.0f); // __mul
  numBytes += sVarf_init(&sVarf_2DXrbhqo, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_9zitgxmg, false);
  numBytes += cVar_init_f(&cVar_bxg4xK2S, 0.0f);
  numBytes += sVarf_init(&sVarf_HLao1xcE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rSFSZWfE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mtnaNdsw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rljGylkW, 1.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_zaUjTJ2X, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_n1mBULxi, 0.0f);
  numBytes += cVar_init_f(&cVar_tioICOBO, 1000.0f);
  numBytes += cBinop_init(&cBinop_VYJKHuzE, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_jhWSsKo5, 0.0f);
  numBytes += cVar_init_f(&cVar_wG8gMr2g, 1000.0f);
  numBytes += cBinop_init(&cBinop_5SuSHTA0, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_DY9o92ME, 0.0f);
  numBytes += cVar_init_f(&cVar_2jdf0w2y, 200.0f);
  numBytes += cSlice_init(&cSlice_dKOrWxGV, 1, 1);
  numBytes += cRandom_init(&cRandom_nXOTMVjc, 1717333318);
  numBytes += cBinop_init(&cBinop_IXpsyChQ, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_5LuGL8PS, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_Mb3Oom6d, 1815315901);
  numBytes += cSlice_init(&cSlice_fmVsWj56, 1, 1);
  numBytes += cBinop_init(&cBinop_slgNIpLk, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6jlMtAi6, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_PFAf8B3M, 0.0f);
  numBytes += cVar_init_f(&cVar_vNmIwWFZ, 200.0f);
  numBytes += sVarf_init(&sVarf_oVKOuuL7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lHvWODSY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zs2ARHXv, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ttXFDuzc, 1000.0f);
  numBytes += cBinop_init(&cBinop_75QMmmnb, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_mrKZljmA, 0.0f);
  numBytes += cBinop_init(&cBinop_Dl26kkEH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_FxYkz8yh, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_d8oqa1r9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_A8THGL24, 1.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_u9YSDI4k, false);
  numBytes += sVarf_init(&sVarf_90ETYJlY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YsLvlxiY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iOA5Ex6i, 0.0f);
  numBytes += sVarf_init(&sVarf_Q0bkAGYI, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_qOJ1SvGO, false);
  numBytes += sVarf_init(&sVarf_xJslgZFD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_z3LWs79X, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QdFVvAfq, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QP7tdi3A, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mfh25uWT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_kTBG1YJp, 0.0f);
  numBytes += cVar_init_f(&cVar_ERgMZfOS, 1000.0f);
  numBytes += cBinop_init(&cBinop_9bejl0Ef, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ferHxxur, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_c5ybgceB, 0.0f);
  numBytes += cBinop_init(&cBinop_afbeomuB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FaFMwHZU, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_kOUyotFF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1uLtXhTB, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_usRvc5tx, 1, -1);
  numBytes += cSlice_init(&cSlice_gHP8NTcH, 1, -1);
  numBytes += sVarf_init(&sVarf_jBzWeCnl, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gaoCOtlL, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_Panoramizer::~Heavy_Panoramizer() {
  sEnv_free(&sEnv_vIzZ7sP9);
  cPack_free(&cPack_BgNhb75u);
  cPack_free(&cPack_VZ4Vbe6z);
  cPack_free(&cPack_TVWxQJAX);
  cPack_free(&cPack_q0b2lD0f);
  cPack_free(&cPack_qE8tcMdh);
  cPack_free(&cPack_84oBoStL);
  cPack_free(&cPack_pwmPsK8A);
  cPack_free(&cPack_HGjeKzLl);
  cPack_free(&cPack_SOuaIdcL);
  cPack_free(&cPack_R5e3gV2r);
  cPack_free(&cPack_7Zx6qeCt);
  cPack_free(&cPack_wsbThzCO);
  cPack_free(&cPack_m9u76HZ6);
  cPack_free(&cPack_Hm2D2lw5);
  cPack_free(&cPack_PVf041un);
  cPack_free(&cPack_2ywB6kJi);
  cPack_free(&cPack_WhjWB6Uw);
  cPack_free(&cPack_l41vCFsR);
  cPack_free(&cPack_udwhr5qK);
  cPack_free(&cPack_KIZvesAc);
}

HvTable *Heavy_Panoramizer::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_Panoramizer::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PptDemuO_sendMessage);
      break;
    }
    case 0xBA8CED4E: { // dry
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QBHXLZcc_sendMessage);
      break;
    }
    case 0x6A6F415D: { // mono
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2HmCSC54_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EuokfNDd_sendMessage);
      break;
    }
    case 0x1B53CD5A: { // wet
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eeA8jCOd_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_Panoramizer::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "dry";
        info->hash = 0xBA8CED4E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 1: {
        info->name = "mono";
        info->hash = 0x6A6F415D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 50.0f;
        info->defaultVal = 25.0f;
        break;
      }
      case 2: {
        info->name = "wet";
        info->hash = 0x1B53CD5A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 1.0f;
        break;
      }
      case 3: {
        info->name = "time";
        info->hash = 0x8E55AA5F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 1.0f;
        info->maxVal = 5.0f;
        info->defaultVal = 2.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 4;
}



/*
 * Send Function Implementations
 */


void Heavy_Panoramizer::cMsg_5wDEuOKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.12f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TmrXnmvZ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jBzWeCnl, m);
}

void Heavy_Panoramizer::cReceive_2HmCSC54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FxYkz8yh, HV_BINOP_ADD, 1, m, &cBinop_FxYkz8yh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_2LaIFiAF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_P4HtOh27, HV_BINOP_ADD, 1, m, &cBinop_P4HtOh27_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_RZyEAznV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FaFMwHZU, HV_BINOP_ADD, 1, m, &cBinop_FaFMwHZU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gP8cMz0G_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dgYWkrdj, HV_BINOP_ADD, 1, m, &cBinop_dgYWkrdj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_V8wXH6U0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ny0Wd1XB, HV_BINOP_ADD, 1, m, &cBinop_ny0Wd1XB_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ASfanXvJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HSey0fsc, HV_BINOP_ADD, 1, m, &cBinop_HSey0fsc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_okAbPEWK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6et0sILy, HV_BINOP_ADD, 1, m, &cBinop_6et0sILy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_MVKetmjI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uXZaLFd3, HV_BINOP_ADD, 1, m, &cBinop_uXZaLFd3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_w5OCC21O_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZF5I7Tr7, HV_BINOP_ADD, 1, m, &cBinop_ZF5I7Tr7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_J8Sg49zj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vpkbrOwk, HV_BINOP_ADD, 1, m, &cBinop_vpkbrOwk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_WD6Srns9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_L03k4Str, HV_BINOP_ADD, 1, m, &cBinop_L03k4Str_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7KApkhnK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0dlKewJy, HV_BINOP_ADD, 1, m, &cBinop_0dlKewJy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_PLnjKVnx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_A9TcDwvM, HV_BINOP_ADD, 1, m, &cBinop_A9TcDwvM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_jvLkmlxH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_thACoG9f, HV_BINOP_ADD, 1, m, &cBinop_thACoG9f_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ttnVjm2M_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8yGGlh9B, HV_BINOP_ADD, 1, m, &cBinop_8yGGlh9B_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ksSzBZXm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzIe9iOX, HV_BINOP_ADD, 1, m, &cBinop_TzIe9iOX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_HJkDJXTb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_kf3lpcIY, HV_BINOP_ADD, 1, m, &cBinop_kf3lpcIY_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YjY9KO9b_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BwmQzwqe, HV_BINOP_ADD, 1, m, &cBinop_BwmQzwqe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_KlLDFq0d_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lVvm4Bfp, HV_BINOP_ADD, 1, m, &cBinop_lVvm4Bfp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_uf550Vv8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_I2Cst5QV, HV_BINOP_ADD, 1, m, &cBinop_I2Cst5QV_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_1weU58OV_sendMessage);
}

void Heavy_Panoramizer::cReceive_PptDemuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oatzeytR, 0, m, &cVar_oatzeytR_sendMessage);
  cMsg_b6qHjsgV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mfh25uWT, 0, m, &cVar_mfh25uWT_sendMessage);
  cMsg_1jfkAmiT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5QtG5Wbl, 0, m, &cVar_5QtG5Wbl_sendMessage);
  cMsg_09rQKo4A_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iOA5Ex6i, 0, m, &cVar_iOA5Ex6i_sendMessage);
  cMsg_b03qO3cH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jtRRuezc, 0, m, &cVar_jtRRuezc_sendMessage);
  cMsg_ZkeAJYN3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Wnx1Ss4v, 0, m, &cVar_Wnx1Ss4v_sendMessage);
  cMsg_f41DJGw5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MAgZq37l, 0, m, &cVar_MAgZq37l_sendMessage);
  cMsg_iTaAmDS6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vYYQjND0, 0, m, &cVar_vYYQjND0_sendMessage);
  cMsg_ZuztzUYG_sendMessage(_c, 0, m);
  cMsg_5q1jvdmG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ttXFDuzc, 0, m, &cVar_ttXFDuzc_sendMessage);
  cMsg_m9wNOXyp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Iy0cNPij, 0, m, &cVar_Iy0cNPij_sendMessage);
  cMsg_2CTYc4Fi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ferHxxur, 0, m, &cVar_ferHxxur_sendMessage);
  cMsg_KmF3NbWi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kAKmpfEa, 0, m, &cVar_kAKmpfEa_sendMessage);
  cMsg_Ujma5Fwo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PYb9Xvc9, 0, m, &cVar_PYb9Xvc9_sendMessage);
  cMsg_8DG5WsFd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_h2miBKEr, 0, m, &cVar_h2miBKEr_sendMessage);
  cMsg_HS2GNovr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wG8gMr2g, 0, m, &cVar_wG8gMr2g_sendMessage);
  cMsg_prOKeH0Y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sLZajxVK, 0, m, &cVar_sLZajxVK_sendMessage);
  cMsg_5QMWww13_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mln0cGd3, 0, m, &cVar_mln0cGd3_sendMessage);
  cMsg_Re0AwdIr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lUs941mW, 0, m, &cVar_lUs941mW_sendMessage);
  cMsg_YlGnQAXo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wEgJgGmd, 0, m, &cVar_wEgJgGmd_sendMessage);
  cMsg_u70Hhzb5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vNmIwWFZ, 0, m, &cVar_vNmIwWFZ_sendMessage);
  cMsg_OW2BAoQQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tioICOBO, 0, m, &cVar_tioICOBO_sendMessage);
  cMsg_6UZJ75K6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Ligl3cRK, 0, m, &cVar_Ligl3cRK_sendMessage);
  cMsg_fFH8vTzx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5XuGwcVF, 0, m, &cVar_5XuGwcVF_sendMessage);
  cMsg_mmBFjxZJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GlFGFJVw, 0, m, &cVar_GlFGFJVw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bxg4xK2S, 0, m, &cVar_bxg4xK2S_sendMessage);
  cMsg_E4QxRxSx_sendMessage(_c, 0, m);
  cMsg_rEhqD9cC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s0u2ZXpi, 0, m, &cVar_s0u2ZXpi_sendMessage);
  cMsg_XDdFA3fs_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_q8chZZpl, 0, m, &cVar_q8chZZpl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_2o3UhK8K, 0, m, &cVar_2o3UhK8K_sendMessage);
  cMsg_6dK4lVPM_sendMessage(_c, 0, m);
  cMsg_J65snLsx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ERgMZfOS, 0, m, &cVar_ERgMZfOS_sendMessage);
  cMsg_m3JJ7aIb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2jdf0w2y, 0, m, &cVar_2jdf0w2y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KZvASSsv, 0, m, &cVar_KZvASSsv_sendMessage);
  cMsg_It2bAlSa_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GXoQXGUE, 0, m, &cVar_GXoQXGUE_sendMessage);
  cMsg_hc2OZkTw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NBo1cCkI, 0, m, &cVar_NBo1cCkI_sendMessage);
  cMsg_kozTQekk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_L2GX4vgF, 0, m, &cVar_L2GX4vgF_sendMessage);
  cMsg_8Ws0oVIO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ncXHOsBv, 0, m, &cVar_ncXHOsBv_sendMessage);
  cMsg_STZFLkIN_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Mb8Q91v0, 0, m, &cVar_Mb8Q91v0_sendMessage);
  cMsg_P98L4rDW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ow0bPaLg, 0, m, &cVar_ow0bPaLg_sendMessage);
  cMsg_zrhBH08W_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_y41LITa6, 0, m, &cVar_y41LITa6_sendMessage);
  cMsg_Tf9teDvo_sendMessage(_c, 0, m);
  cMsg_1Nvoe4DI_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fRddS6aP, 0, m, &cVar_fRddS6aP_sendMessage);
  cMsg_ud30Ca9N_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZKT2nqf4, 0, m, &cVar_ZKT2nqf4_sendMessage);
  cMsg_Z9FOAIuM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2AZHogX9, 0, m, &cVar_2AZHogX9_sendMessage);
  cMsg_X3oZlXnj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RZYHKoS9, 0, m, &cVar_RZYHKoS9_sendMessage);
  cMsg_HIBpbT3Z_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B6FSUic1, 0, m, &cVar_B6FSUic1_sendMessage);
  cMsg_WZpTduSG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OXINzLAu, 0, m, &cVar_OXINzLAu_sendMessage);
  cMsg_D3R8UDAM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_frKFCl06, 0, m, &cVar_frKFCl06_sendMessage);
  cMsg_qfRnOG45_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eRbx0nWe, 0, m, &cVar_eRbx0nWe_sendMessage);
  cMsg_QwBNSkop_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yx1vvfwy, 0, m, &cVar_yx1vvfwy_sendMessage);
  cMsg_lJPDNEB3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_d4qmomJn, 0, m, &cVar_d4qmomJn_sendMessage);
  cMsg_17dGTwHZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3QIz6LKN, 0, m, &cVar_3QIz6LKN_sendMessage);
  cMsg_R2txHqJp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XVRLW315, 0, m, &cVar_XVRLW315_sendMessage);
  cMsg_6WRoQRNj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lUQxK12K, 0, m, &cVar_lUQxK12K_sendMessage);
  cMsg_ywU7nyNV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4QuNDreE, 0, m, &cVar_4QuNDreE_sendMessage);
  cMsg_OZ61KJCJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_t8i9MwWv, 0, m, &cVar_t8i9MwWv_sendMessage);
  cMsg_Y5bnt2d0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xpgkkHjf, 0, m, &cVar_xpgkkHjf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Ry1IebOM, 0, m, &cVar_Ry1IebOM_sendMessage);
  cMsg_wqhQ0gzI_sendMessage(_c, 0, m);
  cMsg_jGULOuIL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PPLuPCJU, 0, m, &cVar_PPLuPCJU_sendMessage);
  cMsg_tNBLoLgD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4uPYedz8, 0, m, &cVar_4uPYedz8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QmihQWOH, 0, m, &cVar_QmihQWOH_sendMessage);
  cMsg_Yxas36Ha_sendMessage(_c, 0, m);
  cMsg_WSSMSVub_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_uQ7KsflP, 0, m, &cVar_uQ7KsflP_sendMessage);
  cMsg_J4u8tGGt_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_B2JxT1Ml, 0, m, &cVar_B2JxT1Ml_sendMessage);
  cMsg_xn0rnegV_sendMessage(_c, 0, m);
  cMsg_b4yX69s3_sendMessage(_c, 0, m);
  cMsg_KDoD0vuM_sendMessage(_c, 0, m);
  cMsg_UjQodQme_sendMessage(_c, 0, m);
  cMsg_Vq1wKjlY_sendMessage(_c, 0, m);
  cMsg_8bMsSrdk_sendMessage(_c, 0, m);
  cMsg_UgLhUApX_sendMessage(_c, 0, m);
  cMsg_5CMNM2F6_sendMessage(_c, 0, m);
  cSwitchcase_aJ6QqlvC_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_P8vVLgsx_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_QSETQVKB_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_kkWM3FL1_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_R92keiWm_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_ZuSuiAQh_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_YIsxOE7v_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_ubevqBIS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_FfF901ji_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HhkjJUyx_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HEnDO9n6_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_YnFKZdF2_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_O6y1J8Kb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_lQJokBhq_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_87cXTt38_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_BuDdufZn_onMessage(_c, NULL, 0, m, NULL);
  cMsg_iYTnrkZk_sendMessage(_c, 0, m);
  cSwitchcase_Ridq6iE8_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_U0WV5rIX_onMessage(_c, NULL, 0, m, NULL);
  cMsg_k38JUeIJ_sendMessage(_c, 0, m);
  cSwitchcase_pDLLKV8L_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_6BpuYxRj_onMessage(_c, NULL, 0, m, NULL);
  cMsg_X20p3qxC_sendMessage(_c, 0, m);
  cMsg_cEfuIOJ2_sendMessage(_c, 0, m);
  cMsg_CYYcaPjY_sendMessage(_c, 0, m);
  cMsg_cLtdRPKF_sendMessage(_c, 0, m);
  cMsg_TGyIgXyk_sendMessage(_c, 0, m);
  cMsg_MvCMzslN_sendMessage(_c, 0, m);
  cMsg_Vumvn3H7_sendMessage(_c, 0, m);
  cMsg_KNwpuXEQ_sendMessage(_c, 0, m);
  cSwitchcase_BY5D6636_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_UkTFRIgT_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_S1dIBOFN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_4zs1zjUo_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_6PZQamoA_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_VlraTLCX_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_fAu4nFqk_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Sf3lSbmc_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_DgRQ0uXw_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_RXR8phfe_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_orbLzIen_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_nUbrNTGd_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_LpN8lKEG_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_qUZjVJEo_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_9BUc3CUV_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_neF1gaYX_onMessage(_c, NULL, 0, m, NULL);
  cMsg_TlhcD4tK_sendMessage(_c, 0, m);
  cSwitchcase_oA4RGlz4_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_4jY8ftHz_onMessage(_c, NULL, 0, m, NULL);
  cMsg_dMHHSV0U_sendMessage(_c, 0, m);
  cSwitchcase_I9LF0MX5_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_HskvbRWo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::sEnv_vIzZ7sP9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_EbPtAcIP_sendMessage);
}

void Heavy_Panoramizer::cBinop_INzAl95R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TVWxQJAX, 1, m, &cPack_TVWxQJAX_sendMessage);
}

void Heavy_Panoramizer::cDelay_XNaD9zXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XNaD9zXd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XNaD9zXd, 0, m, &cDelay_XNaD9zXd_sendMessage);
  cSwitchcase_EIVPQeV2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_Sf3lSbmc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_Xuo52gyX_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Xuo52gyX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1EmRl9TH_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_qfRnOG45_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_D9jR2nRP_sendMessage);
}

void Heavy_Panoramizer::cSystem_D9jR2nRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_BqQR21MN_sendMessage);
}

void Heavy_Panoramizer::cBinop_OWIYNtha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_l2i8l0yF_sendMessage);
}

void Heavy_Panoramizer::cBinop_l2i8l0yF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XNaD9zXd, 2, m, &cDelay_XNaD9zXd_sendMessage);
}

void Heavy_Panoramizer::cMsg_Xuo52gyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XNaD9zXd, 0, m, &cDelay_XNaD9zXd_sendMessage);
}

void Heavy_Panoramizer::cBinop_BqQR21MN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OWIYNtha, HV_BINOP_MULTIPLY, 1, m, &cBinop_OWIYNtha_sendMessage);
}

void Heavy_Panoramizer::cCast_1EmRl9TH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xuo52gyX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XNaD9zXd, 0, m, &cDelay_XNaD9zXd_sendMessage);
  cSwitchcase_EIVPQeV2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_eRbx0nWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OWIYNtha, HV_BINOP_MULTIPLY, 0, m, &cBinop_OWIYNtha_sendMessage);
}

void Heavy_Panoramizer::cMsg_ICi8UnfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ngxOPElX, HV_BINOP_SUBTRACT, 0, m, &cBinop_ngxOPElX_sendMessage);
}

void Heavy_Panoramizer::cCast_MlAvvLWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UuxjzxrT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_QaVIlOEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YXdjPiK4_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_cNl7RdV5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pXnCtlE2_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_YXdjPiK4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jiX2emPT_sendMessage);
}

void Heavy_Panoramizer::cBinop_jiX2emPT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TY1eTrWJ, m);
}

void Heavy_Panoramizer::cMsg_tbFzUY42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6Uca0iPe_sendMessage);
}

void Heavy_Panoramizer::cBinop_6Uca0iPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LA6VwDJJ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9LVe71wa, m);
}

void Heavy_Panoramizer::cMsg_oZtiY8Ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_BprN4Pkp_sendMessage);
}

void Heavy_Panoramizer::cMsg_pXnCtlE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_QaVIlOEX_sendMessage);
}

void Heavy_Panoramizer::cVar_Ry1IebOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_PwA4uZFU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_eQw886Zy, 0, m, &cIf_eQw886Zy_sendMessage);
}

void Heavy_Panoramizer::cMsg_XXA8VZ1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_cNl7RdV5_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LA6VwDJJ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9LVe71wa, m);
}

void Heavy_Panoramizer::cBinop_BprN4Pkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_APBMFKji, m);
}

void Heavy_Panoramizer::cSystem_APwGL594_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oZtiY8Ph_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_wqhQ0gzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_APwGL594_sendMessage);
}

void Heavy_Panoramizer::cBinop_PwA4uZFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_eQw886Zy, 1, m, &cIf_eQw886Zy_sendMessage);
}

void Heavy_Panoramizer::cIf_eQw886Zy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XXA8VZ1Y_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_cNl7RdV5_sendMessage);
      cMsg_tbFzUY42_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_sCiRCSuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WYe2ajYZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_WYe2ajYZ_sendMessage);
}

void Heavy_Panoramizer::cMsg_X20p3qxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_KZvASSsv, 0, m, &cVar_KZvASSsv_sendMessage);
}

void Heavy_Panoramizer::cBinop_7KApkhnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FrHV5h6Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2bqimKsu_sendMessage);
}

void Heavy_Panoramizer::cCast_1dzOEoz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lnlQETjj_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_MvCMzslN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Mb8Q91v0, 0, m, &cVar_Mb8Q91v0_sendMessage);
}

void Heavy_Panoramizer::cBinop_ksSzBZXm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l89WKQb9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_h6vbLyjj_sendMessage);
}

void Heavy_Panoramizer::cMsg_jMCxgpA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Ag6NePAm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_l9QXFGs6, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BSDGpvoj, m);
}

void Heavy_Panoramizer::cBinop_Dg8i0s9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_V10nx0dc, 1, m, &cIf_V10nx0dc_sendMessage);
}

void Heavy_Panoramizer::cIf_V10nx0dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_jMCxgpA6_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Ag6NePAm_sendMessage);
      cMsg_4GxPSD1U_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_JVtoOmzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GA5hE0Yq_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_YOvT7Qn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jdzCHzNc_sendMessage);
}

void Heavy_Panoramizer::cMsg_GA5hE0Yq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_38smbwOL_sendMessage);
}

void Heavy_Panoramizer::cBinop_a6gPzs46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_l9QXFGs6, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BSDGpvoj, m);
}

void Heavy_Panoramizer::cMsg_qpgobf51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JVtoOmzk_sendMessage);
}

void Heavy_Panoramizer::cVar_L2GX4vgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_Dg8i0s9u_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_V10nx0dc, 0, m, &cIf_V10nx0dc_sendMessage);
}

void Heavy_Panoramizer::cBinop_jdzCHzNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HtsEBYby, m);
}

void Heavy_Panoramizer::cBinop_38smbwOL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VSfB8RMv, m);
}

void Heavy_Panoramizer::cBinop_Ag6NePAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qpgobf51_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_4GxPSD1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_a6gPzs46_sendMessage);
}

void Heavy_Panoramizer::cMsg_8Ws0oVIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8VJJ4fsw_sendMessage);
}

void Heavy_Panoramizer::cSystem_8VJJ4fsw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YOvT7Qn2_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_sXDidnYo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ICi8UnfE_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cPack_BgNhb75u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_lLnI9Nmg, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_BwmQzwqe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SOuaIdcL, 0, m, &cPack_SOuaIdcL_sendMessage);
}

void Heavy_Panoramizer::cVar_ow0bPaLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_PVH6Qcea_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_HDdgk1Dw, 0, m, &cIf_HDdgk1Dw_sendMessage);
}

void Heavy_Panoramizer::cMsg_trfnC9Hk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_TaODHK2Q_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ObIvSq7R, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vb2RNPC4, m);
}

void Heavy_Panoramizer::cBinop_LU5o4PKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_NaVGb5do, m);
}

void Heavy_Panoramizer::cIf_HDdgk1Dw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_trfnC9Hk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_TaODHK2Q_sendMessage);
      cMsg_SbfcyFSo_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_PVH6Qcea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_HDdgk1Dw, 1, m, &cIf_HDdgk1Dw_sendMessage);
}

void Heavy_Panoramizer::cMsg_Ny22Qpdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_CRiwbi4Y_sendMessage);
}

void Heavy_Panoramizer::cMsg_SbfcyFSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gfQRfKbS_sendMessage);
}

void Heavy_Panoramizer::cBinop_TaODHK2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ny22Qpdy_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_CRiwbi4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b6u48UMc_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSystem_shTmChOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SEQ1Hzfp_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_zrhBH08W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_shTmChOS_sendMessage);
}

void Heavy_Panoramizer::cMsg_b6u48UMc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_BHwfzdsv_sendMessage);
}

void Heavy_Panoramizer::cBinop_gfQRfKbS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ObIvSq7R, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Vb2RNPC4, m);
}

void Heavy_Panoramizer::cBinop_BHwfzdsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q8tLslKo, m);
}

void Heavy_Panoramizer::cMsg_SEQ1Hzfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LU5o4PKd_sendMessage);
}

void Heavy_Panoramizer::cCast_VcvOkjLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FLK047vC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zeNM9NzY, 0, m, &cDelay_zeNM9NzY_sendMessage);
  cSwitchcase_brZHgS8k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cDelay_zeNM9NzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zeNM9NzY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zeNM9NzY, 0, m, &cDelay_zeNM9NzY_sendMessage);
  cSwitchcase_brZHgS8k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_FLK047vC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zeNM9NzY, 0, m, &cDelay_zeNM9NzY_sendMessage);
}

void Heavy_Panoramizer::cVar_4QuNDreE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_COw4KCc9, HV_BINOP_MULTIPLY, 0, m, &cBinop_COw4KCc9_sendMessage);
}

void Heavy_Panoramizer::cBinop_COw4KCc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_gBvusGTn_sendMessage);
}

void Heavy_Panoramizer::cBinop_gBvusGTn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zeNM9NzY, 2, m, &cDelay_zeNM9NzY_sendMessage);
}

void Heavy_Panoramizer::cSystem_shL8gHkp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_rHaDfWwt_sendMessage);
}

void Heavy_Panoramizer::cMsg_ywU7nyNV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_shL8gHkp_sendMessage);
}

void Heavy_Panoramizer::cBinop_rHaDfWwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_COw4KCc9, HV_BINOP_MULTIPLY, 1, m, &cBinop_COw4KCc9_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_qUZjVJEo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_FLK047vC_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_FLK047vC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VcvOkjLj_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_cLtdRPKF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_L2GX4vgF, 0, m, &cVar_L2GX4vgF_sendMessage);
}

void Heavy_Panoramizer::cBinop_QvD7MZxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FrHyOmBI, HV_BINOP_MULTIPLY, 1, m, &cBinop_FrHyOmBI_sendMessage);
}

void Heavy_Panoramizer::cCast_z93yApB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JNUkZPuE_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSlice_n8a9SdAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hVm1krXV, 1, m, &cRandom_hVm1krXV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_mTLv6KZP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_n8a9SdAy, 0, m, &cSlice_n8a9SdAy_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hVm1krXV, 0, m, &cRandom_hVm1krXV_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_28ZFoqo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A9TcDwvM, HV_BINOP_ADD, 0, m, &cBinop_A9TcDwvM_sendMessage);
}

void Heavy_Panoramizer::cRandom_hVm1krXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FrHyOmBI, HV_BINOP_MULTIPLY, 0, m, &cBinop_FrHyOmBI_sendMessage);
}

void Heavy_Panoramizer::cBinop_FrHyOmBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_28ZFoqo8_sendMessage);
}

void Heavy_Panoramizer::cBinop_jvLkmlxH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iWKt8qk5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XVRfCiHI_sendMessage);
}

void Heavy_Panoramizer::cBinop_lVvm4Bfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HGjeKzLl, 0, m, &cPack_HGjeKzLl_sendMessage);
}

void Heavy_Panoramizer::cCast_9MaIiX1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ngxOPElX, HV_BINOP_SUBTRACT, 1, m, &cBinop_ngxOPElX_sendMessage);
}

void Heavy_Panoramizer::cSlice_nmYMGEPc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eCoZEmAV, 1, m, &cRandom_eCoZEmAV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_eCoZEmAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qjt0yr59, HV_BINOP_MULTIPLY, 0, m, &cBinop_qjt0yr59_sendMessage);
}

void Heavy_Panoramizer::cBinop_qjt0yr59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nRieLHSY_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_UuxjzxrT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_nmYMGEPc, 0, m, &cSlice_nmYMGEPc_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eCoZEmAV, 0, m, &cRandom_eCoZEmAV_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_nRieLHSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzIe9iOX, HV_BINOP_ADD, 0, m, &cBinop_TzIe9iOX_sendMessage);
}

void Heavy_Panoramizer::cMsg_X3oZlXnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3gAZc3TD_sendMessage);
}

void Heavy_Panoramizer::cSystem_3gAZc3TD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0KzrWPnl_sendMessage);
}

void Heavy_Panoramizer::cMsg_lRwVeU7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_obgqjZ53, 0, m, &cDelay_obgqjZ53_sendMessage);
}

void Heavy_Panoramizer::cBinop_0KzrWPnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0FoFR6Y, HV_BINOP_MULTIPLY, 1, m, &cBinop_F0FoFR6Y_sendMessage);
}

void Heavy_Panoramizer::cCast_tezXRUK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lRwVeU7Q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_obgqjZ53, 0, m, &cDelay_obgqjZ53_sendMessage);
  cSwitchcase_8q9mnpqC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_4zs1zjUo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_lRwVeU7Q_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_lRwVeU7Q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tezXRUK3_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_F0FoFR6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Jfta6ce5_sendMessage);
}

void Heavy_Panoramizer::cBinop_Jfta6ce5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_obgqjZ53, 2, m, &cDelay_obgqjZ53_sendMessage);
}

void Heavy_Panoramizer::cVar_RZYHKoS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0FoFR6Y, HV_BINOP_MULTIPLY, 0, m, &cBinop_F0FoFR6Y_sendMessage);
}

void Heavy_Panoramizer::cDelay_obgqjZ53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_obgqjZ53, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_obgqjZ53, 0, m, &cDelay_obgqjZ53_sendMessage);
  cSwitchcase_8q9mnpqC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_EuPCbvFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QvD7MZxU, HV_BINOP_SUBTRACT, 0, m, &cBinop_QvD7MZxU_sendMessage);
}

void Heavy_Panoramizer::cCast_mjkARtEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Uuodf4Ni_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_g6SfZQGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aPlxu1RT, HV_BINOP_SUBTRACT, 1, m, &cBinop_aPlxu1RT_sendMessage);
}

void Heavy_Panoramizer::cVar_d4qmomJn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i9BX3s0u, HV_BINOP_MULTIPLY, 0, m, &cBinop_i9BX3s0u_sendMessage);
}

void Heavy_Panoramizer::cBinop_i9BX3s0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_7BxjeHPQ_sendMessage);
}

void Heavy_Panoramizer::cMsg_lJPDNEB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UlPnO3nd_sendMessage);
}

void Heavy_Panoramizer::cSystem_UlPnO3nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ag5WtiM5_sendMessage);
}

void Heavy_Panoramizer::cCast_tylrNRC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_STZ1xxvW_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc38ukDv, 0, m, &cDelay_Yc38ukDv_sendMessage);
  cSwitchcase_67vSRMxE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cDelay_Yc38ukDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Yc38ukDv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc38ukDv, 0, m, &cDelay_Yc38ukDv_sendMessage);
  cSwitchcase_67vSRMxE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_RXR8phfe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_STZ1xxvW_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_STZ1xxvW_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tylrNRC7_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_STZ1xxvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc38ukDv, 0, m, &cDelay_Yc38ukDv_sendMessage);
}

void Heavy_Panoramizer::cBinop_7BxjeHPQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yc38ukDv, 2, m, &cDelay_Yc38ukDv_sendMessage);
}

void Heavy_Panoramizer::cBinop_ag5WtiM5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i9BX3s0u, HV_BINOP_MULTIPLY, 1, m, &cBinop_i9BX3s0u_sendMessage);
}

void Heavy_Panoramizer::cPack_VZ4Vbe6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_CuqrGXEv, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_h6vbLyjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_V7UOuM5j_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cPack_TVWxQJAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_PwvaKAuJ, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_kf3lpcIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R5e3gV2r, 0, m, &cPack_R5e3gV2r_sendMessage);
}

void Heavy_Panoramizer::cBinop_HJkDJXTb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WR7dCZuW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z93yApB5_sendMessage);
}

void Heavy_Panoramizer::cSlice_uzQrrCIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dYR6iJ7D, 1, m, &cRandom_dYR6iJ7D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_WMfyzHca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Kuurqgk1_sendMessage);
}

void Heavy_Panoramizer::cUnop_Kuurqgk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YY41R8Sr, HV_BINOP_MULTIPLY, 0, m, &cBinop_YY41R8Sr_sendMessage);
}

void Heavy_Panoramizer::cRandom_dYR6iJ7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_WMfyzHca_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_arM3L7wm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uzQrrCIU, 0, m, &cSlice_uzQrrCIU_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dYR6iJ7D, 0, m, &cRandom_dYR6iJ7D_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_xH38ZvI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cwZOkSiK, m);
}

void Heavy_Panoramizer::cBinop_XGmdMUPD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6chEvmhY, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2iHG6fD0, m);
}

void Heavy_Panoramizer::cMsg_P98L4rDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FKqK4NQd_sendMessage);
}

void Heavy_Panoramizer::cSystem_FKqK4NQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hMJLrBSe_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_POTZDqab_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_yuSzHUZi_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6chEvmhY, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_2iHG6fD0, m);
}

void Heavy_Panoramizer::cVar_Mb8Q91v0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_q9cIVn0l_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_xyvdJNLa, 0, m, &cIf_xyvdJNLa_sendMessage);
}

void Heavy_Panoramizer::cBinop_MJeCURdp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7Al7TpYw_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_aQmI6UBE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wtRFW9Kf, m);
}

void Heavy_Panoramizer::cMsg_iGQsVTmH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MJeCURdp_sendMessage);
}

void Heavy_Panoramizer::cMsg_ZxRGa4TN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XGmdMUPD_sendMessage);
}

void Heavy_Panoramizer::cBinop_yuSzHUZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iGQsVTmH_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_q9cIVn0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xyvdJNLa, 1, m, &cIf_xyvdJNLa_sendMessage);
}

void Heavy_Panoramizer::cIf_xyvdJNLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_POTZDqab_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_yuSzHUZi_sendMessage);
      cMsg_ZxRGa4TN_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_7Al7TpYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_aQmI6UBE_sendMessage);
}

void Heavy_Panoramizer::cMsg_hMJLrBSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xH38ZvI1_sendMessage);
}

void Heavy_Panoramizer::cMsg_O8arpR85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Jfr9G19I_sendMessage);
}

void Heavy_Panoramizer::cBinop_FaLWPKiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IrhOuGAu, m);
}

void Heavy_Panoramizer::cMsg_kfcm3Ins_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_FaLWPKiB_sendMessage);
}

void Heavy_Panoramizer::cBinop_VwoAjiPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kfcm3Ins_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_Jfr9G19I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lOTUctdd, m);
}

void Heavy_Panoramizer::cMsg_uFytDaN9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_07LbKW1c_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_y1RscVmb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TEwGdxac, m);
}

void Heavy_Panoramizer::cBinop_5Ju5WvAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_WupUb8Hi, 1, m, &cIf_WupUb8Hi_sendMessage);
}

void Heavy_Panoramizer::cIf_WupUb8Hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_uFytDaN9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_07LbKW1c_sendMessage);
      cMsg_muzys6gd_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_0REB5Hf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VwoAjiPX_sendMessage);
}

void Heavy_Panoramizer::cBinop_KDY8EFWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_y1RscVmb, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TEwGdxac, m);
}

void Heavy_Panoramizer::cVar_NBo1cCkI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_5Ju5WvAR_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_WupUb8Hi, 0, m, &cIf_WupUb8Hi_sendMessage);
}

void Heavy_Panoramizer::cBinop_07LbKW1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0REB5Hf7_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSystem_kr2AZWDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O8arpR85_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_kozTQekk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kr2AZWDE_sendMessage);
}

void Heavy_Panoramizer::cMsg_muzys6gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KDY8EFWw_sendMessage);
}

void Heavy_Panoramizer::cBinop_I2Cst5QV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_84oBoStL, 0, m, &cPack_84oBoStL_sendMessage);
}

void Heavy_Panoramizer::cCast_iWKt8qk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QvD7MZxU, HV_BINOP_SUBTRACT, 1, m, &cBinop_QvD7MZxU_sendMessage);
}

void Heavy_Panoramizer::cMsg_nZ1P7IRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XIs2UU7E_sendMessage);
}

void Heavy_Panoramizer::cBinop_reOdmljz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_groFASn5_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_groFASn5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rBrAx2FM_sendMessage);
}

void Heavy_Panoramizer::cBinop_0uTHIAgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_j9RWhhvD, m);
}

void Heavy_Panoramizer::cBinop_vtMxbf1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_7PbISZrq, m);
}

void Heavy_Panoramizer::cBinop_rBrAx2FM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C6gsuZw1_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_FTyA7Yrn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0uTHIAgc_sendMessage);
}

void Heavy_Panoramizer::cMsg_CRWuCUlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_reOdmljz_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gBDlFIes, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RIzHLBIO, m);
}

void Heavy_Panoramizer::cVar_ncXHOsBv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_yaQGC4mG_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_05ysRCaA, 0, m, &cIf_05ysRCaA_sendMessage);
}

void Heavy_Panoramizer::cSystem_exNnmUzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FTyA7Yrn_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_STZFLkIN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_exNnmUzF_sendMessage);
}

void Heavy_Panoramizer::cMsg_C6gsuZw1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_vtMxbf1q_sendMessage);
}

void Heavy_Panoramizer::cBinop_yaQGC4mG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_05ysRCaA, 1, m, &cIf_05ysRCaA_sendMessage);
}

void Heavy_Panoramizer::cIf_05ysRCaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_CRWuCUlf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_reOdmljz_sendMessage);
      cMsg_nZ1P7IRv_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_XIs2UU7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gBDlFIes, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RIzHLBIO, m);
}

void Heavy_Panoramizer::cCast_s9iqJ0Fa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GvuUieG4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cPack_q0b2lD0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_M1XQKarV, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_u3UTDCdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_EP2dZlU9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_82fM5T4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kqJ05q7B_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aFnQdcZC, 0, m, &cDelay_aFnQdcZC_sendMessage);
  cSwitchcase_SOBKfTWT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_kqJ05q7B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_aFnQdcZC, 0, m, &cDelay_aFnQdcZC_sendMessage);
}

void Heavy_Panoramizer::cMsg_R2txHqJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DHxlGivS_sendMessage);
}

void Heavy_Panoramizer::cSystem_DHxlGivS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1l0peK3d_sendMessage);
}

void Heavy_Panoramizer::cDelay_aFnQdcZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aFnQdcZC, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_aFnQdcZC, 0, m, &cDelay_aFnQdcZC_sendMessage);
  cSwitchcase_SOBKfTWT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_l48pxDQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0W9g2vty_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_nUbrNTGd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_kqJ05q7B_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_kqJ05q7B_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_82fM5T4t_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_0W9g2vty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aFnQdcZC, 2, m, &cDelay_aFnQdcZC_sendMessage);
}

void Heavy_Panoramizer::cVar_XVRLW315_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l48pxDQs, HV_BINOP_MULTIPLY, 0, m, &cBinop_l48pxDQs_sendMessage);
}

void Heavy_Panoramizer::cBinop_1l0peK3d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l48pxDQs, HV_BINOP_MULTIPLY, 1, m, &cBinop_l48pxDQs_sendMessage);
}

void Heavy_Panoramizer::cCast_gk3WBttQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T0yWIMsZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_T0yWIMsZ_sendMessage);
}

void Heavy_Panoramizer::cCast_l89WKQb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DWBFMdnH, HV_BINOP_SUBTRACT, 1, m, &cBinop_DWBFMdnH_sendMessage);
}

void Heavy_Panoramizer::cBinop_DATbBqaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HGjeKzLl, 1, m, &cPack_HGjeKzLl_sendMessage);
}

void Heavy_Panoramizer::cBinop_aPlxu1RT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UxgnROXQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_UxgnROXQ_sendMessage);
}

void Heavy_Panoramizer::cBinop_39lz6YKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qE8tcMdh, 1, m, &cPack_qE8tcMdh_sendMessage);
}

void Heavy_Panoramizer::cBinop_L03k4Str_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_VZ4Vbe6z, 0, m, &cPack_VZ4Vbe6z_sendMessage);
}

void Heavy_Panoramizer::cMsg_6jZoXGJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_peZVejpU, 0, m, &cDelay_peZVejpU_sendMessage);
}

void Heavy_Panoramizer::cBinop_9HdSH1Ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vgP8Ispp, HV_BINOP_MULTIPLY, 1, m, &cBinop_vgP8Ispp_sendMessage);
}

void Heavy_Panoramizer::cBinop_xYMaSj2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_peZVejpU, 2, m, &cDelay_peZVejpU_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_9BUc3CUV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_6jZoXGJ3_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_6jZoXGJ3_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aRgFpnHd_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_vgP8Ispp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_xYMaSj2L_sendMessage);
}

void Heavy_Panoramizer::cVar_t8i9MwWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vgP8Ispp, HV_BINOP_MULTIPLY, 0, m, &cBinop_vgP8Ispp_sendMessage);
}

void Heavy_Panoramizer::cDelay_peZVejpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_peZVejpU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_peZVejpU, 0, m, &cDelay_peZVejpU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gkg5vxwE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S70gd1pF_sendMessage);
}

void Heavy_Panoramizer::cSystem_y3z3dQhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9HdSH1Ej_sendMessage);
}

void Heavy_Panoramizer::cMsg_OZ61KJCJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y3z3dQhA_sendMessage);
}

void Heavy_Panoramizer::cCast_aRgFpnHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6jZoXGJ3_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_peZVejpU, 0, m, &cDelay_peZVejpU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Gkg5vxwE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S70gd1pF_sendMessage);
}

void Heavy_Panoramizer::cMsg_TlhcD4tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Ry1IebOM, 0, m, &cVar_Ry1IebOM_sendMessage);
}

void Heavy_Panoramizer::cCast_zmrGhfjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mTLv6KZP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cUnop_lLlAfUTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uQ7KsflP, 0, m, &cVar_uQ7KsflP_sendMessage);
}

void Heavy_Panoramizer::cRandom_YN2OBmzm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_xRXbTNs4_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_PR8bb7hG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LBMfyPuJ, 0, m, &cSlice_LBMfyPuJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YN2OBmzm, 0, m, &cRandom_YN2OBmzm_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_xRXbTNs4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lLlAfUTS_sendMessage);
}

void Heavy_Panoramizer::cSlice_LBMfyPuJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YN2OBmzm, 1, m, &cRandom_YN2OBmzm_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_KNwpuXEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_y41LITa6, 0, m, &cVar_y41LITa6_sendMessage);
}

void Heavy_Panoramizer::cUnop_IIln1WnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_INzAl95R, HV_BINOP_MULTIPLY, 0, m, &cBinop_INzAl95R_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_NGYkLji0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_X16S9ub0, 0, m, &cSlice_X16S9ub0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ha4Wryad, 0, m, &cRandom_ha4Wryad_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_X16S9ub0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ha4Wryad, 1, m, &cRandom_ha4Wryad_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_PCIMukA7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_IIln1WnK_sendMessage);
}

void Heavy_Panoramizer::cRandom_ha4Wryad_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_PCIMukA7_sendMessage);
}

void Heavy_Panoramizer::cCast_AuF9FAqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a1MQHw8q, HV_BINOP_SUBTRACT, 1, m, &cBinop_a1MQHw8q_sendMessage);
}

void Heavy_Panoramizer::cMsg_GkiD73uL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_m2dINZzB_sendMessage);
}

void Heavy_Panoramizer::cMsg_B4hwhhvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_tsgeDpZX_sendMessage);
}

void Heavy_Panoramizer::cBinop_m2dINZzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pA5d4SXT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TndXOlKD, m);
}

void Heavy_Panoramizer::cBinop_6bXy5SvP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0cWRUb4P_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_GXoQXGUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_4L4geIWA_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_sUJGH7O5, 0, m, &cIf_sUJGH7O5_sendMessage);
}

void Heavy_Panoramizer::cMsg_0cWRUb4P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_nEcqoGHA_sendMessage);
}

void Heavy_Panoramizer::cBinop_GHorA6w1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QWhW5F3n, m);
}

void Heavy_Panoramizer::cSystem_sViYCrVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8C71tXJ1_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_hc2OZkTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sViYCrVu_sendMessage);
}

void Heavy_Panoramizer::cMsg_8C71tXJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GHorA6w1_sendMessage);
}

void Heavy_Panoramizer::cMsg_yxKmmCY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_6bXy5SvP_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pA5d4SXT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TndXOlKD, m);
}

void Heavy_Panoramizer::cBinop_4L4geIWA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_sUJGH7O5, 1, m, &cIf_sUJGH7O5_sendMessage);
}

void Heavy_Panoramizer::cIf_sUJGH7O5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_yxKmmCY9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_6bXy5SvP_sendMessage);
      cMsg_GkiD73uL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_nEcqoGHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B4hwhhvt_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_tsgeDpZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kjcgFWTw, m);
}

void Heavy_Panoramizer::cBinop_PLnjKVnx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g6SfZQGC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JacoGvNR_sendMessage);
}

void Heavy_Panoramizer::cRandom_wILdCJaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3OoWfQLc, HV_BINOP_MULTIPLY, 0, m, &cBinop_3OoWfQLc_sendMessage);
}

void Heavy_Panoramizer::cUnop_hkOjxhw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I2Cst5QV, HV_BINOP_ADD, 0, m, &cBinop_I2Cst5QV_sendMessage);
}

void Heavy_Panoramizer::cBinop_3OoWfQLc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hkOjxhw4_sendMessage);
}

void Heavy_Panoramizer::cSlice_N1x3Iji9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wILdCJaD, 1, m, &cRandom_wILdCJaD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_2z9zRHqt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_N1x3Iji9, 0, m, &cSlice_N1x3Iji9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wILdCJaD, 0, m, &cRandom_wILdCJaD_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_YY41R8Sr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_SOuaIdcL, 1, m, &cPack_SOuaIdcL_sendMessage);
}

void Heavy_Panoramizer::cCast_Kr8dOuBd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qerMrikz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cUnop_cFsWufUb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0dlKewJy, HV_BINOP_ADD, 0, m, &cBinop_0dlKewJy_sendMessage);
}

void Heavy_Panoramizer::cBinop_UxgnROXQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_cFsWufUb_sendMessage);
}

void Heavy_Panoramizer::cSlice_P2L6qI5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_di5vk2Zt, 1, m, &cRandom_di5vk2Zt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_hKJMKjs1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_P2L6qI5n, 0, m, &cSlice_P2L6qI5n_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_di5vk2Zt, 0, m, &cRandom_di5vk2Zt_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_di5vk2Zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UxgnROXQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_UxgnROXQ_sendMessage);
}

void Heavy_Panoramizer::cCast_5jkpqkEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WHQVrgc5, HV_BINOP_SUBTRACT, 1, m, &cBinop_WHQVrgc5_sendMessage);
}

void Heavy_Panoramizer::cUnop_0FA5aD69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t8i9MwWv, 0, m, &cVar_t8i9MwWv_sendMessage);
}

void Heavy_Panoramizer::cBinop_qLqvbHzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0FA5aD69_sendMessage);
}

void Heavy_Panoramizer::cRandom_C0TkFIHi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_qLqvbHzU_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Wz6W8eFP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Bsr4sObD, 0, m, &cSlice_Bsr4sObD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C0TkFIHi, 0, m, &cRandom_C0TkFIHi_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_Bsr4sObD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C0TkFIHi, 1, m, &cRandom_C0TkFIHi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_tow2l6e1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9SxtevoJ_sendMessage);
}

void Heavy_Panoramizer::cSlice_D7IXq6HN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qohdRP5P, 1, m, &cRandom_qohdRP5P_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_SOBKfTWT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_D7IXq6HN, 0, m, &cSlice_D7IXq6HN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qohdRP5P, 0, m, &cRandom_qohdRP5P_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_qohdRP5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_tow2l6e1_sendMessage);
}

void Heavy_Panoramizer::cUnop_9SxtevoJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3QIz6LKN, 0, m, &cVar_3QIz6LKN_sendMessage);
}

void Heavy_Panoramizer::cBinop_5ol0oTBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3smKgX7A, HV_BINOP_MULTIPLY, 1, m, &cBinop_3smKgX7A_sendMessage);
}

void Heavy_Panoramizer::cCast_FrHV5h6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5ol0oTBW, HV_BINOP_SUBTRACT, 1, m, &cBinop_5ol0oTBW_sendMessage);
}

void Heavy_Panoramizer::cCast_nviPuVOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OPZjHZgh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_fQPlW7jq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_arM3L7wm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_f0YzQCDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WdujqZ8v, 2, m, &cDelay_WdujqZ8v_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_BY5D6636_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_Mk32tUgg_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Mk32tUgg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cBuhwt31_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_cBuhwt31_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Mk32tUgg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WdujqZ8v, 0, m, &cDelay_WdujqZ8v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kr8dOuBd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zmrGhfjt_sendMessage);
}

void Heavy_Panoramizer::cBinop_JvCuTRYh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_f0YzQCDr_sendMessage);
}

void Heavy_Panoramizer::cMsg_Mk32tUgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WdujqZ8v, 0, m, &cDelay_WdujqZ8v_sendMessage);
}

void Heavy_Panoramizer::cVar_fRddS6aP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JvCuTRYh, HV_BINOP_MULTIPLY, 0, m, &cBinop_JvCuTRYh_sendMessage);
}

void Heavy_Panoramizer::cDelay_WdujqZ8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WdujqZ8v, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WdujqZ8v, 0, m, &cDelay_WdujqZ8v_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Kr8dOuBd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zmrGhfjt_sendMessage);
}

void Heavy_Panoramizer::cBinop_j6zLzwFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JvCuTRYh, HV_BINOP_MULTIPLY, 1, m, &cBinop_JvCuTRYh_sendMessage);
}

void Heavy_Panoramizer::cSystem_gZ621DAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_j6zLzwFu_sendMessage);
}

void Heavy_Panoramizer::cMsg_1Nvoe4DI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gZ621DAE_sendMessage);
}

void Heavy_Panoramizer::cUnop_0UdoMDo8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8yGGlh9B, HV_BINOP_ADD, 0, m, &cBinop_8yGGlh9B_sendMessage);
}

void Heavy_Panoramizer::cSlice_vU2DZ5vC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ijtw164q, 1, m, &cRandom_ijtw164q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_RACBQ2XD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vU2DZ5vC, 0, m, &cSlice_vU2DZ5vC_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ijtw164q, 0, m, &cRandom_ijtw164q_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_JBZW2Z7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0UdoMDo8_sendMessage);
}

void Heavy_Panoramizer::cRandom_ijtw164q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JBZW2Z7Z, HV_BINOP_MULTIPLY, 0, m, &cBinop_JBZW2Z7Z_sendMessage);
}

void Heavy_Panoramizer::cSlice_AIiAYNqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5uppe6ap, 1, m, &cRandom_5uppe6ap_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_iwB9aMmE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AIiAYNqM, 0, m, &cSlice_AIiAYNqM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5uppe6ap, 0, m, &cRandom_5uppe6ap_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_Ie40iPof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Gur79Q6G_sendMessage);
}

void Heavy_Panoramizer::cRandom_5uppe6ap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_Ie40iPof_sendMessage);
}

void Heavy_Panoramizer::cUnop_Gur79Q6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HPHV9kAx, HV_BINOP_MULTIPLY, 0, m, &cBinop_HPHV9kAx_sendMessage);
}

void Heavy_Panoramizer::cBinop_epFixMSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3OGJWJFF_sendMessage);
}

void Heavy_Panoramizer::cUnop_3OGJWJFF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DATbBqaY, HV_BINOP_MULTIPLY, 0, m, &cBinop_DATbBqaY_sendMessage);
}

void Heavy_Panoramizer::cSlice_3LVHPzGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rS6QuLTU, 1, m, &cRandom_rS6QuLTU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_rS6QuLTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_epFixMSn_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_NLyL2Mig_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3LVHPzGM, 0, m, &cSlice_3LVHPzGM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rS6QuLTU, 0, m, &cRandom_rS6QuLTU_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_EGV34PeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tZplaFOH_sendMessage);
}

void Heavy_Panoramizer::cSlice_0wvJdhVq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TiPYYwmY, 1, m, &cRandom_TiPYYwmY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_FxxoIsNT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0wvJdhVq, 0, m, &cSlice_0wvJdhVq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TiPYYwmY, 0, m, &cRandom_TiPYYwmY_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_tZplaFOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_B6FSUic1, 0, m, &cVar_B6FSUic1_sendMessage);
}

void Heavy_Panoramizer::cRandom_TiPYYwmY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_EGV34PeK_sendMessage);
}

void Heavy_Panoramizer::cCast_0TsBeQZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NGYkLji0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_rmecuPeh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_VZ4Vbe6z, 1, m, &cPack_VZ4Vbe6z_sendMessage);
}

void Heavy_Panoramizer::cBinop_T0yWIMsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3OoWfQLc, HV_BINOP_MULTIPLY, 1, m, &cBinop_3OoWfQLc_sendMessage);
}

void Heavy_Panoramizer::cBinop_gHos0r4b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_6Zvzdypd_sendMessage);
}

void Heavy_Panoramizer::cVar_B2JxT1Ml_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHos0r4b, HV_BINOP_MULTIPLY, 0, m, &cBinop_gHos0r4b_sendMessage);
}

void Heavy_Panoramizer::cSystem_v4dwKsb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RZO5rZJh_sendMessage);
}

void Heavy_Panoramizer::cMsg_J4u8tGGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_v4dwKsb6_sendMessage);
}

void Heavy_Panoramizer::cMsg_plIjVYhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sKnsqGEA, 0, m, &cDelay_sKnsqGEA_sendMessage);
}

void Heavy_Panoramizer::cBinop_6Zvzdypd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sKnsqGEA, 2, m, &cDelay_sKnsqGEA_sendMessage);
}

void Heavy_Panoramizer::cBinop_RZO5rZJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHos0r4b, HV_BINOP_MULTIPLY, 1, m, &cBinop_gHos0r4b_sendMessage);
}

void Heavy_Panoramizer::cDelay_sKnsqGEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sKnsqGEA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sKnsqGEA, 0, m, &cDelay_sKnsqGEA_sendMessage);
  cSwitchcase_PR8bb7hG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_HskvbRWo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_plIjVYhK_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_plIjVYhK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8Soie6eF_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_8Soie6eF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_plIjVYhK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sKnsqGEA, 0, m, &cDelay_sKnsqGEA_sendMessage);
  cSwitchcase_PR8bb7hG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_JacoGvNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tuDq9GJD_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cUnop_qcxQgoL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmecuPeh, HV_BINOP_MULTIPLY, 0, m, &cBinop_rmecuPeh_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_fmOhKYIw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_da8Focxb, 0, m, &cSlice_da8Focxb_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_q4D1VO6Z, 0, m, &cRandom_q4D1VO6Z_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_da8Focxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_q4D1VO6Z, 1, m, &cRandom_q4D1VO6Z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_q4D1VO6Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_iG1eJthG_sendMessage);
}

void Heavy_Panoramizer::cBinop_iG1eJthG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_qcxQgoL8_sendMessage);
}

void Heavy_Panoramizer::cCast_c8usBebJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oHHjv2gk_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_3smKgX7A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LV3HP6Pe_sendMessage);
}

void Heavy_Panoramizer::cUnop_LV3HP6Pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L03k4Str, HV_BINOP_ADD, 0, m, &cBinop_L03k4Str_sendMessage);
}

void Heavy_Panoramizer::cSlice_STP9tAAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jLhQqqxF, 1, m, &cRandom_jLhQqqxF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_Uuodf4Ni_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_STP9tAAw, 0, m, &cSlice_STP9tAAw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jLhQqqxF, 0, m, &cRandom_jLhQqqxF_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_jLhQqqxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3smKgX7A, HV_BINOP_MULTIPLY, 0, m, &cBinop_3smKgX7A_sendMessage);
}

void Heavy_Panoramizer::cBinop_ngxOPElX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBtL4bWS, HV_BINOP_MULTIPLY, 1, m, &cBinop_jBtL4bWS_sendMessage);
}

void Heavy_Panoramizer::cMsg_xFvBoavl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5ol0oTBW, HV_BINOP_SUBTRACT, 0, m, &cBinop_5ol0oTBW_sendMessage);
}

void Heavy_Panoramizer::cBinop_ttnVjm2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AuF9FAqv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pqpJ1VVk_sendMessage);
}

void Heavy_Panoramizer::cRandom_uqT0Bx1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_TzhuuE1J_sendMessage);
}

void Heavy_Panoramizer::cUnop_xehDQ1AA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6VecmVOr, HV_BINOP_MULTIPLY, 0, m, &cBinop_6VecmVOr_sendMessage);
}

void Heavy_Panoramizer::cSlice_qob4azKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uqT0Bx1s, 1, m, &cRandom_uqT0Bx1s_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_TzhuuE1J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xehDQ1AA_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_GvuUieG4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qob4azKm, 0, m, &cSlice_qob4azKm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uqT0Bx1s, 0, m, &cRandom_uqT0Bx1s_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_WSSMSVub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3kYTNAjx_sendMessage);
}

void Heavy_Panoramizer::cSystem_3kYTNAjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TYt6i4o4_sendMessage);
}

void Heavy_Panoramizer::cBinop_34dBe6RY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_azm9aBeZ_sendMessage);
}

void Heavy_Panoramizer::cDelay_bY2d9KZ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bY2d9KZ4, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bY2d9KZ4, 0, m, &cDelay_bY2d9KZ4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TO8r8Mrx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LEhvUC0L_sendMessage);
}

void Heavy_Panoramizer::cBinop_azm9aBeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bY2d9KZ4, 2, m, &cDelay_bY2d9KZ4_sendMessage);
}

void Heavy_Panoramizer::cCast_jagDbKWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HgtV8zfe_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bY2d9KZ4, 0, m, &cDelay_bY2d9KZ4_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TO8r8Mrx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LEhvUC0L_sendMessage);
}

void Heavy_Panoramizer::cBinop_TYt6i4o4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_34dBe6RY, HV_BINOP_MULTIPLY, 1, m, &cBinop_34dBe6RY_sendMessage);
}

void Heavy_Panoramizer::cMsg_HgtV8zfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bY2d9KZ4, 0, m, &cDelay_bY2d9KZ4_sendMessage);
}

void Heavy_Panoramizer::cVar_uQ7KsflP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_34dBe6RY, HV_BINOP_MULTIPLY, 0, m, &cBinop_34dBe6RY_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_I9LF0MX5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_HgtV8zfe_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HgtV8zfe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jagDbKWi_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_AvGy5yer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PPLuPCJU, 0, m, &cVar_PPLuPCJU_sendMessage);
}

void Heavy_Panoramizer::cBinop_vZ1EboQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AvGy5yer_sendMessage);
}

void Heavy_Panoramizer::cRandom_zoFF6Bh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_vZ1EboQs_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_9hvaLHoP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7mKQokqs, 0, m, &cSlice_7mKQokqs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zoFF6Bh7, 0, m, &cRandom_zoFF6Bh7_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_7mKQokqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zoFF6Bh7, 1, m, &cRandom_zoFF6Bh7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_HmczneGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_I3DMJXPB_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_qerMrikz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7PZqJn12, 0, m, &cSlice_7PZqJn12_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HmczneGH, 0, m, &cRandom_HmczneGH_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_I3DMJXPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_x7jbqlM4_sendMessage);
}

void Heavy_Panoramizer::cUnop_x7jbqlM4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4ibIl6qy, HV_BINOP_MULTIPLY, 0, m, &cBinop_4ibIl6qy_sendMessage);
}

void Heavy_Panoramizer::cSlice_7PZqJn12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_HmczneGH, 1, m, &cRandom_HmczneGH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_krWPwuUK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_e2jXOQhO, 0, m, &cSlice_e2jXOQhO_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jb7Zvpds, 0, m, &cRandom_jb7Zvpds_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_e2jXOQhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jb7Zvpds, 1, m, &cRandom_jb7Zvpds_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_jb7Zvpds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_zhCaTEJv_sendMessage);
}

void Heavy_Panoramizer::cBinop_zhCaTEJv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_oguVsZm9_sendMessage);
}

void Heavy_Panoramizer::cUnop_oguVsZm9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NDgelykv, HV_BINOP_MULTIPLY, 0, m, &cBinop_NDgelykv_sendMessage);
}

void Heavy_Panoramizer::cPack_qE8tcMdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6IpjrVLG, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_gOfYXc2I_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YeKC8aju, 0, m, &cSlice_YeKC8aju_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mDH1jwGX, 0, m, &cRandom_mDH1jwGX_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_E9mDtv5I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nCymV5n6_sendMessage);
}

void Heavy_Panoramizer::cSlice_YeKC8aju_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_mDH1jwGX, 1, m, &cRandom_mDH1jwGX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_nCymV5n6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fRddS6aP, 0, m, &cVar_fRddS6aP_sendMessage);
}

void Heavy_Panoramizer::cRandom_mDH1jwGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_E9mDtv5I_sendMessage);
}

void Heavy_Panoramizer::cCast_shSutUup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RACBQ2XD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_YjY9KO9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5jkpqkEP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Wthxd2lO_sendMessage);
}

void Heavy_Panoramizer::cSlice_qvK2IP6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wVD1LshN, 1, m, &cRandom_wVD1LshN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_EIVPQeV2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qvK2IP6I, 0, m, &cSlice_qvK2IP6I_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wVD1LshN, 0, m, &cRandom_wVD1LshN_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_TKOzz30N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6Jzy3Gwn_sendMessage);
}

void Heavy_Panoramizer::cUnop_6Jzy3Gwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_frKFCl06, 0, m, &cVar_frKFCl06_sendMessage);
}

void Heavy_Panoramizer::cRandom_wVD1LshN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_TKOzz30N_sendMessage);
}

void Heavy_Panoramizer::cCast_XVRfCiHI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EuPCbvFZ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_f8LEKesA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_j2Utk1De, 0, m, &cDelay_j2Utk1De_sendMessage);
}

void Heavy_Panoramizer::cMsg_WZpTduSG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_bHnaZkem_sendMessage);
}

void Heavy_Panoramizer::cSystem_bHnaZkem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_zTXEITbf_sendMessage);
}

void Heavy_Panoramizer::cVar_OXINzLAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W5PA71uj, HV_BINOP_MULTIPLY, 0, m, &cBinop_W5PA71uj_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_VlraTLCX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_f8LEKesA_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_f8LEKesA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vFxbLHZe_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cDelay_j2Utk1De_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_j2Utk1De, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_j2Utk1De, 0, m, &cDelay_j2Utk1De_sendMessage);
  cSwitchcase_FxxoIsNT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_zTXEITbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W5PA71uj, HV_BINOP_MULTIPLY, 1, m, &cBinop_W5PA71uj_sendMessage);
}

void Heavy_Panoramizer::cBinop_CjWJHX3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_j2Utk1De, 2, m, &cDelay_j2Utk1De_sendMessage);
}

void Heavy_Panoramizer::cBinop_W5PA71uj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_CjWJHX3S_sendMessage);
}

void Heavy_Panoramizer::cCast_vFxbLHZe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f8LEKesA_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_j2Utk1De, 0, m, &cDelay_j2Utk1De_sendMessage);
  cSwitchcase_FxxoIsNT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_WHQVrgc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BXIWhcdC, HV_BINOP_MULTIPLY, 1, m, &cBinop_BXIWhcdC_sendMessage);
}

void Heavy_Panoramizer::cMsg_tuDq9GJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aPlxu1RT, HV_BINOP_SUBTRACT, 0, m, &cBinop_aPlxu1RT_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_LpN8lKEG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_3Ngz81ur_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_3Ngz81ur_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kcDn6vC1_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_bQ0BxPrl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_i0UyAmnb_sendMessage);
}

void Heavy_Panoramizer::cBinop_ZMcDlq0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQ0BxPrl, HV_BINOP_MULTIPLY, 1, m, &cBinop_bQ0BxPrl_sendMessage);
}

void Heavy_Panoramizer::cBinop_i0UyAmnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WF39Yf3E, 2, m, &cDelay_WF39Yf3E_sendMessage);
}

void Heavy_Panoramizer::cVar_lUQxK12K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bQ0BxPrl, HV_BINOP_MULTIPLY, 0, m, &cBinop_bQ0BxPrl_sendMessage);
}

void Heavy_Panoramizer::cDelay_WF39Yf3E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WF39Yf3E, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WF39Yf3E, 0, m, &cDelay_WF39Yf3E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UCy1KD5K_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SJUEFl0A_sendMessage);
}

void Heavy_Panoramizer::cSystem_j0Ctw4Kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZMcDlq0w_sendMessage);
}

void Heavy_Panoramizer::cMsg_6WRoQRNj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_j0Ctw4Kl_sendMessage);
}

void Heavy_Panoramizer::cMsg_3Ngz81ur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_WF39Yf3E, 0, m, &cDelay_WF39Yf3E_sendMessage);
}

void Heavy_Panoramizer::cCast_kcDn6vC1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3Ngz81ur_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WF39Yf3E, 0, m, &cDelay_WF39Yf3E_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UCy1KD5K_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SJUEFl0A_sendMessage);
}

void Heavy_Panoramizer::cMsg_oHHjv2gk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sCiRCSuX, HV_BINOP_SUBTRACT, 0, m, &cBinop_sCiRCSuX_sendMessage);
}

void Heavy_Panoramizer::cBinop_0dlKewJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pwmPsK8A, 0, m, &cPack_pwmPsK8A_sendMessage);
}

void Heavy_Panoramizer::cCast_997sNCip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZLEmGOWB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_EwrT08X0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a1MQHw8q, HV_BINOP_SUBTRACT, 0, m, &cBinop_a1MQHw8q_sendMessage);
}

void Heavy_Panoramizer::cPack_84oBoStL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_BGOwlXRv, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_8yGGlh9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_TVWxQJAX, 0, m, &cPack_TVWxQJAX_sendMessage);
}

void Heavy_Panoramizer::cCast_gh3y8bz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dyVhkAgl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_LEhvUC0L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hKJMKjs1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cDelay_tpVxd9gd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tpVxd9gd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tpVxd9gd, 0, m, &cDelay_tpVxd9gd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fQPlW7jq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gh3y8bz9_sendMessage);
}

void Heavy_Panoramizer::cSystem_E6GpNxOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QSiskCHS_sendMessage);
}

void Heavy_Panoramizer::cMsg_17dGTwHZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E6GpNxOq_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_orbLzIen_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_eR0wKc1l_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_eR0wKc1l_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pNx5IUWm_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_QSiskCHS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQy3g7lz, HV_BINOP_MULTIPLY, 1, m, &cBinop_eQy3g7lz_sendMessage);
}

void Heavy_Panoramizer::cBinop_eQy3g7lz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_1bVCXrmX_sendMessage);
}

void Heavy_Panoramizer::cBinop_1bVCXrmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tpVxd9gd, 2, m, &cDelay_tpVxd9gd_sendMessage);
}

void Heavy_Panoramizer::cCast_pNx5IUWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eR0wKc1l_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tpVxd9gd, 0, m, &cDelay_tpVxd9gd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fQPlW7jq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gh3y8bz9_sendMessage);
}

void Heavy_Panoramizer::cMsg_eR0wKc1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tpVxd9gd, 0, m, &cDelay_tpVxd9gd_sendMessage);
}

void Heavy_Panoramizer::cVar_3QIz6LKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eQy3g7lz, HV_BINOP_MULTIPLY, 0, m, &cBinop_eQy3g7lz_sendMessage);
}

void Heavy_Panoramizer::cBinop_uf550Vv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xrhYCaT6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_c8usBebJ_sendMessage);
}

void Heavy_Panoramizer::cMsg_CYYcaPjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_NBo1cCkI, 0, m, &cVar_NBo1cCkI_sendMessage);
}

void Heavy_Panoramizer::cMsg_TGyIgXyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ncXHOsBv, 0, m, &cVar_ncXHOsBv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_UDi64SKR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Vak1o6Ar, 0, m, &cSlice_Vak1o6Ar_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4jJ4jzOx, 0, m, &cRandom_4jJ4jzOx_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_WYe2ajYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_edWIjOP6_sendMessage);
}

void Heavy_Panoramizer::cRandom_4jJ4jzOx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WYe2ajYZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_WYe2ajYZ_sendMessage);
}

void Heavy_Panoramizer::cUnop_edWIjOP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lVvm4Bfp, HV_BINOP_ADD, 0, m, &cBinop_lVvm4Bfp_sendMessage);
}

void Heavy_Panoramizer::cSlice_Vak1o6Ar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4jJ4jzOx, 1, m, &cRandom_4jJ4jzOx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_fjcATWsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fpzG3h0q, m);
}

void Heavy_Panoramizer::cMsg_O5tjfoaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lIkV1eG7_sendMessage);
}

void Heavy_Panoramizer::cSystem_i5YNOFZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kchXwaxb_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_Tf9teDvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_i5YNOFZZ_sendMessage);
}

void Heavy_Panoramizer::cMsg_bOlXczd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DO7elm4Y_sendMessage);
}

void Heavy_Panoramizer::cIf_qxLj5ypj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ZSE0ACnJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_FXWUuu8b_sendMessage);
      cMsg_bOlXczd0_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_zDolM2GS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qxLj5ypj, 1, m, &cIf_qxLj5ypj_sendMessage);
}

void Heavy_Panoramizer::cMsg_ZSE0ACnJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_FXWUuu8b_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1FMmiAdi, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ecKAvRmN, m);
}

void Heavy_Panoramizer::cMsg_9MsRm7Ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_IGaTC9LP_sendMessage);
}

void Heavy_Panoramizer::cVar_y41LITa6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_zDolM2GS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qxLj5ypj, 0, m, &cIf_qxLj5ypj_sendMessage);
}

void Heavy_Panoramizer::cBinop_lIkV1eG7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9MsRm7Ht_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_DO7elm4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1FMmiAdi, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ecKAvRmN, m);
}

void Heavy_Panoramizer::cMsg_kchXwaxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_fjcATWsP_sendMessage);
}

void Heavy_Panoramizer::cBinop_FXWUuu8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_O5tjfoaW_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_IGaTC9LP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IWBimtcf, m);
}

void Heavy_Panoramizer::cCast_TO8r8Mrx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_iwB9aMmE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_SJUEFl0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_UDi64SKR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_V7UOuM5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DWBFMdnH, HV_BINOP_SUBTRACT, 0, m, &cBinop_DWBFMdnH_sendMessage);
}

void Heavy_Panoramizer::cBinop_a1MQHw8q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSZgQTvN, HV_BINOP_MULTIPLY, 1, m, &cBinop_BSZgQTvN_sendMessage);
}

void Heavy_Panoramizer::cPack_pwmPsK8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_o0gZgzLz, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_xrhYCaT6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sCiRCSuX, HV_BINOP_SUBTRACT, 1, m, &cBinop_sCiRCSuX_sendMessage);
}

void Heavy_Panoramizer::cUnop_etEG8fSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yx1vvfwy, 0, m, &cVar_yx1vvfwy_sendMessage);
}

void Heavy_Panoramizer::cRandom_dUHWd6kN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_4jGLmLwt_sendMessage);
}

void Heavy_Panoramizer::cBinop_4jGLmLwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_etEG8fSE_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_67vSRMxE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MsocogV3, 0, m, &cSlice_MsocogV3_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dUHWd6kN, 0, m, &cRandom_dUHWd6kN_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_MsocogV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dUHWd6kN, 1, m, &cRandom_dUHWd6kN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_NDgelykv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_84oBoStL, 1, m, &cPack_84oBoStL_sendMessage);
}

void Heavy_Panoramizer::cMsg_lnlQETjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T0yWIMsZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_T0yWIMsZ_sendMessage);
}

void Heavy_Panoramizer::cBinop_DWBFMdnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JBZW2Z7Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_JBZW2Z7Z_sendMessage);
}

void Heavy_Panoramizer::cBinop_4ibIl6qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BgNhb75u, 1, m, &cPack_BgNhb75u_sendMessage);
}

void Heavy_Panoramizer::cBinop_KlLDFq0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9MaIiX1F_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sXDidnYo_sendMessage);
}

void Heavy_Panoramizer::cCast_zG45VNhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_exNt5qP6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYWVh1H5, 0, m, &cDelay_fYWVh1H5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K6ohd5bZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u3UTDCdL_sendMessage);
}

void Heavy_Panoramizer::cDelay_fYWVh1H5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_fYWVh1H5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYWVh1H5, 0, m, &cDelay_fYWVh1H5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K6ohd5bZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u3UTDCdL_sendMessage);
}

void Heavy_Panoramizer::cBinop_hc58jTNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_pL2z4wEr_sendMessage);
}

void Heavy_Panoramizer::cVar_2AZHogX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hc58jTNf, HV_BINOP_MULTIPLY, 0, m, &cBinop_hc58jTNf_sendMessage);
}

void Heavy_Panoramizer::cBinop_pL2z4wEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYWVh1H5, 2, m, &cDelay_fYWVh1H5_sendMessage);
}

void Heavy_Panoramizer::cBinop_YWVXoyeB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hc58jTNf, HV_BINOP_MULTIPLY, 1, m, &cBinop_hc58jTNf_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_S1dIBOFN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_exNt5qP6_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_exNt5qP6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zG45VNhH_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_Z9FOAIuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xxDUsROf_sendMessage);
}

void Heavy_Panoramizer::cSystem_xxDUsROf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_YWVXoyeB_sendMessage);
}

void Heavy_Panoramizer::cMsg_exNt5qP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_fYWVh1H5, 0, m, &cDelay_fYWVh1H5_sendMessage);
}

void Heavy_Panoramizer::cMsg_yxZ69gyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHfcoYqo, 0, m, &cDelay_HHfcoYqo_sendMessage);
}

void Heavy_Panoramizer::cDelay_HHfcoYqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HHfcoYqo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHfcoYqo, 0, m, &cDelay_HHfcoYqo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nviPuVOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MlAvvLWi_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_fAu4nFqk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_yxZ69gyc_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_yxZ69gyc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4MsCiT4k_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_EGyEzwMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kITlxK8u_sendMessage);
}

void Heavy_Panoramizer::cCast_4MsCiT4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yxZ69gyc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHfcoYqo, 0, m, &cDelay_HHfcoYqo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nviPuVOd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MlAvvLWi_sendMessage);
}

void Heavy_Panoramizer::cBinop_kITlxK8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HHfcoYqo, 2, m, &cDelay_HHfcoYqo_sendMessage);
}

void Heavy_Panoramizer::cSystem_Ii4DnFmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Cy9zmFgU_sendMessage);
}

void Heavy_Panoramizer::cMsg_D3R8UDAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ii4DnFmJ_sendMessage);
}

void Heavy_Panoramizer::cVar_frKFCl06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EGyEzwMU, HV_BINOP_MULTIPLY, 0, m, &cBinop_EGyEzwMU_sendMessage);
}

void Heavy_Panoramizer::cBinop_Cy9zmFgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EGyEzwMU, HV_BINOP_MULTIPLY, 1, m, &cBinop_EGyEzwMU_sendMessage);
}

void Heavy_Panoramizer::cBinop_thACoG9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qE8tcMdh, 0, m, &cPack_qE8tcMdh_sendMessage);
}

void Heavy_Panoramizer::cDelay_sekSb42a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sekSb42a, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sekSb42a, 0, m, &cDelay_sekSb42a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s9iqJ0Fa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_997sNCip_sendMessage);
}

void Heavy_Panoramizer::cBinop_apuhzw2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sekSb42a, 2, m, &cDelay_sekSb42a_sendMessage);
}

void Heavy_Panoramizer::cBinop_VRheUX2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_114xhnGv, HV_BINOP_MULTIPLY, 1, m, &cBinop_114xhnGv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_DgRQ0uXw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_K3pjYl0w_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_K3pjYl0w_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WTkMOkh9_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_114xhnGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_apuhzw2P_sendMessage);
}

void Heavy_Panoramizer::cMsg_K3pjYl0w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sekSb42a, 0, m, &cDelay_sekSb42a_sendMessage);
}

void Heavy_Panoramizer::cCast_WTkMOkh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_K3pjYl0w_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sekSb42a, 0, m, &cDelay_sekSb42a_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s9iqJ0Fa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_997sNCip_sendMessage);
}

void Heavy_Panoramizer::cSystem_NFaHtplD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_VRheUX2h_sendMessage);
}

void Heavy_Panoramizer::cMsg_QwBNSkop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NFaHtplD_sendMessage);
}

void Heavy_Panoramizer::cVar_yx1vvfwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_114xhnGv, HV_BINOP_MULTIPLY, 0, m, &cBinop_114xhnGv_sendMessage);
}

void Heavy_Panoramizer::cCast_pqpJ1VVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EwrT08X0_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_1weU58OV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gk3WBttQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1dzOEoz9_sendMessage);
}

void Heavy_Panoramizer::cRandom_JOquYozD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_RBuMm8XH_sendMessage);
}

void Heavy_Panoramizer::cSlice_uARTRu70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JOquYozD, 1, m, &cRandom_JOquYozD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_DakudEMB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_uARTRu70, 0, m, &cSlice_uARTRu70_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JOquYozD, 0, m, &cRandom_JOquYozD_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_TEYJ6YFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_39lz6YKo, HV_BINOP_MULTIPLY, 0, m, &cBinop_39lz6YKo_sendMessage);
}

void Heavy_Panoramizer::cBinop_RBuMm8XH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TEYJ6YFH_sendMessage);
}

void Heavy_Panoramizer::cMsg_yegkUiR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_JyRaJPgr_sendMessage);
}

void Heavy_Panoramizer::cMsg_SRhJUqTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MFn1XChK_sendMessage);
}

void Heavy_Panoramizer::cBinop_MFn1XChK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yegkUiR6_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_drWfZZQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jJNebV4f_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VtKcETzo, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_a45I1UQC, m);
}

void Heavy_Panoramizer::cMsg_Yxas36Ha_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_y6aJizTc_sendMessage);
}

void Heavy_Panoramizer::cSystem_y6aJizTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KwO3tXdj_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_3bNHpLkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_hhbb8mh9_sendMessage);
}

void Heavy_Panoramizer::cBinop_xkug08rX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6gSnK3a4, m);
}

void Heavy_Panoramizer::cBinop_jJNebV4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SRhJUqTo_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_hhbb8mh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VtKcETzo, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_a45I1UQC, m);
}

void Heavy_Panoramizer::cVar_QmihQWOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_iHlLF38x_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hWHTgEMO, 0, m, &cIf_hWHTgEMO_sendMessage);
}

void Heavy_Panoramizer::cBinop_JyRaJPgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vAT1Sc6s, m);
}

void Heavy_Panoramizer::cMsg_KwO3tXdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xkug08rX_sendMessage);
}

void Heavy_Panoramizer::cIf_hWHTgEMO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_drWfZZQD_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jJNebV4f_sendMessage);
      cMsg_3bNHpLkF_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_iHlLF38x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hWHTgEMO, 1, m, &cIf_hWHTgEMO_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_OPZjHZgh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bPsOOox8, 0, m, &cSlice_bPsOOox8_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z5P6JA65, 0, m, &cRandom_z5P6JA65_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_Q5OcIsGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNJinA05, HV_BINOP_MULTIPLY, 0, m, &cBinop_BNJinA05_sendMessage);
}

void Heavy_Panoramizer::cBinop_wJzryLgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Q5OcIsGB_sendMessage);
}

void Heavy_Panoramizer::cSlice_bPsOOox8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_z5P6JA65, 1, m, &cRandom_z5P6JA65_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_z5P6JA65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_wJzryLgs_sendMessage);
}

void Heavy_Panoramizer::cBinop_HPHV9kAx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pwmPsK8A, 1, m, &cPack_pwmPsK8A_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_brZHgS8k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_tNCBmBkX, 0, m, &cSlice_tNCBmBkX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Xzipk2Eu, 0, m, &cRandom_Xzipk2Eu_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_Xzipk2Eu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_cxS7UFu9_sendMessage);
}

void Heavy_Panoramizer::cSlice_tNCBmBkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Xzipk2Eu, 1, m, &cRandom_Xzipk2Eu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_cxS7UFu9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pxumVJv5_sendMessage);
}

void Heavy_Panoramizer::cUnop_pxumVJv5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lUQxK12K, 0, m, &cVar_lUQxK12K_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_ZLEmGOWB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YCICLslS, 0, m, &cSlice_YCICLslS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C89777LO, 0, m, &cRandom_C89777LO_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_rwaFJ6zJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kf3lpcIY, HV_BINOP_ADD, 0, m, &cBinop_kf3lpcIY_sendMessage);
}

void Heavy_Panoramizer::cBinop_BXIWhcdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rwaFJ6zJ_sendMessage);
}

void Heavy_Panoramizer::cSlice_YCICLslS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_C89777LO, 1, m, &cRandom_C89777LO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_C89777LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BXIWhcdC, HV_BINOP_MULTIPLY, 0, m, &cBinop_BXIWhcdC_sendMessage);
}

void Heavy_Panoramizer::cBinop_BNJinA05_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_q0b2lD0f, 1, m, &cPack_q0b2lD0f_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_4jY8ftHz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_BNaWJIwg_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_BNaWJIwg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g4nW5ucY_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_BNaWJIwg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDeNJ6qF, 0, m, &cDelay_cDeNJ6qF_sendMessage);
}

void Heavy_Panoramizer::cBinop_kF44AayX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_o3v1LNq0_sendMessage);
}

void Heavy_Panoramizer::cBinop_fcejh3oW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kF44AayX, HV_BINOP_MULTIPLY, 1, m, &cBinop_kF44AayX_sendMessage);
}

void Heavy_Panoramizer::cCast_g4nW5ucY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BNaWJIwg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDeNJ6qF, 0, m, &cDelay_cDeNJ6qF_sendMessage);
  cSwitchcase_9hvaLHoP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSystem_m3vMNBgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fcejh3oW_sendMessage);
}

void Heavy_Panoramizer::cMsg_tNBLoLgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_m3vMNBgT_sendMessage);
}

void Heavy_Panoramizer::cDelay_cDeNJ6qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cDeNJ6qF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDeNJ6qF, 0, m, &cDelay_cDeNJ6qF_sendMessage);
  cSwitchcase_9hvaLHoP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_o3v1LNq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cDeNJ6qF, 2, m, &cDelay_cDeNJ6qF_sendMessage);
}

void Heavy_Panoramizer::cVar_4uPYedz8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kF44AayX, HV_BINOP_MULTIPLY, 0, m, &cBinop_kF44AayX_sendMessage);
}

void Heavy_Panoramizer::cPack_HGjeKzLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fH1Ocu9h, 0, m, NULL);
}

void Heavy_Panoramizer::cPack_SOuaIdcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LQy9vOAf, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_eSTXImyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nShzcxQq, 2, m, &cDelay_nShzcxQq_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_6PZQamoA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_PidD1hNU_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_PidD1hNU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vG7tQnp1_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_B6FSUic1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7OssKohg, HV_BINOP_MULTIPLY, 0, m, &cBinop_7OssKohg_sendMessage);
}

void Heavy_Panoramizer::cBinop_7OssKohg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_eSTXImyS_sendMessage);
}

void Heavy_Panoramizer::cCast_vG7tQnp1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PidD1hNU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nShzcxQq, 0, m, &cDelay_nShzcxQq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0TsBeQZd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_shSutUup_sendMessage);
}

void Heavy_Panoramizer::cSystem_9rNKampo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gx47fvoW_sendMessage);
}

void Heavy_Panoramizer::cMsg_HIBpbT3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9rNKampo_sendMessage);
}

void Heavy_Panoramizer::cDelay_nShzcxQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nShzcxQq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nShzcxQq, 0, m, &cDelay_nShzcxQq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0TsBeQZd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_shSutUup_sendMessage);
}

void Heavy_Panoramizer::cBinop_gx47fvoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7OssKohg, HV_BINOP_MULTIPLY, 1, m, &cBinop_7OssKohg_sendMessage);
}

void Heavy_Panoramizer::cMsg_PidD1hNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nShzcxQq, 0, m, &cDelay_nShzcxQq_sendMessage);
}

void Heavy_Panoramizer::cCast_WR7dCZuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F3yTcxQZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_F3yTcxQZ_sendMessage);
}

void Heavy_Panoramizer::cPack_R5e3gV2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_OBW7HPwg, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_UCy1KD5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NLyL2Mig_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_Vumvn3H7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ow0bPaLg, 0, m, &cVar_ow0bPaLg_sendMessage);
}

void Heavy_Panoramizer::cMsg_JNUkZPuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_F3yTcxQZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_F3yTcxQZ_sendMessage);
}

void Heavy_Panoramizer::cBinop_6VecmVOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_R5e3gV2r, 1, m, &cPack_R5e3gV2r_sendMessage);
}

void Heavy_Panoramizer::cCast_K6ohd5bZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DakudEMB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_s2kxanbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WHQVrgc5, HV_BINOP_SUBTRACT, 0, m, &cBinop_WHQVrgc5_sendMessage);
}

void Heavy_Panoramizer::cDelay_NVTbk0K8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_NVTbk0K8, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVTbk0K8, 0, m, &cDelay_NVTbk0K8_sendMessage);
  cSwitchcase_gOfYXc2I_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_08rxOxvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVTbk0K8, 2, m, &cDelay_NVTbk0K8_sendMessage);
}

void Heavy_Panoramizer::cBinop_HwtyS3UC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_08rxOxvy_sendMessage);
}

void Heavy_Panoramizer::cVar_ZKT2nqf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwtyS3UC, HV_BINOP_MULTIPLY, 0, m, &cBinop_HwtyS3UC_sendMessage);
}

void Heavy_Panoramizer::cBinop_mk5ysJHd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HwtyS3UC, HV_BINOP_MULTIPLY, 1, m, &cBinop_HwtyS3UC_sendMessage);
}

void Heavy_Panoramizer::cCast_v9o54ZRm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nx7P2TQp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVTbk0K8, 0, m, &cDelay_NVTbk0K8_sendMessage);
  cSwitchcase_gOfYXc2I_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_UkTFRIgT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_nx7P2TQp_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_nx7P2TQp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_v9o54ZRm_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_nx7P2TQp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_NVTbk0K8, 0, m, &cDelay_NVTbk0K8_sendMessage);
}

void Heavy_Panoramizer::cSystem_8xwYjdsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mk5ysJHd_sendMessage);
}

void Heavy_Panoramizer::cMsg_ud30Ca9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8xwYjdsk_sendMessage);
}

void Heavy_Panoramizer::cBinop_F3yTcxQZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qjt0yr59, HV_BINOP_MULTIPLY, 1, m, &cBinop_qjt0yr59_sendMessage);
}

void Heavy_Panoramizer::cMsg_ynvXX4Zr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_hfPVzfNf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vBEQvp1O, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_w3JvETUq, m);
}

void Heavy_Panoramizer::cVar_KZvASSsv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_CR1ztK8u_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Fyv85DDS, 0, m, &cIf_Fyv85DDS_sendMessage);
}

void Heavy_Panoramizer::cBinop_CR1ztK8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Fyv85DDS, 1, m, &cIf_Fyv85DDS_sendMessage);
}

void Heavy_Panoramizer::cIf_Fyv85DDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ynvXX4Zr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_hfPVzfNf_sendMessage);
      cMsg_oyjtRGXa_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_3q2sRCQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_caivJRSw_sendMessage);
}

void Heavy_Panoramizer::cBinop_orTyOiHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vBEQvp1O, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_w3JvETUq, m);
}

void Heavy_Panoramizer::cMsg_eeQj9S9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_YMYvpXbV_sendMessage);
}

void Heavy_Panoramizer::cMsg_oyjtRGXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_orTyOiHs_sendMessage);
}

void Heavy_Panoramizer::cBinop_hfPVzfNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zH6YgKb6_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_lUR3w5UP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eeQj9S9R_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_caivJRSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OElDt3zM, m);
}

void Heavy_Panoramizer::cBinop_YMYvpXbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_K4x2IeDj, m);
}

void Heavy_Panoramizer::cMsg_It2bAlSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K7GsoBa9_sendMessage);
}

void Heavy_Panoramizer::cSystem_K7GsoBa9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3q2sRCQx_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_zH6YgKb6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lUR3w5UP_sendMessage);
}

void Heavy_Panoramizer::cCast_2bqimKsu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xFvBoavl_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_Gkg5vxwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_krWPwuUK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_cEfuIOJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_GXoQXGUE, 0, m, &cVar_GXoQXGUE_sendMessage);
}

void Heavy_Panoramizer::cBinop_A9TcDwvM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_BgNhb75u, 0, m, &cPack_BgNhb75u_sendMessage);
}

void Heavy_Panoramizer::cBinop_MkwaPBnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RQLiOfaS_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_8q9mnpqC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MhEKCcfp, 0, m, &cSlice_MhEKCcfp_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SKv9LBW0, 0, m, &cRandom_SKv9LBW0_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_SKv9LBW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_MkwaPBnX_sendMessage);
}

void Heavy_Panoramizer::cSlice_MhEKCcfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SKv9LBW0, 1, m, &cRandom_SKv9LBW0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_RQLiOfaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2AZHogX9, 0, m, &cVar_2AZHogX9_sendMessage);
}

void Heavy_Panoramizer::cRandom_2wPN5fSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jBtL4bWS, HV_BINOP_MULTIPLY, 0, m, &cBinop_jBtL4bWS_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_dyVhkAgl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xBMkfulY, 0, m, &cSlice_xBMkfulY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2wPN5fSY, 0, m, &cRandom_2wPN5fSY_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_jBtL4bWS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NtzCR5hK_sendMessage);
}

void Heavy_Panoramizer::cSlice_xBMkfulY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2wPN5fSY, 1, m, &cRandom_2wPN5fSY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_NtzCR5hK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BwmQzwqe, HV_BINOP_ADD, 0, m, &cBinop_BwmQzwqe_sendMessage);
}

void Heavy_Panoramizer::cCast_Wthxd2lO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s2kxanbR_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_2LEIF0ui_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_wKJ7HQKm, 2, m, &cDelay_wKJ7HQKm_sendMessage);
}

void Heavy_Panoramizer::cMsg_jGULOuIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ypyWMIfc_sendMessage);
}

void Heavy_Panoramizer::cSystem_ypyWMIfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6qXbIbhF_sendMessage);
}

void Heavy_Panoramizer::cDelay_wKJ7HQKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wKJ7HQKm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wKJ7HQKm, 0, m, &cDelay_wKJ7HQKm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dqBtwKUF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mjkARtEY_sendMessage);
}

void Heavy_Panoramizer::cBinop_YHPoY7m3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_2LEIF0ui_sendMessage);
}

void Heavy_Panoramizer::cCast_qyR7ubIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EeyfMqMJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wKJ7HQKm, 0, m, &cDelay_wKJ7HQKm_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dqBtwKUF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mjkARtEY_sendMessage);
}

void Heavy_Panoramizer::cVar_PPLuPCJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YHPoY7m3, HV_BINOP_MULTIPLY, 0, m, &cBinop_YHPoY7m3_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_oA4RGlz4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_EeyfMqMJ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_EeyfMqMJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qyR7ubIP_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_6qXbIbhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YHPoY7m3, HV_BINOP_MULTIPLY, 1, m, &cBinop_YHPoY7m3_sendMessage);
}

void Heavy_Panoramizer::cMsg_EeyfMqMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_wKJ7HQKm, 0, m, &cDelay_wKJ7HQKm_sendMessage);
}

void Heavy_Panoramizer::cBinop_TzIe9iOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_q0b2lD0f, 0, m, &cPack_q0b2lD0f_sendMessage);
}

void Heavy_Panoramizer::cCast_S70gd1pF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2z9zRHqt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_dMHHSV0U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_QmihQWOH, 0, m, &cVar_QmihQWOH_sendMessage);
}

void Heavy_Panoramizer::cMsg_Y5bnt2d0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xodyMRse_sendMessage);
}

void Heavy_Panoramizer::cSystem_xodyMRse_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GObLVY1q_sendMessage);
}

void Heavy_Panoramizer::cBinop_GObLVY1q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dvJKNU5d, HV_BINOP_MULTIPLY, 1, m, &cBinop_dvJKNU5d_sendMessage);
}

void Heavy_Panoramizer::cBinop_f56XOfzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k6c3m4lO, 2, m, &cDelay_k6c3m4lO_sendMessage);
}

void Heavy_Panoramizer::cCast_1YownrXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qFtilW3z_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k6c3m4lO, 0, m, &cDelay_k6c3m4lO_sendMessage);
  cSwitchcase_Wz6W8eFP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_dvJKNU5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_f56XOfzG_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_neF1gaYX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_qFtilW3z_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_qFtilW3z_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1YownrXe_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_qFtilW3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_k6c3m4lO, 0, m, &cDelay_k6c3m4lO_sendMessage);
}

void Heavy_Panoramizer::cVar_xpgkkHjf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dvJKNU5d, HV_BINOP_MULTIPLY, 0, m, &cBinop_dvJKNU5d_sendMessage);
}

void Heavy_Panoramizer::cDelay_k6c3m4lO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k6c3m4lO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_k6c3m4lO, 0, m, &cDelay_k6c3m4lO_sendMessage);
  cSwitchcase_Wz6W8eFP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_dqBtwKUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fmOhKYIw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_EP2dZlU9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TKJvWyra, 0, m, &cSlice_TKJvWyra_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5MoneVVx, 0, m, &cRandom_5MoneVVx_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_TKJvWyra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_5MoneVVx, 1, m, &cRandom_5MoneVVx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_BSZgQTvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2Dm0BjdB_sendMessage);
}

void Heavy_Panoramizer::cUnop_2Dm0BjdB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_thACoG9f, HV_BINOP_ADD, 0, m, &cBinop_thACoG9f_sendMessage);
}

void Heavy_Panoramizer::cRandom_5MoneVVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSZgQTvN, HV_BINOP_MULTIPLY, 0, m, &cBinop_BSZgQTvN_sendMessage);
}

void Heavy_Panoramizer::cReceive_EuokfNDd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9RsbCDIF, HV_BINOP_MULTIPLY, 1, m, &cBinop_9RsbCDIF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qfvtd4IN, HV_BINOP_MULTIPLY, 1, m, &cBinop_qfvtd4IN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_iyT2qVeO, HV_BINOP_MULTIPLY, 1, m, &cBinop_iyT2qVeO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_lrzLcuGv, HV_BINOP_MULTIPLY, 1, m, &cBinop_lrzLcuGv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9yqUaKxW, HV_BINOP_MULTIPLY, 1, m, &cBinop_9yqUaKxW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZzHRje5A, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZzHRje5A_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oYneyoBN, HV_BINOP_MULTIPLY, 1, m, &cBinop_oYneyoBN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvy9phU4, HV_BINOP_MULTIPLY, 1, m, &cBinop_fvy9phU4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HIEFQgpn, HV_BINOP_MULTIPLY, 1, m, &cBinop_HIEFQgpn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_W4fPNaDc, HV_BINOP_MULTIPLY, 1, m, &cBinop_W4fPNaDc_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6VecmVOr, HV_BINOP_MULTIPLY, 1, m, &cBinop_6VecmVOr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YY41R8Sr, HV_BINOP_MULTIPLY, 1, m, &cBinop_YY41R8Sr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DATbBqaY, HV_BINOP_MULTIPLY, 1, m, &cBinop_DATbBqaY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NDgelykv, HV_BINOP_MULTIPLY, 1, m, &cBinop_NDgelykv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4ibIl6qy, HV_BINOP_MULTIPLY, 1, m, &cBinop_4ibIl6qy_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_39lz6YKo, HV_BINOP_MULTIPLY, 1, m, &cBinop_39lz6YKo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_INzAl95R, HV_BINOP_MULTIPLY, 1, m, &cBinop_INzAl95R_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BNJinA05, HV_BINOP_MULTIPLY, 1, m, &cBinop_BNJinA05_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmecuPeh, HV_BINOP_MULTIPLY, 1, m, &cBinop_rmecuPeh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HPHV9kAx, HV_BINOP_MULTIPLY, 1, m, &cBinop_HPHV9kAx_sendMessage);
}

void Heavy_Panoramizer::cReceive_eeA8jCOd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gaoCOtlL, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xRn2VEfP, m);
}

void Heavy_Panoramizer::cBinop_EbPtAcIP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_oNSWNxVy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cReceive_QBHXLZcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1uLtXhTB, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TVNMH30m, m);
}

void Heavy_Panoramizer::cCast_xIlQQAKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5LuGL8PS, HV_BINOP_SUBTRACT, 1, m, &cBinop_5LuGL8PS_sendMessage);
}

void Heavy_Panoramizer::cBinop_9gZI7hLd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GIp8r6nT, HV_BINOP_MULTIPLY, 1, m, &cBinop_GIp8r6nT_sendMessage);
}

void Heavy_Panoramizer::cMsg_rEhqD9cC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0HGRMN7Z_sendMessage);
}

void Heavy_Panoramizer::cSystem_0HGRMN7Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9gZI7hLd_sendMessage);
}

void Heavy_Panoramizer::cBinop_sIUyWcK3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bh7YHVce, 2, m, &cDelay_bh7YHVce_sendMessage);
}

void Heavy_Panoramizer::cDelay_bh7YHVce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bh7YHVce, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bh7YHVce, 0, m, &cDelay_bh7YHVce_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HkIbj9Vk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PI2GLu9F_sendMessage);
}

void Heavy_Panoramizer::cVar_s0u2ZXpi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GIp8r6nT, HV_BINOP_MULTIPLY, 0, m, &cBinop_GIp8r6nT_sendMessage);
}

void Heavy_Panoramizer::cCast_uyZ1Y9p1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zXC9XXre_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bh7YHVce, 0, m, &cDelay_bh7YHVce_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HkIbj9Vk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PI2GLu9F_sendMessage);
}

void Heavy_Panoramizer::cBinop_GIp8r6nT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_sIUyWcK3_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Ridq6iE8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_zXC9XXre_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_zXC9XXre_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uyZ1Y9p1_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_zXC9XXre_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bh7YHVce, 0, m, &cDelay_bh7YHVce_sendMessage);
}

void Heavy_Panoramizer::cBinop_eVYbX9at_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ar9ob9A7, 1, m, &cIf_Ar9ob9A7_sendMessage);
}

void Heavy_Panoramizer::cIf_Ar9ob9A7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gcZ5IlPd_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_vgvKvxMF_sendMessage);
      cMsg_OYim5lHA_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_b6qHjsgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2UkY8KB3_sendMessage);
}

void Heavy_Panoramizer::cSystem_2UkY8KB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o5XWVMuI_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_6JyXYCVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rhjj9ynC, m);
}

void Heavy_Panoramizer::cBinop_s1A4AoHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ca8rHNVn, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8Kus44jV, m);
}

void Heavy_Panoramizer::cBinop_vgvKvxMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NcgCtwEl_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_kmRl2G8I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9AQBiny1_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_NX839HOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BUiWrmHJ, m);
}

void Heavy_Panoramizer::cMsg_NcgCtwEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kmRl2G8I_sendMessage);
}

void Heavy_Panoramizer::cMsg_gcZ5IlPd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_vgvKvxMF_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ca8rHNVn, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_8Kus44jV, m);
}

void Heavy_Panoramizer::cMsg_OYim5lHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_s1A4AoHl_sendMessage);
}

void Heavy_Panoramizer::cMsg_9AQBiny1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_NX839HOK_sendMessage);
}

void Heavy_Panoramizer::cMsg_o5XWVMuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_6JyXYCVQ_sendMessage);
}

void Heavy_Panoramizer::cVar_oatzeytR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_eVYbX9at_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Ar9ob9A7, 0, m, &cIf_Ar9ob9A7_sendMessage);
}

void Heavy_Panoramizer::cSlice_qvjVO1Py_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ppAOwXEY, 1, m, &cRandom_ppAOwXEY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_ZGrQGpqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wG8gMr2g, 0, m, &cVar_wG8gMr2g_sendMessage);
}

void Heavy_Panoramizer::cRandom_ppAOwXEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_qW2ROgLR_sendMessage);
}

void Heavy_Panoramizer::cBinop_qW2ROgLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZGrQGpqz_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_m69JWqMW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qvjVO1Py, 0, m, &cSlice_qvjVO1Py_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ppAOwXEY, 0, m, &cRandom_ppAOwXEY_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_w5OCC21O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nDmozohD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3BnSSoKy_sendMessage);
}

void Heavy_Panoramizer::cBinop_2hUueL2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4brib5Vi_sendMessage);
}

void Heavy_Panoramizer::cCast_fRMzzwmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7YQ9KCib_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8yzCTDmm, 0, m, &cDelay_8yzCTDmm_sendMessage);
  cSwitchcase_ebWxwsG7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_7YQ9KCib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8yzCTDmm, 0, m, &cDelay_8yzCTDmm_sendMessage);
}

void Heavy_Panoramizer::cVar_lUs941mW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hUueL2P, HV_BINOP_MULTIPLY, 0, m, &cBinop_2hUueL2P_sendMessage);
}

void Heavy_Panoramizer::cBinop_4brib5Vi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8yzCTDmm, 2, m, &cDelay_8yzCTDmm_sendMessage);
}

void Heavy_Panoramizer::cMsg_Re0AwdIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MMpP5jFP_sendMessage);
}

void Heavy_Panoramizer::cSystem_MMpP5jFP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_F3n1uk3j_sendMessage);
}

void Heavy_Panoramizer::cBinop_F3n1uk3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2hUueL2P, HV_BINOP_MULTIPLY, 1, m, &cBinop_2hUueL2P_sendMessage);
}

void Heavy_Panoramizer::cDelay_8yzCTDmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8yzCTDmm, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8yzCTDmm, 0, m, &cDelay_8yzCTDmm_sendMessage);
  cSwitchcase_ebWxwsG7_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_HhkjJUyx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_7YQ9KCib_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_7YQ9KCib_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fRMzzwmx_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_onXwvY8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_us1XHbtO, HV_BINOP_SUBTRACT, 0, m, &cBinop_us1XHbtO_sendMessage);
}

void Heavy_Panoramizer::cPack_7Zx6qeCt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nfcCtHIb, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_ny0Wd1XB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KIZvesAc, 0, m, &cPack_KIZvesAc_sendMessage);
}

void Heavy_Panoramizer::cCast_dedUYmpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bKdFPFTu_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_WhOK7LwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_slgNIpLk, HV_BINOP_SUBTRACT, 0, m, &cBinop_slgNIpLk_sendMessage);
}

void Heavy_Panoramizer::cMsg_0vLmFThu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pyDXEoxS, 0, m, &cDelay_pyDXEoxS_sendMessage);
}

void Heavy_Panoramizer::cBinop_BKkMQAUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_X33bSm2P_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_lQJokBhq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_0vLmFThu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_0vLmFThu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_q8MZseqr_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_QN62ayCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKkMQAUQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_BKkMQAUQ_sendMessage);
}

void Heavy_Panoramizer::cMsg_6UZJ75K6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aY4J8cTm_sendMessage);
}

void Heavy_Panoramizer::cSystem_aY4J8cTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QN62ayCn_sendMessage);
}

void Heavy_Panoramizer::cDelay_pyDXEoxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pyDXEoxS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pyDXEoxS, 0, m, &cDelay_pyDXEoxS_sendMessage);
  cSwitchcase_Ghi5Dd5H_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_Ligl3cRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BKkMQAUQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_BKkMQAUQ_sendMessage);
}

void Heavy_Panoramizer::cCast_q8MZseqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0vLmFThu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pyDXEoxS, 0, m, &cDelay_pyDXEoxS_sendMessage);
  cSwitchcase_Ghi5Dd5H_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_X33bSm2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pyDXEoxS, 2, m, &cDelay_pyDXEoxS_sendMessage);
}

void Heavy_Panoramizer::cBinop_6et0sILy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WhjWB6Uw, 0, m, &cPack_WhjWB6Uw_sendMessage);
}

void Heavy_Panoramizer::cBinop_lrzLcuGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2ywB6kJi, 1, m, &cPack_2ywB6kJi_sendMessage);
}

void Heavy_Panoramizer::cCast_eOaqXCDI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WSJfHmoD, HV_BINOP_SUBTRACT, 1, m, &cBinop_WSJfHmoD_sendMessage);
}

void Heavy_Panoramizer::cBinop_W4fPNaDc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wsbThzCO, 1, m, &cPack_wsbThzCO_sendMessage);
}

void Heavy_Panoramizer::cBinop_V8wXH6U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eOaqXCDI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fan8ldPj_sendMessage);
}

void Heavy_Panoramizer::cCast_0rbwLNa7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VDTJRcxS_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_Hda8XOWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gOERzqT2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_bMBHJfc6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xtIEhuqP, 0, m, &cSlice_xtIEhuqP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qSHco09j, 0, m, &cRandom_qSHco09j_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_xtIEhuqP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qSHco09j, 1, m, &cRandom_qSHco09j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_jiv9TwS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_haYkA3Ds_sendMessage);
}

void Heavy_Panoramizer::cRandom_qSHco09j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_jiv9TwS0_sendMessage);
}

void Heavy_Panoramizer::cUnop_haYkA3Ds_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wEgJgGmd, 0, m, &cVar_wEgJgGmd_sendMessage);
}

void Heavy_Panoramizer::cBinop_9yqUaKxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Hm2D2lw5, 1, m, &cPack_Hm2D2lw5_sendMessage);
}

void Heavy_Panoramizer::cMsg_prOKeH0Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_qzaremvQ_sendMessage);
}

void Heavy_Panoramizer::cSystem_qzaremvQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZhCJ7JgD_sendMessage);
}

void Heavy_Panoramizer::cBinop_plKIoGz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_xQkmb5FQ, 2, m, &cDelay_xQkmb5FQ_sendMessage);
}

void Heavy_Panoramizer::cMsg_nChtV3Yg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_xQkmb5FQ, 0, m, &cDelay_xQkmb5FQ_sendMessage);
}

void Heavy_Panoramizer::cDelay_xQkmb5FQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_xQkmb5FQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xQkmb5FQ, 0, m, &cDelay_xQkmb5FQ_sendMessage);
  cSwitchcase_m69JWqMW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_sLZajxVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kaQWyuBL, HV_BINOP_MULTIPLY, 0, m, &cBinop_kaQWyuBL_sendMessage);
}

void Heavy_Panoramizer::cCast_Y3gxX9Up_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nChtV3Yg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_xQkmb5FQ, 0, m, &cDelay_xQkmb5FQ_sendMessage);
  cSwitchcase_m69JWqMW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_kaQWyuBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_plKIoGz3_sendMessage);
}

void Heavy_Panoramizer::cBinop_ZhCJ7JgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kaQWyuBL, HV_BINOP_MULTIPLY, 1, m, &cBinop_kaQWyuBL_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_ubevqBIS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_nChtV3Yg_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_nChtV3Yg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Y3gxX9Up_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_HIEFQgpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_udwhr5qK, 1, m, &cPack_udwhr5qK_sendMessage);
}

void Heavy_Panoramizer::cPack_wsbThzCO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MUZbgaOJ, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_HSey0fsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_l41vCFsR, 0, m, &cPack_l41vCFsR_sendMessage);
}

void Heavy_Panoramizer::cDelay_rwkD9zCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_rwkD9zCv, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rwkD9zCv, 0, m, &cDelay_rwkD9zCv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bzGdmpzB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hda8XOWd_sendMessage);
}

void Heavy_Panoramizer::cMsg_s0Lp9Mlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_rwkD9zCv, 0, m, &cDelay_rwkD9zCv_sendMessage);
}

void Heavy_Panoramizer::cBinop_tLcgRKHs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_IloUxDFD_sendMessage);
}

void Heavy_Panoramizer::cCast_Za8NKLeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s0Lp9Mlx_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_rwkD9zCv, 0, m, &cDelay_rwkD9zCv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bzGdmpzB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Hda8XOWd_sendMessage);
}

void Heavy_Panoramizer::cVar_wEgJgGmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tLcgRKHs, HV_BINOP_MULTIPLY, 0, m, &cBinop_tLcgRKHs_sendMessage);
}

void Heavy_Panoramizer::cBinop_IloUxDFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_rwkD9zCv, 2, m, &cDelay_rwkD9zCv_sendMessage);
}

void Heavy_Panoramizer::cBinop_OvfDU5nx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tLcgRKHs, HV_BINOP_MULTIPLY, 1, m, &cBinop_tLcgRKHs_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_HEnDO9n6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_s0Lp9Mlx_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_s0Lp9Mlx_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Za8NKLeA_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_YlGnQAXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AMLLLsdT_sendMessage);
}

void Heavy_Panoramizer::cSystem_AMLLLsdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OvfDU5nx_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_K82mERSa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Dv36PfEJ, 0, m, &cSlice_Dv36PfEJ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KaHYrfRZ, 0, m, &cRandom_KaHYrfRZ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_uTFsWvY6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9Ofw8NEf_sendMessage);
}

void Heavy_Panoramizer::cSlice_Dv36PfEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_KaHYrfRZ, 1, m, &cRandom_KaHYrfRZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_KaHYrfRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_uTFsWvY6_sendMessage);
}

void Heavy_Panoramizer::cUnop_9Ofw8NEf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9RsbCDIF, HV_BINOP_MULTIPLY, 0, m, &cBinop_9RsbCDIF_sendMessage);
}

void Heavy_Panoramizer::cBinop_GgJUFsrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8iAKC7BB, HV_BINOP_MULTIPLY, 1, m, &cBinop_8iAKC7BB_sendMessage);
}

void Heavy_Panoramizer::cUnop_tPwMkaNF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lrzLcuGv, HV_BINOP_MULTIPLY, 0, m, &cBinop_lrzLcuGv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_atQ5hQ0f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xIrMWCWM, 0, m, &cSlice_xIrMWCWM_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sHZwBGrw, 0, m, &cRandom_sHZwBGrw_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_sHZwBGrw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_xnVM7BoI_sendMessage);
}

void Heavy_Panoramizer::cSlice_xIrMWCWM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sHZwBGrw, 1, m, &cRandom_sHZwBGrw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_xnVM7BoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tPwMkaNF_sendMessage);
}

void Heavy_Panoramizer::cMsg_8bMsSrdk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Wnx1Ss4v, 0, m, &cVar_Wnx1Ss4v_sendMessage);
}

void Heavy_Panoramizer::cUnop_G1umS4ib_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZF5I7Tr7, HV_BINOP_ADD, 0, m, &cBinop_ZF5I7Tr7_sendMessage);
}

void Heavy_Panoramizer::cRandom_bEjZJI67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9IEeWwJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_M9IEeWwJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_M9IEeWwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_G1umS4ib_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_N5TyPkpK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0rHTX0bR, 0, m, &cSlice_0rHTX0bR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bEjZJI67, 0, m, &cRandom_bEjZJI67_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_0rHTX0bR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bEjZJI67, 1, m, &cRandom_bEjZJI67_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cCast_fan8ldPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tDsGEE0k_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_KDoD0vuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_5QtG5Wbl, 0, m, &cVar_5QtG5Wbl_sendMessage);
}

void Heavy_Panoramizer::cBinop_4Lxy3j8H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tz4dxZ56_sendMessage);
}

void Heavy_Panoramizer::cUnop_tz4dxZ56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ny0Wd1XB, HV_BINOP_ADD, 0, m, &cBinop_ny0Wd1XB_sendMessage);
}

void Heavy_Panoramizer::cRandom_OMhsTQkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Lxy3j8H, HV_BINOP_MULTIPLY, 0, m, &cBinop_4Lxy3j8H_sendMessage);
}

void Heavy_Panoramizer::cSlice_bDQDG5UO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OMhsTQkM, 1, m, &cRandom_OMhsTQkM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_XAtMqTcu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bDQDG5UO, 0, m, &cSlice_bDQDG5UO_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OMhsTQkM, 0, m, &cRandom_OMhsTQkM_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_7NKFoctD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fWB0R7qI, HV_BINOP_MULTIPLY, 1, m, &cBinop_fWB0R7qI_sendMessage);
}

void Heavy_Panoramizer::cMsg_5CMNM2F6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vYYQjND0, 0, m, &cVar_vYYQjND0_sendMessage);
}

void Heavy_Panoramizer::cBinop_qfvtd4IN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7Zx6qeCt, 1, m, &cPack_7Zx6qeCt_sendMessage);
}

void Heavy_Panoramizer::cVar_Iy0cNPij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bL74sB1r, HV_BINOP_MULTIPLY, 0, m, &cBinop_bL74sB1r_sendMessage);
}

void Heavy_Panoramizer::cBinop_fgsEOJ9t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bL74sB1r, HV_BINOP_MULTIPLY, 1, m, &cBinop_bL74sB1r_sendMessage);
}

void Heavy_Panoramizer::cBinop_bL74sB1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_SLlzCugE_sendMessage);
}

void Heavy_Panoramizer::cDelay_JUXYOtkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_JUXYOtkt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JUXYOtkt, 0, m, &cDelay_JUXYOtkt_sendMessage);
  cSwitchcase_WPaQxTuP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_ZPFTzKIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_JUXYOtkt, 0, m, &cDelay_JUXYOtkt_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_P8vVLgsx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ZPFTzKIq_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ZPFTzKIq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9TFA1fgY_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSystem_Uiaro7R2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fgsEOJ9t_sendMessage);
}

void Heavy_Panoramizer::cMsg_m9wNOXyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Uiaro7R2_sendMessage);
}

void Heavy_Panoramizer::cCast_9TFA1fgY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZPFTzKIq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_JUXYOtkt, 0, m, &cDelay_JUXYOtkt_sendMessage);
  cSwitchcase_WPaQxTuP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_SLlzCugE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_JUXYOtkt, 2, m, &cDelay_JUXYOtkt_sendMessage);
}

void Heavy_Panoramizer::cCast_ppJWJ1xu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ohs3raOm_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_V6dCSlQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_atQ5hQ0f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_F55QY8uz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FMhkvfZ7, HV_BINOP_SUBTRACT, 1, m, &cBinop_FMhkvfZ7_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_GbF7kvjv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_i5KHXFpp, 0, m, &cSlice_i5KHXFpp_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_UmC5DNG0, 0, m, &cRandom_UmC5DNG0_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_Mtc8ft1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dHfBWIFs_sendMessage);
}

void Heavy_Panoramizer::cUnop_dHfBWIFs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W4fPNaDc, HV_BINOP_MULTIPLY, 0, m, &cBinop_W4fPNaDc_sendMessage);
}

void Heavy_Panoramizer::cRandom_UmC5DNG0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_Mtc8ft1z_sendMessage);
}

void Heavy_Panoramizer::cSlice_i5KHXFpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_UmC5DNG0, 1, m, &cRandom_UmC5DNG0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_ZzHRje5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PVf041un, 1, m, &cPack_PVf041un_sendMessage);
}

void Heavy_Panoramizer::cSystem_yl5TTK1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_6dRwFI42_sendMessage);
}

void Heavy_Panoramizer::cMsg_KmF3NbWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yl5TTK1V_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_kkWM3FL1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_pntD2iEU_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_pntD2iEU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ElgWt9tD_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_ElgWt9tD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pntD2iEU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9DKYXLTM, 0, m, &cDelay_9DKYXLTM_sendMessage);
  cSwitchcase_QjHxB9PL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_6dRwFI42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JW0PiAFd, HV_BINOP_MULTIPLY, 1, m, &cBinop_JW0PiAFd_sendMessage);
}

void Heavy_Panoramizer::cVar_kAKmpfEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JW0PiAFd, HV_BINOP_MULTIPLY, 0, m, &cBinop_JW0PiAFd_sendMessage);
}

void Heavy_Panoramizer::cDelay_9DKYXLTM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9DKYXLTM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9DKYXLTM, 0, m, &cDelay_9DKYXLTM_sendMessage);
  cSwitchcase_QjHxB9PL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_oqO87UZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9DKYXLTM, 2, m, &cDelay_9DKYXLTM_sendMessage);
}

void Heavy_Panoramizer::cBinop_JW0PiAFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_oqO87UZA_sendMessage);
}

void Heavy_Panoramizer::cMsg_pntD2iEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9DKYXLTM, 0, m, &cDelay_9DKYXLTM_sendMessage);
}

void Heavy_Panoramizer::cBinop_B98AYWC6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vNvYVNXY, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9hCFhEwX, m);
}

void Heavy_Panoramizer::cBinop_ERpc1dFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_tsdoN062, m);
}

void Heavy_Panoramizer::cVar_MAgZq37l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_zqX0t3fT_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_P2GpWQVs, 0, m, &cIf_P2GpWQVs_sendMessage);
}

void Heavy_Panoramizer::cBinop_i4aCMEaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WKipQWz3_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_iTaAmDS6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nGESmoe1_sendMessage);
}

void Heavy_Panoramizer::cSystem_nGESmoe1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uCyQLNvg_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_uCyQLNvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ERpc1dFK_sendMessage);
}

void Heavy_Panoramizer::cMsg_WKipQWz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_9GtYGQ2r_sendMessage);
}

void Heavy_Panoramizer::cMsg_Gf2BavYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_B98AYWC6_sendMessage);
}

void Heavy_Panoramizer::cBinop_p9KtaL3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_amm1qj7f_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_A4mxK8mY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_p9KtaL3L_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vNvYVNXY, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9hCFhEwX, m);
}

void Heavy_Panoramizer::cBinop_9GtYGQ2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_t7XgPdmt, m);
}

void Heavy_Panoramizer::cBinop_zqX0t3fT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_P2GpWQVs, 1, m, &cIf_P2GpWQVs_sendMessage);
}

void Heavy_Panoramizer::cIf_P2GpWQVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_A4mxK8mY_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_p9KtaL3L_sendMessage);
      cMsg_Gf2BavYn_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_amm1qj7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_i4aCMEaf_sendMessage);
}

void Heavy_Panoramizer::cUnop_RsKwy8vQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5XuGwcVF, 0, m, &cVar_5XuGwcVF_sendMessage);
}

void Heavy_Panoramizer::cBinop_2nyWoVGm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RsKwy8vQ_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_jjuMOrPN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_L2FWCXEX, 0, m, &cSlice_L2FWCXEX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eeCjt6O1, 0, m, &cRandom_eeCjt6O1_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_L2FWCXEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_eeCjt6O1, 1, m, &cRandom_eeCjt6O1_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_eeCjt6O1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_2nyWoVGm_sendMessage);
}

void Heavy_Panoramizer::cMsg_rWkwEmHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dl26kkEH, HV_BINOP_SUBTRACT, 0, m, &cBinop_Dl26kkEH_sendMessage);
}

void Heavy_Panoramizer::cBinop_GFrqeqUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Lxy3j8H, HV_BINOP_MULTIPLY, 1, m, &cBinop_4Lxy3j8H_sendMessage);
}

void Heavy_Panoramizer::cBinop_UBDyG3D7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rcYxDyUj, 1, m, &cIf_rcYxDyUj_sendMessage);
}

void Heavy_Panoramizer::cIf_rcYxDyUj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_F6iqJlF7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_KAWf8gMY_sendMessage);
      cMsg_CT5vFUyV_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_5DifSKGv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ScgZ8xs3, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lHTedkk6, m);
}

void Heavy_Panoramizer::cMsg_F6iqJlF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_KAWf8gMY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ScgZ8xs3, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lHTedkk6, m);
}

void Heavy_Panoramizer::cMsg_fULSxTFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Miog3QwU_sendMessage);
}

void Heavy_Panoramizer::cBinop_Miog3QwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y68sVFkZ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_CT5vFUyV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5DifSKGv_sendMessage);
}

void Heavy_Panoramizer::cMsg_6dK4lVPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NCIsoe9S_sendMessage);
}

void Heavy_Panoramizer::cSystem_NCIsoe9S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zog8IWYv_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_ArnDYZ7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qApCAyFA, m);
}

void Heavy_Panoramizer::cBinop_KAWf8gMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fULSxTFZ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_2o3UhK8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_UBDyG3D7_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rcYxDyUj, 0, m, &cIf_rcYxDyUj_sendMessage);
}

void Heavy_Panoramizer::cBinop_qpRd8FVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_cODWyoZT, m);
}

void Heavy_Panoramizer::cMsg_Y68sVFkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ArnDYZ7O_sendMessage);
}

void Heavy_Panoramizer::cMsg_zog8IWYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_qpRd8FVh_sendMessage);
}

void Heavy_Panoramizer::cUnop_jF6VMHhY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_s0u2ZXpi, 0, m, &cVar_s0u2ZXpi_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_MP1TgyYG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_3BmYfj6m, 0, m, &cSlice_3BmYfj6m_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hZwI10Ld, 0, m, &cRandom_hZwI10Ld_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_hZwI10Ld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_o2msvyYk_sendMessage);
}

void Heavy_Panoramizer::cSlice_3BmYfj6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hZwI10Ld, 1, m, &cRandom_hZwI10Ld_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_o2msvyYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jF6VMHhY_sendMessage);
}

void Heavy_Panoramizer::cBinop_gP8cMz0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dpeP5GiW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pLsPSDst_sendMessage);
}

void Heavy_Panoramizer::cMsg_VDTJRcxS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GFrqeqUu, HV_BINOP_SUBTRACT, 0, m, &cBinop_GFrqeqUu_sendMessage);
}

void Heavy_Panoramizer::cBinop_vpkbrOwk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2ywB6kJi, 0, m, &cPack_2ywB6kJi_sendMessage);
}

void Heavy_Panoramizer::cBinop_us1XHbtO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j2DfUNHv, HV_BINOP_MULTIPLY, 1, m, &cBinop_j2DfUNHv_sendMessage);
}

void Heavy_Panoramizer::cBinop_FMhkvfZ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpCeVm84, HV_BINOP_MULTIPLY, 1, m, &cBinop_cpCeVm84_sendMessage);
}

void Heavy_Panoramizer::cCast_cPhyJW9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_PNB578d8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_dpeP5GiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n0qS0I41, HV_BINOP_SUBTRACT, 1, m, &cBinop_n0qS0I41_sendMessage);
}

void Heavy_Panoramizer::cMsg_3zTXH5Ig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n0qS0I41, HV_BINOP_SUBTRACT, 0, m, &cBinop_n0qS0I41_sendMessage);
}

void Heavy_Panoramizer::cBinop_OZQAAg4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3OY8NESs, HV_BINOP_MULTIPLY, 1, m, &cBinop_3OY8NESs_sendMessage);
}

void Heavy_Panoramizer::cMsg_ZlWDSWSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_4umZrSag, 0, m, &cDelay_4umZrSag_sendMessage);
}

void Heavy_Panoramizer::cBinop_3OY8NESs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_JmXgWU12_sendMessage);
}

void Heavy_Panoramizer::cBinop_JmXgWU12_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_4umZrSag, 2, m, &cDelay_4umZrSag_sendMessage);
}

void Heavy_Panoramizer::cDelay_4umZrSag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_4umZrSag, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4umZrSag, 0, m, &cDelay_4umZrSag_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aJJopLdP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tH7cOqKE_sendMessage);
}

void Heavy_Panoramizer::cVar_mln0cGd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3OY8NESs, HV_BINOP_MULTIPLY, 0, m, &cBinop_3OY8NESs_sendMessage);
}

void Heavy_Panoramizer::cSystem_LbzDL24b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_OZQAAg4Z_sendMessage);
}

void Heavy_Panoramizer::cMsg_5QMWww13_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LbzDL24b_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_FfF901ji_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ZlWDSWSj_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ZlWDSWSj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ffhjbzP3_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_ffhjbzP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZlWDSWSj_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_4umZrSag, 0, m, &cDelay_4umZrSag_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aJJopLdP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tH7cOqKE_sendMessage);
}

void Heavy_Panoramizer::cMsg_b4yX69s3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mfh25uWT, 0, m, &cVar_mfh25uWT_sendMessage);
}

void Heavy_Panoramizer::cBinop_dgYWkrdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_PVf041un, 0, m, &cPack_PVf041un_sendMessage);
}

void Heavy_Panoramizer::cRandom_CL3gDiaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_wU50DjTt_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Ml4Q7llm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zf76qCSR, 0, m, &cSlice_zf76qCSR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CL3gDiaQ, 0, m, &cRandom_CL3gDiaQ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_zf76qCSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CL3gDiaQ, 1, m, &cRandom_CL3gDiaQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_wU50DjTt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AXTi6puU_sendMessage);
}

void Heavy_Panoramizer::cUnop_AXTi6puU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PYb9Xvc9, 0, m, &cVar_PYb9Xvc9_sendMessage);
}

void Heavy_Panoramizer::cBinop_ZyJkkFpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujx2N0xJ, 2, m, &cDelay_ujx2N0xJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_z2HFqNHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ZyJkkFpr_sendMessage);
}

void Heavy_Panoramizer::cSystem_5ESJ7Ag8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HvWmgaB3_sendMessage);
}

void Heavy_Panoramizer::cMsg_8DG5WsFd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5ESJ7Ag8_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_ZuSuiAQh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ydl4UZxL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ydl4UZxL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nXsu7e4D_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_h2miBKEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z2HFqNHF, HV_BINOP_MULTIPLY, 0, m, &cBinop_z2HFqNHF_sendMessage);
}

void Heavy_Panoramizer::cCast_nXsu7e4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ydl4UZxL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujx2N0xJ, 0, m, &cDelay_ujx2N0xJ_sendMessage);
  cSwitchcase_Ml4Q7llm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_ydl4UZxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujx2N0xJ, 0, m, &cDelay_ujx2N0xJ_sendMessage);
}

void Heavy_Panoramizer::cDelay_ujx2N0xJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ujx2N0xJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujx2N0xJ, 0, m, &cDelay_ujx2N0xJ_sendMessage);
  cSwitchcase_Ml4Q7llm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_HvWmgaB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z2HFqNHF, HV_BINOP_MULTIPLY, 1, m, &cBinop_z2HFqNHF_sendMessage);
}

void Heavy_Panoramizer::cCast_pYguRCjw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DwUHRuBx_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_gqQEEud0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XAtMqTcu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cPack_m9u76HZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_t6mH6GZI, 0, m, NULL);
}

void Heavy_Panoramizer::cSlice_SweHyKWc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_t3eISuR8, 1, m, &cRandom_t3eISuR8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_t3eISuR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8iAKC7BB, HV_BINOP_MULTIPLY, 0, m, &cBinop_8iAKC7BB_sendMessage);
}

void Heavy_Panoramizer::cUnop_BIfBBVCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P4HtOh27, HV_BINOP_ADD, 0, m, &cBinop_P4HtOh27_sendMessage);
}

void Heavy_Panoramizer::cBinop_8iAKC7BB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BIfBBVCe_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_WLRACdN4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SweHyKWc, 0, m, &cSlice_SweHyKWc_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_t3eISuR8, 0, m, &cRandom_t3eISuR8_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_AxYXU4OU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GgJUFsrq, HV_BINOP_SUBTRACT, 1, m, &cBinop_GgJUFsrq_sendMessage);
}

void Heavy_Panoramizer::cBinop_9RsbCDIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WhjWB6Uw, 1, m, &cPack_WhjWB6Uw_sendMessage);
}

void Heavy_Panoramizer::cMsg_xn0rnegV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_oatzeytR, 0, m, &cVar_oatzeytR_sendMessage);
}

void Heavy_Panoramizer::cBinop_e3uuK5Ec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6s29cxKt, HV_BINOP_MULTIPLY, 1, m, &cBinop_6s29cxKt_sendMessage);
}

void Heavy_Panoramizer::cSystem_66iJVF5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_e3uuK5Ec_sendMessage);
}

void Heavy_Panoramizer::cMsg_fFH8vTzx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_66iJVF5i_sendMessage);
}

void Heavy_Panoramizer::cDelay_FcXgKvar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FcXgKvar, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FcXgKvar, 0, m, &cDelay_FcXgKvar_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V6dCSlQy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bTUPnoxy_sendMessage);
}

void Heavy_Panoramizer::cMsg_cBbuK6hu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FcXgKvar, 0, m, &cDelay_FcXgKvar_sendMessage);
}

void Heavy_Panoramizer::cBinop_yxi5GqLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FcXgKvar, 2, m, &cDelay_FcXgKvar_sendMessage);
}

void Heavy_Panoramizer::cCast_ekA2va6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cBbuK6hu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FcXgKvar, 0, m, &cDelay_FcXgKvar_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V6dCSlQy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bTUPnoxy_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_87cXTt38_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_cBbuK6hu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_cBbuK6hu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ekA2va6z_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_5XuGwcVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6s29cxKt, HV_BINOP_MULTIPLY, 0, m, &cBinop_6s29cxKt_sendMessage);
}

void Heavy_Panoramizer::cBinop_6s29cxKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yxi5GqLu_sendMessage);
}

void Heavy_Panoramizer::cUnop_PTFahyRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9yqUaKxW, HV_BINOP_MULTIPLY, 0, m, &cBinop_9yqUaKxW_sendMessage);
}

void Heavy_Panoramizer::cSlice_iSxEbKGI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kE2NLWBW, 1, m, &cRandom_kE2NLWBW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_eiumWGPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PTFahyRi_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_eIcoIyYf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iSxEbKGI, 0, m, &cSlice_iSxEbKGI_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kE2NLWBW, 0, m, &cRandom_kE2NLWBW_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_kE2NLWBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_eiumWGPe_sendMessage);
}

void Heavy_Panoramizer::cSlice_5O9sjZ7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lWrsQ6wH, 1, m, &cRandom_lWrsQ6wH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_Jk3IqqFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AHpxJ9Py_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_FwLweLqp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5O9sjZ7P, 0, m, &cSlice_5O9sjZ7P_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lWrsQ6wH, 0, m, &cRandom_lWrsQ6wH_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_AHpxJ9Py_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ERgMZfOS, 0, m, &cVar_ERgMZfOS_sendMessage);
}

void Heavy_Panoramizer::cRandom_lWrsQ6wH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_Jk3IqqFr_sendMessage);
}

void Heavy_Panoramizer::cBinop_glfmovcM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_us2DXnN5_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_HJZ74L3q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aaVRPfmI, m);
}

void Heavy_Panoramizer::cBinop_snMoknLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VpyF120T_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_ZkeAJYN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jW6guiHO_sendMessage);
}

void Heavy_Panoramizer::cSystem_jW6guiHO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a1egRvgP_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_a1egRvgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HJZ74L3q_sendMessage);
}

void Heavy_Panoramizer::cBinop_PNUO0AeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MNFdG1jD, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cbJvSfsf, m);
}

void Heavy_Panoramizer::cMsg_VpyF120T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_GzMrXaw8_sendMessage);
}

void Heavy_Panoramizer::cMsg_us2DXnN5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_snMoknLk_sendMessage);
}

void Heavy_Panoramizer::cMsg_JBTvMUFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_glfmovcM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MNFdG1jD, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cbJvSfsf, m);
}

void Heavy_Panoramizer::cMsg_u5S40uHW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_PNUO0AeA_sendMessage);
}

void Heavy_Panoramizer::cVar_jtRRuezc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_Ngolcnff_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_5V3vbmcm, 0, m, &cIf_5V3vbmcm_sendMessage);
}

void Heavy_Panoramizer::cBinop_GzMrXaw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UPsbO0T2, m);
}

void Heavy_Panoramizer::cIf_5V3vbmcm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_JBTvMUFh_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_glfmovcM_sendMessage);
      cMsg_u5S40uHW_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_Ngolcnff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5V3vbmcm, 1, m, &cIf_5V3vbmcm_sendMessage);
}

void Heavy_Panoramizer::cBinop_MVKetmjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FhXlAlzp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_taAivNkZ_sendMessage);
}

void Heavy_Panoramizer::cCast_3BnSSoKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_onXwvY8M_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cUnop_rRbSRclx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dgYWkrdj, HV_BINOP_ADD, 0, m, &cBinop_dgYWkrdj_sendMessage);
}

void Heavy_Panoramizer::cBinop_8O94vyKG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rRbSRclx_sendMessage);
}

void Heavy_Panoramizer::cSlice_ofybVYen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7isTfxNo, 1, m, &cRandom_7isTfxNo_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_7isTfxNo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8O94vyKG, HV_BINOP_MULTIPLY, 0, m, &cBinop_8O94vyKG_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_5d0KzpKv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ofybVYen, 0, m, &cSlice_ofybVYen_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_7isTfxNo, 0, m, &cRandom_7isTfxNo_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_okAbPEWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_F55QY8uz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ppJWJ1xu_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_DwUHRuBx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_APyhOSYD, 0, m, &cSlice_APyhOSYD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZcA9krHz, 0, m, &cRandom_ZcA9krHz_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_AQ1YG8I5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fvy9phU4, HV_BINOP_MULTIPLY, 0, m, &cBinop_fvy9phU4_sendMessage);
}

void Heavy_Panoramizer::cRandom_ZcA9krHz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_Qt8BcWax_sendMessage);
}

void Heavy_Panoramizer::cBinop_Qt8BcWax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_AQ1YG8I5_sendMessage);
}

void Heavy_Panoramizer::cSlice_APyhOSYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZcA9krHz, 1, m, &cRandom_ZcA9krHz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cPack_Hm2D2lw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_mBK8HTmp, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_iyT2qVeO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_m9u76HZ6, 1, m, &cPack_m9u76HZ6_sendMessage);
}

void Heavy_Panoramizer::cBinop_pX0T2pC7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rv3flOzT, HV_BINOP_MULTIPLY, 1, m, &cBinop_rv3flOzT_sendMessage);
}

void Heavy_Panoramizer::cDelay_onGiMVtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_onGiMVtz, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_onGiMVtz, 0, m, &cDelay_onGiMVtz_sendMessage);
  cSwitchcase_MP1TgyYG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_rv3flOzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_RabQoJHx_sendMessage);
}

void Heavy_Panoramizer::cMsg_XDdFA3fs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6ZH37RXe_sendMessage);
}

void Heavy_Panoramizer::cSystem_6ZH37RXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pX0T2pC7_sendMessage);
}

void Heavy_Panoramizer::cBinop_RabQoJHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_onGiMVtz, 2, m, &cDelay_onGiMVtz_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_U0WV5rIX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_JGWiPVpU_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_JGWiPVpU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l1wmzVNf_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_JGWiPVpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_onGiMVtz, 0, m, &cDelay_onGiMVtz_sendMessage);
}

void Heavy_Panoramizer::cCast_l1wmzVNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JGWiPVpU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_onGiMVtz, 0, m, &cDelay_onGiMVtz_sendMessage);
  cSwitchcase_MP1TgyYG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_q8chZZpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rv3flOzT, HV_BINOP_MULTIPLY, 0, m, &cBinop_rv3flOzT_sendMessage);
}

void Heavy_Panoramizer::cPack_PVf041un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MXwWIheG, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_llRYFudd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_GVYLoUcV_sendMessage);
}

void Heavy_Panoramizer::cBinop_636dcGKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4F1cSXrH, m);
}

void Heavy_Panoramizer::cBinop_UO0MocdI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FYPXvwc5_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSystem_DuZhsSaA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vLLupnQB_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_f41DJGw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DuZhsSaA_sendMessage);
}

void Heavy_Panoramizer::cBinop_IYJcii2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MBcTnk6n_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cIf_nWdmkfeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_R8foSqwf_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_IYJcii2i_sendMessage);
      cMsg_llRYFudd_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_Kl3cPBpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nWdmkfeQ, 1, m, &cIf_nWdmkfeQ_sendMessage);
}

void Heavy_Panoramizer::cBinop_SoEXdDd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_WggwOBSz, m);
}

void Heavy_Panoramizer::cMsg_vLLupnQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SoEXdDd6_sendMessage);
}

void Heavy_Panoramizer::cMsg_FYPXvwc5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_636dcGKh_sendMessage);
}

void Heavy_Panoramizer::cVar_Wnx1Ss4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_Kl3cPBpd_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nWdmkfeQ, 0, m, &cIf_nWdmkfeQ_sendMessage);
}

void Heavy_Panoramizer::cMsg_R8foSqwf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_IYJcii2i_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_h9Sk51H8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MNW0v8sE, m);
}

void Heavy_Panoramizer::cBinop_GVYLoUcV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h9Sk51H8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_MNW0v8sE, m);
}

void Heavy_Panoramizer::cMsg_MBcTnk6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UO0MocdI_sendMessage);
}

void Heavy_Panoramizer::cPack_2ywB6kJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_JF2WlRsy, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_WSJfHmoD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8O94vyKG, HV_BINOP_MULTIPLY, 1, m, &cBinop_8O94vyKG_sendMessage);
}

void Heavy_Panoramizer::cRandom_38EyO6at_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I8qij9Me, HV_BINOP_MULTIPLY, 0, m, &cBinop_I8qij9Me_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_aerWU0eX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_35xlwrHY, 0, m, &cSlice_35xlwrHY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_38EyO6at, 0, m, &cRandom_38EyO6at_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_I8qij9Me_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Syguz3Je_sendMessage);
}

void Heavy_Panoramizer::cUnop_Syguz3Je_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FxYkz8yh, HV_BINOP_ADD, 0, m, &cBinop_FxYkz8yh_sendMessage);
}

void Heavy_Panoramizer::cSlice_35xlwrHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_38EyO6at, 1, m, &cRandom_38EyO6at_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_2LaIFiAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xIlQQAKL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dedUYmpS_sendMessage);
}

void Heavy_Panoramizer::cCast_X0tQjJRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dMO7IrMH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_UgLhUApX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_MAgZq37l, 0, m, &cVar_MAgZq37l_sendMessage);
}

void Heavy_Panoramizer::cUnop_4O20Jumn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iyT2qVeO, HV_BINOP_MULTIPLY, 0, m, &cBinop_iyT2qVeO_sendMessage);
}

void Heavy_Panoramizer::cSlice_6WgHO88X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uNDE4LkA, 1, m, &cRandom_uNDE4LkA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_aMd3z2v1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4O20Jumn_sendMessage);
}

void Heavy_Panoramizer::cRandom_uNDE4LkA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_aMd3z2v1_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_GXNQ8Dw5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6WgHO88X, 0, m, &cSlice_6WgHO88X_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uNDE4LkA, 0, m, &cRandom_uNDE4LkA_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_uXZaLFd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_7Zx6qeCt, 0, m, &cPack_7Zx6qeCt_sendMessage);
}

void Heavy_Panoramizer::cCast_eyDvkH6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_eIcoIyYf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_QjHxB9PL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mVnuSSR2, 0, m, &cSlice_mVnuSSR2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yR1Cuzdt, 0, m, &cRandom_yR1Cuzdt_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_8WvNj3hl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FHkucw6C_sendMessage);
}

void Heavy_Panoramizer::cSlice_mVnuSSR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yR1Cuzdt, 1, m, &cRandom_yR1Cuzdt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_FHkucw6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ferHxxur, 0, m, &cVar_ferHxxur_sendMessage);
}

void Heavy_Panoramizer::cRandom_yR1Cuzdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_8WvNj3hl_sendMessage);
}

void Heavy_Panoramizer::cCast_YR65yyvH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5d0KzpKv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_aJJopLdP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_K82mERSa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_tYxhAs9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VvolOUfR, m);
}

void Heavy_Panoramizer::cVar_5QtG5Wbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_biKSkC5Q_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_raz1Kjex, 0, m, &cIf_raz1Kjex_sendMessage);
}

void Heavy_Panoramizer::cMsg_o7wfwk2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_tYxhAs9a_sendMessage);
}

void Heavy_Panoramizer::cBinop_mR02eekq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AI0Kz9tK, m);
}

void Heavy_Panoramizer::cBinop_F76CLMwT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_o7wfwk2i_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_rj9agwSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TwduOrwB, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kuHgA7TB, m);
}

void Heavy_Panoramizer::cMsg_09rQKo4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9vTRADuE_sendMessage);
}

void Heavy_Panoramizer::cSystem_9vTRADuE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OCEgiPbL_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_026lbeeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_F76CLMwT_sendMessage);
}

void Heavy_Panoramizer::cMsg_OCEgiPbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_mR02eekq_sendMessage);
}

void Heavy_Panoramizer::cMsg_Vb10NIq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_YBJEGc4G_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TwduOrwB, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kuHgA7TB, m);
}

void Heavy_Panoramizer::cBinop_biKSkC5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_raz1Kjex, 1, m, &cIf_raz1Kjex_sendMessage);
}

void Heavy_Panoramizer::cIf_raz1Kjex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Vb10NIq1_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_YBJEGc4G_sendMessage);
      cMsg_Lv4P1o4u_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_Lv4P1o4u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rj9agwSr_sendMessage);
}

void Heavy_Panoramizer::cBinop_YBJEGc4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_026lbeeu_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cRandom_l5OvXg7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_5laKEOHg_sendMessage);
}

void Heavy_Panoramizer::cUnop_8TTO2zyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oYneyoBN, HV_BINOP_MULTIPLY, 0, m, &cBinop_oYneyoBN_sendMessage);
}

void Heavy_Panoramizer::cBinop_5laKEOHg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_8TTO2zyO_sendMessage);
}

void Heavy_Panoramizer::cSlice_KNHMEglg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_l5OvXg7K, 1, m, &cRandom_l5OvXg7K_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_bO8IeFkY_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KNHMEglg, 0, m, &cSlice_KNHMEglg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_l5OvXg7K, 0, m, &cRandom_l5OvXg7K_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_HtTFW9uc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zw8fILe3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_PNB578d8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YvGIMVwV, 0, m, &cSlice_YvGIMVwV_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LYttnEdx, 0, m, &cRandom_LYttnEdx_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_ldKjfdjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hlEqwT8d_sendMessage);
}

void Heavy_Panoramizer::cSlice_YvGIMVwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LYttnEdx, 1, m, &cRandom_LYttnEdx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_hlEqwT8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FaFMwHZU, HV_BINOP_ADD, 0, m, &cBinop_FaFMwHZU_sendMessage);
}

void Heavy_Panoramizer::cRandom_LYttnEdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ldKjfdjd, HV_BINOP_MULTIPLY, 0, m, &cBinop_ldKjfdjd_sendMessage);
}

void Heavy_Panoramizer::cCast_HkIbj9Vk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ZaRJhu4N_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_694VXhvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_05C4gqS9, 2, m, &cDelay_05C4gqS9_sendMessage);
}

void Heavy_Panoramizer::cSystem_meCXpb44_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_21supOcs_sendMessage);
}

void Heavy_Panoramizer::cMsg_Ujma5Fwo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_meCXpb44_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_R92keiWm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_lUNJnwSb_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_lUNJnwSb_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZpzWxx5k_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cDelay_05C4gqS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_05C4gqS9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_05C4gqS9, 0, m, &cDelay_05C4gqS9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AjiMI4Gq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gqQEEud0_sendMessage);
}

void Heavy_Panoramizer::cBinop_21supOcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hnaECZdj, HV_BINOP_MULTIPLY, 1, m, &cBinop_hnaECZdj_sendMessage);
}

void Heavy_Panoramizer::cBinop_hnaECZdj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_694VXhvB_sendMessage);
}

void Heavy_Panoramizer::cCast_ZpzWxx5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lUNJnwSb_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_05C4gqS9, 0, m, &cDelay_05C4gqS9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AjiMI4Gq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gqQEEud0_sendMessage);
}

void Heavy_Panoramizer::cVar_PYb9Xvc9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hnaECZdj, HV_BINOP_MULTIPLY, 0, m, &cBinop_hnaECZdj_sendMessage);
}

void Heavy_Panoramizer::cMsg_lUNJnwSb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_05C4gqS9, 0, m, &cDelay_05C4gqS9_sendMessage);
}

void Heavy_Panoramizer::cPack_WhjWB6Uw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_UAKgNdSl, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_RZyEAznV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AxYXU4OU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UpJbczIO_sendMessage);
}

void Heavy_Panoramizer::cCast_PI2GLu9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_aerWU0eX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cRandom_RemScvzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_SRj6FSKI_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_ZaRJhu4N_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5iw5Ces2, 0, m, &cSlice_5iw5Ces2_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RemScvzi, 0, m, &cRandom_RemScvzi_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_SRj6FSKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_u25gVXGE_sendMessage);
}

void Heavy_Panoramizer::cUnop_u25gVXGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HIEFQgpn, HV_BINOP_MULTIPLY, 0, m, &cBinop_HIEFQgpn_sendMessage);
}

void Heavy_Panoramizer::cSlice_5iw5Ces2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RemScvzi, 1, m, &cRandom_RemScvzi_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_Vq1wKjlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_jtRRuezc, 0, m, &cVar_jtRRuezc_sendMessage);
}

void Heavy_Panoramizer::cCast_6g7NYcgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_slgNIpLk, HV_BINOP_SUBTRACT, 1, m, &cBinop_slgNIpLk_sendMessage);
}

void Heavy_Panoramizer::cUnop_jMbz8kWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qfvtd4IN, HV_BINOP_MULTIPLY, 0, m, &cBinop_qfvtd4IN_sendMessage);
}

void Heavy_Panoramizer::cSlice_LQHU6Ojn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XkJZjj94, 1, m, &cRandom_XkJZjj94_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_NWldlzdx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jMbz8kWN_sendMessage);
}

void Heavy_Panoramizer::cRandom_XkJZjj94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_NWldlzdx_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_shLSDE0M_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LQHU6Ojn, 0, m, &cSlice_LQHU6Ojn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XkJZjj94, 0, m, &cRandom_XkJZjj94_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_M5u09ZGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uXZaLFd3, HV_BINOP_ADD, 0, m, &cBinop_uXZaLFd3_sendMessage);
}

void Heavy_Panoramizer::cSlice_1Wbm2c7y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8AMWl9oR, 1, m, &cRandom_8AMWl9oR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_j2DfUNHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_M5u09ZGX_sendMessage);
}

void Heavy_Panoramizer::cRandom_8AMWl9oR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j2DfUNHv, HV_BINOP_MULTIPLY, 0, m, &cBinop_j2DfUNHv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_gOERzqT2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1Wbm2c7y, 0, m, &cSlice_1Wbm2c7y_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8AMWl9oR, 0, m, &cRandom_8AMWl9oR_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_fvy9phU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_l41vCFsR, 1, m, &cPack_l41vCFsR_sendMessage);
}

void Heavy_Panoramizer::cSlice_N8m2qIRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1JCHZQaT, 1, m, &cRandom_1JCHZQaT_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_7kdVsLd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HSey0fsc, HV_BINOP_ADD, 0, m, &cBinop_HSey0fsc_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_dMO7IrMH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_N8m2qIRq, 0, m, &cSlice_N8m2qIRq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1JCHZQaT, 0, m, &cRandom_1JCHZQaT_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_1JCHZQaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cpCeVm84, HV_BINOP_MULTIPLY, 0, m, &cBinop_cpCeVm84_sendMessage);
}

void Heavy_Panoramizer::cBinop_cpCeVm84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7kdVsLd4_sendMessage);
}

void Heavy_Panoramizer::cBinop_rsSleP6q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rLi4i3w9_sendMessage);
}

void Heavy_Panoramizer::cUnop_rLi4i3w9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZzHRje5A, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZzHRje5A_sendMessage);
}

void Heavy_Panoramizer::cSlice_jEnjtf5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZuB3CFG2, 1, m, &cRandom_ZuB3CFG2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_ZuB3CFG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_rsSleP6q_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_zw8fILe3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jEnjtf5P, 0, m, &cSlice_jEnjtf5P_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ZuB3CFG2, 0, m, &cRandom_ZuB3CFG2_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cPack_l41vCFsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_gYdlB2qX, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_ZF5I7Tr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_m9u76HZ6, 0, m, &cPack_m9u76HZ6_sendMessage);
}

void Heavy_Panoramizer::cBinop_P4HtOh27_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_wsbThzCO, 0, m, &cPack_wsbThzCO_sendMessage);
}

void Heavy_Panoramizer::cMsg_SMeFxT9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ahBhl0GD_sendMessage);
}

void Heavy_Panoramizer::cBinop_vkJvsFB9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BAqxZwh8, 1, m, &cIf_BAqxZwh8_sendMessage);
}

void Heavy_Panoramizer::cIf_BAqxZwh8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2RIIMnlu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_QtPxlvBX_sendMessage);
      cMsg_SMeFxT9d_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_dGSsUbHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yR2Twobv, m);
}

void Heavy_Panoramizer::cMsg_2RIIMnlu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_QtPxlvBX_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eCKXgizN, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7bMqtRaW, m);
}

void Heavy_Panoramizer::cBinop_ycXV6oy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UK7isap2_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_vYYQjND0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_vkJvsFB9_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_BAqxZwh8, 0, m, &cIf_BAqxZwh8_sendMessage);
}

void Heavy_Panoramizer::cMsg_UK7isap2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_dGSsUbHr_sendMessage);
}

void Heavy_Panoramizer::cMsg_28b9wBkR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gEeVpFv6_sendMessage);
}

void Heavy_Panoramizer::cBinop_gEeVpFv6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SrQfCTl3, m);
}

void Heavy_Panoramizer::cBinop_ahBhl0GD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eCKXgizN, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_7bMqtRaW, m);
}

void Heavy_Panoramizer::cMsg_cvmlFNLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ycXV6oy4_sendMessage);
}

void Heavy_Panoramizer::cMsg_ZuztzUYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QXjCucVr_sendMessage);
}

void Heavy_Panoramizer::cSystem_QXjCucVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_28b9wBkR_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_QtPxlvBX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cvmlFNLb_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cUnop_REf19vQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tioICOBO, 0, m, &cVar_tioICOBO_sendMessage);
}

void Heavy_Panoramizer::cBinop_xunQ9pLa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_REf19vQR_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Ghi5Dd5H_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Bmqm0w4H, 0, m, &cSlice_Bmqm0w4H_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DSVrZ535, 0, m, &cRandom_DSVrZ535_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_Bmqm0w4H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DSVrZ535, 1, m, &cRandom_DSVrZ535_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_DSVrZ535_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_xunQ9pLa_sendMessage);
}

void Heavy_Panoramizer::cBinop_ASfanXvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_azGgU7FY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0rbwLNa7_sendMessage);
}

void Heavy_Panoramizer::cCast_YcKSY7rC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rWkwEmHA_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cPack_udwhr5qK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_yvNSvGVa, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_n0qS0I41_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ldKjfdjd, HV_BINOP_MULTIPLY, 1, m, &cBinop_ldKjfdjd_sendMessage);
}

void Heavy_Panoramizer::cCast_azGgU7FY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GFrqeqUu, HV_BINOP_SUBTRACT, 1, m, &cBinop_GFrqeqUu_sendMessage);
}

void Heavy_Panoramizer::cMsg_mmBFjxZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wiYGx1W2_sendMessage);
}

void Heavy_Panoramizer::cSystem_wiYGx1W2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yEqvHxqU_sendMessage);
}

void Heavy_Panoramizer::cDelay_qiC7WEyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_qiC7WEyl, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qiC7WEyl, 0, m, &cDelay_qiC7WEyl_sendMessage);
  cSwitchcase_jjuMOrPN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_nWdDGwzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_12j1RkqR_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_qiC7WEyl, 0, m, &cDelay_qiC7WEyl_sendMessage);
  cSwitchcase_jjuMOrPN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_yEqvHxqU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bnCaMEka, HV_BINOP_MULTIPLY, 1, m, &cBinop_bnCaMEka_sendMessage);
}

void Heavy_Panoramizer::cBinop_bnCaMEka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_omTXN6Xk_sendMessage);
}

void Heavy_Panoramizer::cMsg_12j1RkqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_qiC7WEyl, 0, m, &cDelay_qiC7WEyl_sendMessage);
}

void Heavy_Panoramizer::cVar_GlFGFJVw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bnCaMEka, HV_BINOP_MULTIPLY, 0, m, &cBinop_bnCaMEka_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_BuDdufZn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_12j1RkqR_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_12j1RkqR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nWdDGwzO_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_omTXN6Xk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_qiC7WEyl, 2, m, &cDelay_qiC7WEyl_sendMessage);
}

void Heavy_Panoramizer::cPack_KIZvesAc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_MCh6dNEm, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_ozu1Sw62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7NKFoctD, HV_BINOP_SUBTRACT, 0, m, &cBinop_7NKFoctD_sendMessage);
}

void Heavy_Panoramizer::cCast_bzGdmpzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_shLSDE0M_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_A3qIYV2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WhOK7LwQ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_WD6Srns9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6g7NYcgC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A3qIYV2u_sendMessage);
}

void Heavy_Panoramizer::cMsg_k38JUeIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_2o3UhK8K, 0, m, &cVar_2o3UhK8K_sendMessage);
}

void Heavy_Panoramizer::cCast_bTUPnoxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2kpIfmLX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_Bq0i3SFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Dl26kkEH, HV_BINOP_SUBTRACT, 1, m, &cBinop_Dl26kkEH_sendMessage);
}

void Heavy_Panoramizer::cCast_WqNoLpfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GXNQ8Dw5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_oYneyoBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KIZvesAc, 1, m, &cPack_KIZvesAc_sendMessage);
}

void Heavy_Panoramizer::cBinop_J8Sg49zj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Bq0i3SFA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YcKSY7rC_sendMessage);
}

void Heavy_Panoramizer::cBinop_lWNMJDWk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0l9wiIkG_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_ebWxwsG7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RMsbSsAm, 0, m, &cSlice_RMsbSsAm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Px1GNWtq, 0, m, &cRandom_Px1GNWtq_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_RMsbSsAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Px1GNWtq, 1, m, &cRandom_Px1GNWtq_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_0l9wiIkG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mln0cGd3, 0, m, &cVar_mln0cGd3_sendMessage);
}

void Heavy_Panoramizer::cRandom_Px1GNWtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_lWNMJDWk_sendMessage);
}

void Heavy_Panoramizer::cRandom_XfA1tl8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fWB0R7qI, HV_BINOP_MULTIPLY, 0, m, &cBinop_fWB0R7qI_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_7jthlt4q_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SIhymDH9, 0, m, &cSlice_SIhymDH9_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XfA1tl8a, 0, m, &cRandom_XfA1tl8a_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_SIhymDH9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XfA1tl8a, 1, m, &cRandom_XfA1tl8a_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_fWB0R7qI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_v1dafGXT_sendMessage);
}

void Heavy_Panoramizer::cUnop_v1dafGXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6et0sILy, HV_BINOP_ADD, 0, m, &cBinop_6et0sILy_sendMessage);
}

void Heavy_Panoramizer::cCast_xqi0Ald2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GbF7kvjv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_rZAVO4b7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_oWTSJfF2_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rljGylkW, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rSFSZWfE, m);
}

void Heavy_Panoramizer::cBinop_oWTSJfF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_61ZiJJo0_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_61ZiJJo0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_LHCECLMp_sendMessage);
}

void Heavy_Panoramizer::cBinop_XeRJUGbT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_9zitgxmg, 1, m, &cIf_9zitgxmg_sendMessage);
}

void Heavy_Panoramizer::cIf_9zitgxmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rZAVO4b7_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_oWTSJfF2_sendMessage);
      cMsg_SiixkzVs_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_JSTt58WH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mtnaNdsw, m);
}

void Heavy_Panoramizer::cMsg_SiixkzVs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_3dFuam5w_sendMessage);
}

void Heavy_Panoramizer::cMsg_PnWH3GkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_pSmUQPuX_sendMessage);
}

void Heavy_Panoramizer::cBinop_LHCECLMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PnWH3GkN_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_bxg4xK2S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_XeRJUGbT_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_9zitgxmg, 0, m, &cIf_9zitgxmg_sendMessage);
}

void Heavy_Panoramizer::cBinop_3dFuam5w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rljGylkW, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_rSFSZWfE, m);
}

void Heavy_Panoramizer::cBinop_pSmUQPuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HLao1xcE, m);
}

void Heavy_Panoramizer::cMsg_bgUS2I2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JSTt58WH_sendMessage);
}

void Heavy_Panoramizer::cMsg_E4QxRxSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h5bJ2KE5_sendMessage);
}

void Heavy_Panoramizer::cSystem_h5bJ2KE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bgUS2I2Q_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_UpJbczIO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6tVqXWnT_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_zaUjTJ2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XZB81YM6_sendMessage);
}

void Heavy_Panoramizer::cMsg_w2bRUR5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_n1mBULxi, 0, m, &cDelay_n1mBULxi_sendMessage);
}

void Heavy_Panoramizer::cBinop_XZB81YM6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_n1mBULxi, 2, m, &cDelay_n1mBULxi_sendMessage);
}

void Heavy_Panoramizer::cDelay_n1mBULxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_n1mBULxi, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n1mBULxi, 0, m, &cDelay_n1mBULxi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WqNoLpfc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2K9Sx8sW_sendMessage);
}

void Heavy_Panoramizer::cVar_tioICOBO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zaUjTJ2X, HV_BINOP_MULTIPLY, 0, m, &cBinop_zaUjTJ2X_sendMessage);
}

void Heavy_Panoramizer::cBinop_P8lPIqVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zaUjTJ2X, HV_BINOP_MULTIPLY, 1, m, &cBinop_zaUjTJ2X_sendMessage);
}

void Heavy_Panoramizer::cCast_2UWltXDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w2bRUR5e_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_n1mBULxi, 0, m, &cDelay_n1mBULxi_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WqNoLpfc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2K9Sx8sW_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_O6y1J8Kb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_w2bRUR5e_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_w2bRUR5e_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2UWltXDS_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_OW2BAoQQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YbPeBUSP_sendMessage);
}

void Heavy_Panoramizer::cSystem_YbPeBUSP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_P8lPIqVD_sendMessage);
}

void Heavy_Panoramizer::cCast_2K9Sx8sW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_N5TyPkpK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_VYJKHuzE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ex7NYNz5_sendMessage);
}

void Heavy_Panoramizer::cDelay_jhWSsKo5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jhWSsKo5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhWSsKo5, 0, m, &cDelay_jhWSsKo5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pYguRCjw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X0tQjJRK_sendMessage);
}

void Heavy_Panoramizer::cVar_wG8gMr2g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VYJKHuzE, HV_BINOP_MULTIPLY, 0, m, &cBinop_VYJKHuzE_sendMessage);
}

void Heavy_Panoramizer::cMsg_7ksbRluU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhWSsKo5, 0, m, &cDelay_jhWSsKo5_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_YIsxOE7v_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_7ksbRluU_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_7ksbRluU_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AQFbrsT4_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_si19XObh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VYJKHuzE, HV_BINOP_MULTIPLY, 1, m, &cBinop_VYJKHuzE_sendMessage);
}

void Heavy_Panoramizer::cSystem_PYcwRtAL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_si19XObh_sendMessage);
}

void Heavy_Panoramizer::cMsg_HS2GNovr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PYcwRtAL_sendMessage);
}

void Heavy_Panoramizer::cCast_AQFbrsT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7ksbRluU_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhWSsKo5, 0, m, &cDelay_jhWSsKo5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pYguRCjw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X0tQjJRK_sendMessage);
}

void Heavy_Panoramizer::cBinop_ex7NYNz5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jhWSsKo5, 2, m, &cDelay_jhWSsKo5_sendMessage);
}

void Heavy_Panoramizer::cSystem_In6GBlus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M0IJ9aIQ_sendMessage);
}

void Heavy_Panoramizer::cMsg_m3JJ7aIb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_In6GBlus_sendMessage);
}

void Heavy_Panoramizer::cMsg_PTQSAfLL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DY9o92ME, 0, m, &cDelay_DY9o92ME_sendMessage);
}

void Heavy_Panoramizer::cBinop_5SuSHTA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_EZHPO43K_sendMessage);
}

void Heavy_Panoramizer::cDelay_DY9o92ME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DY9o92ME, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DY9o92ME, 0, m, &cDelay_DY9o92ME_sendMessage);
  cSwitchcase_FwLweLqp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_6BpuYxRj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_PTQSAfLL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_PTQSAfLL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F16IolZ5_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_EZHPO43K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DY9o92ME, 2, m, &cDelay_DY9o92ME_sendMessage);
}

void Heavy_Panoramizer::cBinop_M0IJ9aIQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5SuSHTA0, HV_BINOP_MULTIPLY, 1, m, &cBinop_5SuSHTA0_sendMessage);
}

void Heavy_Panoramizer::cCast_F16IolZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PTQSAfLL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DY9o92ME, 0, m, &cDelay_DY9o92ME_sendMessage);
  cSwitchcase_FwLweLqp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_2jdf0w2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5SuSHTA0, HV_BINOP_MULTIPLY, 0, m, &cBinop_5SuSHTA0_sendMessage);
}

void Heavy_Panoramizer::cSlice_dKOrWxGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nXOTMVjc, 1, m, &cRandom_nXOTMVjc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_nXOTMVjc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IXpsyChQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_IXpsyChQ_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_2kpIfmLX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dKOrWxGV, 0, m, &cSlice_dKOrWxGV_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_nXOTMVjc, 0, m, &cRandom_nXOTMVjc_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_IXpsyChQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_NXYpJFd4_sendMessage);
}

void Heavy_Panoramizer::cUnop_NXYpJFd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vpkbrOwk, HV_BINOP_ADD, 0, m, &cBinop_vpkbrOwk_sendMessage);
}

void Heavy_Panoramizer::cBinop_5LuGL8PS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_I8qij9Me, HV_BINOP_MULTIPLY, 1, m, &cBinop_I8qij9Me_sendMessage);
}

void Heavy_Panoramizer::cMsg_6tVqXWnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GgJUFsrq, HV_BINOP_SUBTRACT, 0, m, &cBinop_GgJUFsrq_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_WPaQxTuP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fmVsWj56, 0, m, &cSlice_fmVsWj56_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Mb3Oom6d, 0, m, &cRandom_Mb3Oom6d_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_XuXsX8DX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_aQor39dx_sendMessage);
}

void Heavy_Panoramizer::cRandom_Mb3Oom6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_XuXsX8DX_sendMessage);
}

void Heavy_Panoramizer::cSlice_fmVsWj56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Mb3Oom6d, 1, m, &cRandom_Mb3Oom6d_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_aQor39dx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ttXFDuzc, 0, m, &cVar_ttXFDuzc_sendMessage);
}

void Heavy_Panoramizer::cMsg_iYTnrkZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bxg4xK2S, 0, m, &cVar_bxg4xK2S_sendMessage);
}

void Heavy_Panoramizer::cMsg_tDsGEE0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WSJfHmoD, HV_BINOP_SUBTRACT, 0, m, &cBinop_WSJfHmoD_sendMessage);
}

void Heavy_Panoramizer::cBinop_slgNIpLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IXpsyChQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_IXpsyChQ_sendMessage);
}

void Heavy_Panoramizer::cBinop_6jlMtAi6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Q1qJUBfb_sendMessage);
}

void Heavy_Panoramizer::cBinop_Q1qJUBfb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PFAf8B3M, 2, m, &cDelay_PFAf8B3M_sendMessage);
}

void Heavy_Panoramizer::cDelay_PFAf8B3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PFAf8B3M, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PFAf8B3M, 0, m, &cDelay_PFAf8B3M_sendMessage);
  cSwitchcase_bMBHJfc6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_vNmIwWFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jlMtAi6, HV_BINOP_MULTIPLY, 0, m, &cBinop_6jlMtAi6_sendMessage);
}

void Heavy_Panoramizer::cMsg_UF41GRX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PFAf8B3M, 0, m, &cDelay_PFAf8B3M_sendMessage);
}

void Heavy_Panoramizer::cMsg_u70Hhzb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6gHaZzqQ_sendMessage);
}

void Heavy_Panoramizer::cSystem_6gHaZzqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5BwTuD99_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_YnFKZdF2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_UF41GRX9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_UF41GRX9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AAKsfYFJ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_AAKsfYFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UF41GRX9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PFAf8B3M, 0, m, &cDelay_PFAf8B3M_sendMessage);
  cSwitchcase_bMBHJfc6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_5BwTuD99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jlMtAi6, HV_BINOP_MULTIPLY, 1, m, &cBinop_6jlMtAi6_sendMessage);
}

void Heavy_Panoramizer::cMsg_bKdFPFTu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5LuGL8PS, HV_BINOP_SUBTRACT, 0, m, &cBinop_5LuGL8PS_sendMessage);
}

void Heavy_Panoramizer::cCast_FhXlAlzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7NKFoctD, HV_BINOP_SUBTRACT, 1, m, &cBinop_7NKFoctD_sendMessage);
}

void Heavy_Panoramizer::cMsg_Ohs3raOm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_FMhkvfZ7, HV_BINOP_SUBTRACT, 0, m, &cBinop_FMhkvfZ7_sendMessage);
}

void Heavy_Panoramizer::cMsg_UjQodQme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_iOA5Ex6i, 0, m, &cVar_iOA5Ex6i_sendMessage);
}

void Heavy_Panoramizer::cBinop_iClR2TYt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_75QMmmnb, HV_BINOP_MULTIPLY, 1, m, &cBinop_75QMmmnb_sendMessage);
}

void Heavy_Panoramizer::cMsg_XV7dBGTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mrKZljmA, 0, m, &cDelay_mrKZljmA_sendMessage);
}

void Heavy_Panoramizer::cSystem_2F0aaLUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iClR2TYt_sendMessage);
}

void Heavy_Panoramizer::cMsg_5q1jvdmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2F0aaLUJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_cgoxjG93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mrKZljmA, 2, m, &cDelay_mrKZljmA_sendMessage);
}

void Heavy_Panoramizer::cVar_ttXFDuzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_75QMmmnb, HV_BINOP_MULTIPLY, 0, m, &cBinop_75QMmmnb_sendMessage);
}

void Heavy_Panoramizer::cCast_BPvF43IE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XV7dBGTQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mrKZljmA, 0, m, &cDelay_mrKZljmA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eyDvkH6I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cPhyJW9T_sendMessage);
}

void Heavy_Panoramizer::cBinop_75QMmmnb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_cgoxjG93_sendMessage);
}

void Heavy_Panoramizer::cDelay_mrKZljmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mrKZljmA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mrKZljmA, 0, m, &cDelay_mrKZljmA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eyDvkH6I_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cPhyJW9T_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_aJ6QqlvC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_XV7dBGTQ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_XV7dBGTQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BPvF43IE_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_Dl26kkEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M9IEeWwJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_M9IEeWwJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_FxYkz8yh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_udwhr5qK, 0, m, &cPack_udwhr5qK_sendMessage);
}

void Heavy_Panoramizer::cMsg_EfMraEEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_0az9ip3A_sendMessage);
}

void Heavy_Panoramizer::cMsg_XenwtuIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_4bkBmRWG_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_A8THGL24, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_90ETYJlY, m);
}

void Heavy_Panoramizer::cMsg_zOElbMh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_eFSX3E8i_sendMessage);
}

void Heavy_Panoramizer::cBinop_eFSX3E8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_d8oqa1r9, m);
}

void Heavy_Panoramizer::cBinop_ccEnHdpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zOElbMh4_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_UQfVELhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_FHhzWv1V_sendMessage);
}

void Heavy_Panoramizer::cIf_u9YSDI4k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_XenwtuIk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_4bkBmRWG_sendMessage);
      cMsg_EfMraEEx_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_606M6LBC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_u9YSDI4k, 1, m, &cIf_u9YSDI4k_sendMessage);
}

void Heavy_Panoramizer::cSystem_7nm8JTfH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UQfVELhE_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_b03qO3cH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7nm8JTfH_sendMessage);
}

void Heavy_Panoramizer::cBinop_0az9ip3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_A8THGL24, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_90ETYJlY, m);
}

void Heavy_Panoramizer::cMsg_YGaLkCeo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ccEnHdpd_sendMessage);
}

void Heavy_Panoramizer::cVar_iOA5Ex6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_606M6LBC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_u9YSDI4k, 0, m, &cIf_u9YSDI4k_sendMessage);
}

void Heavy_Panoramizer::cBinop_4bkBmRWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YGaLkCeo_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_FHhzWv1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YsLvlxiY, m);
}

void Heavy_Panoramizer::cCast_AjiMI4Gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_bO8IeFkY_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_gFDvGSEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_WLRACdN4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_taAivNkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ozu1Sw62_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_pLsPSDst_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3zTXH5Ig_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cIf_qOJ1SvGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_FMOC3DUz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Tar1uvpR_sendMessage);
      cMsg_PsDoeKdd_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_mnYhld3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_qOJ1SvGO, 1, m, &cIf_qOJ1SvGO_sendMessage);
}

void Heavy_Panoramizer::cBinop_z4fE8X6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zeiRvpwP_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_50jXsnjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_z3LWs79X, m);
}

void Heavy_Panoramizer::cMsg_vLU7gEm5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_z4fE8X6d_sendMessage);
}

void Heavy_Panoramizer::cMsg_nooJDRrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_uLXpVeMA_sendMessage);
}

void Heavy_Panoramizer::cVar_mfh25uWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_mnYhld3u_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_qOJ1SvGO, 0, m, &cIf_qOJ1SvGO_sendMessage);
}

void Heavy_Panoramizer::cMsg_FMOC3DUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Tar1uvpR_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QdFVvAfq, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xJslgZFD, m);
}

void Heavy_Panoramizer::cBinop_uLXpVeMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QP7tdi3A, m);
}

void Heavy_Panoramizer::cMsg_PsDoeKdd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pO8jygEv_sendMessage);
}

void Heavy_Panoramizer::cBinop_pO8jygEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QdFVvAfq, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_xJslgZFD, m);
}

void Heavy_Panoramizer::cBinop_Tar1uvpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vLU7gEm5_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSystem_ZPYr3VN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nooJDRrt_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_1jfkAmiT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZPYr3VN3_sendMessage);
}

void Heavy_Panoramizer::cMsg_zeiRvpwP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_50jXsnjF_sendMessage);
}

void Heavy_Panoramizer::cCast_tH7cOqKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7jthlt4q_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSystem_DVrp72PQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_TK9j2tnF_sendMessage);
}

void Heavy_Panoramizer::cMsg_J65snLsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DVrp72PQ_sendMessage);
}

void Heavy_Panoramizer::cBinop_TK9j2tnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9bejl0Ef, HV_BINOP_MULTIPLY, 1, m, &cBinop_9bejl0Ef_sendMessage);
}

void Heavy_Panoramizer::cMsg_5hDAZVcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kTBG1YJp, 0, m, &cDelay_kTBG1YJp_sendMessage);
}

void Heavy_Panoramizer::cCast_MVTcaDt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5hDAZVcC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kTBG1YJp, 0, m, &cDelay_kTBG1YJp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xqi0Ald2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gFDvGSEk_sendMessage);
}

void Heavy_Panoramizer::cBinop_FDGrROG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kTBG1YJp, 2, m, &cDelay_kTBG1YJp_sendMessage);
}

void Heavy_Panoramizer::cDelay_kTBG1YJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kTBG1YJp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kTBG1YJp, 0, m, &cDelay_kTBG1YJp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xqi0Ald2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gFDvGSEk_sendMessage);
}

void Heavy_Panoramizer::cVar_ERgMZfOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9bejl0Ef, HV_BINOP_MULTIPLY, 0, m, &cBinop_9bejl0Ef_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_pDLLKV8L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_5hDAZVcC_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_5hDAZVcC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MVTcaDt3_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_9bejl0Ef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FDGrROG1_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_QSETQVKB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_42h38zDN_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_42h38zDN_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LUbbKaNY_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_ferHxxur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_afbeomuB, HV_BINOP_MULTIPLY, 0, m, &cBinop_afbeomuB_sendMessage);
}

void Heavy_Panoramizer::cBinop_tusrD5Gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_c5ybgceB, 2, m, &cDelay_c5ybgceB_sendMessage);
}

void Heavy_Panoramizer::cCast_LUbbKaNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_42h38zDN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c5ybgceB, 0, m, &cDelay_c5ybgceB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HtTFW9uc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YR65yyvH_sendMessage);
}

void Heavy_Panoramizer::cDelay_c5ybgceB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_c5ybgceB, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_c5ybgceB, 0, m, &cDelay_c5ybgceB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HtTFW9uc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YR65yyvH_sendMessage);
}

void Heavy_Panoramizer::cMsg_2CTYc4Fi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7sG8cR87_sendMessage);
}

void Heavy_Panoramizer::cSystem_7sG8cR87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_N9Ckt7Qp_sendMessage);
}

void Heavy_Panoramizer::cBinop_N9Ckt7Qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_afbeomuB, HV_BINOP_MULTIPLY, 1, m, &cBinop_afbeomuB_sendMessage);
}

void Heavy_Panoramizer::cMsg_42h38zDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_c5ybgceB, 0, m, &cDelay_c5ybgceB_sendMessage);
}

void Heavy_Panoramizer::cBinop_afbeomuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_tusrD5Gq_sendMessage);
}

void Heavy_Panoramizer::cBinop_FaFMwHZU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Hm2D2lw5, 0, m, &cPack_Hm2D2lw5_sendMessage);
}

void Heavy_Panoramizer::cCast_nDmozohD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_us1XHbtO, HV_BINOP_SUBTRACT, 1, m, &cBinop_us1XHbtO_sendMessage);
}

void Heavy_Panoramizer::cMsg_oSOTUtBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.06f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TmrXnmvZ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_jBzWeCnl, m);
}

void Heavy_Panoramizer::cSlice_usRvc5tx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_5wDEuOKv_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_5wDEuOKv_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_oNSWNxVy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gHP8NTcH, 0, m, &cSlice_gHP8NTcH_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_usRvc5tx, 0, m, &cSlice_usRvc5tx_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_gHP8NTcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oSOTUtBi_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_oSOTUtBi_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}




/*
 * Context Process Implementation
 */

int Heavy_Panoramizer::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12, Bf13, Bf14, Bf15, Bf16, Bf17, Bf18, Bf19, Bf20, Bf21, Bf22;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_APBMFKji, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_9LVe71wa, VOf(Bf4));
    __hv_fms_f(VIf(Bf3), VIf(Bf4), VIf(Bf2), VOf(Bf4));
    __hv_varread_f(&sVarf_LA6VwDJJ, VOf(Bf3));
    __hv_zero_f(VOf(Bf5));
    __hv_neq_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_min_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf2));
    __hv_varread_f(&sVarf_TY1eTrWJ, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf1), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf2));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_cpole_f(&sCPole_IgNfH7rJ, VIf(Bf5), VIf(ZERO), VIf(Bf8), VIf(Bf6), VOf(Bf6), VOf(Bf8));
    __hv_line_f(&sLine_CuqrGXEv, VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_Jl2LlAW6, VIf(Bf5));
    __hv_var_k_f(VOf(Bf5), 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f);
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_j9RWhhvD, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_RIzHLBIO, VOf(Bf1));
    __hv_fms_f(VIf(Bf3), VIf(Bf1), VIf(Bf4), VOf(Bf1));
    __hv_varread_f(&sVarf_gBDlFIes, VOf(Bf3));
    __hv_zero_f(VOf(Bf7));
    __hv_neq_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf1));
    __hv_min_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf4));
    __hv_varread_f(&sVarf_7PbISZrq, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf5), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf5));
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_cpole_f(&sCPole_CT7FbXRB, VIf(Bf7), VIf(ZERO), VIf(Bf10), VIf(Bf2), VOf(Bf2), VOf(Bf10));
    __hv_line_f(&sLine_OBW7HPwg, VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varwrite_f(&sVarf_SaBo3uD2, VIf(Bf7));
    __hv_var_k_f(VOf(Bf7), 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_lOTUctdd, VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_TEwGdxac, VOf(Bf5));
    __hv_fms_f(VIf(Bf3), VIf(Bf5), VIf(Bf1), VOf(Bf5));
    __hv_varread_f(&sVarf_y1RscVmb, VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_neq_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf5));
    __hv_min_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf1));
    __hv_varread_f(&sVarf_IrhOuGAu, VOf(Bf9));
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf7), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf1), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf7));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_cpole_f(&sCPole_8O8SAtQ8, VIf(Bf9), VIf(ZERO), VIf(Bf12), VIf(Bf4), VOf(Bf4), VOf(Bf12));
    __hv_line_f(&sLine_6IpjrVLG, VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_XTVcualp, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_QWhW5F3n, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_TndXOlKD, VOf(Bf7));
    __hv_fms_f(VIf(Bf3), VIf(Bf7), VIf(Bf5), VOf(Bf7));
    __hv_varread_f(&sVarf_pA5d4SXT, VOf(Bf3));
    __hv_zero_f(VOf(Bf11));
    __hv_neq_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf7));
    __hv_min_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf5), VIf(Bf7), VOf(Bf5));
    __hv_varread_f(&sVarf_kjcgFWTw, VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf9), VOf(Bf5));
    __hv_sub_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf13), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf14), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf5), VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf9));
    __hv_sub_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_abs_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf13), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf13), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf13), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf9), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_cpole_f(&sCPole_FEbliNND, VIf(Bf11), VIf(ZERO), VIf(Bf14), VIf(Bf1), VOf(Bf1), VOf(Bf14));
    __hv_line_f(&sLine_PwvaKAuJ, VOf(Bf14));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_f(&sVarf_Ny2wrpUd, VIf(Bf11));
    __hv_var_k_f(VOf(Bf11), 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f);
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_cwZOkSiK, VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_2iHG6fD0, VOf(Bf9));
    __hv_fms_f(VIf(Bf3), VIf(Bf9), VIf(Bf7), VOf(Bf9));
    __hv_varread_f(&sVarf_6chEvmhY, VOf(Bf3));
    __hv_zero_f(VOf(Bf13));
    __hv_neq_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_zero_f(VOf(Bf9));
    __hv_min_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf7), VIf(Bf9), VOf(Bf7));
    __hv_varread_f(&sVarf_wtRFW9Kf, VOf(Bf13));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf11), VOf(Bf7));
    __hv_sub_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf7));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf15), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf7), VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_floor_f(VIf(Bf15), VOf(Bf11));
    __hv_sub_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf15), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_abs_f(VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf15), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf15), VOf(Bf11));
    __hv_mul_f(VIf(Bf15), VIf(Bf11), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf11), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_MbNHaWs6, VIf(Bf13), VIf(ZERO), VIf(Bf16), VIf(Bf5), VOf(Bf5), VOf(Bf16));
    __hv_line_f(&sLine_LQy9vOAf, VOf(Bf16));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_neg_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_Wt1s3EGB, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f);
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_6gSnK3a4, VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_a45I1UQC, VOf(Bf11));
    __hv_fms_f(VIf(Bf3), VIf(Bf11), VIf(Bf13), VOf(Bf11));
    __hv_varread_f(&sVarf_VtKcETzo, VOf(Bf3));
    __hv_zero_f(VOf(Bf15));
    __hv_neq_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_zero_f(VOf(Bf11));
    __hv_min_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf13), VIf(Bf11), VOf(Bf13));
    __hv_varread_f(&sVarf_vAT1Sc6s, VOf(Bf15));
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_floor_f(VIf(Bf9), VOf(Bf13));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf13));
    __hv_mul_f(VIf(Bf3), VIf(Bf13), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf3), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf13), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf9));
    __hv_sub_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf9));
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf17), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf9), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_cpole_f(&sCPole_G1QAVZbi, VIf(Bf15), VIf(ZERO), VIf(Bf18), VIf(Bf7), VOf(Bf7), VOf(Bf18));
    __hv_line_f(&sLine_o0gZgzLz, VOf(Bf18));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_U0UbiIz3, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f);
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_fpzG3h0q, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ecKAvRmN, VOf(Bf9));
    __hv_fms_f(VIf(Bf3), VIf(Bf9), VIf(Bf11), VOf(Bf9));
    __hv_varread_f(&sVarf_1FMmiAdi, VOf(Bf3));
    __hv_zero_f(VOf(Bf17));
    __hv_neq_f(VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf9));
    __hv_min_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf11), VIf(Bf9), VOf(Bf11));
    __hv_varread_f(&sVarf_IWBimtcf, VOf(Bf17));
    __hv_mul_f(VIf(Bf11), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf15), VOf(Bf11));
    __hv_sub_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf11));
    __hv_mul_f(VIf(Bf3), VIf(Bf11), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf19), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf20), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_sub_f(VIf(Bf3), VIf(Bf20), VOf(Bf20));
    __hv_fma_f(VIf(Bf11), VIf(Bf19), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf9), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf19), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf19), VOf(Bf15));
    __hv_sub_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf19), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_abs_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf19), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf19), VOf(Bf15));
    __hv_mul_f(VIf(Bf19), VIf(Bf15), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf19), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf15), VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_cpole_f(&sCPole_r8jtVWjr, VIf(Bf17), VIf(ZERO), VIf(Bf20), VIf(Bf13), VOf(Bf13), VOf(Bf20));
    __hv_line_f(&sLine_BGOwlXRv, VOf(Bf20));
    __hv_var_k_f(VOf(Bf17), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf20), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_varwrite_f(&sVarf_VyShZwls, VIf(Bf17));
    __hv_var_k_f(VOf(Bf17), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_neg_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf8), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varwrite_f(&sVarf_Uk7dL6UX, VIf(Bf8));
    __hv_var_k_f(VOf(Bf8), 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_OElDt3zM, VOf(Bf8));
    __hv_mul_f(VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf17), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_w3JvETUq, VOf(Bf9));
    __hv_fms_f(VIf(Bf17), VIf(Bf9), VIf(Bf6), VOf(Bf9));
    __hv_varread_f(&sVarf_vBEQvp1O, VOf(Bf17));
    __hv_zero_f(VOf(Bf3));
    __hv_neq_f(VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_min_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf6));
    __hv_varread_f(&sVarf_K4x2IeDj, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf8), VOf(Bf6));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf6));
    __hv_mul_f(VIf(Bf17), VIf(Bf6), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf19), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf17), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf6), VIf(Bf19), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf19), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf19), VOf(Bf8));
    __hv_sub_f(VIf(Bf19), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf19), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf19), VOf(Bf19));
    __hv_abs_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf19), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf19), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf8), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf19), VOf(Bf8));
    __hv_mul_f(VIf(Bf19), VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf8), VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_cpole_f(&sCPole_MPMPRzse, VIf(Bf3), VIf(ZERO), VIf(Bf11), VIf(Bf15), VOf(Bf15), VOf(Bf11));
    __hv_line_f(&sLine_M1XQKarV, VOf(Bf11));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_1MJVepyB, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_QvSVkke0, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_neg_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_varwrite_f(&sVarf_uP69yyM9, VIf(Bf18));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf20), VIf(Bf18), VOf(Bf18));
    __hv_neg_f(VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf20), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf18), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_varwrite_f(&sVarf_qZCovVpH, VIf(Bf20));
    __hv_var_k_f(VOf(Bf20), 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f);
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf18));
    __hv_max_f(VIf(Bf20), VIf(Bf18), VOf(Bf18));
    __hv_varread_f(&sVarf_NaVGb5do, VOf(Bf20));
    __hv_mul_f(VIf(Bf18), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf18), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf20), VIf(Bf18), VOf(Bf18));
    __hv_varread_f(&sVarf_Vb2RNPC4, VOf(Bf7));
    __hv_fms_f(VIf(Bf18), VIf(Bf7), VIf(Bf13), VOf(Bf7));
    __hv_varread_f(&sVarf_ObIvSq7R, VOf(Bf18));
    __hv_zero_f(VOf(Bf9));
    __hv_neq_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf7));
    __hv_min_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf13), VIf(Bf7), VOf(Bf13));
    __hv_varread_f(&sVarf_Q8tLslKo, VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf20), VOf(Bf13));
    __hv_sub_f(VIf(Bf20), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf18), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_abs_f(VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf18), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf18), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf18), VOf(Bf13));
    __hv_mul_f(VIf(Bf18), VIf(Bf13), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf18), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf13), VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf20), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf20));
    __hv_sub_f(VIf(Bf11), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf20), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf20), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf20), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf20));
    __hv_mul_f(VIf(Bf11), VIf(Bf20), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf18), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf20), VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf7), VIf(Bf15), VOf(Bf15));
    __hv_cpole_f(&sCPole_FZoywQ0j, VIf(Bf9), VIf(ZERO), VIf(Bf3), VIf(Bf15), VOf(Bf15), VOf(Bf3));
    __hv_line_f(&sLine_fH1Ocu9h, VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_neg_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_varwrite_f(&sVarf_Lr6cuGEp, VIf(Bf7));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_1kTAQ7Qc, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf7));
    __hv_max_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_HtsEBYby, VOf(Bf10));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_BSDGpvoj, VOf(Bf9));
    __hv_fms_f(VIf(Bf7), VIf(Bf9), VIf(Bf2), VOf(Bf9));
    __hv_varread_f(&sVarf_l9QXFGs6, VOf(Bf7));
    __hv_zero_f(VOf(Bf18));
    __hv_neq_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_and_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_zero_f(VOf(Bf9));
    __hv_min_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf2), VIf(Bf9), VOf(Bf2));
    __hv_varread_f(&sVarf_VSfB8RMv, VOf(Bf18));
    __hv_mul_f(VIf(Bf2), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf0), VIf(Bf18), VOf(Bf18));
    __hv_floor_f(VIf(Bf10), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf20), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf0), VIf(Bf20), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf20), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf20), VOf(Bf20));
    __hv_floor_f(VIf(Bf20), VOf(Bf10));
    __hv_sub_f(VIf(Bf20), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf20), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf20), VOf(Bf20));
    __hv_abs_f(VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf20), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf20), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf20), VIf(Bf20), VOf(Bf10));
    __hv_mul_f(VIf(Bf20), VIf(Bf10), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf20), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf10), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_cpole_f(&sCPole_aGLcYNmy, VIf(Bf18), VIf(ZERO), VIf(Bf11), VIf(Bf7), VOf(Bf7), VOf(Bf11));
    __hv_line_f(&sLine_lLnI9Nmg, VOf(Bf11));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_varwrite_f(&sVarf_tqq9DMNI, VIf(Bf18));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_neg_f(VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf18), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_f(&sVarf_xonWnJsw, VIf(Bf11));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf15), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_f(&sVarf_QFtGY4tK, VIf(Bf11));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf16), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_f(&sVarf_iBOpglHC, VIf(Bf11));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_neg_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf14), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_varwrite_f(&sVarf_klqNpYro, VIf(Bf14));
    __hv_var_k_f(VOf(Bf14), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf12), VIf(Bf14), VOf(Bf14));
    __hv_neg_f(VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf12), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf14), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varwrite_f(&sVarf_lc1diS7u, VIf(Bf12));
    sEnv_process(this, &sEnv_vIzZ7sP9, VIf(I1), &sEnv_vIzZ7sP9_sendMessage);
    __hv_varread_f(&sVarf_aBjHetzF, VOf(Bf12));
    __hv_varread_f(&sVarf_78Fk8XkG, VOf(Bf4));
    __hv_varread_f(&sVarf_pS4aubSM, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_Ta339XnH, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_2DXrbhqo, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_Q0bkAGYI, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_81vSDxJr, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_kOUyotFF, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_zs2ARHXv, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_mUYmoWiJ, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_1MJVepyB, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_qZCovVpH, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_xonWnJsw, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_klqNpYro, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_1kTAQ7Qc, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_Lr6cuGEp, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_uP69yyM9, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_Wt1s3EGB, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_lc1diS7u, VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_Uk7dL6UX, VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_TmrXnmvZ, VOf(Bf12));
    __hv_mul_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_xRn2VEfP, VOf(Bf4));
    __hv_varread_f(&sVarf_TVNMH30m, VOf(Bf14));
    __hv_mul_f(VIf(I1), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf12), VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf14), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_lHvWODSY, VOf(Bf14));
    __hv_varread_f(&sVarf_UbwVENHw, VOf(Bf4));
    __hv_varread_f(&sVarf_oSPt4QwQ, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_oVKOuuL7, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_NplCOnrK, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_tgGjVpBg, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_u2FoeDmB, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_tQcxlbFo, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Y66a1Hxy, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_4zXjaq6V, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_tqq9DMNI, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_QvSVkke0, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_VyShZwls, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_QFtGY4tK, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_Jl2LlAW6, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_iBOpglHC, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_SaBo3uD2, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_U0UbiIz3, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_XTVcualp, VOf(Bf12));
    __hv_add_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_Ny2wrpUd, VOf(Bf4));
    __hv_add_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_jBzWeCnl, VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_gaoCOtlL, VOf(Bf4));
    __hv_varread_f(&sVarf_1uLtXhTB, VOf(Bf12));
    __hv_mul_f(VIf(I0), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf14), VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_add_f(VIf(Bf12), VIf(O0), VOf(O0));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf12));
    __hv_var_k_f(VOf(Bf4), 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f);
    __hv_var_k_f(VOf(Bf14), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cODWyoZT, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_lHTedkk6, VOf(Bf11));
    __hv_fms_f(VIf(Bf1), VIf(Bf11), VIf(Bf14), VOf(Bf11));
    __hv_varread_f(&sVarf_ScgZ8xs3, VOf(Bf1));
    __hv_zero_f(VOf(Bf5));
    __hv_neq_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf11));
    __hv_min_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_add_f(VIf(Bf14), VIf(Bf11), VOf(Bf14));
    __hv_varread_f(&sVarf_qApCAyFA, VOf(Bf5));
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf4), VOf(Bf14));
    __hv_sub_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf14), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf14));
    __hv_mul_f(VIf(Bf1), VIf(Bf14), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf15), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf14), VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_floor_f(VIf(Bf15), VOf(Bf4));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf15), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_abs_f(VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf15), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf15), VIf(Bf15), VOf(Bf4));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf15), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf11), VIf(Bf16), VOf(Bf16));
    __hv_cpole_f(&sCPole_U5QzBXjM, VIf(Bf5), VIf(ZERO), VIf(Bf3), VIf(Bf16), VOf(Bf16), VOf(Bf3));
    __hv_line_f(&sLine_MUZbgaOJ, VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_NplCOnrK, VIf(Bf5));
    __hv_var_k_f(VOf(Bf5), 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f);
    __hv_var_k_f(VOf(Bf11), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_rhjj9ynC, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_8Kus44jV, VOf(Bf4));
    __hv_fms_f(VIf(Bf1), VIf(Bf4), VIf(Bf11), VOf(Bf4));
    __hv_varread_f(&sVarf_ca8rHNVn, VOf(Bf1));
    __hv_zero_f(VOf(Bf15));
    __hv_neq_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_zero_f(VOf(Bf4));
    __hv_min_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf11), VIf(Bf4), VOf(Bf11));
    __hv_varread_f(&sVarf_BUiWrmHJ, VOf(Bf15));
    __hv_mul_f(VIf(Bf11), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_floor_f(VIf(Bf5), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf11), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf11));
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf1), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf11), VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf4), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf5));
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf14), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf4), VIf(Bf14), VOf(Bf14));
    __hv_cpole_f(&sCPole_TGkn9NyC, VIf(Bf15), VIf(ZERO), VIf(Bf18), VIf(Bf14), VOf(Bf14), VOf(Bf18));
    __hv_line_f(&sLine_gYdlB2qX, VOf(Bf18));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf14), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_lHvWODSY, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f);
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_YsLvlxiY, VOf(Bf15));
    __hv_mul_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf1), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_90ETYJlY, VOf(Bf5));
    __hv_fms_f(VIf(Bf1), VIf(Bf5), VIf(Bf4), VOf(Bf5));
    __hv_varread_f(&sVarf_A8THGL24, VOf(Bf1));
    __hv_zero_f(VOf(Bf7));
    __hv_neq_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf5));
    __hv_min_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf4));
    __hv_varread_f(&sVarf_d8oqa1r9, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf12), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf15), VOf(Bf4));
    __hv_sub_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf2), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf11), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf4), VIf(Bf9), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf15));
    __hv_sub_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf15), VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_cpole_f(&sCPole_ojIuU6rA, VIf(Bf7), VIf(ZERO), VIf(Bf2), VIf(Bf11), VOf(Bf11), VOf(Bf2));
    __hv_line_f(&sLine_mBK8HTmp, VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_kOUyotFF, VIf(Bf5));
    __hv_var_k_f(VOf(Bf5), 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f);
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_aaVRPfmI, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_cbJvSfsf, VOf(Bf15));
    __hv_fms_f(VIf(Bf1), VIf(Bf15), VIf(Bf7), VOf(Bf15));
    __hv_varread_f(&sVarf_MNFdG1jD, VOf(Bf1));
    __hv_zero_f(VOf(Bf9));
    __hv_neq_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf15));
    __hv_min_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf7), VIf(Bf15), VOf(Bf7));
    __hv_varread_f(&sVarf_UPsbO0T2, VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf5), VOf(Bf7));
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf20), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf20), VOf(Bf20));
    __hv_sub_f(VIf(Bf1), VIf(Bf20), VOf(Bf20));
    __hv_fma_f(VIf(Bf7), VIf(Bf10), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf15), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf5));
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf10), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf15), VIf(Bf4), VOf(Bf4));
    __hv_cpole_f(&sCPole_QqefG4sW, VIf(Bf9), VIf(ZERO), VIf(Bf20), VIf(Bf4), VOf(Bf4), VOf(Bf20));
    __hv_line_f(&sLine_UAKgNdSl, VOf(Bf20));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf20), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_oSPt4QwQ, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_neg_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_varwrite_f(&sVarf_78Fk8XkG, VIf(Bf18));
    __hv_var_k_f(VOf(Bf18), 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f);
    __hv_var_k_f(VOf(Bf14), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_QP7tdi3A, VOf(Bf18));
    __hv_mul_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf9), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_xJslgZFD, VOf(Bf15));
    __hv_fms_f(VIf(Bf9), VIf(Bf15), VIf(Bf14), VOf(Bf15));
    __hv_varread_f(&sVarf_QdFVvAfq, VOf(Bf9));
    __hv_zero_f(VOf(Bf1));
    __hv_neq_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_and_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_zero_f(VOf(Bf15));
    __hv_min_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf14), VIf(Bf15), VOf(Bf14));
    __hv_varread_f(&sVarf_z3LWs79X, VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf12), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf18), VOf(Bf14));
    __hv_sub_f(VIf(Bf18), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf14), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf14), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf14), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf14));
    __hv_mul_f(VIf(Bf9), VIf(Bf14), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf14), VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf15), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf18));
    __hv_sub_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf18), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf18));
    __hv_mul_f(VIf(Bf10), VIf(Bf18), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf18), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_KRlFHXtJ, VIf(Bf1), VIf(ZERO), VIf(Bf7), VIf(Bf5), VOf(Bf5), VOf(Bf7));
    __hv_line_f(&sLine_MCh6dNEm, VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_neg_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_zs2ARHXv, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_SrQfCTl3, VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf9), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_7bMqtRaW, VOf(Bf18));
    __hv_fms_f(VIf(Bf9), VIf(Bf18), VIf(Bf1), VOf(Bf18));
    __hv_varread_f(&sVarf_eCKXgizN, VOf(Bf9));
    __hv_zero_f(VOf(Bf10));
    __hv_neq_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf18));
    __hv_min_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_add_f(VIf(Bf1), VIf(Bf18), VOf(Bf1));
    __hv_varread_f(&sVarf_yR2Twobv, VOf(Bf10));
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf12), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf15), VOf(Bf1));
    __hv_sub_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf1));
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf18), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf15));
    __hv_sub_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf14), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf15), VIf(Bf9), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf18), VIf(Bf14), VOf(Bf14));
    __hv_cpole_f(&sCPole_RdRh1yjF, VIf(Bf10), VIf(ZERO), VIf(Bf13), VIf(Bf14), VOf(Bf14), VOf(Bf13));
    __hv_line_f(&sLine_JF2WlRsy, VOf(Bf13));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_tgGjVpBg, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f);
    __hv_var_k_f(VOf(Bf18), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_AI0Kz9tK, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_kuHgA7TB, VOf(Bf15));
    __hv_fms_f(VIf(Bf9), VIf(Bf15), VIf(Bf18), VOf(Bf15));
    __hv_varread_f(&sVarf_TwduOrwB, VOf(Bf9));
    __hv_zero_f(VOf(Bf0));
    __hv_neq_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf15));
    __hv_min_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf18), VIf(Bf15), VOf(Bf18));
    __hv_varread_f(&sVarf_VvolOUfR, VOf(Bf0));
    __hv_mul_f(VIf(Bf18), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf12), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf10), VOf(Bf18));
    __hv_sub_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf18), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf18));
    __hv_mul_f(VIf(Bf9), VIf(Bf18), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf18), VIf(Bf17), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf15), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf10));
    __hv_sub_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf10));
    __hv_mul_f(VIf(Bf17), VIf(Bf10), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf18), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf10), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf15), VIf(Bf1), VOf(Bf1));
    __hv_cpole_f(&sCPole_RlH9LWfB, VIf(Bf0), VIf(ZERO), VIf(Bf8), VIf(Bf1), VOf(Bf1), VOf(Bf8));
    __hv_line_f(&sLine_MXwWIheG, VOf(Bf8));
    __hv_var_k_f(VOf(Bf0), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_neg_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf1), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_Ta339XnH, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f);
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_WggwOBSz, VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf9), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_MNW0v8sE, VOf(Bf10));
    __hv_fms_f(VIf(Bf9), VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_varread_f(&sVarf_h9Sk51H8, VOf(Bf9));
    __hv_zero_f(VOf(Bf17));
    __hv_neq_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf10));
    __hv_min_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf0), VIf(Bf10), VOf(Bf0));
    __hv_varread_f(&sVarf_4F1cSXrH, VOf(Bf17));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf15), VOf(Bf0));
    __hv_sub_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf0));
    __hv_mul_f(VIf(Bf9), VIf(Bf0), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf19), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf18), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf0), VIf(Bf19), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf10), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf19), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf19), VOf(Bf15));
    __hv_sub_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf19), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_abs_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf19), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf19), VOf(Bf15));
    __hv_mul_f(VIf(Bf19), VIf(Bf15), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf19), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf15), VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_cpole_f(&sCPole_teiSqXL2, VIf(Bf17), VIf(ZERO), VIf(Bf6), VIf(Bf18), VOf(Bf18), VOf(Bf6));
    __hv_line_f(&sLine_nfcCtHIb, VOf(Bf6));
    __hv_var_k_f(VOf(Bf17), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf6), VIf(Bf17), VOf(Bf17));
    __hv_neg_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_aBjHetzF, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f);
    __hv_var_k_f(VOf(Bf17), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf9));
    __hv_max_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_mtnaNdsw, VOf(Bf10));
    __hv_mul_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_varread_f(&sVarf_rSFSZWfE, VOf(Bf15));
    __hv_fms_f(VIf(Bf9), VIf(Bf15), VIf(Bf17), VOf(Bf15));
    __hv_varread_f(&sVarf_rljGylkW, VOf(Bf9));
    __hv_zero_f(VOf(Bf19));
    __hv_neq_f(VIf(Bf9), VIf(Bf19), VOf(Bf19));
    __hv_and_f(VIf(Bf15), VIf(Bf19), VOf(Bf19));
    __hv_zero_f(VOf(Bf15));
    __hv_min_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf17), VIf(Bf15), VOf(Bf17));
    __hv_varread_f(&sVarf_HLao1xcE, VOf(Bf19));
    __hv_mul_f(VIf(Bf17), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf12), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf10), VOf(Bf17));
    __hv_sub_f(VIf(Bf10), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf17));
    __hv_mul_f(VIf(Bf9), VIf(Bf17), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf21), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf22), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf22), VOf(Bf22));
    __hv_sub_f(VIf(Bf9), VIf(Bf22), VOf(Bf22));
    __hv_fma_f(VIf(Bf17), VIf(Bf21), VIf(Bf22), VOf(Bf22));
    __hv_mul_f(VIf(Bf15), VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf21), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf21), VOf(Bf21));
    __hv_floor_f(VIf(Bf21), VOf(Bf10));
    __hv_sub_f(VIf(Bf21), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf21), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf21), VOf(Bf21));
    __hv_abs_f(VIf(Bf21), VOf(Bf21));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf21), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf21), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf21), VOf(Bf21));
    __hv_mul_f(VIf(Bf21), VIf(Bf21), VOf(Bf10));
    __hv_mul_f(VIf(Bf21), VIf(Bf10), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf21), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf10), VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf15), VIf(Bf0), VOf(Bf0));
    __hv_cpole_f(&sCPole_M6AxxG2t, VIf(Bf19), VIf(ZERO), VIf(Bf22), VIf(Bf0), VOf(Bf0), VOf(Bf22));
    __hv_line_f(&sLine_yvNSvGVa, VOf(Bf22));
    __hv_var_k_f(VOf(Bf19), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf22), VIf(Bf19), VOf(Bf19));
    __hv_neg_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf19), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf0), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_mUYmoWiJ, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_neg_f(VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_2DXrbhqo, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf11), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_u2FoeDmB, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf22), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_UbwVENHw, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_varwrite_f(&sVarf_Q0bkAGYI, VIf(Bf13));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf20), VIf(Bf13), VOf(Bf13));
    __hv_neg_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf20), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf4), VIf(Bf20), VOf(Bf20));
    __hv_varwrite_f(&sVarf_81vSDxJr, VIf(Bf20));
    __hv_var_k_f(VOf(Bf20), 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f);
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf13));
    __hv_max_f(VIf(Bf20), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_tsdoN062, VOf(Bf20));
    __hv_mul_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf13), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf20), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_9hCFhEwX, VOf(Bf14));
    __hv_fms_f(VIf(Bf13), VIf(Bf14), VIf(Bf4), VOf(Bf14));
    __hv_varread_f(&sVarf_vNvYVNXY, VOf(Bf13));
    __hv_zero_f(VOf(Bf3));
    __hv_neq_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf14));
    __hv_min_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_add_f(VIf(Bf4), VIf(Bf14), VOf(Bf4));
    __hv_varread_f(&sVarf_t7XgPdmt, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf20), VOf(Bf12));
    __hv_sub_f(VIf(Bf20), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf4), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf12));
    __hv_mul_f(VIf(Bf4), VIf(Bf12), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf0), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf22), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf22), VOf(Bf22));
    __hv_sub_f(VIf(Bf4), VIf(Bf22), VOf(Bf22));
    __hv_fma_f(VIf(Bf12), VIf(Bf0), VIf(Bf22), VOf(Bf22));
    __hv_mul_f(VIf(Bf14), VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf20), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf20));
    __hv_sub_f(VIf(Bf0), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf20), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf20), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf20), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf20));
    __hv_mul_f(VIf(Bf0), VIf(Bf20), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf4), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf20), VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf14), VIf(Bf13), VOf(Bf13));
    __hv_cpole_f(&sCPole_alxKqtgX, VIf(Bf3), VIf(ZERO), VIf(Bf22), VIf(Bf13), VOf(Bf13), VOf(Bf22));
    __hv_line_f(&sLine_t6mH6GZI, VOf(Bf22));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf22), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_Y66a1Hxy, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_oVKOuuL7, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_tQcxlbFo, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf22), VIf(Bf3), VOf(Bf3));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf22), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf22), VOf(Bf22));
    __hv_mul_f(VIf(Bf13), VIf(Bf22), VOf(Bf22));
    __hv_varwrite_f(&sVarf_pS4aubSM, VIf(Bf22));
    __hv_var_k_f(VOf(Bf22), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf6), VIf(Bf22), VOf(Bf22));
    __hv_mul_f(VIf(Bf18), VIf(Bf22), VOf(Bf22));
    __hv_varwrite_f(&sVarf_4zXjaq6V, VIf(Bf22));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_Panoramizer::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_Panoramizer::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s), uninterleave
  float *const bIn = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));
  #if HV_SIMD_SSE || HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 a = _mm_load_ps(inputBuffers+i);                // LRLR
    __m128 b = _mm_load_ps(inputBuffers+4+i);              // LRLR
    __m128 x = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2,0,2,0)); // LLLL
    __m128 y = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3,1,3,1)); // RRRR
    _mm_store_ps(bIn+j, x);
    _mm_store_ps(bIn+n4+j, y);
  }
  #elif HV_SIMD_NEON
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4x2_t a = vld2q_f32(inputBuffers+i); // load and uninterleave
    vst1q_f32(bIn+j, a.val[0]);
    vst1q_f32(bIn+n4+j, a.val[1]);
  }
  #else // HV_SIMD_NONE
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+2*j];
    bIn[1*n4+j] = inputBuffers[1+2*j];
  }
  #endif

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
