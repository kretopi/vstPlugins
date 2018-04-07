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
  numBytes += sEnv_init(&sEnv_N4bFX7cm, 1024, 512);
  numBytes += sCPole_init(&sCPole_mQcQT4fr);
  numBytes += sLine_init(&sLine_6UOJDo9X);
  numBytes += sCPole_init(&sCPole_U6A4W26R);
  numBytes += sLine_init(&sLine_LJsKvZiV);
  numBytes += sCPole_init(&sCPole_DlwlNtTj);
  numBytes += sLine_init(&sLine_VJ2INnuh);
  numBytes += sCPole_init(&sCPole_7TE3z8p9);
  numBytes += sLine_init(&sLine_DtYYCGqY);
  numBytes += sRPole_init(&sRPole_h8T9GkRt);
  numBytes += sDel1_init(&sDel1_HPm39iRQ);
  numBytes += sLine_init(&sLine_n79ul0lu);
  numBytes += sCPole_init(&sCPole_bPpPW6XI);
  numBytes += sLine_init(&sLine_ZSzD7Aq4);
  numBytes += sCPole_init(&sCPole_3BO9sWwI);
  numBytes += sLine_init(&sLine_QSOD5GhG);
  numBytes += sCPole_init(&sCPole_rrB1wAey);
  numBytes += sLine_init(&sLine_Oe6ZDdpL);
  numBytes += sCPole_init(&sCPole_LeHPsLQ0);
  numBytes += sLine_init(&sLine_GP3GIsdf);
  numBytes += sCPole_init(&sCPole_Mpn9t1jr);
  numBytes += sLine_init(&sLine_fRMuQPsG);
  numBytes += sCPole_init(&sCPole_QbJONgJi);
  numBytes += sCPole_init(&sCPole_x49zFMO7);
  numBytes += sLine_init(&sLine_zPYJjORe);
  numBytes += sCPole_init(&sCPole_Y2lE34WJ);
  numBytes += sLine_init(&sLine_Qlcis11d);
  numBytes += sCPole_init(&sCPole_hA7SuSCW);
  numBytes += sLine_init(&sLine_nv2OGtLu);
  numBytes += sCPole_init(&sCPole_4DlrxkET);
  numBytes += sLine_init(&sLine_L4sHvsTr);
  numBytes += sCPole_init(&sCPole_gV5kXx0c);
  numBytes += sCPole_init(&sCPole_9f1bw8p5);
  numBytes += sLine_init(&sLine_VNZPhbQZ);
  numBytes += sCPole_init(&sCPole_Bw2rZEGP);
  numBytes += sLine_init(&sLine_1zKICT9M);
  numBytes += sCPole_init(&sCPole_Jy8GhGiT);
  numBytes += sLine_init(&sLine_92pzSl5j);
  numBytes += sCPole_init(&sCPole_oKT8lest);
  numBytes += sLine_init(&sLine_vylmWqAR);
  numBytes += sRPole_init(&sRPole_UAOhPuwb);
  numBytes += sDel1_init(&sDel1_5mjas09m);
  numBytes += sLine_init(&sLine_V5maCN7A);
  numBytes += sCPole_init(&sCPole_3FYZV1Ki);
  numBytes += sLine_init(&sLine_NOmkPjal);
  numBytes += sVarf_init(&sVarf_crUSpZwm, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_xZmyxsRH, 1, -1);
  numBytes += cSlice_init(&cSlice_HrwzS8Nl, 1, -1);
  numBytes += sVarf_init(&sVarf_FG0OtkWC, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_9nmDqn6K, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_e1hf7bw5, 1492697874);
  numBytes += cSlice_init(&cSlice_IT22QJgE, 1, 1);
  numBytes += cVar_init_f(&cVar_AoIg2htY, 12000.0f);
  numBytes += sVarf_init(&sVarf_D7H7iYNt, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_h1PeoMDW, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_tP0XYTkJ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_3fWZeJHE, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_L2rJVVdT, 1, 1);
  numBytes += cRandom_init(&cRandom_hLabLiaJ, -463711154);
  numBytes += cBinop_init(&cBinop_GTVkKgMi, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_mFs3rUtS, 1, 1);
  numBytes += cRandom_init(&cRandom_tDTnJi59, -58201091);
  numBytes += cBinop_init(&cBinop_IUCPpPT9, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_yRkgIjd3, -1280369800);
  numBytes += cSlice_init(&cSlice_LxlC4cHx, 1, 1);
  numBytes += cSlice_init(&cSlice_RIyq6S4E, 1, 1);
  numBytes += cRandom_init(&cRandom_vt3cpkRr, -1482162173);
  numBytes += cBinop_init(&cBinop_nMzQy9Cr, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_zLQhiMg7, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_EMfTSTbp, 0.0f);
  numBytes += cVar_init_f(&cVar_Rimh69z5, 1000.0f);
  numBytes += cPack_init(&cPack_QY5fUg9e, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_Rfz7pQXy, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_2gdPS6y9, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_ch7LQUCG, 1, 1);
  numBytes += cRandom_init(&cRandom_APRW1RnW, -992042556);
  numBytes += cBinop_init(&cBinop_XPwdbsi8, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_F5qoVR0X, 1, 1);
  numBytes += cRandom_init(&cRandom_sSnyJVrM, -1130036157);
  numBytes += cVar_init_f(&cVar_KkAeBu11, 200.0f);
  numBytes += cDelay_init(this, &cDelay_QbCNMAkO, 0.0f);
  numBytes += cBinop_init(&cBinop_RMr1zoBN, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_Pt3mL5LF, -1204333224);
  numBytes += cSlice_init(&cSlice_kLpjVXcY, 1, 1);
  numBytes += sVarf_init(&sVarf_Wkb8LeSC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8m3am0l6, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_QYDga5MX, 1, 1);
  numBytes += cRandom_init(&cRandom_FlrNeWWR, -1715932092);
  numBytes += sVarf_init(&sVarf_UQgpdGzs, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_t4ahA9wF, false);
  numBytes += sVarf_init(&sVarf_N5FDJeNJ, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_3whcrt98, 0.0f);
  numBytes += sVarf_init(&sVarf_fkIhYJmU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_JzVog6Qk, 1.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_ZXhtPODX, 1, 1);
  numBytes += cRandom_init(&cRandom_AKKl08uI, 1863467688);
  numBytes += cBinop_init(&cBinop_i4BXVu7M, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_STegrMsA, 1, 1);
  numBytes += cRandom_init(&cRandom_jOUF7oNU, 1740048695);
  numBytes += sVarf_init(&sVarf_S6OfB04b, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1CPJhgtM, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_goARahQy, 0.0f);
  numBytes += cBinop_init(&cBinop_MRM6EQ7e, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zqJUY4V0, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_7kDCHin8, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_TIbwMRr7, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_OkkfNx3g, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zjeSrEqz, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_L3jfBPWx, 0.0f);
  numBytes += cVar_init_f(&cVar_2bG2qPKv, 200.0f);
  numBytes += cRandom_init(&cRandom_m06eKL3N, -1788199822);
  numBytes += cSlice_init(&cSlice_0J2PplUS, 1, 1);
  numBytes += cBinop_init(&cBinop_DlsEWDHp, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_k1ibx9JG, 1799804206);
  numBytes += cBinop_init(&cBinop_gHeuDxPe, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_L7g5jaeS, 1, 1);
  numBytes += cDelay_init(this, &cDelay_5PzNonLr, 0.0f);
  numBytes += cVar_init_f(&cVar_U5pjuaag, 200.0f);
  numBytes += cBinop_init(&cBinop_p7b4qAhC, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_8LqQP0zp, 1000.0f);
  numBytes += cBinop_init(&cBinop_GA2N1RbR, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_75X5i4dn, 0.0f);
  numBytes += cBinop_init(&cBinop_oJaXrasz, 0.0f); // __sub
  numBytes += cSlice_init(&cSlice_JdI0ELyW, 1, 1);
  numBytes += cRandom_init(&cRandom_cK2tqSG2, 1720806289);
  numBytes += cBinop_init(&cBinop_NdSXAOmo, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zewJFUox, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_Qwbjmue8, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_R6SiG3as, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_btFSd5JE, 0.0f);
  numBytes += cBinop_init(&cBinop_oAfaTUEO, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_p298ejCM, 200.0f);
  numBytes += cRandom_init(&cRandom_dYxSn4EF, -2002102834);
  numBytes += cSlice_init(&cSlice_O5bha7Qp, 1, 1);
  numBytes += cBinop_init(&cBinop_m0CJlfBG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_TM1IjIBz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_lCXYxeGB, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_bKiFO9os, -1484594344);
  numBytes += cSlice_init(&cSlice_2HMH5zZO, 1, 1);
  numBytes += cSlice_init(&cSlice_1ebq28wB, 1, 1);
  numBytes += cRandom_init(&cRandom_QgqgmeLn, 1222293938);
  numBytes += cBinop_init(&cBinop_5yObLFH6, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_VwL0Erka, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_LelpA6c5, 0.0f);
  numBytes += cPack_init(&cPack_87Z2lTuD, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_9EqpQhRp, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_6q99H2m3, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_97NV8XEK, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_nxjN3VtO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aBLKlM4i, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_W3bVcBRv, false);
  numBytes += sVarf_init(&sVarf_kTZUn6et, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KQlixPEc, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_67nxbiVh, 0.0f);
  numBytes += sVarf_init(&sVarf_pLnqn8sF, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_g25evTaz, -1673724325);
  numBytes += cSlice_init(&cSlice_AdAmsVIg, 1, 1);
  numBytes += cRandom_init(&cRandom_Rm7Hix70, 592220879);
  numBytes += cSlice_init(&cSlice_AF0gq36c, 1, 1);
  numBytes += cDelay_init(this, &cDelay_KMPh5a37, 0.0f);
  numBytes += cVar_init_f(&cVar_LoPeudQr, 200.0f);
  numBytes += cBinop_init(&cBinop_LbEEq3vT, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_pKj7a8E8, 1459614559);
  numBytes += cSlice_init(&cSlice_sFPWMr6V, 1, 1);
  numBytes += cDelay_init(this, &cDelay_Q3exlxlx, 0.0f);
  numBytes += cBinop_init(&cBinop_L369eW1x, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_I4KIxGIE, 1000.0f);
  numBytes += sVarf_init(&sVarf_vhfgPbOD, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_MXd6qz3M, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wujP0INe, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_9PTQLRIQ, 0.0f);
  numBytes += cVar_init_f(&cVar_QObWm807, 200.0f);
  numBytes += cBinop_init(&cBinop_tJqgrv0Z, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_R85nrMLB, 1, 1);
  numBytes += cRandom_init(&cRandom_rxPOkgEX, -484200674);
  numBytes += cSlice_init(&cSlice_8uyorSTf, 1, 1);
  numBytes += cBinop_init(&cBinop_vCtNYw6n, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_WCJt85Be, 1791685037);
  numBytes += sVarf_init(&sVarf_emuooEVs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jIRlihq3, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vchyr2pd, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_a7zRHm4C, 0.0f);
  numBytes += cIf_init(&cIf_b7S56lnw, false);
  numBytes += sVarf_init(&sVarf_jy3S0COU, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_lwPtQyQR, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_B94cCK8d, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_OwNGCuM2, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_48SpZAm6, 0.0f);
  numBytes += cVar_init_f(&cVar_nk3liotL, 1000.0f);
  numBytes += cPack_init(&cPack_DKnWXe3e, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_7tinuCsZ, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_yI6EDuUF, 0.0f);
  numBytes += cVar_init_f(&cVar_S2ak9brN, 1000.0f);
  numBytes += cBinop_init(&cBinop_q6RARPe0, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_1hXDoMZh, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_qfA2o0vD, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_9mbL52Se, 200.0f);
  numBytes += cDelay_init(this, &cDelay_r6G1ZrhK, 0.0f);
  numBytes += sVarf_init(&sVarf_QjMcnI7C, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_OfUJZT0F, 1917185436);
  numBytes += cSlice_init(&cSlice_hZEWfu19, 1, 1);
  numBytes += cBinop_init(&cBinop_eUwKcqKf, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_E0b9uZnX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_uTehwL36, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_QuGScXHX, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_GrfLG1lr, 200.0f);
  numBytes += cDelay_init(this, &cDelay_FTaC3PcZ, 0.0f);
  numBytes += cDelay_init(this, &cDelay_yvbpZCsx, 0.0f);
  numBytes += cBinop_init(&cBinop_m1K4zmy2, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_0xb9TyBH, 1000.0f);
  numBytes += cBinop_init(&cBinop_6JKcRCAq, 0.0f); // __mul
  numBytes += cPack_init(&cPack_pDSNY4JN, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_uFl3j5x0, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_xVScJl5v, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_IW5wgeRk, false);
  numBytes += sVarf_init(&sVarf_PG91io1z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EHX6psI8, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bKCRbc8J, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_H5abVFdb, 0.0f);
  numBytes += sVarf_init(&sVarf_5QxTXgK3, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_8diG2pig, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_vIM2Idic, 0.0f);
  numBytes += cVar_init_f(&cVar_9CiT0XBJ, 200.0f);
  numBytes += cBinop_init(&cBinop_zgX4qG2W, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_D7UFyLfA, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_UzxSPCNd, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9WXHRRsI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mYrXnenw, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_nkN00Aca, false);
  numBytes += cVar_init_f(&cVar_7jNNLtp9, 0.0f);
  numBytes += cSlice_init(&cSlice_vOgmJE9j, 1, 1);
  numBytes += cRandom_init(&cRandom_hVkeopG9, -1063139388);
  numBytes += cBinop_init(&cBinop_FbTkVbgg, 100.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_IBOhEzDu, 0.0f);
  numBytes += cBinop_init(&cBinop_cUq7bwUu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_gZbQW9tf, 1000.0f);
  numBytes += cPack_init(&cPack_WapmcKov, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_E0B1zMQm, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3jnujRFQ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_QvlwGOUg, 0.0f); // __sub
  numBytes += cIf_init(&cIf_nsScQS7w, false);
  numBytes += sVarf_init(&sVarf_O1LZkbTu, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_IYrdb4vu, 0.0f);
  numBytes += sVarf_init(&sVarf_BFegigXK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bmbHc1d1, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Kjkm7ekA, 1.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_Tg84tVVm, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_maQsqW14, 1632735713);
  numBytes += cSlice_init(&cSlice_BngAo8Ki, 1, 1);
  numBytes += sVarf_init(&sVarf_BoFfdS9o, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_zZWWb0E4, -1354164744);
  numBytes += cSlice_init(&cSlice_SkMN70XS, 1, 1);
  numBytes += sVarf_init(&sVarf_GCLVuW2N, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_leGUt24b, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ObkpX0JF, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bpEJoxb2, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Z2oOxIOS, 0.0f);
  numBytes += cIf_init(&cIf_QGFe5Z5l, false);
  numBytes += cSlice_init(&cSlice_QwtxEuZF, 1, 1);
  numBytes += cRandom_init(&cRandom_MOeIV3Eb, -465442883);
  numBytes += cVar_init_f(&cVar_TVcqWIxl, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_DAeSRX1i, 0.0f);
  numBytes += cBinop_init(&cBinop_rIRNImQP, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_hGV4kkxp, 200.0f);
  numBytes += cBinop_init(&cBinop_hJCj79uI, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_8I1KylPY, 0.0f);
  numBytes += sVarf_init(&sVarf_kQdYjKZK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lSaoDUIF, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_4EABwTjy, false);
  numBytes += sVarf_init(&sVarf_CcwMSHKC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eOMz455y, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hJBOOvUl, 0.0f);
  numBytes += sVarf_init(&sVarf_QKzT4Sf9, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_YgVJAkdc, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_wyPgA57W, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_neqSe77V, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XqPpAKN7, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_kHx7uhjh, 1, 1);
  numBytes += cBinop_init(&cBinop_JisdDsOM, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_QSGUfS55, -207664173);
  numBytes += cRandom_init(&cRandom_Kbv3bUcC, -415045921);
  numBytes += cSlice_init(&cSlice_OMPH4cVY, 1, 1);
  numBytes += cBinop_init(&cBinop_xW54efLi, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_Nk60DtQK, 1, 1);
  numBytes += cRandom_init(&cRandom_Eny0UcHA, -2097285561);
  numBytes += cIf_init(&cIf_zbBpD3X0, false);
  numBytes += sVarf_init(&sVarf_FAOhbPz3, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_w5L4UAGX, 0.0f);
  numBytes += sVarf_init(&sVarf_uxdg4YAe, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_bH99oJFd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8Qd6QDL6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Tp98WJGe, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_fjgWuEaJ, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_KnzsWnIN, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iohOJlDo, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_X1aZmNF2, false);
  numBytes += sVarf_init(&sVarf_zXeeTKt8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0HS1Lj7U, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_7BjEuEMq, 0.0f);
  numBytes += cBinop_init(&cBinop_MdDyB8Ls, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Y7Lmv1O0, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1RwoNlcX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OaJmYKbW, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_7dAFWq7s, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fNwMPrJo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Tmy1Smuh, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IHYSOwIQ, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_8SlAuAP8, 1834081518);
  numBytes += cSlice_init(&cSlice_BHioAAPZ, 1, 1);
  numBytes += cVar_init_f(&cVar_Wcvun8XB, 200.0f);
  numBytes += cDelay_init(this, &cDelay_82m6vm5v, 0.0f);
  numBytes += cBinop_init(&cBinop_bYnWd6kc, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_ceiMZgPP, 1, 1);
  numBytes += cRandom_init(&cRandom_WEfFoW7V, 75040965);
  numBytes += cBinop_init(&cBinop_BI3eis25, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_k6uHwbOR, 1, 1);
  numBytes += cRandom_init(&cRandom_TFtiadFt, -765777512);
  numBytes += cBinop_init(&cBinop_wo11dV7r, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rbJZJbmS, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_KCoyj1sc, 1, 1);
  numBytes += cRandom_init(&cRandom_wqk0Al42, 341055729);
  numBytes += cRandom_init(&cRandom_JtfAw66I, 1445516434);
  numBytes += cSlice_init(&cSlice_o6Ax4Qq4, 1, 1);
  numBytes += cVar_init_f(&cVar_0vtB9sHC, 1000.0f);
  numBytes += cBinop_init(&cBinop_2HOldZ0p, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_76aT2wsZ, 0.0f);
  numBytes += cPack_init(&cPack_5OWxo3Nw, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_LVi6fjJA, 1, 1);
  numBytes += cRandom_init(&cRandom_XKwoWCjj, 440460289);
  numBytes += cBinop_init(&cBinop_LLGnZA3U, 100.0f); // __mul
  numBytes += cBinop_init(&cBinop_Ipne0k3D, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_jPMJCglq, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_OUmSeSZG, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_m5VpCe1r, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_OYxVlYHo, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_stXi7hAs, 1, 1);
  numBytes += cRandom_init(&cRandom_CaTpHi9A, 219726085);
  numBytes += cBinop_init(&cBinop_ahGOwBHb, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_6Yov7vfn, 0.0f);
  numBytes += cVar_init_f(&cVar_BUiVDeyR, 1000.0f);
  numBytes += sVarf_init(&sVarf_OhJOUiQb, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_siSxWMt5, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_d8uY2uc1, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_BxLYb3TU, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_gJnZMWP7, 0.0f);
  numBytes += cVar_init_f(&cVar_JvLnJLmK, 200.0f);
  numBytes += sVarf_init(&sVarf_5UyNY4sS, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qMxGejsN, 200.0f);
  numBytes += cDelay_init(this, &cDelay_XcbxNWMf, 0.0f);
  numBytes += cBinop_init(&cBinop_c1gR6E7D, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_sgTIkpC2, -849898783);
  numBytes += cSlice_init(&cSlice_IBZy7bj7, 1, 1);
  numBytes += sVarf_init(&sVarf_XIw83vrD, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_CBuGSTTS, 0.0f);
  numBytes += cVar_init_f(&cVar_A9Mmxda7, 1000.0f);
  numBytes += cBinop_init(&cBinop_PiEKT2fT, 0.0f); // __mul
  numBytes += cPack_init(&cPack_mLEAj74G, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_2D7XDShQ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_T6qCeL7Y, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_j4ZM6Vy2, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yt8tYLRE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RkRQ9YeV, 0.0f);
  numBytes += cIf_init(&cIf_Ua7hU9ZZ, false);
  numBytes += sVarf_init(&sVarf_p4Vt4F68, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IaVcx8yQ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_P4bab0Ol, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ydTpWVQE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_aGFEWq0p, 12000.0f);
  numBytes += sVarf_init(&sVarf_gmsTS1QU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_pR8udgTw, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_7zZG4hv8, 0.0f); // __mul
  numBytes += cIf_init(&cIf_ADMbRI8p, false);
  numBytes += sVarf_init(&sVarf_xHResXUs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YtHKZMPl, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_HiTPpfeb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_52xmv25q, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cpd2UBKm, 0.0f);
  numBytes += cBinop_init(&cBinop_MelYVOFT, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_M0fP9cvw, 1, 1);
  numBytes += cRandom_init(&cRandom_fJF092py, -1562945395);
  numBytes += cBinop_init(&cBinop_l1kpTUmU, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_Ez482iym, 0.0f);
  numBytes += cVar_init_f(&cVar_8SG59YUA, 200.0f);
  numBytes += cPack_init(&cPack_y35bMjXe, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_42iqBkRC, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_Qtt7MhTR, 0.0f);
  numBytes += cVar_init_f(&cVar_SwME4N3A, 200.0f);
  numBytes += cVar_init_f(&cVar_vL0sjC3u, 0.0f);
  numBytes += sVarf_init(&sVarf_ggzc3Kfp, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_uaUc7NQa, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_BPf4aIBq, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_musW1hFJ, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_YTzPOCJf, false);
  numBytes += cPack_init(&cPack_ewI8OedI, 2, 0.0f, 0.0f);
  numBytes += cRandom_init(&cRandom_fHlOFGOX, 25035814);
  numBytes += cBinop_init(&cBinop_ZGB0ejZo, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_Je6IRhcT, 1, 1);
  numBytes += cSlice_init(&cSlice_zimVwK1f, 1, 1);
  numBytes += cBinop_init(&cBinop_00caoaka, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_ohvWDmfF, -805618878);
  numBytes += cRandom_init(&cRandom_LckIJ85I, -786563509);
  numBytes += cBinop_init(&cBinop_iVofnMuY, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_F5WqpakX, 1, 1);
  numBytes += cBinop_init(&cBinop_b24ovYJW, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HlzE6CZo, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_bRSbfgTU, 0.0f);
  numBytes += cBinop_init(&cBinop_oxZEvaCw, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_zwoxEPBz, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_ANGiGGxM, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zeFeD5Et, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_HoMnd7aR, 200.0f);
  numBytes += cDelay_init(this, &cDelay_0YSlu9Os, 0.0f);
  numBytes += cBinop_init(&cBinop_cN8Ytvzf, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_uvZuNA2M, 1589393963);
  numBytes += cSlice_init(&cSlice_WwMzLeDW, 1, 1);
  numBytes += cBinop_init(&cBinop_Mz6gH7pt, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_02qzk8Gt, 0.0f); // __add
  numBytes += sVarf_init(&sVarf_y8tDw0wC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_OJRnTqNL, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_16yliP8r, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_GSKkAtWd, 0.0f);
  numBytes += cIf_init(&cIf_D3Nyy1DE, false);
  numBytes += sVarf_init(&sVarf_VVK2qXgT, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_XvRn3Xjo, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_PcWwpi2z, false);
  numBytes += cVar_init_f(&cVar_v9wRUjqb, 0.0f);
  numBytes += sVarf_init(&sVarf_SJ7ylz8n, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1h7qsGhr, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_IJ4YXdZM, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nhGCqI07, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_xatWoY4D, -983198413);
  numBytes += cSlice_init(&cSlice_6tlvggcF, 1, 1);
  numBytes += cBinop_init(&cBinop_OZTt3GGd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_VSK1i4gq, 200.0f);
  numBytes += cDelay_init(this, &cDelay_T5foQqrD, 0.0f);
  numBytes += cRandom_init(&cRandom_2VS60E7H, 1076054295);
  numBytes += cSlice_init(&cSlice_B5HcHBjB, 1, 1);
  numBytes += cVar_init_f(&cVar_ZHfKLawv, 0.0f);
  numBytes += sVarf_init(&sVarf_8GmFdEWj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FdD5BchY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aOAC5JtC, 1.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_EWkitfpr, false);
  numBytes += sVarf_init(&sVarf_HJVBC1IV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fXeJdq5K, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_2rA4wbim, false);
  numBytes += sVarf_init(&sVarf_98eg6lHU, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_s2nyp1TU, 0.0f);
  numBytes += sVarf_init(&sVarf_arOGUN5D, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_6tUYgxh1, 1.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qQ4Pvsv3, 1000.0f);
  numBytes += cBinop_init(&cBinop_P7utx3WK, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_owaa2Oxd, 0.0f);
  numBytes += cSlice_init(&cSlice_bKZDYyXa, 1, 1);
  numBytes += cRandom_init(&cRandom_8OACpNrf, 1629088635);
  numBytes += cRandom_init(&cRandom_lmN82G1m, 367496220);
  numBytes += cSlice_init(&cSlice_gmt31RwS, 1, 1);
  numBytes += cSlice_init(&cSlice_4X5vo6ZY, 1, 1);
  numBytes += cBinop_init(&cBinop_xZcZvnlW, 100.0f); // __mul
  numBytes += cRandom_init(&cRandom_0ikYmb6C, 622876295);
  numBytes += sVarf_init(&sVarf_P5Uz78Sj, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_O3bmRSA8, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_49EaOASG, 0.0f);
  numBytes += cVar_init_f(&cVar_HLqgiQZ5, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_kdypqDsj, 0.0f);
  numBytes += cBinop_init(&cBinop_pZkC1T7f, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_iDbpmfUZ, 200.0f);
  numBytes += cRandom_init(&cRandom_1AHr5gKV, 747959789);
  numBytes += cSlice_init(&cSlice_zA6kF6jf, 1, 1);
  numBytes += cVar_init_f(&cVar_xVsw7h5K, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_boG16aB1, 0.0f);
  numBytes += cBinop_init(&cBinop_ALb6V83p, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_TSKJtKEE, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_FG8zDpjb, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_NrXaf2QS, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_RFqgfXtf, 0.0f);
  numBytes += cBinop_init(&cBinop_LjQfPN2D, 0.0f); // __mul
  numBytes += cSlice_init(&cSlice_B9hMMrQg, 1, 1);
  numBytes += cRandom_init(&cRandom_sewkZHyS, 1629833721);
  numBytes += cPack_init(&cPack_Cn5YA3er, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_tvwcMdxz, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_t4cEEUAl, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_dFPy4f4q, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_fQaFKSrX, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eG6D86Ca, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_E449kfwA, 0.0f);
  numBytes += cIf_init(&cIf_4pqK4siO, false);
  numBytes += sVarf_init(&sVarf_N8eWmFKE, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_c6rjZvwE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0PkbET6V, 0.0f); // __sub
  numBytes += cPack_init(&cPack_Om8klIWY, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_REjbwuAe, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_jtxpHkMR, 0.0f);
  numBytes += cBinop_init(&cBinop_W2tDRMrT, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_cVTWc9hF, 1000.0f);
  numBytes += sVarf_init(&sVarf_SKlmK0Vs, 1.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_kDCAapv2, false);
  numBytes += sVarf_init(&sVarf_h8riM1ZY, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gCopKF1Y, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_RsCWoG7b, 0.0f);
  numBytes += sVarf_init(&sVarf_RuTblLji, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_vNj5ytSx, 1, 1);
  numBytes += cRandom_init(&cRandom_ovOOJxqp, -422251341);
  numBytes += cSlice_init(&cSlice_pc9qptQx, 1, 1);
  numBytes += cRandom_init(&cRandom_qUq1h3cy, 1026754745);
  numBytes += cBinop_init(&cBinop_DrZO29TU, 0.0f); // __add
  numBytes += cRandom_init(&cRandom_EozFXAoN, -672659252);
  numBytes += cSlice_init(&cSlice_gtnWTWtY, 1, 1);
  numBytes += cPack_init(&cPack_qtR0WCgA, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_eWqcDLAV, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jJp5cHSe, 200.0f);
  numBytes += cBinop_init(&cBinop_0IDq6I2f, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_KjyhdmjG, 0.0f);
  numBytes += sVarf_init(&sVarf_9lp4WovK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_EwOYPzri, 0.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_ptANniBq, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_z1QrhhkP, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_SZiBnqS4, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_L0SH4LoN, -1353463972);
  numBytes += cSlice_init(&cSlice_TQhNw1ez, 1, 1);
  numBytes += cBinop_init(&cBinop_JQkemYWg, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_X1OoMSP6, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_AgKSUT2Z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hvT1m8Kb, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5yFNHZ2G, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_AwJW8XRL, 1, 1);
  numBytes += cRandom_init(&cRandom_SI5ENb2K, -1079283595);
  numBytes += sVarf_init(&sVarf_zzT2Vmhh, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_RCYSUZvx, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_MGwtL7s8, -39548869);
  numBytes += cSlice_init(&cSlice_a1xKulqn, 1, 1);
  numBytes += cPack_init(&cPack_W9fmRJfz, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_62c0O147, 1, 1);
  numBytes += cRandom_init(&cRandom_fVnSz6qy, -639318236);
  numBytes += cBinop_init(&cBinop_U37Dg4um, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_NFGMmH3L, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ryQC9hgD, 0.0f); // __mul
  numBytes += cPack_init(&cPack_nd6htOOI, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_PBWmHT8n, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Tt3BNlJ9, 0.0f);
  numBytes += sVarf_init(&sVarf_bUjDxYUw, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Rxxhyvoq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_TGBMGt3U, 1.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_nFk8FTJp, false);
  numBytes += sVarf_init(&sVarf_eQnjGg0F, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_VehvOkZW, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_EeAIPlDz, 0.0f); // __add
  numBytes += cRandom_init(&cRandom_w2kDc45B, 615128838);
  numBytes += cBinop_init(&cBinop_zPN8xbI8, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_QzAnwd6i, 1, 1);
  numBytes += cRandom_init(&cRandom_RNyY7Bbb, 1313598063);
  numBytes += cBinop_init(&cBinop_moBH697m, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_dE4hiSoY, 1, 1);
  numBytes += cRandom_init(&cRandom_Ngp0PEgQ, 1984605392);
  numBytes += cBinop_init(&cBinop_LjLFJ3kE, 100.0f); // __mul
  numBytes += cSlice_init(&cSlice_pOewS3jV, 1, 1);
  numBytes += sVarf_init(&sVarf_KvNFMO24, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KVxAJzWJ, 200.0f);
  numBytes += cBinop_init(&cBinop_vYevoqM8, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_x6ADI2af, 0.0f);
  numBytes += cBinop_init(&cBinop_aLavtMi2, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_sAIku2Or, 0.0f);
  numBytes += cVar_init_f(&cVar_2H4vKUdQ, 1000.0f);
  numBytes += sVarf_init(&sVarf_qo4SdCzc, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_Panoramizer::~Heavy_Panoramizer() {
  sEnv_free(&sEnv_N4bFX7cm);
  cPack_free(&cPack_QY5fUg9e);
  cPack_free(&cPack_2gdPS6y9);
  cPack_free(&cPack_87Z2lTuD);
  cPack_free(&cPack_lwPtQyQR);
  cPack_free(&cPack_DKnWXe3e);
  cPack_free(&cPack_pDSNY4JN);
  cPack_free(&cPack_uFl3j5x0);
  cPack_free(&cPack_WapmcKov);
  cPack_free(&cPack_YgVJAkdc);
  cPack_free(&cPack_fjgWuEaJ);
  cPack_free(&cPack_5OWxo3Nw);
  cPack_free(&cPack_mLEAj74G);
  cPack_free(&cPack_y35bMjXe);
  cPack_free(&cPack_ewI8OedI);
  cPack_free(&cPack_Cn5YA3er);
  cPack_free(&cPack_Om8klIWY);
  cPack_free(&cPack_qtR0WCgA);
  cPack_free(&cPack_ptANniBq);
  cPack_free(&cPack_W9fmRJfz);
  cPack_free(&cPack_nd6htOOI);
}

HvTable *Heavy_Panoramizer::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_Panoramizer::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_cW9q0iEu_sendMessage);
      break;
    }
    case 0xBA8CED4E: { // dry
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2yyzQek0_sendMessage);
      break;
    }
    case 0x6A6F415D: { // mono
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_D6yaPrcF_sendMessage);
      break;
    }
    case 0x8E55AA5F: { // time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MPdnA1F6_sendMessage);
      break;
    }
    case 0x1B53CD5A: { // wet
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iHbq2yZR_sendMessage);
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


void Heavy_Panoramizer::cMsg_LEFAhNhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.06f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fNwMPrJo, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_crUSpZwm, m);
}

void Heavy_Panoramizer::cReceive_iHbq2yZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Tmy1Smuh, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FG0OtkWC, m);
}

void Heavy_Panoramizer::cReceive_D6yaPrcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oxZEvaCw, HV_BINOP_ADD, 1, m, &cBinop_oxZEvaCw_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_L4t142nQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T6qCeL7Y, HV_BINOP_ADD, 1, m, &cBinop_T6qCeL7Y_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_44yLmCDV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2D7XDShQ, HV_BINOP_ADD, 1, m, &cBinop_2D7XDShQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ekxCaIOG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EeAIPlDz, HV_BINOP_ADD, 1, m, &cBinop_EeAIPlDz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_L9w5DFFh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ANGiGGxM, HV_BINOP_ADD, 1, m, &cBinop_ANGiGGxM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_58xRd3xU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_REjbwuAe, HV_BINOP_ADD, 1, m, &cBinop_REjbwuAe_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_6nPxR743_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_02qzk8Gt, HV_BINOP_ADD, 1, m, &cBinop_02qzk8Gt_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_tFi4hSNB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JQkemYWg, HV_BINOP_ADD, 1, m, &cBinop_JQkemYWg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_6GW2gei1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NFGMmH3L, HV_BINOP_ADD, 1, m, &cBinop_NFGMmH3L_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_GgRcbGmC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrZO29TU, HV_BINOP_ADD, 1, m, &cBinop_DrZO29TU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gtocELHj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OkkfNx3g, HV_BINOP_ADD, 1, m, &cBinop_OkkfNx3g_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_jUlersTI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TIbwMRr7, HV_BINOP_ADD, 1, m, &cBinop_TIbwMRr7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_3SSskh9I_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TM1IjIBz, HV_BINOP_ADD, 1, m, &cBinop_TM1IjIBz_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_bP17iNNf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wyPgA57W, HV_BINOP_ADD, 1, m, &cBinop_wyPgA57W_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_8LNH9P8P_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EqpQhRp, HV_BINOP_ADD, 1, m, &cBinop_9EqpQhRp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_3KM2e3ku_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8diG2pig, HV_BINOP_ADD, 1, m, &cBinop_8diG2pig_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_qCVXh9tG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y7Lmv1O0, HV_BINOP_ADD, 1, m, &cBinop_Y7Lmv1O0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YV0hmIVM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MXd6qz3M, HV_BINOP_ADD, 1, m, &cBinop_MXd6qz3M_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7oqxSDVt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MdDyB8Ls, HV_BINOP_ADD, 1, m, &cBinop_MdDyB8Ls_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_UA8i5bWI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zqJUY4V0, HV_BINOP_ADD, 1, m, &cBinop_zqJUY4V0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_SaD7KEPB_sendMessage);
}

void Heavy_Panoramizer::cSlice_xZmyxsRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_fx9SAm1u_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_fx9SAm1u_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSlice_HrwzS8Nl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LEFAhNhs_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_LEFAhNhs_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_3n3P1Bjg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_HrwzS8Nl, 0, m, &cSlice_HrwzS8Nl_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xZmyxsRH, 0, m, &cSlice_xZmyxsRH_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_fx9SAm1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.12f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_fNwMPrJo, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_crUSpZwm, m);
}

void Heavy_Panoramizer::sEnv_N4bFX7cm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_SfI5n2k5_sendMessage);
}

void Heavy_Panoramizer::cReceive_2yyzQek0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qo4SdCzc, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_IHYSOwIQ, m);
}

void Heavy_Panoramizer::cReceive_MPdnA1F6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eWqcDLAV, HV_BINOP_MULTIPLY, 1, m, &cBinop_eWqcDLAV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wo11dV7r, HV_BINOP_MULTIPLY, 1, m, &cBinop_wo11dV7r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rbJZJbmS, HV_BINOP_MULTIPLY, 1, m, &cBinop_rbJZJbmS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RCYSUZvx, HV_BINOP_MULTIPLY, 1, m, &cBinop_RCYSUZvx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m5VpCe1r, HV_BINOP_MULTIPLY, 1, m, &cBinop_m5VpCe1r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_siSxWMt5, HV_BINOP_MULTIPLY, 1, m, &cBinop_siSxWMt5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZiBnqS4, HV_BINOP_MULTIPLY, 1, m, &cBinop_SZiBnqS4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VehvOkZW, HV_BINOP_MULTIPLY, 1, m, &cBinop_VehvOkZW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7zZG4hv8, HV_BINOP_MULTIPLY, 1, m, &cBinop_7zZG4hv8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ryQC9hgD, HV_BINOP_MULTIPLY, 1, m, &cBinop_ryQC9hgD_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XPwdbsi8, HV_BINOP_MULTIPLY, 1, m, &cBinop_XPwdbsi8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NdSXAOmo, HV_BINOP_MULTIPLY, 1, m, &cBinop_NdSXAOmo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DlsEWDHp, HV_BINOP_MULTIPLY, 1, m, &cBinop_DlsEWDHp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_i4BXVu7M, HV_BINOP_MULTIPLY, 1, m, &cBinop_i4BXVu7M_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7dAFWq7s, HV_BINOP_MULTIPLY, 1, m, &cBinop_7dAFWq7s_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_97NV8XEK, HV_BINOP_MULTIPLY, 1, m, &cBinop_97NV8XEK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_q6RARPe0, HV_BINOP_MULTIPLY, 1, m, &cBinop_q6RARPe0_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1RwoNlcX, HV_BINOP_MULTIPLY, 1, m, &cBinop_1RwoNlcX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6JKcRCAq, HV_BINOP_MULTIPLY, 1, m, &cBinop_6JKcRCAq_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6SiG3as, HV_BINOP_MULTIPLY, 1, m, &cBinop_R6SiG3as_sendMessage);
}

void Heavy_Panoramizer::cBinop_SfI5n2k5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3n3P1Bjg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cReceive_cW9q0iEu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZHfKLawv, 0, m, &cVar_ZHfKLawv_sendMessage);
  cMsg_b7IYseV4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_E449kfwA, 0, m, &cVar_E449kfwA_sendMessage);
  cMsg_Cj5qMIpF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GSKkAtWd, 0, m, &cVar_GSKkAtWd_sendMessage);
  cMsg_oIOrxHJh_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RkRQ9YeV, 0, m, &cVar_RkRQ9YeV_sendMessage);
  cMsg_OPYs4AZb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_RsCWoG7b, 0, m, &cVar_RsCWoG7b_sendMessage);
  cMsg_5mKt1Z8E_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_s2nyp1TU, 0, m, &cVar_s2nyp1TU_sendMessage);
  cMsg_hcI5jnxK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vL0sjC3u, 0, m, &cVar_vL0sjC3u_sendMessage);
  cMsg_TvHkbCRT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Tt3BNlJ9, 0, m, &cVar_Tt3BNlJ9_sendMessage);
  cMsg_yRVDGQu1_sendMessage(_c, 0, m);
  cMsg_h32iFEKT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0vtB9sHC, 0, m, &cVar_0vtB9sHC_sendMessage);
  cMsg_VxlW84i5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jJp5cHSe, 0, m, &cVar_jJp5cHSe_sendMessage);
  cMsg_v66aF2qM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cVTWc9hF, 0, m, &cVar_cVTWc9hF_sendMessage);
  cMsg_l26kHkIC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Wcvun8XB, 0, m, &cVar_Wcvun8XB_sendMessage);
  cMsg_YigmQovg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HlzE6CZo, 0, m, &cVar_HlzE6CZo_sendMessage);
  cMsg_73TaS2Wm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_JvLnJLmK, 0, m, &cVar_JvLnJLmK_sendMessage);
  cMsg_f7HL7gDQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qQ4Pvsv3, 0, m, &cVar_qQ4Pvsv3_sendMessage);
  cMsg_cU7aIPzi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_SwME4N3A, 0, m, &cVar_SwME4N3A_sendMessage);
  cMsg_EB1c2ugA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HLqgiQZ5, 0, m, &cVar_HLqgiQZ5_sendMessage);
  cMsg_CEexP1Sc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8SG59YUA, 0, m, &cVar_8SG59YUA_sendMessage);
  cMsg_8GTzsoip_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_A9Mmxda7, 0, m, &cVar_A9Mmxda7_sendMessage);
  cMsg_TXFcWh95_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VSK1i4gq, 0, m, &cVar_VSK1i4gq_sendMessage);
  cMsg_18fGWkNn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2H4vKUdQ, 0, m, &cVar_2H4vKUdQ_sendMessage);
  cMsg_jlh4J90X_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HoMnd7aR, 0, m, &cVar_HoMnd7aR_sendMessage);
  cMsg_eLrocFQk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NrXaf2QS, 0, m, &cVar_NrXaf2QS_sendMessage);
  cMsg_sZEQuh1f_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iDbpmfUZ, 0, m, &cVar_iDbpmfUZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v9wRUjqb, 0, m, &cVar_v9wRUjqb_sendMessage);
  cMsg_E4693JeT_sendMessage(_c, 0, m);
  cMsg_xX1IFYEV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BUiVDeyR, 0, m, &cVar_BUiVDeyR_sendMessage);
  cMsg_dgU1HRM3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qMxGejsN, 0, m, &cVar_qMxGejsN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cpd2UBKm, 0, m, &cVar_cpd2UBKm_sendMessage);
  cMsg_0vAOm94p_sendMessage(_c, 0, m);
  cMsg_gSEi0MP3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xVsw7h5K, 0, m, &cVar_xVsw7h5K_sendMessage);
  cMsg_Rw15R2F4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KVxAJzWJ, 0, m, &cVar_KVxAJzWJ_sendMessage);
  cMsg_9MjcGY5a_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_aGFEWq0p, 0, m, &cVar_aGFEWq0p_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_H5abVFdb, 0, m, &cVar_H5abVFdb_sendMessage);
  cMsg_EofMUMNE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_67nxbiVh, 0, m, &cVar_67nxbiVh_sendMessage);
  cMsg_gpencWeu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_3whcrt98, 0, m, &cVar_3whcrt98_sendMessage);
  cMsg_rUVXzpMA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_a7zRHm4C, 0, m, &cVar_a7zRHm4C_sendMessage);
  cMsg_leAkLZTo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IYrdb4vu, 0, m, &cVar_IYrdb4vu_sendMessage);
  cMsg_l0O0f39b_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7jNNLtp9, 0, m, &cVar_7jNNLtp9_sendMessage);
  cMsg_fv5k9ZoK_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_7BjEuEMq, 0, m, &cVar_7BjEuEMq_sendMessage);
  cMsg_mJjiaCcv_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Z2oOxIOS, 0, m, &cVar_Z2oOxIOS_sendMessage);
  cMsg_yghQPCtg_sendMessage(_c, 0, m);
  cMsg_Vdb2ifWV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VwL0Erka, 0, m, &cVar_VwL0Erka_sendMessage);
  cMsg_OMh2pWNd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hGV4kkxp, 0, m, &cVar_hGV4kkxp_sendMessage);
  cMsg_oHfpUXkH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1CPJhgtM, 0, m, &cVar_1CPJhgtM_sendMessage);
  cMsg_W28v8gJA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QObWm807, 0, m, &cVar_QObWm807_sendMessage);
  cMsg_dYmzE5qV_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Rimh69z5, 0, m, &cVar_Rimh69z5_sendMessage);
  cMsg_COFiSWyg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9mbL52Se, 0, m, &cVar_9mbL52Se_sendMessage);
  cMsg_tvcJeUdz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TVcqWIxl, 0, m, &cVar_TVcqWIxl_sendMessage);
  cMsg_r4ZqrfWb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_GrfLG1lr, 0, m, &cVar_GrfLG1lr_sendMessage);
  cMsg_E721mtwp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_gZbQW9tf, 0, m, &cVar_gZbQW9tf_sendMessage);
  cMsg_HFRSZCoQ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9CiT0XBJ, 0, m, &cVar_9CiT0XBJ_sendMessage);
  cMsg_QB0Q9LLb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nk3liotL, 0, m, &cVar_nk3liotL_sendMessage);
  cMsg_0oVb4ai2_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KkAeBu11, 0, m, &cVar_KkAeBu11_sendMessage);
  cMsg_JLMbfIVE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_0xb9TyBH, 0, m, &cVar_0xb9TyBH_sendMessage);
  cMsg_wkkxZxWE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_2bG2qPKv, 0, m, &cVar_2bG2qPKv_sendMessage);
  cMsg_WLO9QnhF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I4KIxGIE, 0, m, &cVar_I4KIxGIE_sendMessage);
  cMsg_vn7afRFS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_p298ejCM, 0, m, &cVar_p298ejCM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hJBOOvUl, 0, m, &cVar_hJBOOvUl_sendMessage);
  cMsg_J98P6sm4_sendMessage(_c, 0, m);
  cMsg_eVIhQDAy_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_8LqQP0zp, 0, m, &cVar_8LqQP0zp_sendMessage);
  cMsg_j9A9vXRC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LoPeudQr, 0, m, &cVar_LoPeudQr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_w5L4UAGX, 0, m, &cVar_w5L4UAGX_sendMessage);
  cMsg_fBeyV6hj_sendMessage(_c, 0, m);
  cMsg_IvWadqeP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_S2ak9brN, 0, m, &cVar_S2ak9brN_sendMessage);
  cMsg_n3qpNKGp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_U5pjuaag, 0, m, &cVar_U5pjuaag_sendMessage);
  cMsg_Sb30glPr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AoIg2htY, 0, m, &cVar_AoIg2htY_sendMessage);
  cMsg_H2Cd2VL4_sendMessage(_c, 0, m);
  cMsg_TZ7B6vT7_sendMessage(_c, 0, m);
  cMsg_uV8zJlqL_sendMessage(_c, 0, m);
  cMsg_d8cP6z8N_sendMessage(_c, 0, m);
  cMsg_XcpXy9tk_sendMessage(_c, 0, m);
  cMsg_g4EGUXFU_sendMessage(_c, 0, m);
  cMsg_YfLJaKZ2_sendMessage(_c, 0, m);
  cMsg_VlZ1nzRw_sendMessage(_c, 0, m);
  cSwitchcase_lTZGKEQL_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_RiFyAnQU_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_DbdFDO2x_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_idq9tHma_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_NCJfMZX8_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_dvMvE5Gw_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_sB9h69hq_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Zg9CfO4T_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_BKZ6EDzA_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Oqkokcu0_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_5J6iAKm6_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Nkrny5fC_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_KP543Cgv_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Fh7cy1w7_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pVWUFGUy_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_cjIARpmH_onMessage(_c, NULL, 0, m, NULL);
  cMsg_115NfWMF_sendMessage(_c, 0, m);
  cSwitchcase_WSiBTsGN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_AFvN4LWu_onMessage(_c, NULL, 0, m, NULL);
  cMsg_SnOM6CvN_sendMessage(_c, 0, m);
  cSwitchcase_hFETmUea_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_DHyfsQyh_onMessage(_c, NULL, 0, m, NULL);
  cMsg_RWZ5ntok_sendMessage(_c, 0, m);
  cMsg_J59fSvqT_sendMessage(_c, 0, m);
  cMsg_pgXJIxBI_sendMessage(_c, 0, m);
  cMsg_PFp9Z0Vb_sendMessage(_c, 0, m);
  cMsg_ZgbzuhYB_sendMessage(_c, 0, m);
  cMsg_1qiuMwLM_sendMessage(_c, 0, m);
  cMsg_EpL2UT5Z_sendMessage(_c, 0, m);
  cMsg_vuVB0zOg_sendMessage(_c, 0, m);
  cSwitchcase_wnl6PRS2_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_haGv9p8c_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_xBJbRwRl_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_VnXPyCFC_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_DgxI1CUd_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_dT3jwOVx_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_LuVNWy2a_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_c8Y2hP0B_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_fRe9ms8e_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_NZhIU6RN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_FQWsfAw0_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_yL6TEXNc_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_7WE75Mnl_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_Cqk3IRHe_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_RgMxiVSS_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_jdRYxIed_onMessage(_c, NULL, 0, m, NULL);
  cMsg_I1BRAiaK_sendMessage(_c, 0, m);
  cSwitchcase_Zupcd3Zu_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_OVQro6zp_onMessage(_c, NULL, 0, m, NULL);
  cMsg_8PrQYkn7_sendMessage(_c, 0, m);
  cSwitchcase_iqW9Ir4K_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_24NHnkmU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_ZgbzuhYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_IYrdb4vu, 0, m, &cVar_IYrdb4vu_sendMessage);
}

void Heavy_Panoramizer::cBinop_9nmDqn6K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pKBInhZX_sendMessage);
}

void Heavy_Panoramizer::cRandom_e1hf7bw5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nmDqn6K, HV_BINOP_MULTIPLY, 0, m, &cBinop_9nmDqn6K_sendMessage);
}

void Heavy_Panoramizer::cUnop_pKBInhZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MdDyB8Ls, HV_BINOP_ADD, 0, m, &cBinop_MdDyB8Ls_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Vx2XJ9kz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IT22QJgE, 0, m, &cSlice_IT22QJgE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e1hf7bw5, 0, m, &cRandom_e1hf7bw5_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_IT22QJgE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_e1hf7bw5, 1, m, &cRandom_e1hf7bw5_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_jUlersTI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UIj3atru_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ssVld2FA_sendMessage);
}

void Heavy_Panoramizer::cVar_AoIg2htY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tP0XYTkJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_tP0XYTkJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_vStBCmph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ms8J593N_sendMessage);
}

void Heavy_Panoramizer::cBinop_6hZRAHCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vStBCmph_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_IOKj9Ecw_sendMessage);
}

void Heavy_Panoramizer::cBinop_Wka703CT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_6hZRAHCw_sendMessage);
}

void Heavy_Panoramizer::cBinop_h1PeoMDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tP0XYTkJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_tP0XYTkJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_BCxmNwo1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h1PeoMDW, HV_BINOP_DIVIDE, 0, m, &cBinop_h1PeoMDW_sendMessage);
}

void Heavy_Panoramizer::cMsg_zrnpIT2E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_6gIkMCcR_sendMessage);
}

void Heavy_Panoramizer::cUnop_6gIkMCcR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_BCxmNwo1_sendMessage);
}

void Heavy_Panoramizer::cSystem_5z1jsT4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h1PeoMDW, HV_BINOP_DIVIDE, 1, m, &cBinop_h1PeoMDW_sendMessage);
  cMsg_zrnpIT2E_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_Sb30glPr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5z1jsT4g_sendMessage);
}

void Heavy_Panoramizer::cBinop_tP0XYTkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_i0mI3u9u_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_ms8J593N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D7H7iYNt, m);
}

void Heavy_Panoramizer::cBinop_IOKj9Ecw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3fWZeJHE, m);
}

void Heavy_Panoramizer::cBinop_Pvw6fEFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Wka703CT_sendMessage);
}

void Heavy_Panoramizer::cMsg_i0mI3u9u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Pvw6fEFa_sendMessage);
}

void Heavy_Panoramizer::cSlice_L2rJVVdT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hLabLiaJ, 1, m, &cRandom_hLabLiaJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_EKrSX7A3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QTAmqfZr_sendMessage);
}

void Heavy_Panoramizer::cRandom_hLabLiaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_EKrSX7A3_sendMessage);
}

void Heavy_Panoramizer::cUnop_QTAmqfZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I4KIxGIE, 0, m, &cVar_I4KIxGIE_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_2nW7QU02_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_L2rJVVdT, 0, m, &cSlice_L2rJVVdT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hLabLiaJ, 0, m, &cRandom_hLabLiaJ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_GTVkKgMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HLpRHAhr_sendMessage);
}

void Heavy_Panoramizer::cUnop_HLpRHAhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TIbwMRr7, HV_BINOP_ADD, 0, m, &cBinop_TIbwMRr7_sendMessage);
}

void Heavy_Panoramizer::cSlice_mFs3rUtS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tDTnJi59, 1, m, &cRandom_tDTnJi59_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_k659IZ3c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_mFs3rUtS, 0, m, &cSlice_mFs3rUtS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_tDTnJi59, 0, m, &cRandom_tDTnJi59_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_tDTnJi59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GTVkKgMi, HV_BINOP_MULTIPLY, 0, m, &cBinop_GTVkKgMi_sendMessage);
}

void Heavy_Panoramizer::cMsg_TGcHRdV6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IUCPpPT9, HV_BINOP_SUBTRACT, 0, m, &cBinop_IUCPpPT9_sendMessage);
}

void Heavy_Panoramizer::cMsg_nDGQdjVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oJaXrasz, HV_BINOP_SUBTRACT, 0, m, &cBinop_oJaXrasz_sendMessage);
}

void Heavy_Panoramizer::cBinop_IUCPpPT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCXYxeGB, HV_BINOP_MULTIPLY, 1, m, &cBinop_lCXYxeGB_sendMessage);
}

void Heavy_Panoramizer::cRandom_yRkgIjd3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_iB0qqcJo_sendMessage);
}

void Heavy_Panoramizer::cSlice_LxlC4cHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yRkgIjd3, 1, m, &cRandom_yRkgIjd3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_iB0qqcJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_TTpjTy3p_sendMessage);
}

void Heavy_Panoramizer::cUnop_TTpjTy3p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XPwdbsi8, HV_BINOP_MULTIPLY, 0, m, &cBinop_XPwdbsi8_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Jrcn2qLh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LxlC4cHx, 0, m, &cSlice_LxlC4cHx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_yRkgIjd3, 0, m, &cRandom_yRkgIjd3_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_J59fSvqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_67nxbiVh, 0, m, &cVar_67nxbiVh_sendMessage);
}

void Heavy_Panoramizer::cBinop_7oqxSDVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hRTDO5E5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ecsS5h61_sendMessage);
}

void Heavy_Panoramizer::cCast_otMFQv8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Nw6ydCH6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_bP17iNNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_igmpyMk0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9lI9UNAU_sendMessage);
}

void Heavy_Panoramizer::cSlice_RIyq6S4E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vt3cpkRr, 1, m, &cRandom_vt3cpkRr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_vYnJ3n4Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NdSXAOmo, HV_BINOP_MULTIPLY, 0, m, &cBinop_NdSXAOmo_sendMessage);
}

void Heavy_Panoramizer::cRandom_vt3cpkRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_CRhnqEGq_sendMessage);
}

void Heavy_Panoramizer::cBinop_CRhnqEGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vYnJ3n4Q_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_5T2Fz1b5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_RIyq6S4E, 0, m, &cSlice_RIyq6S4E_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vt3cpkRr, 0, m, &cRandom_vt3cpkRr_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_nMzQy9Cr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GTVkKgMi, HV_BINOP_MULTIPLY, 1, m, &cBinop_GTVkKgMi_sendMessage);
}

void Heavy_Panoramizer::cMsg_wxAdmGBz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nMzQy9Cr, HV_BINOP_SUBTRACT, 0, m, &cBinop_nMzQy9Cr_sendMessage);
}

void Heavy_Panoramizer::cCast_0gUVKiRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WYtPuNOu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EMfTSTbp, 0, m, &cDelay_EMfTSTbp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eIlUgo6L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_otMFQv8P_sendMessage);
}

void Heavy_Panoramizer::cBinop_h2z5WqWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EMfTSTbp, 2, m, &cDelay_EMfTSTbp_sendMessage);
}

void Heavy_Panoramizer::cMsg_dYmzE5qV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RQopazlW_sendMessage);
}

void Heavy_Panoramizer::cSystem_RQopazlW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_7bNKwNB0_sendMessage);
}

void Heavy_Panoramizer::cBinop_zLQhiMg7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_h2z5WqWa_sendMessage);
}

void Heavy_Panoramizer::cDelay_EMfTSTbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EMfTSTbp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EMfTSTbp, 0, m, &cDelay_EMfTSTbp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eIlUgo6L_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_otMFQv8P_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_DgxI1CUd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_WYtPuNOu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_WYtPuNOu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0gUVKiRs_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_WYtPuNOu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_EMfTSTbp, 0, m, &cDelay_EMfTSTbp_sendMessage);
}

void Heavy_Panoramizer::cVar_Rimh69z5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zLQhiMg7, HV_BINOP_MULTIPLY, 0, m, &cBinop_zLQhiMg7_sendMessage);
}

void Heavy_Panoramizer::cBinop_7bNKwNB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zLQhiMg7, HV_BINOP_MULTIPLY, 1, m, &cBinop_zLQhiMg7_sendMessage);
}

void Heavy_Panoramizer::cPack_QY5fUg9e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_QSOD5GhG, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_RWZ5ntok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_H5abVFdb, 0, m, &cVar_H5abVFdb_sendMessage);
}

void Heavy_Panoramizer::cPack_2gdPS6y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZSzD7Aq4, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_aG0G46hl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ch7LQUCG, 0, m, &cSlice_ch7LQUCG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_APRW1RnW, 0, m, &cRandom_APRW1RnW_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_ch7LQUCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_APRW1RnW, 1, m, &cRandom_APRW1RnW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_APRW1RnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_26U5wjzH_sendMessage);
}

void Heavy_Panoramizer::cBinop_26U5wjzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_4I41fmxh_sendMessage);
}

void Heavy_Panoramizer::cUnop_4I41fmxh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_S2ak9brN, 0, m, &cVar_S2ak9brN_sendMessage);
}

void Heavy_Panoramizer::cBinop_XPwdbsi8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QY5fUg9e, 1, m, &cPack_QY5fUg9e_sendMessage);
}

void Heavy_Panoramizer::cCast_igmpyMk0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QvlwGOUg, HV_BINOP_SUBTRACT, 1, m, &cBinop_QvlwGOUg_sendMessage);
}

void Heavy_Panoramizer::cBinop_8cPl9fDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xpXOTOoH_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_xUMnWl8S_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_F5qoVR0X, 0, m, &cSlice_F5qoVR0X_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sSnyJVrM, 0, m, &cRandom_sSnyJVrM_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_F5qoVR0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sSnyJVrM, 1, m, &cRandom_sSnyJVrM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_sSnyJVrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_8cPl9fDF_sendMessage);
}

void Heavy_Panoramizer::cUnop_xpXOTOoH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_97NV8XEK, HV_BINOP_MULTIPLY, 0, m, &cBinop_97NV8XEK_sendMessage);
}

void Heavy_Panoramizer::cCast_1uUcmeRi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_doHX2n09_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QbCNMAkO, 0, m, &cDelay_QbCNMAkO_sendMessage);
  cSwitchcase_VcANR1pv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_yL6TEXNc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_doHX2n09_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_doHX2n09_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1uUcmeRi_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_KkAeBu11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RMr1zoBN, HV_BINOP_MULTIPLY, 0, m, &cBinop_RMr1zoBN_sendMessage);
}

void Heavy_Panoramizer::cSystem_xGRJ2E4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iS4iCalz_sendMessage);
}

void Heavy_Panoramizer::cMsg_0oVb4ai2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xGRJ2E4f_sendMessage);
}

void Heavy_Panoramizer::cBinop_KJof2lQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QbCNMAkO, 2, m, &cDelay_QbCNMAkO_sendMessage);
}

void Heavy_Panoramizer::cBinop_iS4iCalz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RMr1zoBN, HV_BINOP_MULTIPLY, 1, m, &cBinop_RMr1zoBN_sendMessage);
}

void Heavy_Panoramizer::cMsg_doHX2n09_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QbCNMAkO, 0, m, &cDelay_QbCNMAkO_sendMessage);
}

void Heavy_Panoramizer::cDelay_QbCNMAkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QbCNMAkO, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_QbCNMAkO, 0, m, &cDelay_QbCNMAkO_sendMessage);
  cSwitchcase_VcANR1pv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_RMr1zoBN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_KJof2lQv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_5VvGmzYo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kLpjVXcY, 0, m, &cSlice_kLpjVXcY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Pt3mL5LF, 0, m, &cRandom_Pt3mL5LF_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_VCGWdawf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DlsEWDHp, HV_BINOP_MULTIPLY, 0, m, &cBinop_DlsEWDHp_sendMessage);
}

void Heavy_Panoramizer::cRandom_Pt3mL5LF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_CRef6bKa_sendMessage);
}

void Heavy_Panoramizer::cBinop_CRef6bKa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_VCGWdawf_sendMessage);
}

void Heavy_Panoramizer::cSlice_kLpjVXcY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Pt3mL5LF, 1, m, &cRandom_Pt3mL5LF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSlice_QYDga5MX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FlrNeWWR, 1, m, &cRandom_FlrNeWWR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_FlrNeWWR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_F1HYl9Ff_sendMessage);
}

void Heavy_Panoramizer::cUnop_rFjyGNcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1RwoNlcX, HV_BINOP_MULTIPLY, 0, m, &cBinop_1RwoNlcX_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_GhjeJWhk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QYDga5MX, 0, m, &cSlice_QYDga5MX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_FlrNeWWR, 0, m, &cRandom_FlrNeWWR_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_F1HYl9Ff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_rFjyGNcn_sendMessage);
}

void Heavy_Panoramizer::cCast_hNvo2f0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nMzQy9Cr, HV_BINOP_SUBTRACT, 1, m, &cBinop_nMzQy9Cr_sendMessage);
}

void Heavy_Panoramizer::cSystem_LS0v5VYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xg9lSHE6_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_rUVXzpMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LS0v5VYw_sendMessage);
}

void Heavy_Panoramizer::cMsg_N4w4nMY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_5AtjtHWj_sendMessage);
}

void Heavy_Panoramizer::cBinop_TNXuwCKX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_t4ahA9wF, 1, m, &cIf_t4ahA9wF_sendMessage);
}

void Heavy_Panoramizer::cIf_t4ahA9wF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_eIuyJR4e_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_TQZl2tjE_sendMessage);
      cMsg_N4w4nMY3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cVar_3whcrt98_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_TNXuwCKX_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_t4ahA9wF, 0, m, &cIf_t4ahA9wF_sendMessage);
}

void Heavy_Panoramizer::cMsg_48bl0eU4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_juCOThsC_sendMessage);
}

void Heavy_Panoramizer::cMsg_Xg9lSHE6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_9IPef94K_sendMessage);
}

void Heavy_Panoramizer::cMsg_eIuyJR4e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_TQZl2tjE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_JzVog6Qk, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N5FDJeNJ, m);
}

void Heavy_Panoramizer::cBinop_5AtjtHWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JzVog6Qk, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_N5FDJeNJ, m);
}

void Heavy_Panoramizer::cBinop_TQZl2tjE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_48bl0eU4_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_pNpQEtVD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fkIhYJmU, m);
}

void Heavy_Panoramizer::cBinop_juCOThsC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xhFK8Ril_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_xhFK8Ril_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_pNpQEtVD_sendMessage);
}

void Heavy_Panoramizer::cBinop_9IPef94K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UQgpdGzs, m);
}

void Heavy_Panoramizer::cBinop_tyVfRPti_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7IvHNy0j_sendMessage);
}

void Heavy_Panoramizer::cSlice_ZXhtPODX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AKKl08uI, 1, m, &cRandom_AKKl08uI_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_AKKl08uI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_tyVfRPti_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_0e2yYjzu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZXhtPODX, 0, m, &cSlice_ZXhtPODX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_AKKl08uI, 0, m, &cRandom_AKKl08uI_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_7IvHNy0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0xb9TyBH, 0, m, &cVar_0xb9TyBH_sendMessage);
}

void Heavy_Panoramizer::cBinop_i4BXVu7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YgVJAkdc, 1, m, &cPack_YgVJAkdc_sendMessage);
}

void Heavy_Panoramizer::cBinop_SaD7KEPB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ckIrGuMr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_66anw0n7_sendMessage);
}

void Heavy_Panoramizer::cUnop_vvPOz2W6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q6RARPe0, HV_BINOP_MULTIPLY, 0, m, &cBinop_q6RARPe0_sendMessage);
}

void Heavy_Panoramizer::cSlice_STegrMsA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jOUF7oNU, 1, m, &cRandom_jOUF7oNU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_jOUF7oNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_KeJoR6UN_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_fIzgAomU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_STegrMsA, 0, m, &cSlice_STegrMsA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_jOUF7oNU, 0, m, &cRandom_jOUF7oNU_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_KeJoR6UN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vvPOz2W6_sendMessage);
}

void Heavy_Panoramizer::cCast_DUeeqTOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OJFdgOW9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_EhHCdDv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_A6LLXEAs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_i9gNTfNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gGQHPir9_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_fDfbOJY9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_MYM8RN1l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_1CPJhgtM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MRM6EQ7e, HV_BINOP_MULTIPLY, 0, m, &cBinop_MRM6EQ7e_sendMessage);
}

void Heavy_Panoramizer::cBinop_lbtHxrEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MRM6EQ7e, HV_BINOP_MULTIPLY, 1, m, &cBinop_MRM6EQ7e_sendMessage);
}

void Heavy_Panoramizer::cDelay_goARahQy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_goARahQy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_goARahQy, 0, m, &cDelay_goARahQy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D6OsDOPA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LNcCJvXP_sendMessage);
}

void Heavy_Panoramizer::cMsg_FTW59rJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_goARahQy, 0, m, &cDelay_goARahQy_sendMessage);
}

void Heavy_Panoramizer::cBinop_R1gcheAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_goARahQy, 2, m, &cDelay_goARahQy_sendMessage);
}

void Heavy_Panoramizer::cSystem_LNmFRei3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lbtHxrEr_sendMessage);
}

void Heavy_Panoramizer::cMsg_oHfpUXkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LNmFRei3_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_xBJbRwRl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_FTW59rJ9_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_FTW59rJ9_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X1W1LC3k_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_MRM6EQ7e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_R1gcheAI_sendMessage);
}

void Heavy_Panoramizer::cCast_X1W1LC3k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FTW59rJ9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_goARahQy, 0, m, &cDelay_goARahQy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D6OsDOPA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LNcCJvXP_sendMessage);
}

void Heavy_Panoramizer::cCast_UM5LCM73_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_qGqkfgEt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_zqJUY4V0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_YgVJAkdc, 0, m, &cPack_YgVJAkdc_sendMessage);
}

void Heavy_Panoramizer::cCast_PawHZ6Dw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uTehwL36, HV_BINOP_SUBTRACT, 1, m, &cBinop_uTehwL36_sendMessage);
}

void Heavy_Panoramizer::cBinop_TIbwMRr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lwPtQyQR, 0, m, &cPack_lwPtQyQR_sendMessage);
}

void Heavy_Panoramizer::cBinop_OkkfNx3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2gdPS6y9, 0, m, &cPack_2gdPS6y9_sendMessage);
}

void Heavy_Panoramizer::cCast_ecsS5h61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ivsj0UEJ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_ckIrGuMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IUCPpPT9, HV_BINOP_SUBTRACT, 1, m, &cBinop_IUCPpPT9_sendMessage);
}

void Heavy_Panoramizer::cCast_F6ciAt8Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_mA1yupT8_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_gGQHPir9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0CJlfBG, HV_BINOP_SUBTRACT, 0, m, &cBinop_m0CJlfBG_sendMessage);
}

void Heavy_Panoramizer::cBinop_d1gv9Wj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zjeSrEqz, HV_BINOP_MULTIPLY, 1, m, &cBinop_zjeSrEqz_sendMessage);
}

void Heavy_Panoramizer::cBinop_zjeSrEqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_93pWBzWG_sendMessage);
}

void Heavy_Panoramizer::cMsg_CLly6DTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3jfBPWx, 0, m, &cDelay_L3jfBPWx_sendMessage);
}

void Heavy_Panoramizer::cSystem_LAJeeuUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_d1gv9Wj3_sendMessage);
}

void Heavy_Panoramizer::cMsg_wkkxZxWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LAJeeuUS_sendMessage);
}

void Heavy_Panoramizer::cCast_W2UgWlIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CLly6DTF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3jfBPWx, 0, m, &cDelay_L3jfBPWx_sendMessage);
  cSwitchcase_0e2yYjzu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_93pWBzWG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3jfBPWx, 2, m, &cDelay_L3jfBPWx_sendMessage);
}

void Heavy_Panoramizer::cDelay_L3jfBPWx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_L3jfBPWx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_L3jfBPWx, 0, m, &cDelay_L3jfBPWx_sendMessage);
  cSwitchcase_0e2yYjzu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_2bG2qPKv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zjeSrEqz, HV_BINOP_MULTIPLY, 0, m, &cBinop_zjeSrEqz_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Cqk3IRHe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_CLly6DTF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_CLly6DTF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W2UgWlIW_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_m06eKL3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_JnyNkZkq_sendMessage);
}

void Heavy_Panoramizer::cBinop_JnyNkZkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nUvwd9qc_sendMessage);
}

void Heavy_Panoramizer::cSlice_0J2PplUS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_m06eKL3N, 1, m, &cRandom_m06eKL3N_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_nUvwd9qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_gZbQW9tf, 0, m, &cVar_gZbQW9tf_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_TRTOnIYs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0J2PplUS, 0, m, &cSlice_0J2PplUS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_m06eKL3N, 0, m, &cRandom_m06eKL3N_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_DlsEWDHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fjgWuEaJ, 1, m, &cPack_fjgWuEaJ_sendMessage);
}

void Heavy_Panoramizer::cRandom_k1ibx9JG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHeuDxPe, HV_BINOP_MULTIPLY, 0, m, &cBinop_gHeuDxPe_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_4gcv5h32_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_L7g5jaeS, 0, m, &cSlice_L7g5jaeS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k1ibx9JG, 0, m, &cRandom_k1ibx9JG_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_gHeuDxPe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PZF8mtda_sendMessage);
}

void Heavy_Panoramizer::cUnop_PZF8mtda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TM1IjIBz, HV_BINOP_ADD, 0, m, &cBinop_TM1IjIBz_sendMessage);
}

void Heavy_Panoramizer::cSlice_L7g5jaeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k1ibx9JG, 1, m, &cRandom_k1ibx9JG_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_16H3iY9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PzNonLr, 2, m, &cDelay_5PzNonLr_sendMessage);
}

void Heavy_Panoramizer::cSystem_VCLAjRN1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FPURW7zZ_sendMessage);
}

void Heavy_Panoramizer::cMsg_n3qpNKGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_VCLAjRN1_sendMessage);
}

void Heavy_Panoramizer::cDelay_5PzNonLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5PzNonLr, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PzNonLr, 0, m, &cDelay_5PzNonLr_sendMessage);
  cSwitchcase_aG0G46hl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_0ayKAcaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_H26NhxAB_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PzNonLr, 0, m, &cDelay_5PzNonLr_sendMessage);
  cSwitchcase_aG0G46hl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_U5pjuaag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p7b4qAhC, HV_BINOP_MULTIPLY, 0, m, &cBinop_p7b4qAhC_sendMessage);
}

void Heavy_Panoramizer::cBinop_FPURW7zZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p7b4qAhC, HV_BINOP_MULTIPLY, 1, m, &cBinop_p7b4qAhC_sendMessage);
}

void Heavy_Panoramizer::cMsg_H26NhxAB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5PzNonLr, 0, m, &cDelay_5PzNonLr_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_24NHnkmU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_H26NhxAB_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_H26NhxAB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0ayKAcaV_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_p7b4qAhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_16H3iY9R_sendMessage);
}

void Heavy_Panoramizer::cBinop_86GD9J5U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GA2N1RbR, HV_BINOP_MULTIPLY, 1, m, &cBinop_GA2N1RbR_sendMessage);
}

void Heavy_Panoramizer::cVar_8LqQP0zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GA2N1RbR, HV_BINOP_MULTIPLY, 0, m, &cBinop_GA2N1RbR_sendMessage);
}

void Heavy_Panoramizer::cBinop_GA2N1RbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_kxEXD7vn_sendMessage);
}

void Heavy_Panoramizer::cMsg_eVIhQDAy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZqMPlxhG_sendMessage);
}

void Heavy_Panoramizer::cSystem_ZqMPlxhG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_86GD9J5U_sendMessage);
}

void Heavy_Panoramizer::cCast_QiQYseLC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8PAI0DzZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_75X5i4dn, 0, m, &cDelay_75X5i4dn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uvpFheWB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F6ciAt8Z_sendMessage);
}

void Heavy_Panoramizer::cBinop_kxEXD7vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_75X5i4dn, 2, m, &cDelay_75X5i4dn_sendMessage);
}

void Heavy_Panoramizer::cMsg_8PAI0DzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_75X5i4dn, 0, m, &cDelay_75X5i4dn_sendMessage);
}

void Heavy_Panoramizer::cDelay_75X5i4dn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_75X5i4dn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_75X5i4dn, 0, m, &cDelay_75X5i4dn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uvpFheWB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F6ciAt8Z_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Zupcd3Zu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_8PAI0DzZ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_8PAI0DzZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QiQYseLC_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_uLgI6Rek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Jrcn2qLh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_hZNtVRRd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_GhjeJWhk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_qCVXh9tG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PawHZ6Dw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HdyBZV7I_sendMessage);
}

void Heavy_Panoramizer::cCast_5A5rfsu2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NicVLAIT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_oJaXrasz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JisdDsOM, HV_BINOP_MULTIPLY, 1, m, &cBinop_JisdDsOM_sendMessage);
}

void Heavy_Panoramizer::cSlice_JdI0ELyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cK2tqSG2, 1, m, &cRandom_cK2tqSG2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_cVP5v8PM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_i4BXVu7M, HV_BINOP_MULTIPLY, 0, m, &cBinop_i4BXVu7M_sendMessage);
}

void Heavy_Panoramizer::cBinop_KN3dEerH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_cVP5v8PM_sendMessage);
}

void Heavy_Panoramizer::cRandom_cK2tqSG2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_KN3dEerH_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_MYM8RN1l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JdI0ELyW, 0, m, &cSlice_JdI0ELyW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cK2tqSG2, 0, m, &cRandom_cK2tqSG2_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_FYOFqzKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wxAdmGBz_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_NdSXAOmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DKnWXe3e, 1, m, &cPack_DKnWXe3e_sendMessage);
}

void Heavy_Panoramizer::cCast_LNcCJvXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KqJtsqqe_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_zewJFUox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCtNYw6n, HV_BINOP_MULTIPLY, 1, m, &cBinop_vCtNYw6n_sendMessage);
}

void Heavy_Panoramizer::cCast_TfKvA7O5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wujP0INe, HV_BINOP_SUBTRACT, 1, m, &cBinop_wujP0INe_sendMessage);
}

void Heavy_Panoramizer::cBinop_R6SiG3as_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_lwPtQyQR, 1, m, &cPack_lwPtQyQR_sendMessage);
}

void Heavy_Panoramizer::cMsg_4yKzQ85y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zewJFUox, HV_BINOP_SUBTRACT, 0, m, &cBinop_zewJFUox_sendMessage);
}

void Heavy_Panoramizer::cBinop_UA8i5bWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BQVH8s1W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_i9gNTfNM_sendMessage);
}

void Heavy_Panoramizer::cDelay_btFSd5JE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_btFSd5JE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_btFSd5JE, 0, m, &cDelay_btFSd5JE_sendMessage);
  cSwitchcase_2nW7QU02_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSystem_1OdlRCdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qax6aHgL_sendMessage);
}

void Heavy_Panoramizer::cMsg_vn7afRFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1OdlRCdD_sendMessage);
}

void Heavy_Panoramizer::cCast_JQikBTOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l7ok8oOg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_btFSd5JE, 0, m, &cDelay_btFSd5JE_sendMessage);
  cSwitchcase_2nW7QU02_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_jdRYxIed_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_l7ok8oOg_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_l7ok8oOg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JQikBTOK_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_oAfaTUEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FIg8TJaX_sendMessage);
}

void Heavy_Panoramizer::cMsg_l7ok8oOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_btFSd5JE, 0, m, &cDelay_btFSd5JE_sendMessage);
}

void Heavy_Panoramizer::cBinop_FIg8TJaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_btFSd5JE, 2, m, &cDelay_btFSd5JE_sendMessage);
}

void Heavy_Panoramizer::cBinop_qax6aHgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oAfaTUEO, HV_BINOP_MULTIPLY, 1, m, &cBinop_oAfaTUEO_sendMessage);
}

void Heavy_Panoramizer::cVar_p298ejCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oAfaTUEO, HV_BINOP_MULTIPLY, 0, m, &cBinop_oAfaTUEO_sendMessage);
}

void Heavy_Panoramizer::cBinop_aLqV9Fwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_wx4dqloI_sendMessage);
}

void Heavy_Panoramizer::cRandom_dYxSn4EF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_aLqV9Fwc_sendMessage);
}

void Heavy_Panoramizer::cUnop_wx4dqloI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7dAFWq7s, HV_BINOP_MULTIPLY, 0, m, &cBinop_7dAFWq7s_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_OJFdgOW9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_O5bha7Qp, 0, m, &cSlice_O5bha7Qp_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dYxSn4EF, 0, m, &cRandom_dYxSn4EF_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_O5bha7Qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_dYxSn4EF, 1, m, &cRandom_dYxSn4EF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_m0CJlfBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9nmDqn6K, HV_BINOP_MULTIPLY, 1, m, &cBinop_9nmDqn6K_sendMessage);
}

void Heavy_Panoramizer::cBinop_TM1IjIBz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uFl3j5x0, 0, m, &cPack_uFl3j5x0_sendMessage);
}

void Heavy_Panoramizer::cMsg_PFp9Z0Vb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_a7zRHm4C, 0, m, &cVar_a7zRHm4C_sendMessage);
}

void Heavy_Panoramizer::cCast_uaGoykXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nDGQdjVD_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_lCXYxeGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2SLHn5BX_sendMessage);
}

void Heavy_Panoramizer::cUnop_2SLHn5BX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zqJUY4V0, HV_BINOP_ADD, 0, m, &cBinop_zqJUY4V0_sendMessage);
}

void Heavy_Panoramizer::cRandom_bKiFO9os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lCXYxeGB, HV_BINOP_MULTIPLY, 0, m, &cBinop_lCXYxeGB_sendMessage);
}

void Heavy_Panoramizer::cSlice_2HMH5zZO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bKiFO9os, 1, m, &cRandom_bKiFO9os_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_QPcqCZAX_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2HMH5zZO, 0, m, &cSlice_2HMH5zZO_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_bKiFO9os, 0, m, &cRandom_bKiFO9os_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSwitchcase_y6LYGUeg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1ebq28wB, 0, m, &cSlice_1ebq28wB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QgqgmeLn, 0, m, &cRandom_QgqgmeLn_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_OGPWX8Tg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_KACGLjt5_sendMessage);
}

void Heavy_Panoramizer::cSlice_1ebq28wB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QgqgmeLn, 1, m, &cRandom_QgqgmeLn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_QgqgmeLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_OGPWX8Tg_sendMessage);
}

void Heavy_Panoramizer::cUnop_KACGLjt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TVcqWIxl, 0, m, &cVar_TVcqWIxl_sendMessage);
}

void Heavy_Panoramizer::cCast_D6OsDOPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xUMnWl8S_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_5yObLFH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_nAXmbsNb_sendMessage);
}

void Heavy_Panoramizer::cSystem_Hg8OselG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qXkIYzEh_sendMessage);
}

void Heavy_Panoramizer::cMsg_Vdb2ifWV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Hg8OselG_sendMessage);
}

void Heavy_Panoramizer::cCast_GhrSnamJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YUFpHtVM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LelpA6c5, 0, m, &cDelay_LelpA6c5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DUeeqTOg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rvBxuAyw_sendMessage);
}

void Heavy_Panoramizer::cMsg_YUFpHtVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_LelpA6c5, 0, m, &cDelay_LelpA6c5_sendMessage);
}

void Heavy_Panoramizer::cBinop_qXkIYzEh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yObLFH6, HV_BINOP_MULTIPLY, 1, m, &cBinop_5yObLFH6_sendMessage);
}

void Heavy_Panoramizer::cVar_VwL0Erka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5yObLFH6, HV_BINOP_MULTIPLY, 0, m, &cBinop_5yObLFH6_sendMessage);
}

void Heavy_Panoramizer::cDelay_LelpA6c5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LelpA6c5, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LelpA6c5, 0, m, &cDelay_LelpA6c5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DUeeqTOg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rvBxuAyw_sendMessage);
}

void Heavy_Panoramizer::cBinop_nAXmbsNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_LelpA6c5, 2, m, &cDelay_LelpA6c5_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_wnl6PRS2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_YUFpHtVM_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YUFpHtVM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GhrSnamJ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cPack_87Z2lTuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_GP3GIsdf, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_9EqpQhRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pDSNY4JN, 0, m, &cPack_pDSNY4JN_sendMessage);
}

void Heavy_Panoramizer::cCast_mZgwgDdN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_0DNSpdia_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_97NV8XEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WapmcKov, 1, m, &cPack_WapmcKov_sendMessage);
}

void Heavy_Panoramizer::cMsg_8PrQYkn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_w5L4UAGX, 0, m, &cVar_w5L4UAGX_sendMessage);
}

void Heavy_Panoramizer::cMsg_FRZB7cUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vbIiOsd4_sendMessage);
}

void Heavy_Panoramizer::cBinop_pdprc17s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_W3bVcBRv, 1, m, &cIf_W3bVcBRv_sendMessage);
}

void Heavy_Panoramizer::cIf_W3bVcBRv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LLR87FMv_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_uGb52Ba0_sendMessage);
      cMsg_y6XHtYAn_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_vbIiOsd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rjShnytN_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_LLR87FMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_uGb52Ba0_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_kTZUn6et, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pLnqn8sF, m);
}

void Heavy_Panoramizer::cBinop_uGb52Ba0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FRZB7cUZ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_pYi7r4Mr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_kTZUn6et, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pLnqn8sF, m);
}

void Heavy_Panoramizer::cBinop_Ly4dVi5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KQlixPEc, m);
}

void Heavy_Panoramizer::cMsg_gpencWeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_87tGntFf_sendMessage);
}

void Heavy_Panoramizer::cSystem_87tGntFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2IjeyCZz_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_rjShnytN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_s2yCPnop_sendMessage);
}

void Heavy_Panoramizer::cMsg_2IjeyCZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Ly4dVi5J_sendMessage);
}

void Heavy_Panoramizer::cBinop_s2yCPnop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aBLKlM4i, m);
}

void Heavy_Panoramizer::cMsg_y6XHtYAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pYi7r4Mr_sendMessage);
}

void Heavy_Panoramizer::cVar_67nxbiVh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_pdprc17s_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_W3bVcBRv, 0, m, &cIf_W3bVcBRv_sendMessage);
}

void Heavy_Panoramizer::cRandom_g25evTaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_azhHtq1F_sendMessage);
}

void Heavy_Panoramizer::cSlice_AdAmsVIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_g25evTaz, 1, m, &cRandom_g25evTaz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_azhHtq1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_OaEkR1L9_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_XM5zFE4k_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AdAmsVIg, 0, m, &cSlice_AdAmsVIg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_g25evTaz, 0, m, &cRandom_g25evTaz_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_OaEkR1L9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VwL0Erka, 0, m, &cVar_VwL0Erka_sendMessage);
}

void Heavy_Panoramizer::cCast_jtZwJ3el_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QPcqCZAX_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_8LNH9P8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v2Al8zXD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XBzKRwQF_sendMessage);
}

void Heavy_Panoramizer::cUnop_Xwmcl5Sm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_R6SiG3as, HV_BINOP_MULTIPLY, 0, m, &cBinop_R6SiG3as_sendMessage);
}

void Heavy_Panoramizer::cRandom_Rm7Hix70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_JDp52ln1_sendMessage);
}

void Heavy_Panoramizer::cBinop_JDp52ln1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Xwmcl5Sm_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_NicVLAIT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AF0gq36c, 0, m, &cSlice_AF0gq36c_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Rm7Hix70, 0, m, &cRandom_Rm7Hix70_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_AF0gq36c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Rm7Hix70, 1, m, &cRandom_Rm7Hix70_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_Ci77lQUi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KMPh5a37, 0, m, &cDelay_KMPh5a37_sendMessage);
}

void Heavy_Panoramizer::cCast_Uqeg9aek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ci77lQUi_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KMPh5a37, 0, m, &cDelay_KMPh5a37_sendMessage);
  cSwitchcase_ndVTOlCM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_j9A9vXRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OTe9zWK7_sendMessage);
}

void Heavy_Panoramizer::cSystem_OTe9zWK7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AyhBSd2O_sendMessage);
}

void Heavy_Panoramizer::cBinop_AyhBSd2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LbEEq3vT, HV_BINOP_MULTIPLY, 1, m, &cBinop_LbEEq3vT_sendMessage);
}

void Heavy_Panoramizer::cBinop_tAPAO7dW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KMPh5a37, 2, m, &cDelay_KMPh5a37_sendMessage);
}

void Heavy_Panoramizer::cDelay_KMPh5a37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KMPh5a37, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KMPh5a37, 0, m, &cDelay_KMPh5a37_sendMessage);
  cSwitchcase_ndVTOlCM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_LoPeudQr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LbEEq3vT, HV_BINOP_MULTIPLY, 0, m, &cBinop_LbEEq3vT_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_OVQro6zp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_Ci77lQUi_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Ci77lQUi_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Uqeg9aek_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_LbEEq3vT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_tAPAO7dW_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_uUQWb2D5_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sFPWMr6V, 0, m, &cSlice_sFPWMr6V_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pKj7a8E8, 0, m, &cRandom_pKj7a8E8_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_pKj7a8E8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_gkCJOzuR_sendMessage);
}

void Heavy_Panoramizer::cSlice_sFPWMr6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pKj7a8E8, 1, m, &cRandom_pKj7a8E8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_gkCJOzuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_mtWFkBSm_sendMessage);
}

void Heavy_Panoramizer::cUnop_mtWFkBSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1CPJhgtM, 0, m, &cVar_1CPJhgtM_sendMessage);
}

void Heavy_Panoramizer::cMsg_pgXJIxBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3whcrt98, 0, m, &cVar_3whcrt98_sendMessage);
}

void Heavy_Panoramizer::cDelay_Q3exlxlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Q3exlxlx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q3exlxlx, 0, m, &cDelay_Q3exlxlx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fDfbOJY9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jtZwJ3el_sendMessage);
}

void Heavy_Panoramizer::cBinop_L369eW1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_fp7Zzke9_sendMessage);
}

void Heavy_Panoramizer::cBinop_fp7Zzke9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q3exlxlx, 2, m, &cDelay_Q3exlxlx_sendMessage);
}

void Heavy_Panoramizer::cVar_I4KIxGIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L369eW1x, HV_BINOP_MULTIPLY, 0, m, &cBinop_L369eW1x_sendMessage);
}

void Heavy_Panoramizer::cMsg_WLO9QnhF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L2Fqcokg_sendMessage);
}

void Heavy_Panoramizer::cSystem_L2Fqcokg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fs9oD97e_sendMessage);
}

void Heavy_Panoramizer::cBinop_fs9oD97e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L369eW1x, HV_BINOP_MULTIPLY, 1, m, &cBinop_L369eW1x_sendMessage);
}

void Heavy_Panoramizer::cMsg_FSPcLB1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q3exlxlx, 0, m, &cDelay_Q3exlxlx_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_RgMxiVSS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_FSPcLB1H_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_FSPcLB1H_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R1JnBURi_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_R1JnBURi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FSPcLB1H_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Q3exlxlx, 0, m, &cDelay_Q3exlxlx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fDfbOJY9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jtZwJ3el_sendMessage);
}

void Heavy_Panoramizer::cMsg_mUvP5eYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uTehwL36, HV_BINOP_SUBTRACT, 0, m, &cBinop_uTehwL36_sendMessage);
}

void Heavy_Panoramizer::cBinop_MXd6qz3M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_DKnWXe3e, 0, m, &cPack_DKnWXe3e_sendMessage);
}

void Heavy_Panoramizer::cCast_A3953s56_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5VvGmzYo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_wujP0INe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbTkVbgg, HV_BINOP_MULTIPLY, 1, m, &cBinop_FbTkVbgg_sendMessage);
}

void Heavy_Panoramizer::cMsg_2GGn5Ydf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_E0b9uZnX, HV_BINOP_SUBTRACT, 0, m, &cBinop_E0b9uZnX_sendMessage);
}

void Heavy_Panoramizer::cCast_z1EvaZAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jumGWHuC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PTQLRIQ, 0, m, &cDelay_9PTQLRIQ_sendMessage);
  cSwitchcase_uUQWb2D5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_SM6eba2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tJqgrv0Z, HV_BINOP_MULTIPLY, 1, m, &cBinop_tJqgrv0Z_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_VnXPyCFC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_jumGWHuC_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_jumGWHuC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_z1EvaZAw_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cDelay_9PTQLRIQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9PTQLRIQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PTQLRIQ, 0, m, &cDelay_9PTQLRIQ_sendMessage);
  cSwitchcase_uUQWb2D5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_jumGWHuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PTQLRIQ, 0, m, &cDelay_9PTQLRIQ_sendMessage);
}

void Heavy_Panoramizer::cBinop_v2dxImVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PTQLRIQ, 2, m, &cDelay_9PTQLRIQ_sendMessage);
}

void Heavy_Panoramizer::cSystem_SBkQfgd1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SM6eba2G_sendMessage);
}

void Heavy_Panoramizer::cMsg_W28v8gJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SBkQfgd1_sendMessage);
}

void Heavy_Panoramizer::cVar_QObWm807_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tJqgrv0Z, HV_BINOP_MULTIPLY, 0, m, &cBinop_tJqgrv0Z_sendMessage);
}

void Heavy_Panoramizer::cBinop_tJqgrv0Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_v2dxImVW_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_JQVQUzcc_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_R85nrMLB, 0, m, &cSlice_R85nrMLB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rxPOkgEX, 0, m, &cRandom_rxPOkgEX_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_V5jGsOxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_6zWzkMES_sendMessage);
}

void Heavy_Panoramizer::cSlice_R85nrMLB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rxPOkgEX, 1, m, &cRandom_rxPOkgEX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_rxPOkgEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_V5jGsOxk_sendMessage);
}

void Heavy_Panoramizer::cUnop_6zWzkMES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6JKcRCAq, HV_BINOP_MULTIPLY, 0, m, &cBinop_6JKcRCAq_sendMessage);
}

void Heavy_Panoramizer::cMsg_EpL2UT5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7BjEuEMq, 0, m, &cVar_7BjEuEMq_sendMessage);
}

void Heavy_Panoramizer::cSlice_8uyorSTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WCJt85Be, 1, m, &cRandom_WCJt85Be_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_vCtNYw6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sJGWDbCz_sendMessage);
}

void Heavy_Panoramizer::cUnop_sJGWDbCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wyPgA57W, HV_BINOP_ADD, 0, m, &cBinop_wyPgA57W_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_KqJtsqqe_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8uyorSTf, 0, m, &cSlice_8uyorSTf_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WCJt85Be, 0, m, &cRandom_WCJt85Be_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_WCJt85Be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCtNYw6n, HV_BINOP_MULTIPLY, 0, m, &cBinop_vCtNYw6n_sendMessage);
}

void Heavy_Panoramizer::cBinop_kBLpUdPN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jIRlihq3, m);
}

void Heavy_Panoramizer::cBinop_gNQ7lpYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jy3S0COU, m);
}

void Heavy_Panoramizer::cSystem_sBdPNqOb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_CdePAndB_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_leAkLZTo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sBdPNqOb_sendMessage);
}

void Heavy_Panoramizer::cBinop_5jHh0977_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8JZyEBdE_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_xfVuvDsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_5jHh0977_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_vchyr2pd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_emuooEVs, m);
}

void Heavy_Panoramizer::cMsg_XnluhnBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_PeKCboAg_sendMessage);
}

void Heavy_Panoramizer::cMsg_nb5KqkMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_kBLpUdPN_sendMessage);
}

void Heavy_Panoramizer::cBinop_lMFj0RYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nb5KqkMt_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_PeKCboAg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vchyr2pd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_emuooEVs, m);
}

void Heavy_Panoramizer::cVar_a7zRHm4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_xHYQNAAl_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_b7S56lnw, 0, m, &cIf_b7S56lnw_sendMessage);
}

void Heavy_Panoramizer::cBinop_xHYQNAAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_b7S56lnw, 1, m, &cIf_b7S56lnw_sendMessage);
}

void Heavy_Panoramizer::cIf_b7S56lnw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_xfVuvDsk_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_5jHh0977_sendMessage);
      cMsg_XnluhnBq_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_8JZyEBdE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lMFj0RYZ_sendMessage);
}

void Heavy_Panoramizer::cMsg_CdePAndB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gNQ7lpYb_sendMessage);
}

void Heavy_Panoramizer::cPack_lwPtQyQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_n79ul0lu, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_F6h0inRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5T2Fz1b5_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_BQVH8s1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m0CJlfBG, HV_BINOP_SUBTRACT, 1, m, &cBinop_m0CJlfBG_sendMessage);
}

void Heavy_Panoramizer::cBinop_dempEsex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OwNGCuM2, HV_BINOP_MULTIPLY, 1, m, &cBinop_OwNGCuM2_sendMessage);
}

void Heavy_Panoramizer::cBinop_OwNGCuM2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FaYdsN7a_sendMessage);
}

void Heavy_Panoramizer::cBinop_FaYdsN7a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_48SpZAm6, 2, m, &cDelay_48SpZAm6_sendMessage);
}

void Heavy_Panoramizer::cDelay_48SpZAm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_48SpZAm6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_48SpZAm6, 0, m, &cDelay_48SpZAm6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F6h0inRF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mZgwgDdN_sendMessage);
}

void Heavy_Panoramizer::cMsg_8s77YTiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_48SpZAm6, 0, m, &cDelay_48SpZAm6_sendMessage);
}

void Heavy_Panoramizer::cCast_am2V5rGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8s77YTiF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_48SpZAm6, 0, m, &cDelay_48SpZAm6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_F6h0inRF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mZgwgDdN_sendMessage);
}

void Heavy_Panoramizer::cVar_nk3liotL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OwNGCuM2, HV_BINOP_MULTIPLY, 0, m, &cBinop_OwNGCuM2_sendMessage);
}

void Heavy_Panoramizer::cSystem_J3tsjCHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dempEsex_sendMessage);
}

void Heavy_Panoramizer::cMsg_QB0Q9LLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_J3tsjCHo_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_FQWsfAw0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_8s77YTiF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_8s77YTiF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_am2V5rGE_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cPack_DKnWXe3e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VJ2INnuh, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_lNrAdeKR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6EDuUF, 2, m, &cDelay_yI6EDuUF_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_iqW9Ir4K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_3l1zt6CF_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_3l1zt6CF_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cdEsxwZj_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_7tinuCsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lNrAdeKR_sendMessage);
}

void Heavy_Panoramizer::cMsg_3l1zt6CF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6EDuUF, 0, m, &cDelay_yI6EDuUF_sendMessage);
}

void Heavy_Panoramizer::cMsg_IvWadqeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JQ7u5BOA_sendMessage);
}

void Heavy_Panoramizer::cSystem_JQ7u5BOA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GPf10WUa_sendMessage);
}

void Heavy_Panoramizer::cCast_cdEsxwZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3l1zt6CF_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6EDuUF, 0, m, &cDelay_yI6EDuUF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5A5rfsu2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FVRESX0E_sendMessage);
}

void Heavy_Panoramizer::cDelay_yI6EDuUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yI6EDuUF, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yI6EDuUF, 0, m, &cDelay_yI6EDuUF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5A5rfsu2_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FVRESX0E_sendMessage);
}

void Heavy_Panoramizer::cVar_S2ak9brN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7tinuCsZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_7tinuCsZ_sendMessage);
}

void Heavy_Panoramizer::cBinop_GPf10WUa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7tinuCsZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_7tinuCsZ_sendMessage);
}

void Heavy_Panoramizer::cBinop_q6RARPe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_pDSNY4JN, 1, m, &cPack_pDSNY4JN_sendMessage);
}

void Heavy_Panoramizer::cMsg_COFiSWyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HYeYW8zh_sendMessage);
}

void Heavy_Panoramizer::cSystem_HYeYW8zh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SIdQyQPH_sendMessage);
}

void Heavy_Panoramizer::cBinop_tnPboza7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_r6G1ZrhK, 2, m, &cDelay_r6G1ZrhK_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_dT3jwOVx_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_8xkJ8jp4_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_8xkJ8jp4_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_J1WHoWin_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_qfA2o0vD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_tnPboza7_sendMessage);
}

void Heavy_Panoramizer::cBinop_SIdQyQPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qfA2o0vD, HV_BINOP_MULTIPLY, 1, m, &cBinop_qfA2o0vD_sendMessage);
}

void Heavy_Panoramizer::cMsg_8xkJ8jp4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_r6G1ZrhK, 0, m, &cDelay_r6G1ZrhK_sendMessage);
}

void Heavy_Panoramizer::cCast_J1WHoWin_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8xkJ8jp4_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r6G1ZrhK, 0, m, &cDelay_r6G1ZrhK_sendMessage);
  cSwitchcase_2ZbEujOQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_9mbL52Se_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qfA2o0vD, HV_BINOP_MULTIPLY, 0, m, &cBinop_qfA2o0vD_sendMessage);
}

void Heavy_Panoramizer::cDelay_r6G1ZrhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_r6G1ZrhK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_r6G1ZrhK, 0, m, &cDelay_r6G1ZrhK_sendMessage);
  cSwitchcase_2ZbEujOQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cUnop_R7qTYARZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8diG2pig, HV_BINOP_ADD, 0, m, &cBinop_8diG2pig_sendMessage);
}

void Heavy_Panoramizer::cRandom_OfUJZT0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eUwKcqKf, HV_BINOP_MULTIPLY, 0, m, &cBinop_eUwKcqKf_sendMessage);
}

void Heavy_Panoramizer::cSlice_hZEWfu19_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OfUJZT0F, 1, m, &cRandom_OfUJZT0F_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_qGqkfgEt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hZEWfu19, 0, m, &cSlice_hZEWfu19_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OfUJZT0F, 0, m, &cRandom_OfUJZT0F_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_eUwKcqKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_R7qTYARZ_sendMessage);
}

void Heavy_Panoramizer::cBinop_E0b9uZnX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tg84tVVm, HV_BINOP_MULTIPLY, 1, m, &cBinop_Tg84tVVm_sendMessage);
}

void Heavy_Panoramizer::cBinop_uTehwL36_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eUwKcqKf, HV_BINOP_MULTIPLY, 1, m, &cBinop_eUwKcqKf_sendMessage);
}

void Heavy_Panoramizer::cBinop_6TzJ2Cay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FTaC3PcZ, 2, m, &cDelay_FTaC3PcZ_sendMessage);
}

void Heavy_Panoramizer::cCast_y6hmWlmA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iY5NZpbZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FTaC3PcZ, 0, m, &cDelay_FTaC3PcZ_sendMessage);
  cSwitchcase_y6LYGUeg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_QuGScXHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_6TzJ2Cay_sendMessage);
}

void Heavy_Panoramizer::cBinop_22k6eXzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QuGScXHX, HV_BINOP_MULTIPLY, 1, m, &cBinop_QuGScXHX_sendMessage);
}

void Heavy_Panoramizer::cVar_GrfLG1lr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QuGScXHX, HV_BINOP_MULTIPLY, 0, m, &cBinop_QuGScXHX_sendMessage);
}

void Heavy_Panoramizer::cMsg_iY5NZpbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FTaC3PcZ, 0, m, &cDelay_FTaC3PcZ_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_c8Y2hP0B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_iY5NZpbZ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_iY5NZpbZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_y6hmWlmA_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_r4ZqrfWb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0aG7pRRJ_sendMessage);
}

void Heavy_Panoramizer::cSystem_0aG7pRRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_22k6eXzO_sendMessage);
}

void Heavy_Panoramizer::cDelay_FTaC3PcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FTaC3PcZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FTaC3PcZ, 0, m, &cDelay_FTaC3PcZ_sendMessage);
  cSwitchcase_y6LYGUeg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_XBzKRwQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4yKzQ85y_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_qiApx25y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yak1lkHk_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_JLMbfIVE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sLo3ijjn_sendMessage);
}

void Heavy_Panoramizer::cSystem_sLo3ijjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_1fYFz9ZT_sendMessage);
}

void Heavy_Panoramizer::cDelay_yvbpZCsx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yvbpZCsx, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvbpZCsx, 0, m, &cDelay_yvbpZCsx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A3953s56_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_npMzyNMi_sendMessage);
}

void Heavy_Panoramizer::cBinop_1fYFz9ZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m1K4zmy2, HV_BINOP_MULTIPLY, 1, m, &cBinop_m1K4zmy2_sendMessage);
}

void Heavy_Panoramizer::cCast_mdkdRl1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EPrMgCg2_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvbpZCsx, 0, m, &cDelay_yvbpZCsx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_A3953s56_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_npMzyNMi_sendMessage);
}

void Heavy_Panoramizer::cBinop_VicjiHWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvbpZCsx, 2, m, &cDelay_yvbpZCsx_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_7WE75Mnl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_EPrMgCg2_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_EPrMgCg2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mdkdRl1c_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_EPrMgCg2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yvbpZCsx, 0, m, &cDelay_yvbpZCsx_sendMessage);
}

void Heavy_Panoramizer::cBinop_m1K4zmy2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VicjiHWT_sendMessage);
}

void Heavy_Panoramizer::cVar_0xb9TyBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m1K4zmy2, HV_BINOP_MULTIPLY, 0, m, &cBinop_m1K4zmy2_sendMessage);
}

void Heavy_Panoramizer::cBinop_6JKcRCAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_2gdPS6y9, 1, m, &cPack_2gdPS6y9_sendMessage);
}

void Heavy_Panoramizer::cPack_pDSNY4JN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_6UOJDo9X, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_1qiuMwLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_7jNNLtp9, 0, m, &cVar_7jNNLtp9_sendMessage);
}

void Heavy_Panoramizer::cMsg_I1BRAiaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_hJBOOvUl, 0, m, &cVar_hJBOOvUl_sendMessage);
}

void Heavy_Panoramizer::cPack_uFl3j5x0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_DtYYCGqY, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_phorwBp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NGt9SaAS_sendMessage);
}

void Heavy_Panoramizer::cBinop_E0VZ3cOj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IW5wgeRk, 1, m, &cIf_IW5wgeRk_sendMessage);
}

void Heavy_Panoramizer::cIf_IW5wgeRk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_rm9eUa1c_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_GAshXQ0E_sendMessage);
      cMsg_BnvR15BJ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_FMkWujKB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JX18KPrU_sendMessage);
}

void Heavy_Panoramizer::cBinop_JX18KPrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m7Ud7IA0_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_NN0ekAZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_EHX6psI8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bKCRbc8J, m);
}

void Heavy_Panoramizer::cBinop_GAshXQ0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FMkWujKB_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_rm9eUa1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_GAshXQ0E_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_EHX6psI8, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bKCRbc8J, m);
}

void Heavy_Panoramizer::cBinop_f0xx7Z6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5QxTXgK3, m);
}

void Heavy_Panoramizer::cMsg_m7Ud7IA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_f0xx7Z6B_sendMessage);
}

void Heavy_Panoramizer::cVar_H5abVFdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_E0VZ3cOj_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IW5wgeRk, 0, m, &cIf_IW5wgeRk_sendMessage);
}

void Heavy_Panoramizer::cBinop_NGt9SaAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PG91io1z, m);
}

void Heavy_Panoramizer::cMsg_BnvR15BJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NN0ekAZs_sendMessage);
}

void Heavy_Panoramizer::cSystem_1wfIO3Ei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_phorwBp9_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_EofMUMNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1wfIO3Ei_sendMessage);
}

void Heavy_Panoramizer::cCast_v2Al8zXD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zewJFUox, HV_BINOP_SUBTRACT, 1, m, &cBinop_zewJFUox_sendMessage);
}

void Heavy_Panoramizer::cBinop_8diG2pig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_87Z2lTuD, 0, m, &cPack_87Z2lTuD_sendMessage);
}

void Heavy_Panoramizer::cDelay_vIM2Idic_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vIM2Idic, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIM2Idic, 0, m, &cDelay_vIM2Idic_sendMessage);
  cSwitchcase_TRTOnIYs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_a9zQ451R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIM2Idic, 2, m, &cDelay_vIM2Idic_sendMessage);
}

void Heavy_Panoramizer::cVar_9CiT0XBJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zgX4qG2W, HV_BINOP_MULTIPLY, 0, m, &cBinop_zgX4qG2W_sendMessage);
}

void Heavy_Panoramizer::cMsg_HFRSZCoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZNgrJphN_sendMessage);
}

void Heavy_Panoramizer::cSystem_ZNgrJphN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_0FySX1SI_sendMessage);
}

void Heavy_Panoramizer::cBinop_0FySX1SI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zgX4qG2W, HV_BINOP_MULTIPLY, 1, m, &cBinop_zgX4qG2W_sendMessage);
}

void Heavy_Panoramizer::cBinop_zgX4qG2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_a9zQ451R_sendMessage);
}

void Heavy_Panoramizer::cCast_WqCu9Yyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EVd73lf7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIM2Idic, 0, m, &cDelay_vIM2Idic_sendMessage);
  cSwitchcase_TRTOnIYs_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_EVd73lf7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_vIM2Idic, 0, m, &cDelay_vIM2Idic_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_NZhIU6RN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_EVd73lf7_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_EVd73lf7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WqCu9Yyu_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_66anw0n7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TGcHRdV6_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_zOCZuOHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9WXHRRsI, m);
}

void Heavy_Panoramizer::cBinop_bGROlnKo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BelIWrzO_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_iRj9eDd2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4t0X0maP_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_eQ4sSs6p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ksd9iDak_sendMessage);
}

void Heavy_Panoramizer::cMsg_4t0X0maP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_bGROlnKo_sendMessage);
}

void Heavy_Panoramizer::cSystem_ggLslitN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_blMYjEa1_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_fv5k9ZoK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ggLslitN_sendMessage);
}

void Heavy_Panoramizer::cMsg_BelIWrzO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_zOCZuOHK_sendMessage);
}

void Heavy_Panoramizer::cMsg_blMYjEa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VjvUgGUw_sendMessage);
}

void Heavy_Panoramizer::cMsg_gt8SdCX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_iRj9eDd2_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UzxSPCNd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mYrXnenw, m);
}

void Heavy_Panoramizer::cIf_nkN00Aca_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gt8SdCX9_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_iRj9eDd2_sendMessage);
      cMsg_eQ4sSs6p_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_38VGuWd0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nkN00Aca, 1, m, &cIf_nkN00Aca_sendMessage);
}

void Heavy_Panoramizer::cBinop_VjvUgGUw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_D7UFyLfA, m);
}

void Heavy_Panoramizer::cVar_7jNNLtp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_38VGuWd0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nkN00Aca, 0, m, &cIf_nkN00Aca_sendMessage);
}

void Heavy_Panoramizer::cBinop_ksd9iDak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_UzxSPCNd, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_mYrXnenw, m);
}

void Heavy_Panoramizer::cSlice_vOgmJE9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hVkeopG9, 1, m, &cRandom_hVkeopG9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_b7tX6h9T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y7Lmv1O0, HV_BINOP_ADD, 0, m, &cBinop_Y7Lmv1O0_sendMessage);
}

void Heavy_Panoramizer::cRandom_hVkeopG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FbTkVbgg, HV_BINOP_MULTIPLY, 0, m, &cBinop_FbTkVbgg_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_A6LLXEAs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vOgmJE9j, 0, m, &cSlice_vOgmJE9j_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hVkeopG9, 0, m, &cRandom_hVkeopG9_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_FbTkVbgg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_b7tX6h9T_sendMessage);
}

void Heavy_Panoramizer::cCast_3HbDDQ5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YFkeNfJt_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBOhEzDu, 0, m, &cDelay_IBOhEzDu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uLgI6Rek_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EhHCdDv9_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_fRe9ms8e_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_YFkeNfJt_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YFkeNfJt_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3HbDDQ5l_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_DPTtIGNq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cUq7bwUu, HV_BINOP_MULTIPLY, 1, m, &cBinop_cUq7bwUu_sendMessage);
}

void Heavy_Panoramizer::cDelay_IBOhEzDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_IBOhEzDu, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBOhEzDu, 0, m, &cDelay_IBOhEzDu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uLgI6Rek_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EhHCdDv9_sendMessage);
}

void Heavy_Panoramizer::cMsg_E721mtwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uo4AkPy8_sendMessage);
}

void Heavy_Panoramizer::cSystem_uo4AkPy8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DPTtIGNq_sendMessage);
}

void Heavy_Panoramizer::cBinop_ghHWFDaX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBOhEzDu, 2, m, &cDelay_IBOhEzDu_sendMessage);
}

void Heavy_Panoramizer::cBinop_cUq7bwUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ghHWFDaX_sendMessage);
}

void Heavy_Panoramizer::cVar_gZbQW9tf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cUq7bwUu, HV_BINOP_MULTIPLY, 0, m, &cBinop_cUq7bwUu_sendMessage);
}

void Heavy_Panoramizer::cMsg_YFkeNfJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_IBOhEzDu, 0, m, &cDelay_IBOhEzDu_sendMessage);
}

void Heavy_Panoramizer::cPack_WapmcKov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_fRMuQPsG, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_UIj3atru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_E0b9uZnX, HV_BINOP_SUBTRACT, 1, m, &cBinop_E0b9uZnX_sendMessage);
}

void Heavy_Panoramizer::cCast_ssVld2FA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2GGn5Ydf_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_QvlwGOUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gHeuDxPe, HV_BINOP_MULTIPLY, 1, m, &cBinop_gHeuDxPe_sendMessage);
}

void Heavy_Panoramizer::cBinop_VkxGHrn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_O1LZkbTu, m);
}

void Heavy_Panoramizer::cBinop_cqF25FgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PQ4m1D2O_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_PQ4m1D2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_xbPMyH9G_sendMessage);
}

void Heavy_Panoramizer::cBinop_WgC8KZpJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nsScQS7w, 1, m, &cIf_nsScQS7w_sendMessage);
}

void Heavy_Panoramizer::cIf_nsScQS7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_AguU0ilw_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_ENS8O23D_sendMessage);
      cMsg_Vmyu6nWQ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_xbPMyH9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BFegigXK, m);
}

void Heavy_Panoramizer::cMsg_AguU0ilw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_ENS8O23D_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Kjkm7ekA, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bmbHc1d1, m);
}

void Heavy_Panoramizer::cVar_IYrdb4vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_WgC8KZpJ_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nsScQS7w, 0, m, &cIf_nsScQS7w_sendMessage);
}

void Heavy_Panoramizer::cBinop_ENS8O23D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vBC14fx2_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_vBC14fx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_cqF25FgB_sendMessage);
}

void Heavy_Panoramizer::cBinop_kNASfJIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Kjkm7ekA, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bmbHc1d1, m);
}

void Heavy_Panoramizer::cMsg_l0O0f39b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_wms4oxmP_sendMessage);
}

void Heavy_Panoramizer::cSystem_wms4oxmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XsR3za2u_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_XsR3za2u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VkxGHrn4_sendMessage);
}

void Heavy_Panoramizer::cMsg_Vmyu6nWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kNASfJIF_sendMessage);
}

void Heavy_Panoramizer::cBinop_Tg84tVVm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_XE6i7UX0_sendMessage);
}

void Heavy_Panoramizer::cRandom_maQsqW14_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Tg84tVVm, HV_BINOP_MULTIPLY, 0, m, &cBinop_Tg84tVVm_sendMessage);
}

void Heavy_Panoramizer::cSlice_BngAo8Ki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_maQsqW14, 1, m, &cRandom_maQsqW14_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_mA1yupT8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BngAo8Ki, 0, m, &cSlice_BngAo8Ki_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_maQsqW14, 0, m, &cRandom_maQsqW14_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_XE6i7UX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OkkfNx3g, HV_BINOP_ADD, 0, m, &cBinop_OkkfNx3g_sendMessage);
}

void Heavy_Panoramizer::cRandom_zZWWb0E4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_pJAT8Tzg_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_2ZbEujOQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SkMN70XS, 0, m, &cSlice_SkMN70XS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zZWWb0E4, 0, m, &cRandom_zZWWb0E4_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_SkMN70XS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_zZWWb0E4, 1, m, &cRandom_zZWWb0E4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_3uFG3hY5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rimh69z5, 0, m, &cVar_Rimh69z5_sendMessage);
}

void Heavy_Panoramizer::cBinop_pJAT8Tzg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_3uFG3hY5_sendMessage);
}

void Heavy_Panoramizer::cCast_hRTDO5E5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OaJmYKbW, HV_BINOP_SUBTRACT, 1, m, &cBinop_OaJmYKbW_sendMessage);
}

void Heavy_Panoramizer::cMsg_hgfKXODP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_B3oNS12V_sendMessage);
}

void Heavy_Panoramizer::cMsg_r2CSduaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kNJwnUkq_sendMessage);
}

void Heavy_Panoramizer::cBinop_gHXnme5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_leGUt24b, m);
}

void Heavy_Panoramizer::cBinop_HS4BF3gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GCLVuW2N, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bpEJoxb2, m);
}

void Heavy_Panoramizer::cBinop_kNJwnUkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ObkpX0JF, m);
}

void Heavy_Panoramizer::cVar_Z2oOxIOS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_T0EOugGt_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_QGFe5Z5l, 0, m, &cIf_QGFe5Z5l_sendMessage);
}

void Heavy_Panoramizer::cMsg_7L55KVzN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gHXnme5Q_sendMessage);
}

void Heavy_Panoramizer::cBinop_T0EOugGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QGFe5Z5l, 1, m, &cIf_QGFe5Z5l_sendMessage);
}

void Heavy_Panoramizer::cIf_QGFe5Z5l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_OxJLHguX_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_qQs99amS_sendMessage);
      cMsg_jzet7w1X_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_qQs99amS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hgfKXODP_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_jzet7w1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HS4BF3gz_sendMessage);
}

void Heavy_Panoramizer::cSystem_sAk4XfRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_r2CSduaD_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_yghQPCtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sAk4XfRP_sendMessage);
}

void Heavy_Panoramizer::cMsg_OxJLHguX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_qQs99amS_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_GCLVuW2N, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bpEJoxb2, m);
}

void Heavy_Panoramizer::cBinop_B3oNS12V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7L55KVzN_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_3SSskh9I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hNvo2f0r_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FYOFqzKr_sendMessage);
}

void Heavy_Panoramizer::cCast_HdyBZV7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mUvP5eYY_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSlice_QwtxEuZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MOeIV3Eb, 1, m, &cRandom_MOeIV3Eb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_ndVTOlCM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QwtxEuZF, 0, m, &cSlice_QwtxEuZF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MOeIV3Eb, 0, m, &cRandom_MOeIV3Eb_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_LuWgHMXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8LqQP0zp, 0, m, &cVar_8LqQP0zp_sendMessage);
}

void Heavy_Panoramizer::cBinop_sd9RhUTq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_LuWgHMXV_sendMessage);
}

void Heavy_Panoramizer::cRandom_MOeIV3Eb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_sd9RhUTq_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_LuVNWy2a_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_BVDB4YT7_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_BVDB4YT7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M7JCW8y1_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_TVcqWIxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rIRNImQP, HV_BINOP_MULTIPLY, 0, m, &cBinop_rIRNImQP_sendMessage);
}

void Heavy_Panoramizer::cCast_M7JCW8y1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BVDB4YT7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAeSRX1i, 0, m, &cDelay_DAeSRX1i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hZNtVRRd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UM5LCM73_sendMessage);
}

void Heavy_Panoramizer::cDelay_DAeSRX1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DAeSRX1i, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAeSRX1i, 0, m, &cDelay_DAeSRX1i_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hZNtVRRd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UM5LCM73_sendMessage);
}

void Heavy_Panoramizer::cBinop_GbJ4une3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rIRNImQP, HV_BINOP_MULTIPLY, 1, m, &cBinop_rIRNImQP_sendMessage);
}

void Heavy_Panoramizer::cSystem_xjufophj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GbJ4une3_sendMessage);
}

void Heavy_Panoramizer::cMsg_tvcJeUdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_xjufophj_sendMessage);
}

void Heavy_Panoramizer::cBinop_5IYjpbiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAeSRX1i, 2, m, &cDelay_DAeSRX1i_sendMessage);
}

void Heavy_Panoramizer::cMsg_BVDB4YT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DAeSRX1i, 0, m, &cDelay_DAeSRX1i_sendMessage);
}

void Heavy_Panoramizer::cBinop_rIRNImQP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5IYjpbiC_sendMessage);
}

void Heavy_Panoramizer::cMsg_Ivsj0UEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OaJmYKbW, HV_BINOP_SUBTRACT, 0, m, &cBinop_OaJmYKbW_sendMessage);
}

void Heavy_Panoramizer::cCast_rvBxuAyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4gcv5h32_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_i6ljfKk8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8I1KylPY, 2, m, &cDelay_8I1KylPY_sendMessage);
}

void Heavy_Panoramizer::cCast_jysf2f4c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kpZ5oayh_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8I1KylPY, 0, m, &cDelay_8I1KylPY_sendMessage);
  cSwitchcase_XM5zFE4k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_haGv9p8c_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_kpZ5oayh_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_kpZ5oayh_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jysf2f4c_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_mqwg39Te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hJCj79uI, HV_BINOP_MULTIPLY, 1, m, &cBinop_hJCj79uI_sendMessage);
}

void Heavy_Panoramizer::cMsg_OMh2pWNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CCHBzpXd_sendMessage);
}

void Heavy_Panoramizer::cSystem_CCHBzpXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_mqwg39Te_sendMessage);
}

void Heavy_Panoramizer::cVar_hGV4kkxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hJCj79uI, HV_BINOP_MULTIPLY, 0, m, &cBinop_hJCj79uI_sendMessage);
}

void Heavy_Panoramizer::cBinop_hJCj79uI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_i6ljfKk8_sendMessage);
}

void Heavy_Panoramizer::cMsg_kpZ5oayh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8I1KylPY, 0, m, &cDelay_8I1KylPY_sendMessage);
}

void Heavy_Panoramizer::cDelay_8I1KylPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8I1KylPY, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8I1KylPY, 0, m, &cDelay_8I1KylPY_sendMessage);
  cSwitchcase_XM5zFE4k_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_uvpFheWB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JQVQUzcc_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_Y1bm5OzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oJaXrasz, HV_BINOP_SUBTRACT, 1, m, &cBinop_oJaXrasz_sendMessage);
}

void Heavy_Panoramizer::cBinop_3KM2e3ku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y1bm5OzD_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uaGoykXD_sendMessage);
}

void Heavy_Panoramizer::cBinop_8SoQ2ccF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_il0zRn2U_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_LQXOkjaL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_S1eqeP5u_sendMessage);
}

void Heavy_Panoramizer::cMsg_uvHUiFbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NOBhvT8p_sendMessage);
}

void Heavy_Panoramizer::cIf_4EABwTjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_L6Fmtp67_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_o13RkN5Z_sendMessage);
      cMsg_LQXOkjaL_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_lIIv4vkh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4EABwTjy, 1, m, &cIf_4EABwTjy_sendMessage);
}

void Heavy_Panoramizer::cMsg_L6Fmtp67_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_o13RkN5Z_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eOMz455y, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QKzT4Sf9, m);
}

void Heavy_Panoramizer::cBinop_o13RkN5Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_grpRuu0I_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_grpRuu0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8SoQ2ccF_sendMessage);
}

void Heavy_Panoramizer::cBinop_NOBhvT8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CcwMSHKC, m);
}

void Heavy_Panoramizer::cBinop_hely9r7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lSaoDUIF, m);
}

void Heavy_Panoramizer::cBinop_S1eqeP5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eOMz455y, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QKzT4Sf9, m);
}

void Heavy_Panoramizer::cMsg_J98P6sm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JlpltRzL_sendMessage);
}

void Heavy_Panoramizer::cSystem_JlpltRzL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uvHUiFbD_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_hJBOOvUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_lIIv4vkh_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4EABwTjy, 0, m, &cIf_4EABwTjy_sendMessage);
}

void Heavy_Panoramizer::cMsg_il0zRn2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_hely9r7D_sendMessage);
}

void Heavy_Panoramizer::cPack_YgVJAkdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_LJsKvZiV, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_wyPgA57W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_WapmcKov, 0, m, &cPack_WapmcKov_sendMessage);
}

void Heavy_Panoramizer::cMsg_yak1lkHk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wujP0INe, HV_BINOP_SUBTRACT, 0, m, &cBinop_wujP0INe_sendMessage);
}

void Heavy_Panoramizer::cCast_FVRESX0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_k659IZ3c_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_WCKuP8Y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QvlwGOUg, HV_BINOP_SUBTRACT, 0, m, &cBinop_QvlwGOUg_sendMessage);
}

void Heavy_Panoramizer::cUnop_blrRJsZX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9EqpQhRp, HV_BINOP_ADD, 0, m, &cBinop_9EqpQhRp_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Nw6ydCH6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_kHx7uhjh, 0, m, &cSlice_kHx7uhjh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QSGUfS55, 0, m, &cRandom_QSGUfS55_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_kHx7uhjh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_QSGUfS55, 1, m, &cRandom_QSGUfS55_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_JisdDsOM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_blrRJsZX_sendMessage);
}

void Heavy_Panoramizer::cRandom_QSGUfS55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JisdDsOM, HV_BINOP_MULTIPLY, 0, m, &cBinop_JisdDsOM_sendMessage);
}

void Heavy_Panoramizer::cUnop_sZsSzTWy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nk3liotL, 0, m, &cVar_nk3liotL_sendMessage);
}

void Heavy_Panoramizer::cRandom_Kbv3bUcC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_82XWj0ZF_sendMessage);
}

void Heavy_Panoramizer::cSlice_OMPH4cVY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Kbv3bUcC, 1, m, &cRandom_Kbv3bUcC_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_82XWj0ZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sZsSzTWy_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_VcANR1pv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_OMPH4cVY, 0, m, &cSlice_OMPH4cVY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Kbv3bUcC, 0, m, &cRandom_Kbv3bUcC_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_xW54efLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_CRwJfHiy_sendMessage);
}

void Heavy_Panoramizer::cSlice_Nk60DtQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Eny0UcHA, 1, m, &cRandom_Eny0UcHA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_Eny0UcHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xW54efLi, HV_BINOP_MULTIPLY, 0, m, &cBinop_xW54efLi_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_0DNSpdia_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Nk60DtQK, 0, m, &cSlice_Nk60DtQK_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Eny0UcHA, 0, m, &cRandom_Eny0UcHA_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_CRwJfHiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MXd6qz3M, HV_BINOP_ADD, 0, m, &cBinop_MXd6qz3M_sendMessage);
}

void Heavy_Panoramizer::cSystem_NzapWZrS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4RTjPOS0_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_fBeyV6hj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NzapWZrS_sendMessage);
}

void Heavy_Panoramizer::cIf_zbBpD3X0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_j8Kez6d3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_4Ld2EU8x_sendMessage);
      cMsg_JaYHCxDP_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_pzwYeYKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_zbBpD3X0, 1, m, &cIf_zbBpD3X0_sendMessage);
}

void Heavy_Panoramizer::cMsg_N341fPGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1dMeD7lM_sendMessage);
}

void Heavy_Panoramizer::cBinop_1dMeD7lM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bH99oJFd, m);
}

void Heavy_Panoramizer::cMsg_j8Kez6d3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_4Ld2EU8x_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_uxdg4YAe, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FAOhbPz3, m);
}

void Heavy_Panoramizer::cMsg_rHqPKdQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gaJv0Y55_sendMessage);
}

void Heavy_Panoramizer::cBinop_KTrFyUKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uxdg4YAe, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FAOhbPz3, m);
}

void Heavy_Panoramizer::cVar_w5L4UAGX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_pzwYeYKc_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_zbBpD3X0, 0, m, &cIf_zbBpD3X0_sendMessage);
}

void Heavy_Panoramizer::cMsg_JaYHCxDP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KTrFyUKe_sendMessage);
}

void Heavy_Panoramizer::cBinop_1OxZE64n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8Qd6QDL6, m);
}

void Heavy_Panoramizer::cBinop_4Ld2EU8x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rHqPKdQd_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_4RTjPOS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1OxZE64n_sendMessage);
}

void Heavy_Panoramizer::cBinop_gaJv0Y55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_N341fPGY_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cPack_fjgWuEaJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Oe6ZDdpL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_AvmLtVge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SzWjGscQ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_Z3zbv4Gw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_AtNHQPvU_sendMessage);
}

void Heavy_Panoramizer::cMsg_aJ6NHUTT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_AvmLtVge_sendMessage);
}

void Heavy_Panoramizer::cBinop_PBgK77el_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aJ6NHUTT_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_tCXX8y8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0HS1Lj7U, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KnzsWnIN, m);
}

void Heavy_Panoramizer::cMsg_SzWjGscQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_e2BdLSfs_sendMessage);
}

void Heavy_Panoramizer::cBinop_AtNHQPvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iohOJlDo, m);
}

void Heavy_Panoramizer::cBinop_e2BdLSfs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zXeeTKt8, m);
}

void Heavy_Panoramizer::cIf_X1aZmNF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_jGgKt9BJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_PBgK77el_sendMessage);
      cMsg_CtGw8whx_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_7XK2TJyb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_X1aZmNF2, 1, m, &cIf_X1aZmNF2_sendMessage);
}

void Heavy_Panoramizer::cMsg_mJjiaCcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ybLX54fm_sendMessage);
}

void Heavy_Panoramizer::cSystem_ybLX54fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z3zbv4Gw_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_jGgKt9BJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_PBgK77el_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0HS1Lj7U, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_KnzsWnIN, m);
}

void Heavy_Panoramizer::cVar_7BjEuEMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_7XK2TJyb_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_X1aZmNF2, 0, m, &cIf_X1aZmNF2_sendMessage);
}

void Heavy_Panoramizer::cMsg_CtGw8whx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_tCXX8y8i_sendMessage);
}

void Heavy_Panoramizer::cBinop_MdDyB8Ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_fjgWuEaJ, 0, m, &cPack_fjgWuEaJ_sendMessage);
}

void Heavy_Panoramizer::cBinop_Y7Lmv1O0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_QY5fUg9e, 0, m, &cPack_QY5fUg9e_sendMessage);
}

void Heavy_Panoramizer::cMsg_vuVB0zOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Z2oOxIOS, 0, m, &cVar_Z2oOxIOS_sendMessage);
}

void Heavy_Panoramizer::cBinop_YV0hmIVM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TfKvA7O5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qiApx25y_sendMessage);
}

void Heavy_Panoramizer::cCast_9lI9UNAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WCKuP8Y8_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_npMzyNMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_Vx2XJ9kz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_1RwoNlcX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_87Z2lTuD, 1, m, &cPack_87Z2lTuD_sendMessage);
}

void Heavy_Panoramizer::cCast_eIlUgo6L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_fIzgAomU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_OaJmYKbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xW54efLi, HV_BINOP_MULTIPLY, 1, m, &cBinop_xW54efLi_sendMessage);
}

void Heavy_Panoramizer::cBinop_7dAFWq7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_uFl3j5x0, 1, m, &cPack_uFl3j5x0_sendMessage);
}

void Heavy_Panoramizer::cBinop_L9w5DFFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0ZVAzrbE_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7Ebs7ylb_sendMessage);
}

void Heavy_Panoramizer::cUnop_jmhqamny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wo11dV7r, HV_BINOP_MULTIPLY, 0, m, &cBinop_wo11dV7r_sendMessage);
}

void Heavy_Panoramizer::cRandom_8SlAuAP8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_HQv1Hquj_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_nvXiU0Qh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BHioAAPZ, 0, m, &cSlice_BHioAAPZ_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8SlAuAP8, 0, m, &cRandom_8SlAuAP8_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_HQv1Hquj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_jmhqamny_sendMessage);
}

void Heavy_Panoramizer::cSlice_BHioAAPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8SlAuAP8, 1, m, &cRandom_8SlAuAP8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_JudLwSnr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bYnWd6kc, HV_BINOP_MULTIPLY, 1, m, &cBinop_bYnWd6kc_sendMessage);
}

void Heavy_Panoramizer::cVar_Wcvun8XB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bYnWd6kc, HV_BINOP_MULTIPLY, 0, m, &cBinop_bYnWd6kc_sendMessage);
}

void Heavy_Panoramizer::cSystem_PylE5JlA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_JudLwSnr_sendMessage);
}

void Heavy_Panoramizer::cMsg_l26kHkIC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PylE5JlA_sendMessage);
}

void Heavy_Panoramizer::cDelay_82m6vm5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_82m6vm5v, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_82m6vm5v, 0, m, &cDelay_82m6vm5v_sendMessage);
  cSwitchcase_xuPDsH2h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_MwxA99wu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_n0MuTK6T_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_82m6vm5v, 0, m, &cDelay_82m6vm5v_sendMessage);
  cSwitchcase_xuPDsH2h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_bYnWd6kc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_FqQIKH3Y_sendMessage);
}

void Heavy_Panoramizer::cBinop_FqQIKH3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_82m6vm5v, 2, m, &cDelay_82m6vm5v_sendMessage);
}

void Heavy_Panoramizer::cMsg_n0MuTK6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_82m6vm5v, 0, m, &cDelay_82m6vm5v_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_idq9tHma_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_n0MuTK6T_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_n0MuTK6T_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MwxA99wu_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_6nPxR743_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xdxbmnDv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AYnW9mKN_sendMessage);
}

void Heavy_Panoramizer::cSlice_ceiMZgPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WEfFoW7V, 1, m, &cRandom_WEfFoW7V_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_WEfFoW7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_tY3HrTav_sendMessage);
}

void Heavy_Panoramizer::cBinop_tY3HrTav_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_C2HeYfZg_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_77kZnW7L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ceiMZgPP, 0, m, &cSlice_ceiMZgPP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_WEfFoW7V, 0, m, &cRandom_WEfFoW7V_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_C2HeYfZg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_siSxWMt5, HV_BINOP_MULTIPLY, 0, m, &cBinop_siSxWMt5_sendMessage);
}

void Heavy_Panoramizer::cBinop_BI3eis25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tBDMZV6X_sendMessage);
}

void Heavy_Panoramizer::cSlice_k6uHwbOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TFtiadFt, 1, m, &cRandom_TFtiadFt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_lLq8VYlZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_k6uHwbOR, 0, m, &cSlice_k6uHwbOR_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_TFtiadFt, 0, m, &cRandom_TFtiadFt_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_tBDMZV6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JQkemYWg, HV_BINOP_ADD, 0, m, &cBinop_JQkemYWg_sendMessage);
}

void Heavy_Panoramizer::cRandom_TFtiadFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BI3eis25, HV_BINOP_MULTIPLY, 0, m, &cBinop_BI3eis25_sendMessage);
}

void Heavy_Panoramizer::cCast_cLtQaIWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSKJtKEE, HV_BINOP_SUBTRACT, 1, m, &cBinop_TSKJtKEE_sendMessage);
}

void Heavy_Panoramizer::cBinop_wo11dV7r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nd6htOOI, 1, m, &cPack_nd6htOOI_sendMessage);
}

void Heavy_Panoramizer::cBinop_rbJZJbmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ptANniBq, 1, m, &cPack_ptANniBq_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_bTZ231YJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KCoyj1sc, 0, m, &cSlice_KCoyj1sc_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wqk0Al42, 0, m, &cRandom_wqk0Al42_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_KCoyj1sc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wqk0Al42, 1, m, &cRandom_wqk0Al42_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_e4vYtUIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NrXaf2QS, 0, m, &cVar_NrXaf2QS_sendMessage);
}

void Heavy_Panoramizer::cRandom_wqk0Al42_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_LG1F3aiQ_sendMessage);
}

void Heavy_Panoramizer::cBinop_LG1F3aiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_e4vYtUIh_sendMessage);
}

void Heavy_Panoramizer::cRandom_JtfAw66I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_h65T5geX_sendMessage);
}

void Heavy_Panoramizer::cBinop_h65T5geX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dHZPWgtJ_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_3ijLazE3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_o6Ax4Qq4, 0, m, &cSlice_o6Ax4Qq4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JtfAw66I, 0, m, &cRandom_JtfAw66I_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_dHZPWgtJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7zZG4hv8, HV_BINOP_MULTIPLY, 0, m, &cBinop_7zZG4hv8_sendMessage);
}

void Heavy_Panoramizer::cSlice_o6Ax4Qq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JtfAw66I, 1, m, &cRandom_JtfAw66I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_SeRiPdaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_76aT2wsZ, 2, m, &cDelay_76aT2wsZ_sendMessage);
}

void Heavy_Panoramizer::cVar_0vtB9sHC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2HOldZ0p, HV_BINOP_MULTIPLY, 0, m, &cBinop_2HOldZ0p_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_lTZGKEQL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ORwdl27f_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ORwdl27f_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pw2kKW2v_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_2HOldZ0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_SeRiPdaT_sendMessage);
}

void Heavy_Panoramizer::cCast_pw2kKW2v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ORwdl27f_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_76aT2wsZ, 0, m, &cDelay_76aT2wsZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eJ8nIrwC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s9x3hnTN_sendMessage);
}

void Heavy_Panoramizer::cBinop_dIJd5R0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2HOldZ0p, HV_BINOP_MULTIPLY, 1, m, &cBinop_2HOldZ0p_sendMessage);
}

void Heavy_Panoramizer::cDelay_76aT2wsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_76aT2wsZ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_76aT2wsZ, 0, m, &cDelay_76aT2wsZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eJ8nIrwC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s9x3hnTN_sendMessage);
}

void Heavy_Panoramizer::cMsg_ORwdl27f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_76aT2wsZ, 0, m, &cDelay_76aT2wsZ_sendMessage);
}

void Heavy_Panoramizer::cMsg_h32iFEKT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aG2yfEXv_sendMessage);
}

void Heavy_Panoramizer::cSystem_aG2yfEXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dIJd5R0p_sendMessage);
}

void Heavy_Panoramizer::cPack_5OWxo3Nw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_vylmWqAR, 0, m, NULL);
}

void Heavy_Panoramizer::cUnop_Dz5htzPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EeAIPlDz, HV_BINOP_ADD, 0, m, &cBinop_EeAIPlDz_sendMessage);
}

void Heavy_Panoramizer::cSlice_LVi6fjJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XKwoWCjj, 1, m, &cRandom_XKwoWCjj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_KFb8KPuu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LVi6fjJA, 0, m, &cSlice_LVi6fjJA_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_XKwoWCjj, 0, m, &cRandom_XKwoWCjj_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_XKwoWCjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LLGnZA3U, HV_BINOP_MULTIPLY, 0, m, &cBinop_LLGnZA3U_sendMessage);
}

void Heavy_Panoramizer::cBinop_LLGnZA3U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Dz5htzPF_sendMessage);
}

void Heavy_Panoramizer::cCast_n5bPGY26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_K2ZqffEo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_eJ8nIrwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_e9y0sETG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_Ipne0k3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BI3eis25, HV_BINOP_MULTIPLY, 1, m, &cBinop_BI3eis25_sendMessage);
}

void Heavy_Panoramizer::cCast_yUkjmYAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9SBmxF0B_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_SnOM6CvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_cpd2UBKm, 0, m, &cVar_cpd2UBKm_sendMessage);
}

void Heavy_Panoramizer::cBinop_OUmSeSZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MelYVOFT, HV_BINOP_MULTIPLY, 1, m, &cBinop_MelYVOFT_sendMessage);
}

void Heavy_Panoramizer::cBinop_m5VpCe1r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mLEAj74G, 1, m, &cPack_mLEAj74G_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_7Hn2TLQa_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_stXi7hAs, 0, m, &cSlice_stXi7hAs_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CaTpHi9A, 0, m, &cRandom_CaTpHi9A_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_MeY0YXSq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VehvOkZW, HV_BINOP_MULTIPLY, 0, m, &cBinop_VehvOkZW_sendMessage);
}

void Heavy_Panoramizer::cSlice_stXi7hAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CaTpHi9A, 1, m, &cRandom_CaTpHi9A_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_3JifaIx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_MeY0YXSq_sendMessage);
}

void Heavy_Panoramizer::cRandom_CaTpHi9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_3JifaIx4_sendMessage);
}

void Heavy_Panoramizer::cBinop_ahGOwBHb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_X5yqjkPS_sendMessage);
}

void Heavy_Panoramizer::cBinop_X5yqjkPS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Yov7vfn, 2, m, &cDelay_6Yov7vfn_sendMessage);
}

void Heavy_Panoramizer::cCast_mERyixhZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ef30C3T5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Yov7vfn, 0, m, &cDelay_6Yov7vfn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kdMgG3Gw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hDsjjkMw_sendMessage);
}

void Heavy_Panoramizer::cDelay_6Yov7vfn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6Yov7vfn, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Yov7vfn, 0, m, &cDelay_6Yov7vfn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kdMgG3Gw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hDsjjkMw_sendMessage);
}

void Heavy_Panoramizer::cMsg_ef30C3T5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6Yov7vfn, 0, m, &cDelay_6Yov7vfn_sendMessage);
}

void Heavy_Panoramizer::cMsg_xX1IFYEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OoJC9y5q_sendMessage);
}

void Heavy_Panoramizer::cSystem_OoJC9y5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_8u0h7NvU_sendMessage);
}

void Heavy_Panoramizer::cBinop_8u0h7NvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ahGOwBHb, HV_BINOP_MULTIPLY, 1, m, &cBinop_ahGOwBHb_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_WSiBTsGN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ef30C3T5_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ef30C3T5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mERyixhZ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_BUiVDeyR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ahGOwBHb, HV_BINOP_MULTIPLY, 0, m, &cBinop_ahGOwBHb_sendMessage);
}

void Heavy_Panoramizer::cMsg_uV8zJlqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_GSKkAtWd, 0, m, &cVar_GSKkAtWd_sendMessage);
}

void Heavy_Panoramizer::cBinop_GgRcbGmC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_m3nGRmwz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yUkjmYAz_sendMessage);
}

void Heavy_Panoramizer::cBinop_siSxWMt5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Om8klIWY, 1, m, &cPack_Om8klIWY_sendMessage);
}

void Heavy_Panoramizer::cMsg_YfLJaKZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vL0sjC3u, 0, m, &cVar_vL0sjC3u_sendMessage);
}

void Heavy_Panoramizer::cMsg_9SBmxF0B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_t4cEEUAl, HV_BINOP_SUBTRACT, 0, m, &cBinop_t4cEEUAl_sendMessage);
}

void Heavy_Panoramizer::cCast_ZvupEsA5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_7Hn2TLQa_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_LvgUjhLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2cXckHjd_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnZMWP7, 0, m, &cDelay_gJnZMWP7_sendMessage);
  cSwitchcase_sCASq7sZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_BxLYb3TU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9CyukNxi_sendMessage);
}

void Heavy_Panoramizer::cDelay_gJnZMWP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gJnZMWP7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnZMWP7, 0, m, &cDelay_gJnZMWP7_sendMessage);
  cSwitchcase_sCASq7sZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_JvLnJLmK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BxLYb3TU, HV_BINOP_MULTIPLY, 0, m, &cBinop_BxLYb3TU_sendMessage);
}

void Heavy_Panoramizer::cBinop_9CyukNxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnZMWP7, 2, m, &cDelay_gJnZMWP7_sendMessage);
}

void Heavy_Panoramizer::cBinop_gOOJmoVN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BxLYb3TU, HV_BINOP_MULTIPLY, 1, m, &cBinop_BxLYb3TU_sendMessage);
}

void Heavy_Panoramizer::cMsg_2cXckHjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gJnZMWP7, 0, m, &cDelay_gJnZMWP7_sendMessage);
}

void Heavy_Panoramizer::cMsg_73TaS2Wm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kY1K8qVF_sendMessage);
}

void Heavy_Panoramizer::cSystem_kY1K8qVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gOOJmoVN_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_dvMvE5Gw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_2cXckHjd_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_2cXckHjd_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LvgUjhLy_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_qMxGejsN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c1gR6E7D, HV_BINOP_MULTIPLY, 0, m, &cBinop_c1gR6E7D_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_AFvN4LWu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_3IlbirKL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_3IlbirKL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EvJnXS7k_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_DK5PXZtx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c1gR6E7D, HV_BINOP_MULTIPLY, 1, m, &cBinop_c1gR6E7D_sendMessage);
}

void Heavy_Panoramizer::cSystem_Ecammibg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DK5PXZtx_sendMessage);
}

void Heavy_Panoramizer::cMsg_dgU1HRM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ecammibg_sendMessage);
}

void Heavy_Panoramizer::cBinop_zMSLdkvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XcbxNWMf, 2, m, &cDelay_XcbxNWMf_sendMessage);
}

void Heavy_Panoramizer::cMsg_3IlbirKL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XcbxNWMf, 0, m, &cDelay_XcbxNWMf_sendMessage);
}

void Heavy_Panoramizer::cDelay_XcbxNWMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XcbxNWMf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XcbxNWMf, 0, m, &cDelay_XcbxNWMf_sendMessage);
  cSwitchcase_N1o3Egv0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_c1gR6E7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_zMSLdkvV_sendMessage);
}

void Heavy_Panoramizer::cCast_EvJnXS7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3IlbirKL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XcbxNWMf, 0, m, &cDelay_XcbxNWMf_sendMessage);
  cSwitchcase_N1o3Egv0_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_YPB0dPdM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TSKJtKEE, HV_BINOP_SUBTRACT, 0, m, &cBinop_TSKJtKEE_sendMessage);
}

void Heavy_Panoramizer::cMsg_e6jiCYPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_X1OoMSP6, HV_BINOP_SUBTRACT, 0, m, &cBinop_X1OoMSP6_sendMessage);
}

void Heavy_Panoramizer::cRandom_sgTIkpC2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_w00Dkf6X_sendMessage);
}

void Heavy_Panoramizer::cSlice_IBZy7bj7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sgTIkpC2, 1, m, &cRandom_sgTIkpC2_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_w00Dkf6X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Pq39lC4t_sendMessage);
}

void Heavy_Panoramizer::cUnop_Pq39lC4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ryQC9hgD, HV_BINOP_MULTIPLY, 0, m, &cBinop_ryQC9hgD_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_K2ZqffEo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_IBZy7bj7, 0, m, &cSlice_IBZy7bj7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sgTIkpC2, 0, m, &cRandom_sgTIkpC2_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_hDsjjkMw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OmevIY5b_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_euxlsWcS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2MCk59HI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cDelay_CBuGSTTS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CBuGSTTS, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBuGSTTS, 0, m, &cDelay_CBuGSTTS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iDtqnOGu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_phqoZQzH_sendMessage);
}

void Heavy_Panoramizer::cCast_ySCXGtEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HMGPxhpQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBuGSTTS, 0, m, &cDelay_CBuGSTTS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iDtqnOGu_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_phqoZQzH_sendMessage);
}

void Heavy_Panoramizer::cVar_A9Mmxda7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PiEKT2fT, HV_BINOP_MULTIPLY, 0, m, &cBinop_PiEKT2fT_sendMessage);
}

void Heavy_Panoramizer::cMsg_8GTzsoip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3TYrXQk6_sendMessage);
}

void Heavy_Panoramizer::cSystem_3TYrXQk6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_izTveDPq_sendMessage);
}

void Heavy_Panoramizer::cMsg_HMGPxhpQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBuGSTTS, 0, m, &cDelay_CBuGSTTS_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_5J6iAKm6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_HMGPxhpQ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HMGPxhpQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ySCXGtEg_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_PiEKT2fT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_7x2egLQg_sendMessage);
}

void Heavy_Panoramizer::cBinop_izTveDPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PiEKT2fT, HV_BINOP_MULTIPLY, 1, m, &cBinop_PiEKT2fT_sendMessage);
}

void Heavy_Panoramizer::cBinop_7x2egLQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CBuGSTTS, 2, m, &cDelay_CBuGSTTS_sendMessage);
}

void Heavy_Panoramizer::cPack_mLEAj74G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_1zKICT9M, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_2D7XDShQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_mLEAj74G, 0, m, &cPack_mLEAj74G_sendMessage);
}

void Heavy_Panoramizer::cCast_phqoZQzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_lLq8VYlZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_H2Cd2VL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ZHfKLawv, 0, m, &cVar_ZHfKLawv_sendMessage);
}

void Heavy_Panoramizer::cBinop_T6qCeL7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qtR0WCgA, 0, m, &cPack_qtR0WCgA_sendMessage);
}

void Heavy_Panoramizer::cMsg_Ikp1n7li_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pbCTQOO3_sendMessage);
}

void Heavy_Panoramizer::cMsg_lVaFPehf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MRg6XaUW_sendMessage);
}

void Heavy_Panoramizer::cVar_RkRQ9YeV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_6AqEfEs0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Ua7hU9ZZ, 0, m, &cIf_Ua7hU9ZZ_sendMessage);
}

void Heavy_Panoramizer::cMsg_nnozUf2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_n3YM2iyE_sendMessage);
}

void Heavy_Panoramizer::cBinop_n3YM2iyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_p4Vt4F68, m);
}

void Heavy_Panoramizer::cMsg_QxAryzlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_iQaDh00W_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_j4ZM6Vy2, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yt8tYLRE, m);
}

void Heavy_Panoramizer::cBinop_pbCTQOO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_j4ZM6Vy2, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yt8tYLRE, m);
}

void Heavy_Panoramizer::cBinop_iQaDh00W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lVaFPehf_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_Is6PEjPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IaVcx8yQ, m);
}

void Heavy_Panoramizer::cMsg_W2LGIRqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Is6PEjPs_sendMessage);
}

void Heavy_Panoramizer::cIf_Ua7hU9ZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_QxAryzlZ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_iQaDh00W_sendMessage);
      cMsg_Ikp1n7li_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_6AqEfEs0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Ua7hU9ZZ, 1, m, &cIf_Ua7hU9ZZ_sendMessage);
}

void Heavy_Panoramizer::cBinop_MRg6XaUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W2LGIRqf_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_OPYs4AZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DittNIMf_sendMessage);
}

void Heavy_Panoramizer::cSystem_DittNIMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nnozUf2q_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_5RejKyxb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_pOF3Vll4_sendMessage);
}

void Heavy_Panoramizer::cUnop_mEyHvSCU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_sEnpiW81_sendMessage);
}

void Heavy_Panoramizer::cMsg_9MjcGY5a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_73oF14v1_sendMessage);
}

void Heavy_Panoramizer::cSystem_73oF14v1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P4bab0Ol, HV_BINOP_DIVIDE, 1, m, &cBinop_P4bab0Ol_sendMessage);
  cMsg_ez3usrXn_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_P4bab0Ol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ydTpWVQE, HV_BINOP_MULTIPLY, 1, m, &cBinop_ydTpWVQE_sendMessage);
}

void Heavy_Panoramizer::cMsg_ez3usrXn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_mEyHvSCU_sendMessage);
}

void Heavy_Panoramizer::cBinop_sEnpiW81_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P4bab0Ol, HV_BINOP_DIVIDE, 0, m, &cBinop_P4bab0Ol_sendMessage);
}

void Heavy_Panoramizer::cBinop_ydTpWVQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7nGIe51r_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_7nGIe51r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_5RejKyxb_sendMessage);
}

void Heavy_Panoramizer::cVar_aGFEWq0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ydTpWVQE, HV_BINOP_MULTIPLY, 0, m, &cBinop_ydTpWVQE_sendMessage);
}

void Heavy_Panoramizer::cBinop_OgivpM77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_N58SfWnE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Ry5kw1zM_sendMessage);
}

void Heavy_Panoramizer::cBinop_pOF3Vll4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OgivpM77_sendMessage);
}

void Heavy_Panoramizer::cBinop_3TcZFSNP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gmsTS1QU, m);
}

void Heavy_Panoramizer::cBinop_N58SfWnE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_3TcZFSNP_sendMessage);
}

void Heavy_Panoramizer::cBinop_Ry5kw1zM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pR8udgTw, m);
}

void Heavy_Panoramizer::cBinop_7zZG4hv8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Cn5YA3er, 1, m, &cPack_Cn5YA3er_sendMessage);
}

void Heavy_Panoramizer::cCast_kdMgG3Gw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3ijLazE3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_Hg1HI4TO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HiTPpfeb, m);
}

void Heavy_Panoramizer::cBinop_CqhKX9tp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ADMbRI8p, 1, m, &cIf_ADMbRI8p_sendMessage);
}

void Heavy_Panoramizer::cIf_ADMbRI8p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_MfWSplHM_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_x0JyUon7_sendMessage);
      cMsg_M4Lr0HjK_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_0vAOm94p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lR91urY1_sendMessage);
}

void Heavy_Panoramizer::cSystem_lR91urY1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8TihthW7_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_eEUWLK4m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Es7UGwdv_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_99SYwLTA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xHResXUs, m);
}

void Heavy_Panoramizer::cBinop_x0JyUon7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eb0u5T9g_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_M4Lr0HjK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OFJRugVg_sendMessage);
}

void Heavy_Panoramizer::cBinop_OFJRugVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YtHKZMPl, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_52xmv25q, m);
}

void Heavy_Panoramizer::cMsg_Es7UGwdv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_99SYwLTA_sendMessage);
}

void Heavy_Panoramizer::cMsg_MfWSplHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_x0JyUon7_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YtHKZMPl, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_52xmv25q, m);
}

void Heavy_Panoramizer::cVar_cpd2UBKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_CqhKX9tp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ADMbRI8p, 0, m, &cIf_ADMbRI8p_sendMessage);
}

void Heavy_Panoramizer::cMsg_eb0u5T9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eEUWLK4m_sendMessage);
}

void Heavy_Panoramizer::cMsg_8TihthW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Hg1HI4TO_sendMessage);
}

void Heavy_Panoramizer::cCast_bXVYMY4Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_m4Ezei0g_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_StLAaoG5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_c6rjZvwE, HV_BINOP_SUBTRACT, 0, m, &cBinop_c6rjZvwE_sendMessage);
}

void Heavy_Panoramizer::cBinop_MelYVOFT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZyEszSEc_sendMessage);
}

void Heavy_Panoramizer::cSlice_M0fP9cvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fJF092py, 1, m, &cRandom_fJF092py_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_x7YrJcKI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_M0fP9cvw, 0, m, &cSlice_M0fP9cvw_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fJF092py, 0, m, &cRandom_fJF092py_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_ZyEszSEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DrZO29TU, HV_BINOP_ADD, 0, m, &cBinop_DrZO29TU_sendMessage);
}

void Heavy_Panoramizer::cRandom_fJF092py_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MelYVOFT, HV_BINOP_MULTIPLY, 0, m, &cBinop_MelYVOFT_sendMessage);
}

void Heavy_Panoramizer::cCast_vAD7H57e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_s0ackoer_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_Q55CJWRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vmlHoKSS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ez482iym, 0, m, &cDelay_Ez482iym_sendMessage);
  cSwitchcase_2HDcUz85_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_l1kpTUmU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_mKoEUY0k_sendMessage);
}

void Heavy_Panoramizer::cBinop_mKoEUY0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ez482iym, 2, m, &cDelay_Ez482iym_sendMessage);
}

void Heavy_Panoramizer::cBinop_bExLElBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l1kpTUmU, HV_BINOP_MULTIPLY, 1, m, &cBinop_l1kpTUmU_sendMessage);
}

void Heavy_Panoramizer::cMsg_vmlHoKSS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ez482iym, 0, m, &cDelay_Ez482iym_sendMessage);
}

void Heavy_Panoramizer::cMsg_CEexP1Sc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_TsDtL9u6_sendMessage);
}

void Heavy_Panoramizer::cSystem_TsDtL9u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_bExLElBc_sendMessage);
}

void Heavy_Panoramizer::cDelay_Ez482iym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Ez482iym, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Ez482iym, 0, m, &cDelay_Ez482iym_sendMessage);
  cSwitchcase_2HDcUz85_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cSwitchcase_Oqkokcu0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_vmlHoKSS_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_vmlHoKSS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q55CJWRx_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_8SG59YUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l1kpTUmU, HV_BINOP_MULTIPLY, 0, m, &cBinop_l1kpTUmU_sendMessage);
}

void Heavy_Panoramizer::cPack_y35bMjXe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_zPYJjORe, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_HQ72CdbX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qtt7MhTR, 0, m, &cDelay_Qtt7MhTR_sendMessage);
}

void Heavy_Panoramizer::cSystem_fQ1vilbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gVjKJuhf_sendMessage);
}

void Heavy_Panoramizer::cMsg_cU7aIPzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fQ1vilbx_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Zg9CfO4T_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_HQ72CdbX_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HQ72CdbX_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_r9IV6bh4_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_ET3Q9EBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qtt7MhTR, 2, m, &cDelay_Qtt7MhTR_sendMessage);
}

void Heavy_Panoramizer::cBinop_42iqBkRC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ET3Q9EBP_sendMessage);
}

void Heavy_Panoramizer::cDelay_Qtt7MhTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Qtt7MhTR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qtt7MhTR, 0, m, &cDelay_Qtt7MhTR_sendMessage);
  cSwitchcase_bPJIHPxB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_r9IV6bh4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HQ72CdbX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Qtt7MhTR, 0, m, &cDelay_Qtt7MhTR_sendMessage);
  cSwitchcase_bPJIHPxB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_gVjKJuhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42iqBkRC, HV_BINOP_MULTIPLY, 1, m, &cBinop_42iqBkRC_sendMessage);
}

void Heavy_Panoramizer::cVar_SwME4N3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_42iqBkRC, HV_BINOP_MULTIPLY, 0, m, &cBinop_42iqBkRC_sendMessage);
}

void Heavy_Panoramizer::cVar_vL0sjC3u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_eO6awb6S_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_YTzPOCJf, 0, m, &cIf_YTzPOCJf_sendMessage);
}

void Heavy_Panoramizer::cBinop_VSQNtt5D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a9WijUuc_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_3nzV1bDu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EFPWzLnL_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_sSRrUYbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_KaPJ0Y2c_sendMessage);
}

void Heavy_Panoramizer::cBinop_KaPJ0Y2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BPf4aIBq, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_musW1hFJ, m);
}

void Heavy_Panoramizer::cMsg_SxSufsjm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_3nzV1bDu_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_BPf4aIBq, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_musW1hFJ, m);
}

void Heavy_Panoramizer::cBinop_6YRPR6im_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ggzc3Kfp, m);
}

void Heavy_Panoramizer::cMsg_a9WijUuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_6YRPR6im_sendMessage);
}

void Heavy_Panoramizer::cMsg_GAmf5nlE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gxEpeXmX_sendMessage);
}

void Heavy_Panoramizer::cBinop_eO6awb6S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YTzPOCJf, 1, m, &cIf_YTzPOCJf_sendMessage);
}

void Heavy_Panoramizer::cIf_YTzPOCJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_SxSufsjm_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_3nzV1bDu_sendMessage);
      cMsg_sSRrUYbE_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_EFPWzLnL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_VSQNtt5D_sendMessage);
}

void Heavy_Panoramizer::cBinop_gxEpeXmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uaUc7NQa, m);
}

void Heavy_Panoramizer::cMsg_TvHkbCRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aU8I7450_sendMessage);
}

void Heavy_Panoramizer::cSystem_aU8I7450_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GAmf5nlE_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cPack_ewI8OedI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_L4sHvsTr, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_amxvk08q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_x7YrJcKI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cUnop_EhnA0kfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2D7XDShQ, HV_BINOP_ADD, 0, m, &cBinop_2D7XDShQ_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_CDcsfdYM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Je6IRhcT, 0, m, &cSlice_Je6IRhcT_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fHlOFGOX, 0, m, &cRandom_fHlOFGOX_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_fHlOFGOX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZGB0ejZo, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZGB0ejZo_sendMessage);
}

void Heavy_Panoramizer::cBinop_ZGB0ejZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_EhnA0kfF_sendMessage);
}

void Heavy_Panoramizer::cSlice_Je6IRhcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fHlOFGOX, 1, m, &cRandom_fHlOFGOX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_sCFBwH4F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zimVwK1f, 0, m, &cSlice_zimVwK1f_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ohvWDmfF, 0, m, &cRandom_ohvWDmfF_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_zimVwK1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ohvWDmfF, 1, m, &cRandom_ohvWDmfF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_yEhCridK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NFGMmH3L, HV_BINOP_ADD, 0, m, &cBinop_NFGMmH3L_sendMessage);
}

void Heavy_Panoramizer::cBinop_00caoaka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yEhCridK_sendMessage);
}

void Heavy_Panoramizer::cRandom_ohvWDmfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_00caoaka, HV_BINOP_MULTIPLY, 0, m, &cBinop_00caoaka_sendMessage);
}

void Heavy_Panoramizer::cCast_Khcu6SYZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_z1eBGwWV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cRandom_LckIJ85I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iVofnMuY, HV_BINOP_MULTIPLY, 0, m, &cBinop_iVofnMuY_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_uBbVVGsN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_F5WqpakX, 0, m, &cSlice_F5WqpakX_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LckIJ85I, 0, m, &cRandom_LckIJ85I_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_iVofnMuY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_G5It3bjp_sendMessage);
}

void Heavy_Panoramizer::cSlice_F5WqpakX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_LckIJ85I, 1, m, &cRandom_LckIJ85I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_G5It3bjp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T6qCeL7Y, HV_BINOP_ADD, 0, m, &cBinop_T6qCeL7Y_sendMessage);
}

void Heavy_Panoramizer::cMsg_0nK2P06e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bRSbfgTU, 0, m, &cDelay_bRSbfgTU_sendMessage);
}

void Heavy_Panoramizer::cBinop_b24ovYJW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Y2whwuW9_sendMessage);
}

void Heavy_Panoramizer::cVar_HlzE6CZo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b24ovYJW, HV_BINOP_MULTIPLY, 0, m, &cBinop_b24ovYJW_sendMessage);
}

void Heavy_Panoramizer::cSystem_GnjjuHDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UWEzsECE_sendMessage);
}

void Heavy_Panoramizer::cMsg_YigmQovg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GnjjuHDJ_sendMessage);
}

void Heavy_Panoramizer::cCast_fAK1gVUR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0nK2P06e_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bRSbfgTU, 0, m, &cDelay_bRSbfgTU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bXVYMY4Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S4aC79El_sendMessage);
}

void Heavy_Panoramizer::cBinop_Y2whwuW9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bRSbfgTU, 2, m, &cDelay_bRSbfgTU_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_NCJfMZX8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_0nK2P06e_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_0nK2P06e_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fAK1gVUR_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cDelay_bRSbfgTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bRSbfgTU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_bRSbfgTU, 0, m, &cDelay_bRSbfgTU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bXVYMY4Y_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_S4aC79El_sendMessage);
}

void Heavy_Panoramizer::cBinop_UWEzsECE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b24ovYJW, HV_BINOP_MULTIPLY, 1, m, &cBinop_b24ovYJW_sendMessage);
}

void Heavy_Panoramizer::cBinop_oxZEvaCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Cn5YA3er, 0, m, &cPack_Cn5YA3er_sendMessage);
}

void Heavy_Panoramizer::cCast_rjD9hs0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cN8Ytvzf, HV_BINOP_SUBTRACT, 1, m, &cBinop_cN8Ytvzf_sendMessage);
}

void Heavy_Panoramizer::cBinop_ANGiGGxM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5OWxo3Nw, 0, m, &cPack_5OWxo3Nw_sendMessage);
}

void Heavy_Panoramizer::cBinop_aQlYPWgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeFeD5Et, HV_BINOP_MULTIPLY, 1, m, &cBinop_zeFeD5Et_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Fh7cy1w7_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_rvpQpTf6_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_rvpQpTf6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kXYyBnw0_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_zeFeD5Et_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0PqG58Ky_sendMessage);
}

void Heavy_Panoramizer::cVar_HoMnd7aR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeFeD5Et, HV_BINOP_MULTIPLY, 0, m, &cBinop_zeFeD5Et_sendMessage);
}

void Heavy_Panoramizer::cBinop_0PqG58Ky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_0YSlu9Os, 2, m, &cDelay_0YSlu9Os_sendMessage);
}

void Heavy_Panoramizer::cCast_kXYyBnw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rvpQpTf6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0YSlu9Os, 0, m, &cDelay_0YSlu9Os_sendMessage);
  cSwitchcase_N9SsTywh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cDelay_0YSlu9Os_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_0YSlu9Os, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_0YSlu9Os, 0, m, &cDelay_0YSlu9Os_sendMessage);
  cSwitchcase_N9SsTywh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_jlh4J90X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FfnuZZRZ_sendMessage);
}

void Heavy_Panoramizer::cSystem_FfnuZZRZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aQlYPWgJ_sendMessage);
}

void Heavy_Panoramizer::cMsg_rvpQpTf6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_0YSlu9Os, 0, m, &cDelay_0YSlu9Os_sendMessage);
}

void Heavy_Panoramizer::cMsg_115NfWMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_v9wRUjqb, 0, m, &cVar_v9wRUjqb_sendMessage);
}

void Heavy_Panoramizer::cCast_lwcy7WmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KFb8KPuu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_cN8Ytvzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iVofnMuY, HV_BINOP_MULTIPLY, 1, m, &cBinop_iVofnMuY_sendMessage);
}

void Heavy_Panoramizer::cCast_JN3qnPMF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uBbVVGsN_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_0p5Y3c87_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X1OoMSP6, HV_BINOP_SUBTRACT, 1, m, &cBinop_X1OoMSP6_sendMessage);
}

void Heavy_Panoramizer::cBinop_drx0xO72_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_m7beqnpp_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_w0hFg79y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WwMzLeDW, 0, m, &cSlice_WwMzLeDW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uvZuNA2M, 0, m, &cRandom_uvZuNA2M_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_uvZuNA2M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_drx0xO72_sendMessage);
}

void Heavy_Panoramizer::cUnop_m7beqnpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rbJZJbmS, HV_BINOP_MULTIPLY, 0, m, &cBinop_rbJZJbmS_sendMessage);
}

void Heavy_Panoramizer::cSlice_WwMzLeDW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_uvZuNA2M, 1, m, &cRandom_uvZuNA2M_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_Mz6gH7pt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LjLFJ3kE, HV_BINOP_MULTIPLY, 1, m, &cBinop_LjLFJ3kE_sendMessage);
}

void Heavy_Panoramizer::cBinop_02qzk8Gt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W9fmRJfz, 0, m, &cPack_W9fmRJfz_sendMessage);
}

void Heavy_Panoramizer::cCast_7Ebs7ylb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_StLAaoG5_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_GSKkAtWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_PigYmDD4_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_D3Nyy1DE, 0, m, &cIf_D3Nyy1DE_sendMessage);
}

void Heavy_Panoramizer::cBinop_YaxDi62V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XvRn3Xjo, m);
}

void Heavy_Panoramizer::cMsg_zSOMj055_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Mu3bEg4A_sendMessage);
}

void Heavy_Panoramizer::cBinop_PigYmDD4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_D3Nyy1DE, 1, m, &cIf_D3Nyy1DE_sendMessage);
}

void Heavy_Panoramizer::cIf_D3Nyy1DE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_pY4tYCMb_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jQBHLbbq_sendMessage);
      cMsg_6PN9Vz8v_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_M25BGRuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zSOMj055_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_6PN9Vz8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_IyZ8medk_sendMessage);
}

void Heavy_Panoramizer::cBinop_Mu3bEg4A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_16yliP8r, m);
}

void Heavy_Panoramizer::cSystem_gph1UqV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7QLfw7nX_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_oIOrxHJh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gph1UqV7_sendMessage);
}

void Heavy_Panoramizer::cMsg_1Ys1rmCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_M25BGRuu_sendMessage);
}

void Heavy_Panoramizer::cMsg_7QLfw7nX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YaxDi62V_sendMessage);
}

void Heavy_Panoramizer::cBinop_jQBHLbbq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1Ys1rmCS_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_IyZ8medk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VVK2qXgT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OJRnTqNL, m);
}

void Heavy_Panoramizer::cMsg_pY4tYCMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jQBHLbbq_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_VVK2qXgT, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_OJRnTqNL, m);
}

void Heavy_Panoramizer::cMsg_X0Ob7ZiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mz6gH7pt, HV_BINOP_SUBTRACT, 0, m, &cBinop_Mz6gH7pt_sendMessage);
}

void Heavy_Panoramizer::cMsg_YmgdjMyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_iqf52Ywm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_1h7qsGhr, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SJ7ylz8n, m);
}

void Heavy_Panoramizer::cBinop_XcXHpfXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nhGCqI07, m);
}

void Heavy_Panoramizer::cBinop_50vBBZnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_PcWwpi2z, 1, m, &cIf_PcWwpi2z_sendMessage);
}

void Heavy_Panoramizer::cIf_PcWwpi2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_YmgdjMyl_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_iqf52Ywm_sendMessage);
      cMsg_buvOChPv_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_4TFYOIMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1h7qsGhr, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SJ7ylz8n, m);
}

void Heavy_Panoramizer::cMsg_7RtQc050_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1H3vA2JD_sendMessage);
}

void Heavy_Panoramizer::cSystem_prfFyESQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aOiG0E6z_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_E4693JeT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_prfFyESQ_sendMessage);
}

void Heavy_Panoramizer::cMsg_A0PSU5id_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oZtx6oIc_sendMessage);
}

void Heavy_Panoramizer::cMsg_buvOChPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4TFYOIMA_sendMessage);
}

void Heavy_Panoramizer::cBinop_1H3vA2JD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_IJ4YXdZM, m);
}

void Heavy_Panoramizer::cVar_v9wRUjqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_50vBBZnM_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_PcWwpi2z, 0, m, &cIf_PcWwpi2z_sendMessage);
}

void Heavy_Panoramizer::cMsg_aOiG0E6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_XcXHpfXs_sendMessage);
}

void Heavy_Panoramizer::cBinop_oZtx6oIc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7RtQc050_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_iqf52Ywm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A0PSU5id_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cSwitchcase_e9y0sETG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6tlvggcF, 0, m, &cSlice_6tlvggcF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xatWoY4D, 0, m, &cRandom_xatWoY4D_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_xatWoY4D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_kclNqYJl_sendMessage);
}

void Heavy_Panoramizer::cSlice_6tlvggcF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_xatWoY4D, 1, m, &cRandom_xatWoY4D_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_kclNqYJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_H5U1GjJa_sendMessage);
}

void Heavy_Panoramizer::cUnop_H5U1GjJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m5VpCe1r, HV_BINOP_MULTIPLY, 0, m, &cBinop_m5VpCe1r_sendMessage);
}

void Heavy_Panoramizer::cMsg_XcpXy9tk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RsCWoG7b, 0, m, &cVar_RsCWoG7b_sendMessage);
}

void Heavy_Panoramizer::cBinop_OZTt3GGd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_rYpFakrK_sendMessage);
}

void Heavy_Panoramizer::cBinop_rYpFakrK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5foQqrD, 2, m, &cDelay_T5foQqrD_sendMessage);
}

void Heavy_Panoramizer::cVar_VSK1i4gq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OZTt3GGd, HV_BINOP_MULTIPLY, 0, m, &cBinop_OZTt3GGd_sendMessage);
}

void Heavy_Panoramizer::cMsg_KDbh0es6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5foQqrD, 0, m, &cDelay_T5foQqrD_sendMessage);
}

void Heavy_Panoramizer::cCast_Qg2yh5Om_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KDbh0es6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5foQqrD, 0, m, &cDelay_T5foQqrD_sendMessage);
  cSwitchcase_YsY5SKGR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cDelay_T5foQqrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_T5foQqrD, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_T5foQqrD, 0, m, &cDelay_T5foQqrD_sendMessage);
  cSwitchcase_YsY5SKGR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_20pHG0Ur_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OZTt3GGd, HV_BINOP_MULTIPLY, 1, m, &cBinop_OZTt3GGd_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Nkrny5fC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_KDbh0es6_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_KDbh0es6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qg2yh5Om_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSystem_5ypRwIeb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_20pHG0Ur_sendMessage);
}

void Heavy_Panoramizer::cMsg_TXFcWh95_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5ypRwIeb_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_sCASq7sZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_B5HcHBjB, 0, m, &cSlice_B5HcHBjB_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2VS60E7H, 0, m, &cRandom_2VS60E7H_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_2VS60E7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_daVeDsFp_sendMessage);
}

void Heavy_Panoramizer::cUnop_hk5zlryA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HlzE6CZo, 0, m, &cVar_HlzE6CZo_sendMessage);
}

void Heavy_Panoramizer::cSlice_B5HcHBjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2VS60E7H, 1, m, &cRandom_2VS60E7H_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_daVeDsFp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_hk5zlryA_sendMessage);
}

void Heavy_Panoramizer::cCast_bg8Omyvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q6d4Eew8_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_8RdMsw0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EqPAlUaj_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_EqPAlUaj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_O4OKymDF_sendMessage);
}

void Heavy_Panoramizer::cVar_ZHfKLawv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_y1N2ysps_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_EWkitfpr, 0, m, &cIf_EWkitfpr_sendMessage);
}

void Heavy_Panoramizer::cBinop_rZNyFAwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_aOAC5JtC, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FdD5BchY, m);
}

void Heavy_Panoramizer::cBinop_O4OKymDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HWN3viWC_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_vrqeH1gx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_8RdMsw0h_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aOAC5JtC, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FdD5BchY, m);
}

void Heavy_Panoramizer::cMsg_HWN3viWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_uLoEadLn_sendMessage);
}

void Heavy_Panoramizer::cBinop_uLoEadLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HJVBC1IV, m);
}

void Heavy_Panoramizer::cBinop_y1N2ysps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_EWkitfpr, 1, m, &cIf_EWkitfpr_sendMessage);
}

void Heavy_Panoramizer::cIf_EWkitfpr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_vrqeH1gx_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_8RdMsw0h_sendMessage);
      cMsg_MNAALtZH_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_b7IYseV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aBufhLXU_sendMessage);
}

void Heavy_Panoramizer::cSystem_aBufhLXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qIHwMmhk_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_4uKZUFfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8GmFdEWj, m);
}

void Heavy_Panoramizer::cMsg_MNAALtZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rZNyFAwB_sendMessage);
}

void Heavy_Panoramizer::cMsg_qIHwMmhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4uKZUFfX_sendMessage);
}

void Heavy_Panoramizer::cMsg_n0fl7sxU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_OKsZ8FgU_sendMessage);
}

void Heavy_Panoramizer::cBinop_Vbv7wGYj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_arOGUN5D, m);
}

void Heavy_Panoramizer::cMsg_2A09mpcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jKQUp9S6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6tUYgxh1, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_98eg6lHU, m);
}

void Heavy_Panoramizer::cSystem_Br4VyB4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dw1MpEFO_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_hcI5jnxK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Br4VyB4I_sendMessage);
}

void Heavy_Panoramizer::cMsg_dw1MpEFO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Vbv7wGYj_sendMessage);
}

void Heavy_Panoramizer::cBinop_jKQUp9S6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9EC30zXo_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_OKsZ8FgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6tUYgxh1, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_98eg6lHU, m);
}

void Heavy_Panoramizer::cBinop_SwgqeKTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ep881cFJ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_L5UVs6Sq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2rA4wbim, 1, m, &cIf_2rA4wbim_sendMessage);
}

void Heavy_Panoramizer::cIf_2rA4wbim_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2A09mpcI_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jKQUp9S6_sendMessage);
      cMsg_n0fl7sxU_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_9EC30zXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SwgqeKTN_sendMessage);
}

void Heavy_Panoramizer::cVar_s2nyp1TU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_L5UVs6Sq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2rA4wbim, 0, m, &cIf_2rA4wbim_sendMessage);
}

void Heavy_Panoramizer::cBinop_fVbVkMeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fXeJdq5K, m);
}

void Heavy_Panoramizer::cMsg_Ep881cFJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_fVbVkMeY_sendMessage);
}

void Heavy_Panoramizer::cCast_EUbnNKhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sd86TYlJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owaa2Oxd, 0, m, &cDelay_owaa2Oxd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZvupEsA5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_malw4Pcc_sendMessage);
}

void Heavy_Panoramizer::cBinop_2QeJofk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P7utx3WK, HV_BINOP_MULTIPLY, 1, m, &cBinop_P7utx3WK_sendMessage);
}

void Heavy_Panoramizer::cVar_qQ4Pvsv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P7utx3WK, HV_BINOP_MULTIPLY, 0, m, &cBinop_P7utx3WK_sendMessage);
}

void Heavy_Panoramizer::cBinop_HjArR5Wr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_owaa2Oxd, 2, m, &cDelay_owaa2Oxd_sendMessage);
}

void Heavy_Panoramizer::cMsg_sd86TYlJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_owaa2Oxd, 0, m, &cDelay_owaa2Oxd_sendMessage);
}

void Heavy_Panoramizer::cMsg_f7HL7gDQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NhLNMmsB_sendMessage);
}

void Heavy_Panoramizer::cSystem_NhLNMmsB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_2QeJofk1_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_sB9h69hq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_sd86TYlJ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_sd86TYlJ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EUbnNKhx_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_P7utx3WK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_HjArR5Wr_sendMessage);
}

void Heavy_Panoramizer::cDelay_owaa2Oxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_owaa2Oxd, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_owaa2Oxd, 0, m, &cDelay_owaa2Oxd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZvupEsA5_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_malw4Pcc_sendMessage);
}

void Heavy_Panoramizer::cSlice_bKZDYyXa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8OACpNrf, 1, m, &cRandom_8OACpNrf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_Aw270Lyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0vtB9sHC, 0, m, &cVar_0vtB9sHC_sendMessage);
}

void Heavy_Panoramizer::cBinop_oFE4vfyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Aw270Lyv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_Q2GGKUhv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_bKZDYyXa, 0, m, &cSlice_bKZDYyXa_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_8OACpNrf, 0, m, &cRandom_8OACpNrf_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_8OACpNrf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_oFE4vfyy_sendMessage);
}

void Heavy_Panoramizer::cBinop_Zk2IQcTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_vKt8hGAJ_sendMessage);
}

void Heavy_Panoramizer::cRandom_lmN82G1m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_Zk2IQcTX_sendMessage);
}

void Heavy_Panoramizer::cUnop_vKt8hGAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eWqcDLAV, HV_BINOP_MULTIPLY, 0, m, &cBinop_eWqcDLAV_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_z1eBGwWV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gmt31RwS, 0, m, &cSlice_gmt31RwS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lmN82G1m, 0, m, &cRandom_lmN82G1m_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_gmt31RwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_lmN82G1m, 1, m, &cRandom_lmN82G1m_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_q9FHGWZu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_4X5vo6ZY, 0, m, &cSlice_4X5vo6ZY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0ikYmb6C, 0, m, &cRandom_0ikYmb6C_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_4X5vo6ZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0ikYmb6C, 1, m, &cRandom_0ikYmb6C_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_xZcZvnlW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_cztohALq_sendMessage);
}

void Heavy_Panoramizer::cRandom_0ikYmb6C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZcZvnlW, HV_BINOP_MULTIPLY, 0, m, &cBinop_xZcZvnlW_sendMessage);
}

void Heavy_Panoramizer::cUnop_cztohALq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ANGiGGxM, HV_BINOP_ADD, 0, m, &cBinop_ANGiGGxM_sendMessage);
}

void Heavy_Panoramizer::cBinop_ppBP2Sv5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O3bmRSA8, HV_BINOP_MULTIPLY, 1, m, &cBinop_O3bmRSA8_sendMessage);
}

void Heavy_Panoramizer::cMsg_VHkce3eg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_49EaOASG, 0, m, &cDelay_49EaOASG_sendMessage);
}

void Heavy_Panoramizer::cBinop_AVhh2njR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_49EaOASG, 2, m, &cDelay_49EaOASG_sendMessage);
}

void Heavy_Panoramizer::cMsg_EB1c2ugA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AGDDvGt6_sendMessage);
}

void Heavy_Panoramizer::cSystem_AGDDvGt6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ppBP2Sv5_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_BKZ6EDzA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_VHkce3eg_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_VHkce3eg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xlbPBT2L_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_O3bmRSA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_AVhh2njR_sendMessage);
}

void Heavy_Panoramizer::cDelay_49EaOASG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_49EaOASG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_49EaOASG, 0, m, &cDelay_49EaOASG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Khcu6SYZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sySFbygs_sendMessage);
}

void Heavy_Panoramizer::cCast_xlbPBT2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VHkce3eg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_49EaOASG, 0, m, &cDelay_49EaOASG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Khcu6SYZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sySFbygs_sendMessage);
}

void Heavy_Panoramizer::cVar_HLqgiQZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O3bmRSA8, HV_BINOP_MULTIPLY, 0, m, &cBinop_O3bmRSA8_sendMessage);
}

void Heavy_Panoramizer::cMsg_sZEQuh1f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_el1NfoJN_sendMessage);
}

void Heavy_Panoramizer::cSystem_el1NfoJN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Paxln3Cz_sendMessage);
}

void Heavy_Panoramizer::cDelay_kdypqDsj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kdypqDsj, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kdypqDsj, 0, m, &cDelay_kdypqDsj_sendMessage);
  cSwitchcase_bTZ231YJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_TuBh4HIZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_t2tHMrNM_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kdypqDsj, 0, m, &cDelay_kdypqDsj_sendMessage);
  cSwitchcase_bTZ231YJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_t2tHMrNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kdypqDsj, 0, m, &cDelay_kdypqDsj_sendMessage);
}

void Heavy_Panoramizer::cBinop_hqRfqMyl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kdypqDsj, 2, m, &cDelay_kdypqDsj_sendMessage);
}

void Heavy_Panoramizer::cBinop_Paxln3Cz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pZkC1T7f, HV_BINOP_MULTIPLY, 1, m, &cBinop_pZkC1T7f_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_cjIARpmH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_t2tHMrNM_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_t2tHMrNM_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TuBh4HIZ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_pZkC1T7f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hqRfqMyl_sendMessage);
}

void Heavy_Panoramizer::cVar_iDbpmfUZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pZkC1T7f, HV_BINOP_MULTIPLY, 0, m, &cBinop_pZkC1T7f_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_N9SsTywh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zA6kF6jf, 0, m, &cSlice_zA6kF6jf_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1AHr5gKV, 0, m, &cRandom_1AHr5gKV_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_1AHr5gKV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_9ABquUAQ_sendMessage);
}

void Heavy_Panoramizer::cUnop_7k4YZED5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2H4vKUdQ, 0, m, &cVar_2H4vKUdQ_sendMessage);
}

void Heavy_Panoramizer::cSlice_zA6kF6jf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1AHr5gKV, 1, m, &cRandom_1AHr5gKV_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_9ABquUAQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7k4YZED5_sendMessage);
}

void Heavy_Panoramizer::cCast_S4aC79El_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_q9FHGWZu_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_gSEi0MP3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2iohUJzT_sendMessage);
}

void Heavy_Panoramizer::cSystem_2iohUJzT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_59aEJNbv_sendMessage);
}

void Heavy_Panoramizer::cBinop_59aEJNbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ALb6V83p, HV_BINOP_MULTIPLY, 1, m, &cBinop_ALb6V83p_sendMessage);
}

void Heavy_Panoramizer::cMsg_PiRKHmJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_boG16aB1, 0, m, &cDelay_boG16aB1_sendMessage);
}

void Heavy_Panoramizer::cCast_pmqYe7rl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PiRKHmJq_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_boG16aB1, 0, m, &cDelay_boG16aB1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n5bPGY26_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JN3qnPMF_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_hFETmUea_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_PiRKHmJq_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_PiRKHmJq_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pmqYe7rl_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cVar_xVsw7h5K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ALb6V83p, HV_BINOP_MULTIPLY, 0, m, &cBinop_ALb6V83p_sendMessage);
}

void Heavy_Panoramizer::cBinop_wFFQrvIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_boG16aB1, 2, m, &cDelay_boG16aB1_sendMessage);
}

void Heavy_Panoramizer::cDelay_boG16aB1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_boG16aB1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_boG16aB1, 0, m, &cDelay_boG16aB1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n5bPGY26_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JN3qnPMF_sendMessage);
}

void Heavy_Panoramizer::cBinop_ALb6V83p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_wFFQrvIy_sendMessage);
}

void Heavy_Panoramizer::cCast_KjSlRqYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YPB0dPdM_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_g4EGUXFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_s2nyp1TU, 0, m, &cVar_s2nyp1TU_sendMessage);
}

void Heavy_Panoramizer::cCast_s9x3hnTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CDcsfdYM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_TSKJtKEE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zPN8xbI8, HV_BINOP_MULTIPLY, 1, m, &cBinop_zPN8xbI8_sendMessage);
}

void Heavy_Panoramizer::cBinop_ekxCaIOG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6fvC3mn6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m8QkBPyg_sendMessage);
}

void Heavy_Panoramizer::cVar_NrXaf2QS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LjQfPN2D, HV_BINOP_MULTIPLY, 0, m, &cBinop_LjQfPN2D_sendMessage);
}

void Heavy_Panoramizer::cDelay_RFqgfXtf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RFqgfXtf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFqgfXtf, 0, m, &cDelay_RFqgfXtf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_euxlsWcS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_amxvk08q_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_pVWUFGUy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_WnMNEdfO_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_WnMNEdfO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YQmbbKnk_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_LjQfPN2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_2yB9dFmR_sendMessage);
}

void Heavy_Panoramizer::cCast_YQmbbKnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WnMNEdfO_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFqgfXtf, 0, m, &cDelay_RFqgfXtf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_euxlsWcS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_amxvk08q_sendMessage);
}

void Heavy_Panoramizer::cBinop_gtCJXOr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LjQfPN2D, HV_BINOP_MULTIPLY, 1, m, &cBinop_LjQfPN2D_sendMessage);
}

void Heavy_Panoramizer::cSystem_mqA2RhJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_gtCJXOr4_sendMessage);
}

void Heavy_Panoramizer::cMsg_eLrocFQk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mqA2RhJt_sendMessage);
}

void Heavy_Panoramizer::cBinop_2yB9dFmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFqgfXtf, 2, m, &cDelay_RFqgfXtf_sendMessage);
}

void Heavy_Panoramizer::cMsg_WnMNEdfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RFqgfXtf, 0, m, &cDelay_RFqgfXtf_sendMessage);
}

void Heavy_Panoramizer::cCast_1u3qL0ge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_w0hFg79y_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_SatCeEp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_77kZnW7L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_6GW2gei1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LrdlIgQ0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bg8Omyvg_sendMessage);
}

void Heavy_Panoramizer::cBinop_L4t142nQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0p5Y3c87_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_V79dVbyU_sendMessage);
}

void Heavy_Panoramizer::cSlice_B9hMMrQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sewkZHyS, 1, m, &cRandom_sewkZHyS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cRandom_sewkZHyS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_mGz5rofY_sendMessage);
}

void Heavy_Panoramizer::cUnop_HwxokRuQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SZiBnqS4, HV_BINOP_MULTIPLY, 0, m, &cBinop_SZiBnqS4_sendMessage);
}

void Heavy_Panoramizer::cBinop_mGz5rofY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_HwxokRuQ_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_m4Ezei0g_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_B9hMMrQg, 0, m, &cSlice_B9hMMrQg_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_sewkZHyS, 0, m, &cRandom_sewkZHyS_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cCast_m3nGRmwz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t4cEEUAl, HV_BINOP_SUBTRACT, 1, m, &cBinop_t4cEEUAl_sendMessage);
}

void Heavy_Panoramizer::cPack_Cn5YA3er_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_nv2OGtLu, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_iDtqnOGu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nvXiU0Qh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_V79dVbyU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e6jiCYPH_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cCast_m8QkBPyg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Gy4PfGMa_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_t4cEEUAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_00caoaka, HV_BINOP_MULTIPLY, 1, m, &cBinop_00caoaka_sendMessage);
}

void Heavy_Panoramizer::cCast_xdxbmnDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mz6gH7pt, HV_BINOP_SUBTRACT, 1, m, &cBinop_Mz6gH7pt_sendMessage);
}

void Heavy_Panoramizer::cMsg_YG9LoChS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_vP3tlHZk_sendMessage);
}

void Heavy_Panoramizer::cBinop_uvcLANII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_N8eWmFKE, m);
}

void Heavy_Panoramizer::cMsg_26x8faTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_uvcLANII_sendMessage);
}

void Heavy_Panoramizer::cBinop_Z1ZUligO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_26x8faTm_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_4sCTo5Fp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fQaFKSrX, m);
}

void Heavy_Panoramizer::cMsg_qOPsF2gr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Aqv15M2I_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_dFPy4f4q, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eG6D86Ca, m);
}

void Heavy_Panoramizer::cVar_E449kfwA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_0dDoLIAF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4pqK4siO, 0, m, &cIf_4pqK4siO_sendMessage);
}

void Heavy_Panoramizer::cIf_4pqK4siO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_qOPsF2gr_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_Aqv15M2I_sendMessage);
      cMsg_YG9LoChS_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_0dDoLIAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4pqK4siO, 1, m, &cIf_4pqK4siO_sendMessage);
}

void Heavy_Panoramizer::cBinop_Aqv15M2I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W62L1Mg4_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_vP3tlHZk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_dFPy4f4q, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eG6D86Ca, m);
}

void Heavy_Panoramizer::cSystem_74TxpVER_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oXALtuMZ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_Cj5qMIpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_74TxpVER_sendMessage);
}

void Heavy_Panoramizer::cMsg_W62L1Mg4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Z1ZUligO_sendMessage);
}

void Heavy_Panoramizer::cMsg_oXALtuMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4sCTo5Fp_sendMessage);
}

void Heavy_Panoramizer::cBinop_c6rjZvwE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LLGnZA3U, HV_BINOP_MULTIPLY, 1, m, &cBinop_LLGnZA3U_sendMessage);
}

void Heavy_Panoramizer::cBinop_0PkbET6V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xZcZvnlW, HV_BINOP_MULTIPLY, 1, m, &cBinop_xZcZvnlW_sendMessage);
}

void Heavy_Panoramizer::cBinop_44yLmCDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rjD9hs0A_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JtmmRsLk_sendMessage);
}

void Heavy_Panoramizer::cPack_Om8klIWY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_92pzSl5j, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_d8cP6z8N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RkRQ9YeV, 0, m, &cVar_RkRQ9YeV_sendMessage);
}

void Heavy_Panoramizer::cBinop_REjbwuAe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ewI8OedI, 0, m, &cPack_ewI8OedI_sendMessage);
}

void Heavy_Panoramizer::cDelay_jtxpHkMR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jtxpHkMR, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jtxpHkMR, 0, m, &cDelay_jtxpHkMR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SatCeEp8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lwcy7WmW_sendMessage);
}

void Heavy_Panoramizer::cBinop_W2tDRMrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_uCdE6C0f_sendMessage);
}

void Heavy_Panoramizer::cBinop_uCdE6C0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jtxpHkMR, 2, m, &cDelay_jtxpHkMR_sendMessage);
}

void Heavy_Panoramizer::cBinop_DODACrbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W2tDRMrT, HV_BINOP_MULTIPLY, 1, m, &cBinop_W2tDRMrT_sendMessage);
}

void Heavy_Panoramizer::cSystem_1Kw0uOfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_DODACrbw_sendMessage);
}

void Heavy_Panoramizer::cMsg_v66aF2qM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Kw0uOfX_sendMessage);
}

void Heavy_Panoramizer::cVar_cVTWc9hF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_W2tDRMrT, HV_BINOP_MULTIPLY, 0, m, &cBinop_W2tDRMrT_sendMessage);
}

void Heavy_Panoramizer::cCast_X1dSHkYU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6uaxxW4X_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_jtxpHkMR, 0, m, &cDelay_jtxpHkMR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SatCeEp8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lwcy7WmW_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_DbdFDO2x_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_6uaxxW4X_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_6uaxxW4X_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X1dSHkYU_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_6uaxxW4X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jtxpHkMR, 0, m, &cDelay_jtxpHkMR_sendMessage);
}

void Heavy_Panoramizer::cMsg_GHUpAlaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_HpKUrAPP_sendMessage);
}

void Heavy_Panoramizer::cBinop_HpKUrAPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gCopKF1Y, m);
}

void Heavy_Panoramizer::cBinop_Fk3HZ3gf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SKlmK0Vs, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_h8riM1ZY, m);
}

void Heavy_Panoramizer::cBinop_mcfPOzq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dqtDWfsc_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_RMqUwjw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Fk3HZ3gf_sendMessage);
}

void Heavy_Panoramizer::cIf_kDCAapv2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_RpipAEnK_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_mcfPOzq8_sendMessage);
      cMsg_RMqUwjw0_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_M3eufOpE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kDCAapv2, 1, m, &cIf_kDCAapv2_sendMessage);
}

void Heavy_Panoramizer::cMsg_dqtDWfsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Up87Mqio_sendMessage);
}

void Heavy_Panoramizer::cBinop_BEK1imeN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RuTblLji, m);
}

void Heavy_Panoramizer::cMsg_5mKt1Z8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Yc3pKFQC_sendMessage);
}

void Heavy_Panoramizer::cSystem_Yc3pKFQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GHUpAlaQ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cVar_RsCWoG7b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_M3eufOpE_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_kDCAapv2, 0, m, &cIf_kDCAapv2_sendMessage);
}

void Heavy_Panoramizer::cBinop_Up87Mqio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jFyKv8ne_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_jFyKv8ne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_BEK1imeN_sendMessage);
}

void Heavy_Panoramizer::cMsg_RpipAEnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_mcfPOzq8_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_SKlmK0Vs, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_h8riM1ZY, m);
}

void Heavy_Panoramizer::cSlice_vNj5ytSx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ovOOJxqp, 1, m, &cRandom_ovOOJxqp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_N1o3Egv0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vNj5ytSx, 0, m, &cSlice_vNj5ytSx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ovOOJxqp, 0, m, &cRandom_ovOOJxqp_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_am722UrU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BUiVDeyR, 0, m, &cVar_BUiVDeyR_sendMessage);
}

void Heavy_Panoramizer::cRandom_ovOOJxqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_hZe28BgU_sendMessage);
}

void Heavy_Panoramizer::cBinop_hZe28BgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_am722UrU_sendMessage);
}

void Heavy_Panoramizer::cBinop_xKHLzfTV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_l15WWzlQ_sendMessage);
}

void Heavy_Panoramizer::cSlice_pc9qptQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qUq1h3cy, 1, m, &cRandom_qUq1h3cy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_2MCk59HI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pc9qptQx, 0, m, &cSlice_pc9qptQx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_qUq1h3cy, 0, m, &cRandom_qUq1h3cy_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_l15WWzlQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RCYSUZvx, HV_BINOP_MULTIPLY, 0, m, &cBinop_RCYSUZvx_sendMessage);
}

void Heavy_Panoramizer::cRandom_qUq1h3cy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_xKHLzfTV_sendMessage);
}

void Heavy_Panoramizer::cBinop_DrZO29TU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y35bMjXe, 0, m, &cPack_y35bMjXe_sendMessage);
}

void Heavy_Panoramizer::cMsg_s0ackoer_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0PkbET6V, HV_BINOP_SUBTRACT, 0, m, &cBinop_0PkbET6V_sendMessage);
}

void Heavy_Panoramizer::cMsg_Gy4PfGMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U37Dg4um, HV_BINOP_SUBTRACT, 0, m, &cBinop_U37Dg4um_sendMessage);
}

void Heavy_Panoramizer::cMsg_NSKXj5pQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cN8Ytvzf, HV_BINOP_SUBTRACT, 0, m, &cBinop_cN8Ytvzf_sendMessage);
}

void Heavy_Panoramizer::cRandom_EozFXAoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_Hg9D4Mkr_sendMessage);
}

void Heavy_Panoramizer::cSlice_gtnWTWtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EozFXAoN, 1, m, &cRandom_EozFXAoN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_Hg9D4Mkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RDmuSqGU_sendMessage);
}

void Heavy_Panoramizer::cUnop_RDmuSqGU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HLqgiQZ5, 0, m, &cVar_HLqgiQZ5_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_2HDcUz85_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gtnWTWtY, 0, m, &cSlice_gtnWTWtY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_EozFXAoN, 0, m, &cRandom_EozFXAoN_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_TZ7B6vT7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_E449kfwA, 0, m, &cVar_E449kfwA_sendMessage);
}

void Heavy_Panoramizer::cPack_qtR0WCgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_V5maCN7A, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_malw4Pcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RPikQ2uf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_eWqcDLAV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_W9fmRJfz, 1, m, &cPack_W9fmRJfz_sendMessage);
}

void Heavy_Panoramizer::cSystem_Hy1Mqsqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NkLQwWqA_sendMessage);
}

void Heavy_Panoramizer::cMsg_VxlW84i5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Hy1Mqsqp_sendMessage);
}

void Heavy_Panoramizer::cCast_IqHNaqXC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qf8yn2u6_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjyhdmjG, 0, m, &cDelay_KjyhdmjG_sendMessage);
  cSwitchcase_Q2GGKUhv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cVar_jJp5cHSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0IDq6I2f, HV_BINOP_MULTIPLY, 0, m, &cBinop_0IDq6I2f_sendMessage);
}

void Heavy_Panoramizer::cMsg_qf8yn2u6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjyhdmjG, 0, m, &cDelay_KjyhdmjG_sendMessage);
}

void Heavy_Panoramizer::cBinop_XitbF1AP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjyhdmjG, 2, m, &cDelay_KjyhdmjG_sendMessage);
}

void Heavy_Panoramizer::cBinop_0IDq6I2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XitbF1AP_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_RiFyAnQU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_qf8yn2u6_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_qf8yn2u6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IqHNaqXC_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_NkLQwWqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0IDq6I2f, HV_BINOP_MULTIPLY, 1, m, &cBinop_0IDq6I2f_sendMessage);
}

void Heavy_Panoramizer::cDelay_KjyhdmjG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KjyhdmjG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_KjyhdmjG, 0, m, &cDelay_KjyhdmjG_sendMessage);
  cSwitchcase_Q2GGKUhv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_gYagnZTv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_sCFBwH4F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cPack_ptANniBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_NOmkPjal, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_SZiBnqS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_5OWxo3Nw, 1, m, &cPack_5OWxo3Nw_sendMessage);
}

void Heavy_Panoramizer::cCast_AYnW9mKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_X0Ob7ZiA_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cUnop_d5T9GWgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cVTWc9hF, 0, m, &cVar_cVTWc9hF_sendMessage);
}

void Heavy_Panoramizer::cRandom_L0SH4LoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_OUqQKKQB_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_xuPDsH2h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TQhNw1ez, 0, m, &cSlice_TQhNw1ez_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_L0SH4LoN, 0, m, &cRandom_L0SH4LoN_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_OUqQKKQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_d5T9GWgA_sendMessage);
}

void Heavy_Panoramizer::cSlice_TQhNw1ez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_L0SH4LoN, 1, m, &cRandom_L0SH4LoN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cMsg_VlZ1nzRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Tt3BNlJ9, 0, m, &cVar_Tt3BNlJ9_sendMessage);
}

void Heavy_Panoramizer::cBinop_JQkemYWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_nd6htOOI, 0, m, &cPack_nd6htOOI_sendMessage);
}

void Heavy_Panoramizer::cMsg_rjp0KLeS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OUmSeSZG, HV_BINOP_SUBTRACT, 0, m, &cBinop_OUmSeSZG_sendMessage);
}

void Heavy_Panoramizer::cBinop_X1OoMSP6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_moBH697m, HV_BINOP_MULTIPLY, 1, m, &cBinop_moBH697m_sendMessage);
}

void Heavy_Panoramizer::cCast_qzkcfLqS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0PkbET6V, HV_BINOP_SUBTRACT, 1, m, &cBinop_0PkbET6V_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_UU8pa0pD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AwJW8XRL, 0, m, &cSlice_AwJW8XRL_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SI5ENb2K, 0, m, &cRandom_SI5ENb2K_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_4wP72aLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Zk51mS7k_sendMessage);
}

void Heavy_Panoramizer::cSlice_AwJW8XRL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_SI5ENb2K, 1, m, &cRandom_SI5ENb2K_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_Zk51mS7k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xVsw7h5K, 0, m, &cVar_xVsw7h5K_sendMessage);
}

void Heavy_Panoramizer::cRandom_SI5ENb2K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_4wP72aLI_sendMessage);
}

void Heavy_Panoramizer::cBinop_RCYSUZvx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_y35bMjXe, 1, m, &cPack_y35bMjXe_sendMessage);
}

void Heavy_Panoramizer::cBinop_tFi4hSNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cLtQaIWW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KjSlRqYu_sendMessage);
}

void Heavy_Panoramizer::cCast_VnnYgnhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rjp0KLeS_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cUnop_xo9Xzy5i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qQ4Pvsv3, 0, m, &cVar_qQ4Pvsv3_sendMessage);
}

void Heavy_Panoramizer::cRandom_MGwtL7s8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_CzYx0WOO_sendMessage);
}

void Heavy_Panoramizer::cSlice_a1xKulqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MGwtL7s8, 1, m, &cRandom_MGwtL7s8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_CzYx0WOO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xo9Xzy5i_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_bPJIHPxB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_a1xKulqn, 0, m, &cSlice_a1xKulqn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_MGwtL7s8, 0, m, &cRandom_MGwtL7s8_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cPack_W9fmRJfz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_Qlcis11d, 0, m, NULL);
}

void Heavy_Panoramizer::cSlice_62c0O147_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fVnSz6qy, 1, m, &cRandom_fVnSz6qy_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cSwitchcase_YsY5SKGR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_62c0O147, 0, m, &cSlice_62c0O147_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_fVnSz6qy, 0, m, &cRandom_fVnSz6qy_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cUnop_IHqglj6P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A9Mmxda7, 0, m, &cVar_A9Mmxda7_sendMessage);
}

void Heavy_Panoramizer::cRandom_fVnSz6qy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1000.0f, 0, m, &cBinop_L0xCkGVO_sendMessage);
}

void Heavy_Panoramizer::cBinop_L0xCkGVO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_IHqglj6P_sendMessage);
}

void Heavy_Panoramizer::cMsg_q6d4Eew8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 100.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ipne0k3D, HV_BINOP_SUBTRACT, 0, m, &cBinop_Ipne0k3D_sendMessage);
}

void Heavy_Panoramizer::cCast_6fvC3mn6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U37Dg4um, HV_BINOP_SUBTRACT, 1, m, &cBinop_U37Dg4um_sendMessage);
}

void Heavy_Panoramizer::cBinop_U37Dg4um_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZGB0ejZo, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZGB0ejZo_sendMessage);
}

void Heavy_Panoramizer::cBinop_NFGMmH3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ptANniBq, 0, m, &cPack_ptANniBq_sendMessage);
}

void Heavy_Panoramizer::cBinop_ryQC9hgD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_qtR0WCgA, 1, m, &cPack_qtR0WCgA_sendMessage);
}

void Heavy_Panoramizer::cCast_JtmmRsLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NSKXj5pQ_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_58xRd3xU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qzkcfLqS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vAD7H57e_sendMessage);
}

void Heavy_Panoramizer::cPack_nd6htOOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_VNZPhbQZ, 0, m, NULL);
}

void Heavy_Panoramizer::cCast_sySFbygs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_a8Eav3gU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cMsg_SwGZSk7s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_EQgphIe3_sendMessage);
}

void Heavy_Panoramizer::cVar_Tt3BNlJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_sm3xwW6T_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_nFk8FTJp, 0, m, &cIf_nFk8FTJp_sendMessage);
}

void Heavy_Panoramizer::cMsg_zLUPeT4w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1obE3Wwh_sendMessage);
}

void Heavy_Panoramizer::cBinop_DBEwqJaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eQnjGg0F, m);
}

void Heavy_Panoramizer::cMsg_6H21RkRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_DBEwqJaf_sendMessage);
}

void Heavy_Panoramizer::cMsg_yRVDGQu1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nspDp5is_sendMessage);
}

void Heavy_Panoramizer::cSystem_nspDp5is_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6H21RkRq_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cBinop_EQgphIe3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_bUjDxYUw, m);
}

void Heavy_Panoramizer::cBinop_EAdRqPx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lGLhZ20V_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_nkzQAmbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_EAdRqPx6_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TGBMGt3U, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rxxhyvoq, m);
}

void Heavy_Panoramizer::cBinop_sm3xwW6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_nFk8FTJp, 1, m, &cIf_nFk8FTJp_sendMessage);
}

void Heavy_Panoramizer::cIf_nFk8FTJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_nkzQAmbU_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_EAdRqPx6_sendMessage);
      cMsg_zLUPeT4w_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_1obE3Wwh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_TGBMGt3U, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Rxxhyvoq, m);
}

void Heavy_Panoramizer::cBinop_TwpzK0Zk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SwGZSk7s_sendMessage(_c, 0, m);
}

void Heavy_Panoramizer::cMsg_lGLhZ20V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TwpzK0Zk_sendMessage);
}

void Heavy_Panoramizer::cBinop_VehvOkZW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_ewI8OedI, 1, m, &cPack_ewI8OedI_sendMessage);
}

void Heavy_Panoramizer::cBinop_EeAIPlDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Om8klIWY, 0, m, &cPack_Om8klIWY_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_a8Eav3gU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_QzAnwd6i, 0, m, &cSlice_QzAnwd6i_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_w2kDc45B, 0, m, &cRandom_w2kDc45B_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cRandom_w2kDc45B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zPN8xbI8, HV_BINOP_MULTIPLY, 0, m, &cBinop_zPN8xbI8_sendMessage);
}

void Heavy_Panoramizer::cBinop_zPN8xbI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_2AslkCdz_sendMessage);
}

void Heavy_Panoramizer::cUnop_2AslkCdz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_02qzk8Gt, HV_BINOP_ADD, 0, m, &cBinop_02qzk8Gt_sendMessage);
}

void Heavy_Panoramizer::cSlice_QzAnwd6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_w2kDc45B, 1, m, &cRandom_w2kDc45B_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_XunfjoNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oxZEvaCw, HV_BINOP_ADD, 0, m, &cBinop_oxZEvaCw_sendMessage);
}

void Heavy_Panoramizer::cRandom_RNyY7Bbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_moBH697m, HV_BINOP_MULTIPLY, 0, m, &cBinop_moBH697m_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_OmevIY5b_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dE4hiSoY, 0, m, &cSlice_dE4hiSoY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RNyY7Bbb, 0, m, &cRandom_RNyY7Bbb_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_moBH697m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_XunfjoNl_sendMessage);
}

void Heavy_Panoramizer::cSlice_dE4hiSoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RNyY7Bbb, 1, m, &cRandom_RNyY7Bbb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cBinop_gtocELHj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WSdkcf6W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VnnYgnhA_sendMessage);
}

void Heavy_Panoramizer::cRandom_Ngp0PEgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LjLFJ3kE, HV_BINOP_MULTIPLY, 0, m, &cBinop_LjLFJ3kE_sendMessage);
}

void Heavy_Panoramizer::cBinop_LjLFJ3kE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_yb6Tjv7p_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_RPikQ2uf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pOewS3jV, 0, m, &cSlice_pOewS3jV_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ngp0PEgQ, 0, m, &cRandom_Ngp0PEgQ_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cSlice_pOewS3jV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_Ngp0PEgQ, 1, m, &cRandom_Ngp0PEgQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_Panoramizer::cUnop_yb6Tjv7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_REjbwuAe, HV_BINOP_ADD, 0, m, &cBinop_REjbwuAe_sendMessage);
}

void Heavy_Panoramizer::cCast_0ZVAzrbE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c6rjZvwE, HV_BINOP_SUBTRACT, 1, m, &cBinop_c6rjZvwE_sendMessage);
}

void Heavy_Panoramizer::cCast_LrdlIgQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ipne0k3D, HV_BINOP_SUBTRACT, 1, m, &cBinop_Ipne0k3D_sendMessage);
}

void Heavy_Panoramizer::cCast_WSdkcf6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OUmSeSZG, HV_BINOP_SUBTRACT, 1, m, &cBinop_OUmSeSZG_sendMessage);
}

void Heavy_Panoramizer::cCast_aUYRAL0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EmJxcypm_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x6ADI2af, 0, m, &cDelay_x6ADI2af_sendMessage);
  cSwitchcase_UU8pa0pD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_hUctVNvt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vYevoqM8, HV_BINOP_MULTIPLY, 1, m, &cBinop_vYevoqM8_sendMessage);
}

void Heavy_Panoramizer::cVar_KVxAJzWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vYevoqM8, HV_BINOP_MULTIPLY, 0, m, &cBinop_vYevoqM8_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_DHyfsQyh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_EmJxcypm_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_EmJxcypm_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aUYRAL0G_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cBinop_7vcIgque_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_x6ADI2af, 2, m, &cDelay_x6ADI2af_sendMessage);
}

void Heavy_Panoramizer::cBinop_vYevoqM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_7vcIgque_sendMessage);
}

void Heavy_Panoramizer::cMsg_EmJxcypm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_x6ADI2af, 0, m, &cDelay_x6ADI2af_sendMessage);
}

void Heavy_Panoramizer::cMsg_Rw15R2F4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Kp3DoVii_sendMessage);
}

void Heavy_Panoramizer::cSystem_Kp3DoVii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_hUctVNvt_sendMessage);
}

void Heavy_Panoramizer::cDelay_x6ADI2af_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_x6ADI2af, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_x6ADI2af, 0, m, &cDelay_x6ADI2af_sendMessage);
  cSwitchcase_UU8pa0pD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_Panoramizer::cBinop_M8l6MMwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aLavtMi2, HV_BINOP_MULTIPLY, 1, m, &cBinop_aLavtMi2_sendMessage);
}

void Heavy_Panoramizer::cBinop_aLavtMi2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VGlAIDoU_sendMessage);
}

void Heavy_Panoramizer::cDelay_sAIku2Or_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_sAIku2Or, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sAIku2Or, 0, m, &cDelay_sAIku2Or_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1u3qL0ge_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gYagnZTv_sendMessage);
}

void Heavy_Panoramizer::cSwitchcase_KP543Cgv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_FdQMJsYu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_FdQMJsYu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lUwn8oSj_sendMessage);
      break;
    }
  }
}

void Heavy_Panoramizer::cMsg_18fGWkNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JZ7fZsgB_sendMessage);
}

void Heavy_Panoramizer::cSystem_JZ7fZsgB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_M8l6MMwG_sendMessage);
}

void Heavy_Panoramizer::cMsg_FdQMJsYu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_sAIku2Or, 0, m, &cDelay_sAIku2Or_sendMessage);
}

void Heavy_Panoramizer::cBinop_VGlAIDoU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_sAIku2Or, 2, m, &cDelay_sAIku2Or_sendMessage);
}

void Heavy_Panoramizer::cVar_2H4vKUdQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aLavtMi2, HV_BINOP_MULTIPLY, 0, m, &cBinop_aLavtMi2_sendMessage);
}

void Heavy_Panoramizer::cCast_lUwn8oSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FdQMJsYu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_sAIku2Or, 0, m, &cDelay_sAIku2Or_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1u3qL0ge_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gYagnZTv_sendMessage);
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
    sEnv_process(this, &sEnv_N4bFX7cm, VIf(I1), &sEnv_N4bFX7cm_sendMessage);
    __hv_varread_f(&sVarf_qo4SdCzc, VOf(Bf0));
    __hv_varread_f(&sVarf_5yFNHZ2G, VOf(Bf1));
    __hv_varread_f(&sVarf_AgKSUT2Z, VOf(Bf2));
    __hv_varread_f(&sVarf_5UyNY4sS, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_KvNFMO24, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_zzT2Vmhh, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_tvwcMdxz, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_OYxVlYHo, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_PBWmHT8n, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_hvT1m8Kb, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_z1QrhhkP, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_B94cCK8d, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_neqSe77V, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_vhfgPbOD, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_BoFfdS9o, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Qwbjmue8, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_S6OfB04b, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_xVScJl5v, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_7kDCHin8, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Wkb8LeSC, VOf(Bf3));
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_XqPpAKN7, VOf(Bf2));
    __hv_add_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_crUSpZwm, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Tmy1Smuh, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(I0), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_KQlixPEc, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_pLnqn8sF, VOf(Bf4));
    __hv_fms_f(VIf(Bf3), VIf(Bf4), VIf(Bf1), VOf(Bf4));
    __hv_varread_f(&sVarf_kTZUn6et, VOf(Bf3));
    __hv_zero_f(VOf(Bf5));
    __hv_neq_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf4));
    __hv_min_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf1), VIf(Bf4), VOf(Bf1));
    __hv_varread_f(&sVarf_aBLKlM4i, VOf(Bf5));
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf0), VOf(Bf1));
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf3), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf7), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf7), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf0));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_cpole_f(&sCPole_mQcQT4fr, VIf(Bf5), VIf(ZERO), VIf(Bf8), VIf(Bf6), VOf(Bf6), VOf(Bf8));
    __hv_line_f(&sLine_6UOJDo9X, VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_neg_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_1hXDoMZh, VIf(Bf4));
    __hv_var_k_f(VOf(Bf4), 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_ObkpX0JF, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_bpEJoxb2, VOf(Bf0));
    __hv_fms_f(VIf(Bf3), VIf(Bf0), VIf(Bf5), VOf(Bf0));
    __hv_varread_f(&sVarf_GCLVuW2N, VOf(Bf3));
    __hv_zero_f(VOf(Bf7));
    __hv_neq_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_and_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_zero_f(VOf(Bf0));
    __hv_min_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf5), VIf(Bf0), VOf(Bf5));
    __hv_varread_f(&sVarf_leGUt24b, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_floor_f(VIf(Bf4), VOf(Bf5));
    __hv_sub_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
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
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf3), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf5), VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf4));
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_cpole_f(&sCPole_U6A4W26R, VIf(Bf7), VIf(ZERO), VIf(Bf10), VIf(Bf1), VOf(Bf1), VOf(Bf10));
    __hv_line_f(&sLine_LJsKvZiV, VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_QjMcnI7C, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f);
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_D7UFyLfA, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_mYrXnenw, VOf(Bf4));
    __hv_fms_f(VIf(Bf3), VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_varread_f(&sVarf_UzxSPCNd, VOf(Bf3));
    __hv_zero_f(VOf(Bf9));
    __hv_neq_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_and_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_zero_f(VOf(Bf4));
    __hv_min_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf7), VIf(Bf4), VOf(Bf7));
    __hv_varread_f(&sVarf_9WXHRRsI, VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf0), VOf(Bf7));
    __hv_sub_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
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
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf3), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf7), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf4), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf11), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf11), VOf(Bf0));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_abs_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf11), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf11), VOf(Bf0));
    __hv_mul_f(VIf(Bf11), VIf(Bf0), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf11), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_DlwlNtTj, VIf(Bf9), VIf(ZERO), VIf(Bf12), VIf(Bf5), VOf(Bf5), VOf(Bf12));
    __hv_line_f(&sLine_VJ2INnuh, VOf(Bf12));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_neg_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf4), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_E0B1zMQm, VIf(Bf4));
    __hv_var_k_f(VOf(Bf4), 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f);
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_jy3S0COU, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_emuooEVs, VOf(Bf0));
    __hv_fms_f(VIf(Bf3), VIf(Bf0), VIf(Bf9), VOf(Bf0));
    __hv_varread_f(&sVarf_vchyr2pd, VOf(Bf3));
    __hv_zero_f(VOf(Bf11));
    __hv_neq_f(VIf(Bf3), VIf(Bf11), VOf(Bf11));
    __hv_and_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_zero_f(VOf(Bf0));
    __hv_min_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf9), VIf(Bf0), VOf(Bf9));
    __hv_varread_f(&sVarf_jIRlihq3, VOf(Bf11));
    __hv_mul_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_floor_f(VIf(Bf4), VOf(Bf9));
    __hv_sub_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf3), VIf(Bf9), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf13), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf14), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf9), VIf(Bf13), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf13), VOf(Bf4));
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_abs_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf13), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf13), VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_cpole_f(&sCPole_7TE3z8p9, VIf(Bf11), VIf(ZERO), VIf(Bf14), VIf(Bf7), VOf(Bf7), VOf(Bf14));
    __hv_line_f(&sLine_DtYYCGqY, VOf(Bf14));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf14), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_f(&sVarf_neqSe77V, VIf(Bf11));
    __hv_varread_f(&sVarf_3fWZeJHE, VOf(Bf11));
    __hv_rpole_f(&sRPole_h8T9GkRt, VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_HPm39iRQ, VIf(Bf11), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf11), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_D7H7iYNt, VOf(Bf11));
    __hv_mul_f(VIf(Bf0), VIf(Bf11), VOf(Bf11));
    __hv_line_f(&sLine_n79ul0lu, VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf11), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_f(&sVarf_6q99H2m3, VIf(Bf4));
    __hv_var_k_f(VOf(Bf4), 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf13));
    __hv_max_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_CcwMSHKC, VOf(Bf4));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf13), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_varread_f(&sVarf_QKzT4Sf9, VOf(Bf9));
    __hv_fms_f(VIf(Bf13), VIf(Bf9), VIf(Bf3), VOf(Bf9));
    __hv_varread_f(&sVarf_eOMz455y, VOf(Bf13));
    __hv_zero_f(VOf(Bf15));
    __hv_neq_f(VIf(Bf13), VIf(Bf15), VOf(Bf15));
    __hv_and_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_zero_f(VOf(Bf9));
    __hv_min_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf3), VIf(Bf9), VOf(Bf3));
    __hv_varread_f(&sVarf_lSaoDUIF, VOf(Bf15));
    __hv_mul_f(VIf(Bf3), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_floor_f(VIf(Bf4), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_abs_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf13), VOf(Bf3));
    __hv_mul_f(VIf(Bf13), VIf(Bf3), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf3), VIf(Bf17), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf4));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf4));
    __hv_mul_f(VIf(Bf17), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf13), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf3), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf4), VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_cpole_f(&sCPole_bPpPW6XI, VIf(Bf15), VIf(ZERO), VIf(Bf18), VIf(Bf16), VOf(Bf16), VOf(Bf18));
    __hv_line_f(&sLine_ZSzD7Aq4, VOf(Bf18));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf18), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_7kDCHin8, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_S6OfB04b, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_O1LZkbTu, VOf(Bf15));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf12), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_bmbHc1d1, VOf(Bf9));
    __hv_fms_f(VIf(Bf12), VIf(Bf9), VIf(Bf5), VOf(Bf9));
    __hv_varread_f(&sVarf_Kjkm7ekA, VOf(Bf12));
    __hv_zero_f(VOf(Bf13));
    __hv_neq_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_and_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_zero_f(VOf(Bf9));
    __hv_min_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_varread_f(&sVarf_BFegigXK, VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_floor_f(VIf(Bf15), VOf(Bf5));
    __hv_sub_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_abs_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf12), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf5));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf3), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf12), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf17), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf15));
    __hv_sub_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf15));
    __hv_mul_f(VIf(Bf17), VIf(Bf15), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf12), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf15), VIf(Bf12), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf9), VIf(Bf4), VOf(Bf4));
    __hv_cpole_f(&sCPole_3BO9sWwI, VIf(Bf13), VIf(ZERO), VIf(Bf3), VIf(Bf4), VOf(Bf4), VOf(Bf3));
    __hv_line_f(&sLine_QSOD5GhG, VOf(Bf3));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_neg_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf4), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_nxjN3VtO, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f);
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf12));
    __hv_max_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_iohOJlDo, VOf(Bf9));
    __hv_mul_f(VIf(Bf12), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf12), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf9), VIf(Bf12), VOf(Bf12));
    __hv_varread_f(&sVarf_KnzsWnIN, VOf(Bf15));
    __hv_fms_f(VIf(Bf12), VIf(Bf15), VIf(Bf13), VOf(Bf15));
    __hv_varread_f(&sVarf_0HS1Lj7U, VOf(Bf12));
    __hv_zero_f(VOf(Bf17));
    __hv_neq_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_and_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_zero_f(VOf(Bf15));
    __hv_min_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf13), VIf(Bf15), VOf(Bf13));
    __hv_varread_f(&sVarf_zXeeTKt8, VOf(Bf17));
    __hv_mul_f(VIf(Bf13), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf2), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf9), VOf(Bf13));
    __hv_sub_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf12), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_abs_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf12), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf12), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf12), VOf(Bf13));
    __hv_mul_f(VIf(Bf12), VIf(Bf13), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf19), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf20), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf20), VOf(Bf20));
    __hv_sub_f(VIf(Bf12), VIf(Bf20), VOf(Bf20));
    __hv_fma_f(VIf(Bf13), VIf(Bf19), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf15), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf19), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf19), VOf(Bf9));
    __hv_sub_f(VIf(Bf19), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf19), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf19), VOf(Bf19));
    __hv_abs_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf19), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf19), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf9), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf19), VOf(Bf9));
    __hv_mul_f(VIf(Bf19), VIf(Bf9), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf12), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf19), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf9), VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf15), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_rrB1wAey, VIf(Bf17), VIf(ZERO), VIf(Bf20), VIf(Bf5), VOf(Bf5), VOf(Bf20));
    __hv_line_f(&sLine_Oe6ZDdpL, VOf(Bf20));
    __hv_var_k_f(VOf(Bf17), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf20), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_varwrite_f(&sVarf_XqPpAKN7, VIf(Bf17));
    __hv_var_k_f(VOf(Bf17), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf20), VIf(Bf17), VOf(Bf17));
    __hv_neg_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf20), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf17), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf5), VIf(Bf20), VOf(Bf20));
    __hv_varwrite_f(&sVarf_Rfz7pQXy, VIf(Bf20));
    __hv_var_k_f(VOf(Bf20), 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f);
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf20), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_PG91io1z, VOf(Bf20));
    __hv_mul_f(VIf(Bf17), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf17), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf20), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_bKCRbc8J, VOf(Bf15));
    __hv_fms_f(VIf(Bf17), VIf(Bf15), VIf(Bf5), VOf(Bf15));
    __hv_varread_f(&sVarf_EHX6psI8, VOf(Bf17));
    __hv_zero_f(VOf(Bf12));
    __hv_neq_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_and_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_zero_f(VOf(Bf15));
    __hv_min_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_add_f(VIf(Bf5), VIf(Bf15), VOf(Bf5));
    __hv_varread_f(&sVarf_5QxTXgK3, VOf(Bf12));
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf2), VIf(Bf12), VOf(Bf12));
    __hv_floor_f(VIf(Bf20), VOf(Bf5));
    __hv_sub_f(VIf(Bf20), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf5));
    __hv_mul_f(VIf(Bf17), VIf(Bf5), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf19), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf17), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf5), VIf(Bf19), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf15), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf19), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf20), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf19), VOf(Bf20));
    __hv_sub_f(VIf(Bf19), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf19), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf20), VIf(Bf19), VOf(Bf19));
    __hv_abs_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf20), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf19), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf19), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf20), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf19), VOf(Bf20));
    __hv_mul_f(VIf(Bf19), VIf(Bf20), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf19), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf20), VIf(Bf17), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf15), VIf(Bf9), VOf(Bf9));
    __hv_cpole_f(&sCPole_LeHPsLQ0, VIf(Bf12), VIf(ZERO), VIf(Bf13), VIf(Bf9), VOf(Bf9), VOf(Bf13));
    __hv_line_f(&sLine_GP3GIsdf, VOf(Bf13));
    __hv_var_k_f(VOf(Bf12), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf13), VIf(Bf12), VOf(Bf12));
    __hv_neg_f(VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf9), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_8m3am0l6, VIf(Bf15));
    __hv_var_k_f(VOf(Bf15), 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f);
    __hv_var_k_f(VOf(Bf12), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf17));
    __hv_max_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_UQgpdGzs, VOf(Bf15));
    __hv_mul_f(VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf17), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf15), VIf(Bf17), VOf(Bf17));
    __hv_varread_f(&sVarf_N5FDJeNJ, VOf(Bf20));
    __hv_fms_f(VIf(Bf17), VIf(Bf20), VIf(Bf12), VOf(Bf20));
    __hv_varread_f(&sVarf_JzVog6Qk, VOf(Bf17));
    __hv_zero_f(VOf(Bf19));
    __hv_neq_f(VIf(Bf17), VIf(Bf19), VOf(Bf19));
    __hv_and_f(VIf(Bf20), VIf(Bf19), VOf(Bf19));
    __hv_zero_f(VOf(Bf20));
    __hv_min_f(VIf(Bf19), VIf(Bf20), VOf(Bf20));
    __hv_add_f(VIf(Bf12), VIf(Bf20), VOf(Bf12));
    __hv_varread_f(&sVarf_fkIhYJmU, VOf(Bf19));
    __hv_mul_f(VIf(Bf12), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf2), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf15), VOf(Bf12));
    __hv_sub_f(VIf(Bf15), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf12), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf12), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf12));
    __hv_mul_f(VIf(Bf17), VIf(Bf12), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf12), VOf(Bf12));
    __hv_var_k_f(VOf(Bf21), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf22), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf5), VIf(Bf22), VOf(Bf22));
    __hv_sub_f(VIf(Bf17), VIf(Bf22), VOf(Bf22));
    __hv_fma_f(VIf(Bf12), VIf(Bf21), VIf(Bf22), VOf(Bf22));
    __hv_mul_f(VIf(Bf20), VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf21), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf15), VIf(Bf21), VOf(Bf21));
    __hv_floor_f(VIf(Bf21), VOf(Bf15));
    __hv_sub_f(VIf(Bf21), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf21), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf15), VIf(Bf21), VOf(Bf21));
    __hv_abs_f(VIf(Bf21), VOf(Bf21));
    __hv_var_k_f(VOf(Bf15), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf21), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf21), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf15), VIf(Bf21), VOf(Bf21));
    __hv_mul_f(VIf(Bf21), VIf(Bf21), VOf(Bf15));
    __hv_mul_f(VIf(Bf21), VIf(Bf15), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf5), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf21), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf15), VIf(Bf17), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf20), VIf(Bf5), VOf(Bf5));
    __hv_cpole_f(&sCPole_Mpn9t1jr, VIf(Bf19), VIf(ZERO), VIf(Bf22), VIf(Bf5), VOf(Bf5), VOf(Bf22));
    __hv_line_f(&sLine_fRMuQPsG, VOf(Bf22));
    __hv_var_k_f(VOf(Bf19), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf22), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf5), VIf(Bf19), VOf(Bf19));
    __hv_varwrite_f(&sVarf_BoFfdS9o, VIf(Bf19));
    __hv_var_k_f(VOf(Bf19), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf4), VIf(Bf19), VOf(Bf19));
    __hv_varwrite_f(&sVarf_xVScJl5v, VIf(Bf19));
    __hv_var_k_f(VOf(Bf19), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf11), VIf(Bf19), VOf(Bf19));
    __hv_varwrite_f(&sVarf_vhfgPbOD, VIf(Bf19));
    __hv_var_k_f(VOf(Bf19), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf9), VIf(Bf19), VOf(Bf19));
    __hv_varwrite_f(&sVarf_Qwbjmue8, VIf(Bf19));
    __hv_var_k_f(VOf(Bf19), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf18), VIf(Bf19), VOf(Bf19));
    __hv_neg_f(VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf19), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_varwrite_f(&sVarf_Tp98WJGe, VIf(Bf18));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf1), VIf(Bf18), VOf(Bf18));
    __hv_varwrite_f(&sVarf_Wkb8LeSC, VIf(Bf18));
    __hv_var_k_f(VOf(Bf18), 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f);
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf10));
    __hv_max_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_8Qd6QDL6, VOf(Bf18));
    __hv_mul_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf10), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_varread_f(&sVarf_FAOhbPz3, VOf(Bf16));
    __hv_fms_f(VIf(Bf10), VIf(Bf16), VIf(Bf1), VOf(Bf16));
    __hv_varread_f(&sVarf_uxdg4YAe, VOf(Bf10));
    __hv_zero_f(VOf(Bf19));
    __hv_neq_f(VIf(Bf10), VIf(Bf19), VOf(Bf19));
    __hv_and_f(VIf(Bf16), VIf(Bf19), VOf(Bf19));
    __hv_zero_f(VOf(Bf16));
    __hv_min_f(VIf(Bf19), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf1), VIf(Bf16), VOf(Bf1));
    __hv_varread_f(&sVarf_bH99oJFd, VOf(Bf19));
    __hv_mul_f(VIf(Bf1), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf2), VIf(Bf19), VOf(Bf19));
    __hv_floor_f(VIf(Bf18), VOf(Bf2));
    __hv_sub_f(VIf(Bf18), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf9), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf1), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf2), VIf(Bf9), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_floor_f(VIf(Bf9), VOf(Bf18));
    __hv_sub_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf18), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf9), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf18));
    __hv_mul_f(VIf(Bf9), VIf(Bf18), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf1), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf18), VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_cpole_f(&sCPole_QbJONgJi, VIf(Bf19), VIf(ZERO), VIf(Bf13), VIf(Bf10), VOf(Bf10), VOf(Bf13));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_varwrite_f(&sVarf_B94cCK8d, VIf(Bf13));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf22), VIf(Bf13), VOf(Bf13));
    __hv_neg_f(VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf22), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf13), VIf(Bf22), VOf(Bf22));
    __hv_mul_f(VIf(Bf5), VIf(Bf22), VOf(Bf22));
    __hv_varwrite_f(&sVarf_3jnujRFQ, VIf(Bf22));
    __hv_var_k_f(VOf(Bf22), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf14), VIf(Bf22), VOf(Bf22));
    __hv_neg_f(VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf14), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf22), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_varwrite_f(&sVarf_kQdYjKZK, VIf(Bf14));
    __hv_varread_f(&sVarf_jPMJCglq, VOf(Bf14));
    __hv_varread_f(&sVarf_OhJOUiQb, VOf(Bf7));
    __hv_varread_f(&sVarf_FG8zDpjb, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_d8uY2uc1, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_9lp4WovK, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_zwoxEPBz, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_y8tDw0wC, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_XIw83vrD, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_EwOYPzri, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_P5Uz78Sj, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Rfz7pQXy, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_Tp98WJGe, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_kQdYjKZK, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_1hXDoMZh, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_E0B1zMQm, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_6q99H2m3, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_QjMcnI7C, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_nxjN3VtO, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_8m3am0l6, VOf(Bf22));
    __hv_add_f(VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_varread_f(&sVarf_3jnujRFQ, VOf(Bf7));
    __hv_add_f(VIf(Bf22), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_fNwMPrJo, VOf(Bf14));
    __hv_mul_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_varread_f(&sVarf_FG0OtkWC, VOf(Bf7));
    __hv_varread_f(&sVarf_IHYSOwIQ, VOf(Bf22));
    __hv_mul_f(VIf(I1), VIf(Bf22), VOf(Bf22));
    __hv_fma_f(VIf(Bf14), VIf(Bf7), VIf(Bf22), VOf(Bf22));
    __hv_add_f(VIf(Bf22), VIf(O1), VOf(O1));
    __hv_add_f(VIf(I0), VIf(I1), VOf(Bf22));
    __hv_var_k_f(VOf(Bf7), 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f, 3000.0f);
    __hv_var_k_f(VOf(Bf14), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_eQnjGg0F, VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Rxxhyvoq, VOf(Bf13));
    __hv_fms_f(VIf(Bf5), VIf(Bf13), VIf(Bf14), VOf(Bf13));
    __hv_varread_f(&sVarf_TGBMGt3U, VOf(Bf5));
    __hv_zero_f(VOf(Bf6));
    __hv_neq_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf13));
    __hv_min_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf14), VIf(Bf13), VOf(Bf14));
    __hv_varread_f(&sVarf_bUjDxYUw, VOf(Bf6));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf22), VIf(Bf6), VOf(Bf6));
    __hv_floor_f(VIf(Bf7), VOf(Bf14));
    __hv_sub_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf14), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf14), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf14));
    __hv_mul_f(VIf(Bf5), VIf(Bf14), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf10), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf19), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf19), VOf(Bf19));
    __hv_sub_f(VIf(Bf5), VIf(Bf19), VOf(Bf19));
    __hv_fma_f(VIf(Bf14), VIf(Bf10), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf13), VIf(Bf19), VOf(Bf19));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf10), VOf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_abs_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf10), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf8), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf10), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf7), VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf13), VIf(Bf8), VOf(Bf8));
    __hv_cpole_f(&sCPole_x49zFMO7, VIf(Bf6), VIf(ZERO), VIf(Bf19), VIf(Bf8), VOf(Bf8), VOf(Bf19));
    __hv_line_f(&sLine_zPYJjORe, VOf(Bf19));
    __hv_var_k_f(VOf(Bf6), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf19), VIf(Bf6), VOf(Bf6));
    __hv_neg_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf13), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf8), VIf(Bf13), VOf(Bf13));
    __hv_varwrite_f(&sVarf_FG8zDpjb, VIf(Bf13));
    __hv_var_k_f(VOf(Bf13), 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f, 375.0f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_gCopKF1Y, VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_h8riM1ZY, VOf(Bf7));
    __hv_fms_f(VIf(Bf5), VIf(Bf7), VIf(Bf6), VOf(Bf7));
    __hv_varread_f(&sVarf_SKlmK0Vs, VOf(Bf5));
    __hv_zero_f(VOf(Bf10));
    __hv_neq_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_zero_f(VOf(Bf7));
    __hv_min_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf6), VIf(Bf7), VOf(Bf6));
    __hv_varread_f(&sVarf_RuTblLji, VOf(Bf10));
    __hv_mul_f(VIf(Bf6), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf22), VIf(Bf10), VOf(Bf10));
    __hv_floor_f(VIf(Bf13), VOf(Bf6));
    __hv_sub_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf16), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf1), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf16), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf16), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_floor_f(VIf(Bf16), VOf(Bf13));
    __hv_sub_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_abs_f(VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf16), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf16), VOf(Bf13));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf14), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf14), VOf(Bf14));
    __hv_sub_f(VIf(Bf16), VIf(Bf14), VOf(Bf14));
    __hv_fma_f(VIf(Bf13), VIf(Bf5), VIf(Bf14), VOf(Bf14));
    __hv_mul_f(VIf(Bf7), VIf(Bf14), VOf(Bf14));
    __hv_cpole_f(&sCPole_Y2lE34WJ, VIf(Bf10), VIf(ZERO), VIf(Bf1), VIf(Bf14), VOf(Bf14), VOf(Bf1));
    __hv_line_f(&sLine_Qlcis11d, VOf(Bf1));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf14), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_tvwcMdxz, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f, 6000.0f);
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_nhGCqI07, VOf(Bf10));
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_SJ7ylz8n, VOf(Bf13));
    __hv_fms_f(VIf(Bf5), VIf(Bf13), VIf(Bf7), VOf(Bf13));
    __hv_varread_f(&sVarf_1h7qsGhr, VOf(Bf5));
    __hv_zero_f(VOf(Bf16));
    __hv_neq_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_and_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_zero_f(VOf(Bf13));
    __hv_min_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_add_f(VIf(Bf7), VIf(Bf13), VOf(Bf7));
    __hv_varread_f(&sVarf_IJ4YXdZM, VOf(Bf16));
    __hv_mul_f(VIf(Bf7), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf22), VIf(Bf16), VOf(Bf16));
    __hv_floor_f(VIf(Bf10), VOf(Bf7));
    __hv_sub_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf18), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf9), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_sub_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf18), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf13), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf18), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_floor_f(VIf(Bf18), VOf(Bf10));
    __hv_sub_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf18), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_abs_f(VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf18), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf18), VOf(Bf10));
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf6), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf18), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf10), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf13), VIf(Bf6), VOf(Bf6));
    __hv_cpole_f(&sCPole_hA7SuSCW, VIf(Bf16), VIf(ZERO), VIf(Bf9), VIf(Bf6), VOf(Bf6), VOf(Bf9));
    __hv_line_f(&sLine_nv2OGtLu, VOf(Bf9));
    __hv_var_k_f(VOf(Bf16), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf6), VIf(Bf16), VOf(Bf16));
    __hv_varwrite_f(&sVarf_PBWmHT8n, VIf(Bf16));
    __hv_var_k_f(VOf(Bf16), 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f, 24.0f);
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_8GmFdEWj, VOf(Bf16));
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf5), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_FdD5BchY, VOf(Bf10));
    __hv_fms_f(VIf(Bf5), VIf(Bf10), VIf(Bf13), VOf(Bf10));
    __hv_varread_f(&sVarf_aOAC5JtC, VOf(Bf5));
    __hv_zero_f(VOf(Bf18));
    __hv_neq_f(VIf(Bf5), VIf(Bf18), VOf(Bf18));
    __hv_and_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_zero_f(VOf(Bf10));
    __hv_min_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf13), VIf(Bf10), VOf(Bf13));
    __hv_varread_f(&sVarf_HJVBC1IV, VOf(Bf18));
    __hv_mul_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf22), VIf(Bf18), VOf(Bf18));
    __hv_floor_f(VIf(Bf16), VOf(Bf13));
    __hv_sub_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf13));
    __hv_mul_f(VIf(Bf5), VIf(Bf13), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf11), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf5), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf13), VIf(Bf2), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf2), VOf(Bf16));
    __hv_sub_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf16), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf16));
    __hv_mul_f(VIf(Bf2), VIf(Bf16), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf7), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf16), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf10), VIf(Bf7), VOf(Bf7));
    __hv_cpole_f(&sCPole_4DlrxkET, VIf(Bf18), VIf(ZERO), VIf(Bf11), VIf(Bf7), VOf(Bf7), VOf(Bf11));
    __hv_line_f(&sLine_L4sHvsTr, VOf(Bf11));
    __hv_var_k_f(VOf(Bf18), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf7), VIf(Bf18), VOf(Bf18));
    __hv_varwrite_f(&sVarf_z1QrhhkP, VIf(Bf18));
    __hv_var_k_f(VOf(Bf18), 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f);
    __hv_var_k_f(VOf(Bf10), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf5));
    __hv_max_f(VIf(Bf18), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_HiTPpfeb, VOf(Bf18));
    __hv_mul_f(VIf(Bf5), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf5), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf18), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_52xmv25q, VOf(Bf16));
    __hv_fms_f(VIf(Bf5), VIf(Bf16), VIf(Bf10), VOf(Bf16));
    __hv_varread_f(&sVarf_YtHKZMPl, VOf(Bf5));
    __hv_zero_f(VOf(Bf2));
    __hv_neq_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf16));
    __hv_min_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf10), VIf(Bf16), VOf(Bf10));
    __hv_varread_f(&sVarf_xHResXUs, VOf(Bf2));
    __hv_mul_f(VIf(Bf10), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf22), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf18), VOf(Bf10));
    __hv_sub_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf10));
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf0), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf10), VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf16), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf18), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf18));
    __hv_sub_f(VIf(Bf0), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf18), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf18), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf18), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf18));
    __hv_mul_f(VIf(Bf0), VIf(Bf18), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf18), VOf(Bf18));
    __hv_var_k_f(VOf(Bf5), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf10), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf0), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf18), VIf(Bf5), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_cpole_f(&sCPole_gV5kXx0c, VIf(Bf2), VIf(ZERO), VIf(Bf4), VIf(Bf13), VOf(Bf13), VOf(Bf4));
    __hv_var_k_f(VOf(Bf4), 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f, 750.0f);
    __hv_var_k_f(VOf(Bf13), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_arOGUN5D, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_98eg6lHU, VOf(Bf16));
    __hv_fms_f(VIf(Bf2), VIf(Bf16), VIf(Bf13), VOf(Bf16));
    __hv_varread_f(&sVarf_6tUYgxh1, VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_neq_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_and_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_zero_f(VOf(Bf16));
    __hv_min_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_add_f(VIf(Bf13), VIf(Bf16), VOf(Bf13));
    __hv_varread_f(&sVarf_fXeJdq5K, VOf(Bf5));
    __hv_mul_f(VIf(Bf13), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf22), VIf(Bf5), VOf(Bf5));
    __hv_floor_f(VIf(Bf4), VOf(Bf13));
    __hv_sub_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf13), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf13), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf13));
    __hv_mul_f(VIf(Bf2), VIf(Bf13), VOf(Bf18));
    __hv_mul_f(VIf(Bf18), VIf(Bf13), VOf(Bf13));
    __hv_var_k_f(VOf(Bf0), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf10), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_sub_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_fma_f(VIf(Bf13), VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf16), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf18), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf18), VOf(Bf18));
    __hv_sub_f(VIf(Bf0), VIf(Bf18), VOf(Bf18));
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf18), VOf(Bf18));
    __hv_mul_f(VIf(Bf16), VIf(Bf18), VOf(Bf18));
    __hv_cpole_f(&sCPole_9f1bw8p5, VIf(Bf5), VIf(ZERO), VIf(Bf10), VIf(Bf18), VOf(Bf18), VOf(Bf10));
    __hv_line_f(&sLine_VNZPhbQZ, VOf(Bf10));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf18), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_OYxVlYHo, VIf(Bf5));
    __hv_var_k_f(VOf(Bf5), 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f, 190.0f);
    __hv_var_k_f(VOf(Bf16), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_p4Vt4F68, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_yt8tYLRE, VOf(Bf4));
    __hv_fms_f(VIf(Bf2), VIf(Bf4), VIf(Bf16), VOf(Bf4));
    __hv_varread_f(&sVarf_j4ZM6Vy2, VOf(Bf2));
    __hv_zero_f(VOf(Bf0));
    __hv_neq_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_and_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf4));
    __hv_min_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf16), VIf(Bf4), VOf(Bf16));
    __hv_varread_f(&sVarf_IaVcx8yQ, VOf(Bf0));
    __hv_mul_f(VIf(Bf16), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf22), VIf(Bf0), VOf(Bf0));
    __hv_floor_f(VIf(Bf5), VOf(Bf16));
    __hv_sub_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf16), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf16), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf16));
    __hv_mul_f(VIf(Bf2), VIf(Bf16), VOf(Bf13));
    __hv_mul_f(VIf(Bf13), VIf(Bf16), VOf(Bf16));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf20), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_sub_f(VIf(Bf2), VIf(Bf20), VOf(Bf20));
    __hv_fma_f(VIf(Bf16), VIf(Bf3), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf4), VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf13), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf16), VIf(Bf13), VOf(Bf13));
    __hv_sub_f(VIf(Bf3), VIf(Bf13), VOf(Bf13));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf13), VOf(Bf13));
    __hv_mul_f(VIf(Bf4), VIf(Bf13), VOf(Bf13));
    __hv_cpole_f(&sCPole_Bw2rZEGP, VIf(Bf0), VIf(ZERO), VIf(Bf20), VIf(Bf13), VOf(Bf13), VOf(Bf20));
    __hv_line_f(&sLine_1zKICT9M, VOf(Bf20));
    __hv_var_k_f(VOf(Bf0), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf20), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf13), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_AgKSUT2Z, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f, 96.0f);
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf2));
    __hv_max_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_XvRn3Xjo, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_OJRnTqNL, VOf(Bf5));
    __hv_fms_f(VIf(Bf2), VIf(Bf5), VIf(Bf4), VOf(Bf5));
    __hv_varread_f(&sVarf_VVK2qXgT, VOf(Bf2));
    __hv_zero_f(VOf(Bf3));
    __hv_neq_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf5));
    __hv_min_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf4));
    __hv_varread_f(&sVarf_16yliP8r, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf22), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf0), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf16));
    __hv_mul_f(VIf(Bf16), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf15), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_sub_f(VIf(Bf2), VIf(Bf15), VOf(Bf15));
    __hv_fma_f(VIf(Bf4), VIf(Bf17), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf5), VIf(Bf15), VOf(Bf15));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf0));
    __hv_sub_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf0));
    __hv_mul_f(VIf(Bf17), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf16), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf4), VIf(Bf16), VOf(Bf16));
    __hv_sub_f(VIf(Bf17), VIf(Bf16), VOf(Bf16));
    __hv_fma_f(VIf(Bf0), VIf(Bf2), VIf(Bf16), VOf(Bf16));
    __hv_mul_f(VIf(Bf5), VIf(Bf16), VOf(Bf16));
    __hv_cpole_f(&sCPole_Jy8GhGiT, VIf(Bf3), VIf(ZERO), VIf(Bf15), VIf(Bf16), VOf(Bf16), VOf(Bf15));
    __hv_line_f(&sLine_92pzSl5j, VOf(Bf15));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf15), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf16), VIf(Bf3), VOf(Bf3));
    __hv_varwrite_f(&sVarf_5yFNHZ2G, VIf(Bf3));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_zwoxEPBz, VIf(Bf1));
    __hv_var_k_f(VOf(Bf1), 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f, 48.0f);
    __hv_var_k_f(VOf(Bf14), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf3));
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_fQaFKSrX, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_eG6D86Ca, VOf(Bf5));
    __hv_fms_f(VIf(Bf3), VIf(Bf5), VIf(Bf14), VOf(Bf5));
    __hv_varread_f(&sVarf_dFPy4f4q, VOf(Bf3));
    __hv_zero_f(VOf(Bf2));
    __hv_neq_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_and_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_zero_f(VOf(Bf5));
    __hv_min_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf14), VIf(Bf5), VOf(Bf14));
    __hv_varread_f(&sVarf_N8eWmFKE, VOf(Bf2));
    __hv_mul_f(VIf(Bf14), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf22), VIf(Bf2), VOf(Bf2));
    __hv_floor_f(VIf(Bf1), VOf(Bf14));
    __hv_sub_f(VIf(Bf1), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf14), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf14), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf14));
    __hv_mul_f(VIf(Bf3), VIf(Bf14), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf14), VOf(Bf14));
    __hv_var_k_f(VOf(Bf17), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf4), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf14), VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf17), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_floor_f(VIf(Bf17), VOf(Bf1));
    __hv_sub_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf17), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_abs_f(VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf17), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf17), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf17), VIf(Bf17), VOf(Bf1));
    __hv_mul_f(VIf(Bf17), VIf(Bf1), VOf(Bf14));
    __hv_mul_f(VIf(Bf14), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf0), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf14), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf17), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_cpole_f(&sCPole_oKT8lest, VIf(Bf2), VIf(ZERO), VIf(Bf4), VIf(Bf0), VOf(Bf0), VOf(Bf4));
    __hv_line_f(&sLine_vylmWqAR, VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_neg_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_varwrite_f(&sVarf_jPMJCglq, VIf(Bf5));
    __hv_varread_f(&sVarf_pR8udgTw, VOf(Bf5));
    __hv_rpole_f(&sRPole_UAOhPuwb, VIf(Bf22), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_5mjas09m, VIf(Bf5), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_gmsTS1QU, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_V5maCN7A, VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_neg_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_EwOYPzri, VIf(Bf1));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_zzT2Vmhh, VIf(Bf1));
    __hv_var_k_f(VOf(Bf1), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf19), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_hvT1m8Kb, VIf(Bf1));
    __hv_var_k_f(VOf(Bf1), 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f, 1500.0f);
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_zero_f(VOf(Bf19));
    __hv_max_f(VIf(Bf1), VIf(Bf19), VOf(Bf19));
    __hv_varread_f(&sVarf_uaUc7NQa, VOf(Bf1));
    __hv_mul_f(VIf(Bf19), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf19), 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f, 6.28318f);
    __hv_mul_f(VIf(Bf1), VIf(Bf19), VOf(Bf19));
    __hv_varread_f(&sVarf_musW1hFJ, VOf(Bf0));
    __hv_fms_f(VIf(Bf19), VIf(Bf0), VIf(Bf8), VOf(Bf0));
    __hv_varread_f(&sVarf_BPf4aIBq, VOf(Bf19));
    __hv_zero_f(VOf(Bf4));
    __hv_neq_f(VIf(Bf19), VIf(Bf4), VOf(Bf4));
    __hv_and_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_zero_f(VOf(Bf0));
    __hv_min_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_varread_f(&sVarf_ggzc3Kfp, VOf(Bf4));
    __hv_mul_f(VIf(Bf8), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf22), VIf(Bf4), VOf(Bf4));
    __hv_floor_f(VIf(Bf1), VOf(Bf22));
    __hv_sub_f(VIf(Bf1), VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf8), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf22), VIf(Bf8), VOf(Bf8));
    __hv_abs_f(VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf22), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf8), VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf8), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf22), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf8), VOf(Bf22));
    __hv_mul_f(VIf(Bf8), VIf(Bf22), VOf(Bf19));
    __hv_mul_f(VIf(Bf19), VIf(Bf22), VOf(Bf22));
    __hv_var_k_f(VOf(Bf3), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf17), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf19), VIf(Bf17), VOf(Bf17));
    __hv_sub_f(VIf(Bf8), VIf(Bf17), VOf(Bf17));
    __hv_fma_f(VIf(Bf22), VIf(Bf3), VIf(Bf17), VOf(Bf17));
    __hv_mul_f(VIf(Bf0), VIf(Bf17), VOf(Bf17));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_floor_f(VIf(Bf3), VOf(Bf1));
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf22));
    __hv_mul_f(VIf(Bf22), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf8), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf19), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf22), VIf(Bf19), VOf(Bf19));
    __hv_sub_f(VIf(Bf3), VIf(Bf19), VOf(Bf19));
    __hv_fma_f(VIf(Bf1), VIf(Bf8), VIf(Bf19), VOf(Bf19));
    __hv_mul_f(VIf(Bf0), VIf(Bf19), VOf(Bf19));
    __hv_cpole_f(&sCPole_3FYZV1Ki, VIf(Bf4), VIf(ZERO), VIf(Bf17), VIf(Bf19), VOf(Bf19), VOf(Bf17));
    __hv_line_f(&sLine_NOmkPjal, VOf(Bf17));
    __hv_var_k_f(VOf(Bf4), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf17), VIf(Bf4), VOf(Bf4));
    __hv_neg_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf19), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_d8uY2uc1, VIf(Bf0));
    __hv_var_k_f(VOf(Bf0), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf9), VIf(Bf0), VOf(Bf0));
    __hv_neg_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf0), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf6), VIf(Bf9), VOf(Bf9));
    __hv_varwrite_f(&sVarf_XIw83vrD, VIf(Bf9));
    __hv_var_k_f(VOf(Bf9), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_neg_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf9), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf18), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_y8tDw0wC, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf17), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf19), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_5UyNY4sS, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf2), VIf(Bf10), VOf(Bf10));
    __hv_mul_f(VIf(Bf5), VIf(Bf10), VOf(Bf10));
    __hv_varwrite_f(&sVarf_KvNFMO24, VIf(Bf10));
    __hv_var_k_f(VOf(Bf10), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf11), VIf(Bf10), VOf(Bf10));
    __hv_neg_f(VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf10), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_varwrite_f(&sVarf_P5Uz78Sj, VIf(Bf11));
    __hv_var_k_f(VOf(Bf11), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf20), VIf(Bf11), VOf(Bf11));
    __hv_neg_f(VIf(Bf11), VOf(Bf11));
    __hv_var_k_f(VOf(Bf20), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf11), VIf(Bf20), VOf(Bf20));
    __hv_mul_f(VIf(Bf13), VIf(Bf20), VOf(Bf20));
    __hv_varwrite_f(&sVarf_9lp4WovK, VIf(Bf20));
    __hv_var_k_f(VOf(Bf20), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_sub_f(VIf(Bf15), VIf(Bf20), VOf(Bf20));
    __hv_neg_f(VIf(Bf20), VOf(Bf20));
    __hv_var_k_f(VOf(Bf15), 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f, 100.0f);
    __hv_div_f(VIf(Bf20), VIf(Bf15), VOf(Bf15));
    __hv_mul_f(VIf(Bf16), VIf(Bf15), VOf(Bf15));
    __hv_varwrite_f(&sVarf_OhJOUiQb, VIf(Bf15));

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
