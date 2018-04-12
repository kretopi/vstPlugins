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

#include "Heavy_FourPointDelay.hpp"

#define Context(_c) reinterpret_cast<Heavy_FourPointDelay *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_FourPointDelay_new(double sampleRate) {
    return new Heavy_FourPointDelay(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_FourPointDelay_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_FourPointDelay(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_FourPointDelay::Heavy_FourPointDelay(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sTabread_init(&sTabread_a2LgDYTc, &hTable_dN3dpzUH, true);
  numBytes += sRPole_init(&sRPole_UBsurWGr);
  numBytes += sRPole_init(&sRPole_VKUfYP6m);
  numBytes += sRPole_init(&sRPole_4k9fbaH7);
  numBytes += sDel1_init(&sDel1_Kw3Fsl4N);
  numBytes += sRPole_init(&sRPole_ZD0u1Wu9);
  numBytes += sDel1_init(&sDel1_3KwxjCYG);
  numBytes += sTabwrite_init(&sTabwrite_TsdC26oq, &hTable_dN3dpzUH);
  numBytes += sTabread_init(&sTabread_AuTAmAp8, &hTable_oiABVAPE, true);
  numBytes += sRPole_init(&sRPole_T50XDFGh);
  numBytes += sRPole_init(&sRPole_zoJUTz7W);
  numBytes += sRPole_init(&sRPole_dp7fsKAx);
  numBytes += sDel1_init(&sDel1_nejanQ8j);
  numBytes += sRPole_init(&sRPole_T2D06U0K);
  numBytes += sDel1_init(&sDel1_ej899vUK);
  numBytes += sTabwrite_init(&sTabwrite_oUoR0KbL, &hTable_oiABVAPE);
  numBytes += sTabread_init(&sTabread_CjeLMNLG, &hTable_GjFTquZx, true);
  numBytes += sTabread_init(&sTabread_gnRw7hUq, &hTable_TLD5TOQ5, true);
  numBytes += sRPole_init(&sRPole_T5Pu5PHa);
  numBytes += sRPole_init(&sRPole_Slfhv0J1);
  numBytes += sRPole_init(&sRPole_BbCThNPe);
  numBytes += sDel1_init(&sDel1_MFzNAKvR);
  numBytes += sRPole_init(&sRPole_u21iyTgF);
  numBytes += sDel1_init(&sDel1_QP3HLtIi);
  numBytes += sTabwrite_init(&sTabwrite_zmIkBDFH, &hTable_GjFTquZx);
  numBytes += sRPole_init(&sRPole_sLXthXKC);
  numBytes += sRPole_init(&sRPole_ltPKGIxb);
  numBytes += sRPole_init(&sRPole_1bClSnrK);
  numBytes += sDel1_init(&sDel1_0HZ6dsPv);
  numBytes += sRPole_init(&sRPole_NyLGVpL3);
  numBytes += sDel1_init(&sDel1_w3Y2IXNw);
  numBytes += sTabwrite_init(&sTabwrite_VRY7zSue, &hTable_TLD5TOQ5);
  numBytes += sTabread_init(&sTabread_3JW8lI6g, &hTable_6w65nCNQ, true);
  numBytes += sTabread_init(&sTabread_TzwpoU0A, &hTable_mF8kKd6s, true);
  numBytes += sTabread_init(&sTabread_zKRg1vzk, &hTable_MAtR0uMN, true);
  numBytes += sTabread_init(&sTabread_3juhxaOr, &hTable_WzANuIJk, true);
  numBytes += sRPole_init(&sRPole_quzzZuNF);
  numBytes += sRPole_init(&sRPole_j2XQRrnM);
  numBytes += sRPole_init(&sRPole_9d3vY41T);
  numBytes += sDel1_init(&sDel1_9ASft9rr);
  numBytes += sRPole_init(&sRPole_ui1BRscN);
  numBytes += sDel1_init(&sDel1_VsOanfky);
  numBytes += sTabwrite_init(&sTabwrite_1hwD5EJe, &hTable_mF8kKd6s);
  numBytes += sRPole_init(&sRPole_KGMAfATO);
  numBytes += sRPole_init(&sRPole_eBjMDA3e);
  numBytes += sRPole_init(&sRPole_GsMsm4g7);
  numBytes += sDel1_init(&sDel1_kahCY8mO);
  numBytes += sRPole_init(&sRPole_UO5nT8sf);
  numBytes += sDel1_init(&sDel1_ZJqlNPTX);
  numBytes += sTabwrite_init(&sTabwrite_5bBPMslL, &hTable_MAtR0uMN);
  numBytes += sRPole_init(&sRPole_emoHZ5c7);
  numBytes += sRPole_init(&sRPole_q8R9kvfz);
  numBytes += sRPole_init(&sRPole_RZVqGk4Q);
  numBytes += sDel1_init(&sDel1_ADQAL5SB);
  numBytes += sRPole_init(&sRPole_CFqcxNY2);
  numBytes += sDel1_init(&sDel1_G0klFKf8);
  numBytes += sTabwrite_init(&sTabwrite_UnfirIcJ, &hTable_WzANuIJk);
  numBytes += sRPole_init(&sRPole_H5edj5Iu);
  numBytes += sRPole_init(&sRPole_6SAoLY13);
  numBytes += sRPole_init(&sRPole_c0n9gWoA);
  numBytes += sDel1_init(&sDel1_slEy5wtu);
  numBytes += sRPole_init(&sRPole_yXZCbYqb);
  numBytes += sDel1_init(&sDel1_idyo6xFa);
  numBytes += sTabwrite_init(&sTabwrite_z79K5GKw, &hTable_6w65nCNQ);
  numBytes += sVarf_init(&sVarf_fofyc2LC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ZN1n8ftU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_5wc0mCHZ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_hhXr5GBB, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YH8xXBAK, 22050.0f);
  numBytes += sVarf_init(&sVarf_gYm5muES, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_24KBTlEa, "del-2pointR");
  numBytes += cBinop_init(&cBinop_pwgEE2f7, 5000.0f); // __mul
  numBytes += cBinop_init(&cBinop_AtNNKeLb, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_QYtQyXyt, &hTable_GjFTquZx);
  numBytes += cBinop_init(&cBinop_NPocc83r, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_tJm4Azci, 0.0f);
  numBytes += cDelay_init(this, &cDelay_iHRA8r0r, 5000.0f);
  numBytes += cBinop_init(&cBinop_lDKt95kh, 0.0f); // __max
  numBytes += cDelay_init(this, &cDelay_VORrNGgb, 0.0f);
  numBytes += hTable_init(&hTable_dN3dpzUH, 256);
  numBytes += cDelay_init(this, &cDelay_mwlDREvg, 0.0f);
  numBytes += sVarf_init(&sVarf_NjWamTgd, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_8gMVh1Mk, 0.0f);
  numBytes += hTable_init(&hTable_oiABVAPE, 256);
  numBytes += cDelay_init(this, &cDelay_ThDV7U55, 0.0f);
  numBytes += cBinop_init(&cBinop_nOC42LaZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QoTlyods, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_RJoPmadP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_c7Gle2Dy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ySDtUde9, 0.0f);
  numBytes += cBinop_init(&cBinop_WhsnttHr, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_Zuw2HqLA, 5000.0f); // __mul
  numBytes += cTabhead_init(&cTabhead_qX0yovRY, &hTable_dN3dpzUH);
  numBytes += cDelay_init(this, &cDelay_mjnh65EO, 0.0f);
  numBytes += cVar_init_s(&cVar_O1QyEYjN, "del-4pointR");
  numBytes += cDelay_init(this, &cDelay_cxK5Ihv6, 5000.0f);
  numBytes += cBinop_init(&cBinop_kRRiaV9H, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UGgPbFGB, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_UmRCorBf, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_YU7yLrXC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_BQVFIQgx, 22050.0f);
  numBytes += sVarf_init(&sVarf_5bxZRUjQ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_5GRHfUdu, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_opE0dtuL, &hTable_TLD5TOQ5);
  numBytes += cVar_init_s(&cVar_QpvQnXjU, "del-3pointR");
  numBytes += cBinop_init(&cBinop_9sXf36Ou, 0.0f); // __max
  numBytes += cDelay_init(this, &cDelay_73TFrCT0, 0.0f);
  numBytes += cBinop_init(&cBinop_Shw3cB8X, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4IunfYEY, 5000.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_aOca7fKM, 5000.0f);
  numBytes += cDelay_init(this, &cDelay_dyT7X4VP, 0.0f);
  numBytes += cBinop_init(&cBinop_4aYQd68l, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_fkgXijhN, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_WX3kSbYn, 5000.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_7DQrofQ0, 5000.0f);
  numBytes += cBinop_init(&cBinop_m739B3K7, 0.0f); // __max
  numBytes += cTabhead_init(&cTabhead_L833PIYM, &hTable_oiABVAPE);
  numBytes += cVar_init_s(&cVar_W1l3IdNt, "del-1pointR");
  numBytes += cVar_init_f(&cVar_LNBSlOKc, 22050.0f);
  numBytes += sVarf_init(&sVarf_hbPtLKFX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_VrcowatB, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_5bGcG39A, 0.0f, 0.0f, false);
  numBytes += hTable_init(&hTable_GjFTquZx, 256);
  numBytes += cDelay_init(this, &cDelay_kymT769C, 0.0f);
  numBytes += cDelay_init(this, &cDelay_RHI3jBvz, 0.0f);
  numBytes += cVar_init_f(&cVar_YlGbMeLo, 0.0f);
  numBytes += sVarf_init(&sVarf_VUGnP38E, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FdQuW9Po, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_HlQ4oakN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_S7UP71Lw, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_pKq1Hsw6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_n097wKv9, 22050.0f);
  numBytes += sVarf_init(&sVarf_cXVvrOHR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nadW8d7Y, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_2dLyrJj2, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_s2ZhNE5o, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_6jc2fmaI, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_uigZTkGO, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_VF0439iW, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5NbEMODr, 0.0f);
  numBytes += sVarf_init(&sVarf_OQPTZQHY, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bdc53X4y, 22050.0f);
  numBytes += cBinop_init(&cBinop_gWWfIfPV, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_fqQuRH6f, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eoo1hzVy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_gYYUUzip, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mGaudv4N, 22050.0f);
  numBytes += cBinop_init(&cBinop_96zH4ITk, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_vrRSo3OE, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Do5DnuB8, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_1Abz8Jfk, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MaBUDMon, 0.0f);
  numBytes += sVarf_init(&sVarf_CqbCLuGo, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_nfJmxzGz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_PZj9pliq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ytsxAqX8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JZEQ04M8, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_X7UHm64o, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_FRe54Gnj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ulKdRyYG, 0.0f);
  numBytes += sVarf_init(&sVarf_VwYkcQ4r, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6QYRuIyf, 0.0f);
  numBytes += sVarf_init(&sVarf_SyXgHt5p, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_y5v3cnxz, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Pog5mjIh, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Y6vFUXlD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CmQr4cUf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SYj90OhX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_DpRhVzgb, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_4MVWZWoQ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_pEDDYb1R, 0.0f);
  numBytes += sVarf_init(&sVarf_fEQUvPH9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zhg6RBt6, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_7DPi7d86, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_TboFzg5Z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Xzjw74kC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_yeQ1voel, 22050.0f);
  numBytes += sVarf_init(&sVarf_yqxuikFY, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_5ZfE8uQG, 0.0f);
  numBytes += hTable_init(&hTable_TLD5TOQ5, 256);
  numBytes += cDelay_init(this, &cDelay_vyNPPRND, 0.0f);
  numBytes += sVarf_init(&sVarf_RAKpPlIH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_8ahjfSsC, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_1xFEHBax, 0.0f);
  numBytes += sVarf_init(&sVarf_xmmgLQoL, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_NSJTL9zT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Aee1ppuB, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_vWXoAVPZ, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_MlJYf3SE, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_T4kPX42T, 22050.0f);
  numBytes += sVarf_init(&sVarf_UjzeVdJo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_eQwBpGWo, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_MhMYiLdH, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_L8IeMbtY, 22050.0f);
  numBytes += sVarf_init(&sVarf_SQuPZAME, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q1FuC71z, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_4BHFk7BO, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0YZxaRxf, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ep4U7JVy, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_q8RbFUhW, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Xod0FLvd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_xZoLYLfZ, 0.0f);
  numBytes += cVar_init_f(&cVar_kRtmec7K, 22050.0f);
  numBytes += sVarf_init(&sVarf_h0Mu0Otk, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WJyTO7UI, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_CbS9coFt, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FAuHB0kb, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_XiEaZFmT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PUsPBQAT, 5000.0f);
  numBytes += cTabhead_init(&cTabhead_mvpJuAaN, &hTable_mF8kKd6s);
  numBytes += cVar_init_s(&cVar_DmPVtxII, "del-4pointL");
  numBytes += cBinop_init(&cBinop_ujGOOR1I, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_htrxMPUA, 5000.0f); // __mul
  numBytes += cBinop_init(&cBinop_vxINkrN3, 0.0f); // __max
  numBytes += sVarf_init(&sVarf_k4TXKi72, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_41zt0KxG, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_hmvZWCHT, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_yF2shCCN, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_pS28cUWI, 22050.0f);
  numBytes += sVarf_init(&sVarf_3civjISe, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q8OY2Pwy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_eDKUTEqv, 0.0f);
  numBytes += sVarf_init(&sVarf_HsxVLfWX, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_4cwtMhAT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hTjPYtgl, 0.0f); // __div
  numBytes += cDelay_init(this, &cDelay_WP5iKiTX, 0.0f);
  numBytes += cDelay_init(this, &cDelay_wYtsomyi, 0.0f);
  numBytes += hTable_init(&hTable_mF8kKd6s, 256);
  numBytes += cBinop_init(&cBinop_kiL0Onfe, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_wntEjsdW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_tWfaBUVP, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_R0zeIQWC, 22050.0f);
  numBytes += cDelay_init(this, &cDelay_J61rSkgV, 0.0f);
  numBytes += cBinop_init(&cBinop_yILQPhht, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_oGh8oTqu, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sYLa6tJR, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_SrDixsh7, 5000.0f);
  numBytes += cTabhead_init(&cTabhead_lQsAq9zw, &hTable_MAtR0uMN);
  numBytes += cVar_init_s(&cVar_k6spZMyh, "del-3pointL");
  numBytes += cBinop_init(&cBinop_OGwJ0aFU, 5000.0f); // __mul
  numBytes += sVarf_init(&sVarf_j7NLiNJK, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iiGV3lku, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_O9rQUjPA, 0.0f);
  numBytes += sVarf_init(&sVarf_BAQYFNHd, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_uMJNoFME, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HgohTVdt, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_wBQfIboz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ADbFej9x, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iFOLStnK, 0.0f);
  numBytes += cBinop_init(&cBinop_wSfxQBMm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1JChjE64, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_qGAvfWAn, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_QfgtRGmo, "del-2pointL");
  numBytes += cBinop_init(&cBinop_hMcDcid5, 0.0f); // __sub
  numBytes += cTabhead_init(&cTabhead_8Y8TFryn, &hTable_WzANuIJk);
  numBytes += cBinop_init(&cBinop_Bg801iiP, 0.0f); // __max
  numBytes += cBinop_init(&cBinop_iGUZL5Sv, 5000.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_XIYWlf2D, 5000.0f);
  numBytes += cBinop_init(&cBinop_c0rNLeiO, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_wCgSttXM, 0.0f);
  numBytes += cVar_init_f(&cVar_x820zk5s, 0.0f);
  numBytes += sVarf_init(&sVarf_wuIzaLUT, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_3mGtNMNd, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_o5J9Krbb, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_muSgF83r, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iOzj3DQ7, 0.0f);
  numBytes += sVarf_init(&sVarf_Ied3wZPo, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_3zCdI0dE, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_l73Go3d5, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_4cvooVTj, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_RNgkevKj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_z2KcLVJB, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_cYGFBKJl, 22050.0f);
  numBytes += cBinop_init(&cBinop_SCjdaW0C, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4T9VgUBr, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_bbXb0eCS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PMS1iv9E, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KWXnR5GT, 22050.0f);
  numBytes += sVarf_init(&sVarf_PW3AD4rj, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_AC5vakgn, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_oljs6H1c, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Xg6tMOXL, 22050.0f);
  numBytes += sVarf_init(&sVarf_lBao26Hz, 0.0f, 0.0f, false);
  numBytes += hTable_init(&hTable_MAtR0uMN, 256);
  numBytes += cDelay_init(this, &cDelay_pn87nQdq, 0.0f);
  numBytes += cDelay_init(this, &cDelay_LnDG4lTD, 0.0f);
  numBytes += cVar_init_s(&cVar_AusJ3DLY, "del-1pointL");
  numBytes += cTabhead_init(&cTabhead_VlSl8OZR, &hTable_6w65nCNQ);
  numBytes += cBinop_init(&cBinop_LmjH6dMY, 0.0f); // __sub
  numBytes += cDelay_init(this, &cDelay_6p4HlBZ9, 5000.0f);
  numBytes += cBinop_init(&cBinop_GusbIrAX, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_u1Lv98Sz, 5000.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_pkarhCwq, 0.0f);
  numBytes += cBinop_init(&cBinop_dLOtAXm1, 0.0f); // __max
  numBytes += sVarf_init(&sVarf_pSsfj5nZ, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_y3BNyf2i, 0.0f);
  numBytes += hTable_init(&hTable_WzANuIJk, 256);
  numBytes += cDelay_init(this, &cDelay_9PtPQ2Ro, 0.0f);
  numBytes += sVarf_init(&sVarf_rC7JHJDw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_oAwyxlop, 22050.0f);
  numBytes += cBinop_init(&cBinop_qSe6krMG, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_c6x9p2qe, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_misQBCyf, 0.0f);
  numBytes += cDelay_init(this, &cDelay_FyENiaYA, 0.0f);
  numBytes += hTable_init(&hTable_6w65nCNQ, 256);
  numBytes += cVar_init_f(&cVar_nRLdOSPP, 0.0f);
  numBytes += cBinop_init(&cBinop_5MsCqrcH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_z1E8xoRV, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_xfxyDFX5, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MYBSk5PR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_N0hYUKKy, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_M2KLtQSW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_QDh1Ip88, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_hdCf90mK, 0.0f);
  numBytes += cBinop_init(&cBinop_mBzwumgF, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_rarWEnSY, 0.0f); // __mul
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_FourPointDelay::~Heavy_FourPointDelay() {
  hTable_free(&hTable_dN3dpzUH);
  hTable_free(&hTable_oiABVAPE);
  hTable_free(&hTable_GjFTquZx);
  hTable_free(&hTable_TLD5TOQ5);
  hTable_free(&hTable_mF8kKd6s);
  hTable_free(&hTable_MAtR0uMN);
  hTable_free(&hTable_WzANuIJk);
  hTable_free(&hTable_6w65nCNQ);
}

HvTable *Heavy_FourPointDelay::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xA3C03217: return &hTable_6w65nCNQ; // del-1pointL
    case 0x93F2DEB0: return &hTable_WzANuIJk; // del-2pointL
    case 0x70DEB699: return &hTable_mF8kKd6s; // del-4pointL
    case 0xEFF37C10: return &hTable_dN3dpzUH; // del-4pointR
    case 0x5CE3A061: return &hTable_GjFTquZx; // del-2pointR
    case 0x25A63369: return &hTable_oiABVAPE; // del-1pointR
    case 0xBF86F15D: return &hTable_TLD5TOQ5; // del-3pointR
    case 0xD71F9D3E: return &hTable_MAtR0uMN; // del-3pointL
    default: return nullptr;
  }
}

void Heavy_FourPointDelay::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xA43D8EBB: { // 1feed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_gWz31Sn0_sendMessage);
      break;
    }
    case 0xAE922D5E: { // 1point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2yVPJVwe_sendMessage);
      break;
    }
    case 0x6A401883: { // 1time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_5NhTA9nR_sendMessage);
      break;
    }
    case 0x8D622449: { // 1vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7znOwf68_sendMessage);
      break;
    }
    case 0x529E72F3: { // 2feed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FclOS2TR_sendMessage);
      break;
    }
    case 0xCBD550B1: { // 2point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_nqKmx4dm_sendMessage);
      break;
    }
    case 0x686A73A8: { // 2time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jx64evSi_sendMessage);
      break;
    }
    case 0xBD7BB228: { // 2vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QqnSQeOK_sendMessage);
      break;
    }
    case 0x803EB744: { // 3feed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_EZcF2EQK_sendMessage);
      break;
    }
    case 0x244F5F9E: { // 3point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_iXGXZ43A_sendMessage);
      break;
    }
    case 0x52ECA77D: { // 3time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ia2mHZIq_sendMessage);
      break;
    }
    case 0xBE49A30F: { // 3vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jU5jZEC0_sendMessage);
      break;
    }
    case 0xF294C022: { // 4feed
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6dodWejG_sendMessage);
      break;
    }
    case 0xB7BCDFBB: { // 4point
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YfqqIe8v_sendMessage);
      break;
    }
    case 0xB2A79489: { // 4time
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qFHWt8jd_sendMessage);
      break;
    }
    case 0xF2256234: { // 4vol
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DlkF76rh_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_WlRdU2qY_sendMessage);
      break;
    }
    case 0xBA8CED4E: { // dry
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rp32aHTx_sendMessage);
      break;
    }
    case 0x1B53CD5A: { // wet
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F0ZhdAAF_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_FourPointDelay::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "4time";
        info->hash = 0xB2A79489;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 5000.0f;
        info->defaultVal = 100.0f;
        break;
      }
      case 1: {
        info->name = "dry";
        info->hash = 0xBA8CED4E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "1vol";
        info->hash = 0x8D622449;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 3: {
        info->name = "3point";
        info->hash = 0x244F5F9E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 10.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 700.0f;
        break;
      }
      case 4: {
        info->name = "4point";
        info->hash = 0xB7BCDFBB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 10.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 2000.0f;
        break;
      }
      case 5: {
        info->name = "1feed";
        info->hash = 0xA43D8EBB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.9f;
        info->defaultVal = 0.2f;
        break;
      }
      case 6: {
        info->name = "4vol";
        info->hash = 0xF2256234;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 7: {
        info->name = "1point";
        info->hash = 0xAE922D5E;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 10.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 100.0f;
        break;
      }
      case 8: {
        info->name = "2time";
        info->hash = 0x686A73A8;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 5000.0f;
        info->defaultVal = 100.0f;
        break;
      }
      case 9: {
        info->name = "3feed";
        info->hash = 0x803EB744;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.9f;
        info->defaultVal = 0.2f;
        break;
      }
      case 10: {
        info->name = "1time";
        info->hash = 0x6A401883;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 5000.0f;
        info->defaultVal = 100.0f;
        break;
      }
      case 11: {
        info->name = "2vol";
        info->hash = 0xBD7BB228;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 12: {
        info->name = "2point";
        info->hash = 0xCBD550B1;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 10.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 300.0f;
        break;
      }
      case 13: {
        info->name = "wet";
        info->hash = 0x1B53CD5A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 14: {
        info->name = "3vol";
        info->hash = 0xBE49A30F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 15: {
        info->name = "2feed";
        info->hash = 0x529E72F3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.9f;
        info->defaultVal = 0.2f;
        break;
      }
      case 16: {
        info->name = "4feed";
        info->hash = 0xF294C022;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.9f;
        info->defaultVal = 0.2f;
        break;
      }
      case 17: {
        info->name = "3time";
        info->hash = 0x52ECA77D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 5000.0f;
        info->defaultVal = 100.0f;
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
  return 18;
}



/*
 * Send Function Implementations
 */


void Heavy_FourPointDelay::cReceive_YfqqIe8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kRtmec7K, 0, m, &cVar_kRtmec7K_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Xg6tMOXL, 0, m, &cVar_Xg6tMOXL_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xZoLYLfZ, 0, m, &cVar_xZoLYLfZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hdCf90mK, 0, m, &cVar_hdCf90mK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yeQ1voel, 0, m, &cVar_yeQ1voel_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_LNBSlOKc, 0, m, &cVar_LNBSlOKc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6QYRuIyf, 0, m, &cVar_6QYRuIyf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5NbEMODr, 0, m, &cVar_5NbEMODr_sendMessage);
}

void Heavy_FourPointDelay::cReceive_gWz31Sn0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_N0hYUKKy, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_zhg6RBt6, m);
}

void Heavy_FourPointDelay::cReceive_QqnSQeOK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PW3AD4rj, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CmQr4cUf, m);
}

void Heavy_FourPointDelay::cReceive_F0ZhdAAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3civjISe, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gYYUUzip, m);
}

void Heavy_FourPointDelay::cReceive_rp32aHTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fofyc2LC, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ZN1n8ftU, m);
}

void Heavy_FourPointDelay::cReceive_5NhTA9nR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u1Lv98Sz, HV_BINOP_MULTIPLY, 1, m, &cBinop_u1Lv98Sz_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gM0DxMAU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WX3kSbYn, HV_BINOP_MULTIPLY, 1, m, &cBinop_WX3kSbYn_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lJJU9fmu_sendMessage);
}

void Heavy_FourPointDelay::cReceive_iXGXZ43A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L8IeMbtY, 0, m, &cVar_L8IeMbtY_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pS28cUWI, 0, m, &cVar_pS28cUWI_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_x820zk5s, 0, m, &cVar_x820zk5s_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iFOLStnK, 0, m, &cVar_iFOLStnK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_mGaudv4N, 0, m, &cVar_mGaudv4N_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bdc53X4y, 0, m, &cVar_bdc53X4y_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_1xFEHBax, 0, m, &cVar_1xFEHBax_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pEDDYb1R, 0, m, &cVar_pEDDYb1R_sendMessage);
}

void Heavy_FourPointDelay::cReceive_7znOwf68_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4BHFk7BO, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_yqxuikFY, m);
}

void Heavy_FourPointDelay::cReceive_ia2mHZIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OGwJ0aFU, HV_BINOP_MULTIPLY, 1, m, &cBinop_OGwJ0aFU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tJUiQuHx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IunfYEY, HV_BINOP_MULTIPLY, 1, m, &cBinop_4IunfYEY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_g3vu5LPa_sendMessage);
}

void Heavy_FourPointDelay::cReceive_EZcF2EQK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_eQwBpGWo, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Y6vFUXlD, m);
}

void Heavy_FourPointDelay::cReceive_6dodWejG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_pSsfj5nZ, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_pKq1Hsw6, m);
}

void Heavy_FourPointDelay::cReceive_DlkF76rh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_j7NLiNJK, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_RAKpPlIH, m);
}

void Heavy_FourPointDelay::cReceive_jx64evSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iGUZL5Sv, HV_BINOP_MULTIPLY, 1, m, &cBinop_iGUZL5Sv_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZyBd7Wb9_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pwgEE2f7, HV_BINOP_MULTIPLY, 1, m, &cBinop_pwgEE2f7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kv3c7bUh_sendMessage);
}

void Heavy_FourPointDelay::cReceive_nqKmx4dm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cYGFBKJl, 0, m, &cVar_cYGFBKJl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_oAwyxlop, 0, m, &cVar_oAwyxlop_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iOzj3DQ7, 0, m, &cVar_iOzj3DQ7_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_O9rQUjPA, 0, m, &cVar_O9rQUjPA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BQVFIQgx, 0, m, &cVar_BQVFIQgx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YH8xXBAK, 0, m, &cVar_YH8xXBAK_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ySDtUde9, 0, m, &cVar_ySDtUde9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MaBUDMon, 0, m, &cVar_MaBUDMon_sendMessage);
}

void Heavy_FourPointDelay::cReceive_2yVPJVwe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KWXnR5GT, 0, m, &cVar_KWXnR5GT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R0zeIQWC, 0, m, &cVar_R0zeIQWC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_nRLdOSPP, 0, m, &cVar_nRLdOSPP_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eDKUTEqv, 0, m, &cVar_eDKUTEqv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n097wKv9, 0, m, &cVar_n097wKv9_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_T4kPX42T, 0, m, &cVar_T4kPX42T_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ulKdRyYG, 0, m, &cVar_ulKdRyYG_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YlGbMeLo, 0, m, &cVar_YlGbMeLo_sendMessage);
}

void Heavy_FourPointDelay::cReceive_qFHWt8jd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_htrxMPUA, HV_BINOP_MULTIPLY, 1, m, &cBinop_htrxMPUA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_CcGO3vqT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zuw2HqLA, HV_BINOP_MULTIPLY, 1, m, &cBinop_Zuw2HqLA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I9stqpjB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_eZMcV2qX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_EbSKNO6l_sendMessage);
}

void Heavy_FourPointDelay::cBinop_EbSKNO6l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_fZSmARjk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_gYm5muES, m);
}

void Heavy_FourPointDelay::cMsg_2qybwnkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_oIzvWV0H_sendMessage);
}

void Heavy_FourPointDelay::cMsg_DT9DDGPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_giwgi56P_sendMessage);
}

void Heavy_FourPointDelay::cSystem_giwgi56P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2qybwnkq_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_hhXr5GBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_eZMcV2qX_sendMessage);
}

void Heavy_FourPointDelay::cBinop_oIzvWV0H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hhXr5GBB, HV_BINOP_MULTIPLY, 1, m, &cBinop_hhXr5GBB_sendMessage);
}

void Heavy_FourPointDelay::cVar_YH8xXBAK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hhXr5GBB, HV_BINOP_MULTIPLY, 0, m, &cBinop_hhXr5GBB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_fZSmARjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5wc0mCHZ, m);
}

void Heavy_FourPointDelay::cBinop_4lF1OfZi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iHRA8r0r, 2, m, &cDelay_iHRA8r0r_sendMessage);
}

void Heavy_FourPointDelay::cMsg_x27U8JmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vdUT9NSV_sendMessage);
}

void Heavy_FourPointDelay::cMsg_xlFEQ4qF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_lDKt95kh, HV_BINOP_MAX, 1, m, &cBinop_lDKt95kh_sendMessage);
}

void Heavy_FourPointDelay::cVar_24KBTlEa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_x27U8JmT_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_pwgEE2f7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lDKt95kh, HV_BINOP_MAX, 0, m, &cBinop_lDKt95kh_sendMessage);
}

void Heavy_FourPointDelay::sTabread_CjeLMNLG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_NPocc83r, HV_BINOP_SUBTRACT, 0, m, &cBinop_NPocc83r_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cBinop_ph3WZg21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pwgEE2f7, HV_BINOP_MULTIPLY, 0, m, &cBinop_pwgEE2f7_sendMessage);
}

void Heavy_FourPointDelay::cMsg_rl0YOSFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_iHRA8r0r, 0, m, &cDelay_iHRA8r0r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJm4Azci, 0, m, &cDelay_tJm4Azci_sendMessage);
}

void Heavy_FourPointDelay::cBinop_AtNNKeLb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rl0YOSFS_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CjeLMNLG, 0, m, &sTabread_CjeLMNLG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_05yLeHPg_sendMessage);
}

void Heavy_FourPointDelay::cSystem_AwvFtiNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ph3WZg21_sendMessage);
}

void Heavy_FourPointDelay::cMsg_PELxfkAk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AwvFtiNC_sendMessage);
}

void Heavy_FourPointDelay::cSystem_vdUT9NSV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NPocc83r, HV_BINOP_SUBTRACT, 1, m, &cBinop_NPocc83r_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJm4Azci, 2, m, &cDelay_tJm4Azci_sendMessage);
}

void Heavy_FourPointDelay::cCast_kv3c7bUh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_24KBTlEa, 0, m, &cVar_24KBTlEa_sendMessage);
  cMsg_PELxfkAk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QYtQyXyt, 0, m, &cTabhead_QYtQyXyt_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_QYtQyXyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AtNNKeLb, HV_BINOP_SUBTRACT, 0, m, &cBinop_AtNNKeLb_sendMessage);
}

void Heavy_FourPointDelay::cBinop_NPocc83r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4lF1OfZi_sendMessage);
}

void Heavy_FourPointDelay::cDelay_tJm4Azci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tJm4Azci, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CjeLMNLG, 0, m, &sTabread_CjeLMNLG_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJm4Azci, 0, m, &cDelay_tJm4Azci_sendMessage);
}

void Heavy_FourPointDelay::cCast_05yLeHPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_iHRA8r0r, 0, m, &cDelay_iHRA8r0r_sendMessage);
}

void Heavy_FourPointDelay::cDelay_iHRA8r0r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_iHRA8r0r, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_tJm4Azci, 0, m, &cDelay_tJm4Azci_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_CjeLMNLG, 0, m, &sTabread_CjeLMNLG_sendMessage);
}

void Heavy_FourPointDelay::cBinop_lDKt95kh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AtNNKeLb, HV_BINOP_SUBTRACT, 1, m, &cBinop_AtNNKeLb_sendMessage);
}

void Heavy_FourPointDelay::cMsg_GK37wLAp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_dN3dpzUH, 0, m, &hTable_dN3dpzUH_sendMessage);
}

void Heavy_FourPointDelay::cCast_IZUrntLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_VORrNGgb, 0, m, &cDelay_VORrNGgb_sendMessage);
}

void Heavy_FourPointDelay::cMsg_qcN4lrmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_mwlDREvg, 2, m, &cDelay_mwlDREvg_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Sz3zaT0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GK37wLAp_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_dZ8Z7Ii3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_Sz3zaT0d_sendMessage);
}

void Heavy_FourPointDelay::cMsg_j5wmEXY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_2kgqvkiJ_sendMessage);
}

void Heavy_FourPointDelay::cSystem_2kgqvkiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dZ8Z7Ii3_sendMessage);
}

void Heavy_FourPointDelay::cDelay_VORrNGgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_VORrNGgb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mwlDREvg, 0, m, &cDelay_mwlDREvg_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VORrNGgb, 0, m, &cDelay_VORrNGgb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_TsdC26oq, 1, m, NULL);
}

void Heavy_FourPointDelay::hTable_dN3dpzUH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qcN4lrmJ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_VORrNGgb, 2, m, &cDelay_VORrNGgb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IZUrntLy_sendMessage);
}

void Heavy_FourPointDelay::cDelay_mwlDREvg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mwlDREvg, m);
  cMsg_DvHBoKBr_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_DvHBoKBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_dN3dpzUH, 0, m, &hTable_dN3dpzUH_sendMessage);
}

void Heavy_FourPointDelay::cDelay_8gMVh1Mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8gMVh1Mk, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ThDV7U55, 0, m, &cDelay_ThDV7U55_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gMVh1Mk, 0, m, &cDelay_8gMVh1Mk_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_oUoR0KbL, 1, m, NULL);
}

void Heavy_FourPointDelay::hTable_oiABVAPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SiglmXhN_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gMVh1Mk, 2, m, &cDelay_8gMVh1Mk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_721rim6A_sendMessage);
}

void Heavy_FourPointDelay::cMsg_PlShWRFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P8tAWoI3_sendMessage);
}

void Heavy_FourPointDelay::cSystem_P8tAWoI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_08dtKRN4_sendMessage);
}

void Heavy_FourPointDelay::cDelay_ThDV7U55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ThDV7U55, m);
  cMsg_Ezp4pDFn_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_DVDtIDUf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_oiABVAPE, 0, m, &hTable_oiABVAPE_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Ezp4pDFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_oiABVAPE, 0, m, &hTable_oiABVAPE_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4pUDQ2AV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DVDtIDUf_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_SiglmXhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_ThDV7U55, 2, m, &cDelay_ThDV7U55_sendMessage);
}

void Heavy_FourPointDelay::cCast_721rim6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8gMVh1Mk, 0, m, &cDelay_8gMVh1Mk_sendMessage);
}

void Heavy_FourPointDelay::cBinop_08dtKRN4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_4pUDQ2AV_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Hn2aXOmm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_dbZqT0tK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ofCb8Uve_sendMessage);
}

void Heavy_FourPointDelay::cBinop_bGjRj3TJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Hn2aXOmm_sendMessage);
}

void Heavy_FourPointDelay::cMsg_WgJrhh0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_IKze1ZKU_sendMessage);
}

void Heavy_FourPointDelay::cBinop_YAXZxcw4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_c7Gle2Dy, m);
}

void Heavy_FourPointDelay::cBinop_nOC42LaZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WgJrhh0N_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_ArgTylll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QoTlyods, HV_BINOP_DIVIDE, 0, m, &cBinop_QoTlyods_sendMessage);
}

void Heavy_FourPointDelay::cMsg_j6YY74A0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_R6dkMjnk_sendMessage);
}

void Heavy_FourPointDelay::cSystem_awoBITka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QoTlyods, HV_BINOP_DIVIDE, 1, m, &cBinop_QoTlyods_sendMessage);
  cMsg_j6YY74A0_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_2oE6zIFZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_awoBITka_sendMessage);
}

void Heavy_FourPointDelay::cUnop_R6dkMjnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_ArgTylll_sendMessage);
}

void Heavy_FourPointDelay::cBinop_QoTlyods_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOC42LaZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_nOC42LaZ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_ofCb8Uve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RJoPmadP, m);
}

void Heavy_FourPointDelay::cBinop_IKze1ZKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_bGjRj3TJ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_dbZqT0tK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_YAXZxcw4_sendMessage);
}

void Heavy_FourPointDelay::cVar_ySDtUde9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nOC42LaZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_nOC42LaZ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_WhsnttHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGgPbFGB, HV_BINOP_SUBTRACT, 1, m, &cBinop_UGgPbFGB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Zuw2HqLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WhsnttHr, HV_BINOP_MAX, 0, m, &cBinop_WhsnttHr_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_qX0yovRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGgPbFGB, HV_BINOP_SUBTRACT, 0, m, &cBinop_UGgPbFGB_sendMessage);
}

void Heavy_FourPointDelay::cSystem_YpBZFViQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kRRiaV9H, HV_BINOP_SUBTRACT, 1, m, &cBinop_kRRiaV9H_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mjnh65EO, 2, m, &cDelay_mjnh65EO_sendMessage);
}

void Heavy_FourPointDelay::cBinop_SHvUKGih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Zuw2HqLA, HV_BINOP_MULTIPLY, 0, m, &cBinop_Zuw2HqLA_sendMessage);
}

void Heavy_FourPointDelay::cDelay_mjnh65EO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mjnh65EO, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_a2LgDYTc, 0, m, &sTabread_a2LgDYTc_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mjnh65EO, 0, m, &cDelay_mjnh65EO_sendMessage);
}

void Heavy_FourPointDelay::cVar_O1QyEYjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mSojq6dw_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cCast_I9stqpjB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O1QyEYjN, 0, m, &cVar_O1QyEYjN_sendMessage);
  cMsg_czeqsrWv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qX0yovRY, 0, m, &cTabhead_qX0yovRY_sendMessage);
}

void Heavy_FourPointDelay::cMsg_mSojq6dw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YpBZFViQ_sendMessage);
}

void Heavy_FourPointDelay::sTabread_a2LgDYTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_kRRiaV9H, HV_BINOP_SUBTRACT, 0, m, &cBinop_kRRiaV9H_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cMsg_tJjl5sIe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_WhsnttHr, HV_BINOP_MAX, 1, m, &cBinop_WhsnttHr_sendMessage);
}

void Heavy_FourPointDelay::cDelay_cxK5Ihv6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_cxK5Ihv6, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mjnh65EO, 0, m, &cDelay_mjnh65EO_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_a2LgDYTc, 0, m, &sTabread_a2LgDYTc_sendMessage);
}

void Heavy_FourPointDelay::cBinop_xF7j8ixp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cxK5Ihv6, 2, m, &cDelay_cxK5Ihv6_sendMessage);
}

void Heavy_FourPointDelay::cBinop_kRRiaV9H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xF7j8ixp_sendMessage);
}

void Heavy_FourPointDelay::cMsg_GXsfVugM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_cxK5Ihv6, 0, m, &cDelay_cxK5Ihv6_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mjnh65EO, 0, m, &cDelay_mjnh65EO_sendMessage);
}

void Heavy_FourPointDelay::cBinop_UGgPbFGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GXsfVugM_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_a2LgDYTc, 0, m, &sTabread_a2LgDYTc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FW8L5nqA_sendMessage);
}

void Heavy_FourPointDelay::cSystem_UfgSzUfc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SHvUKGih_sendMessage);
}

void Heavy_FourPointDelay::cMsg_czeqsrWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UfgSzUfc_sendMessage);
}

void Heavy_FourPointDelay::cCast_FW8L5nqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_cxK5Ihv6, 0, m, &cDelay_cxK5Ihv6_sendMessage);
}

void Heavy_FourPointDelay::cMsg_BlB7W7gh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Yab4anOY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Yab4anOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UmRCorBf, HV_BINOP_MULTIPLY, 1, m, &cBinop_UmRCorBf_sendMessage);
}

void Heavy_FourPointDelay::cMsg_SWot9rGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0ZrKUkIG_sendMessage);
}

void Heavy_FourPointDelay::cSystem_0ZrKUkIG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_BlB7W7gh_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_UmRCorBf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_9KGu9ekb_sendMessage);
}

void Heavy_FourPointDelay::cVar_BQVFIQgx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UmRCorBf, HV_BINOP_MULTIPLY, 0, m, &cBinop_UmRCorBf_sendMessage);
}

void Heavy_FourPointDelay::cBinop_FDcYMfGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YU7yLrXC, m);
}

void Heavy_FourPointDelay::cBinop_9KGu9ekb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DZJo3amP_sendMessage);
}

void Heavy_FourPointDelay::cBinop_DZJo3amP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FDcYMfGC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_5bxZRUjQ, m);
}

void Heavy_FourPointDelay::cBinop_5GRHfUdu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KlX0970t_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gnRw7hUq, 0, m, &sTabread_gnRw7hUq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o4oj9EYS_sendMessage);
}

void Heavy_FourPointDelay::cCast_o4oj9EYS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aOca7fKM, 0, m, &cDelay_aOca7fKM_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_opE0dtuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5GRHfUdu, HV_BINOP_SUBTRACT, 0, m, &cBinop_5GRHfUdu_sendMessage);
}

void Heavy_FourPointDelay::cVar_QpvQnXjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gclqPGrq_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_Mmvp8TW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4IunfYEY, HV_BINOP_MULTIPLY, 0, m, &cBinop_4IunfYEY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_9sXf36Ou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5GRHfUdu, HV_BINOP_SUBTRACT, 1, m, &cBinop_5GRHfUdu_sendMessage);
}

void Heavy_FourPointDelay::cBinop_2jJtaThr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_aOca7fKM, 2, m, &cDelay_aOca7fKM_sendMessage);
}

void Heavy_FourPointDelay::cMsg_hG0VG47i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_9sXf36Ou, HV_BINOP_MAX, 1, m, &cBinop_9sXf36Ou_sendMessage);
}

void Heavy_FourPointDelay::cDelay_73TFrCT0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_73TFrCT0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gnRw7hUq, 0, m, &sTabread_gnRw7hUq_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_73TFrCT0, 0, m, &cDelay_73TFrCT0_sendMessage);
}

void Heavy_FourPointDelay::cSystem_BMDofZUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Mmvp8TW0_sendMessage);
}

void Heavy_FourPointDelay::cMsg_5Pfr0qVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BMDofZUU_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Shw3cB8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2jJtaThr_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4IunfYEY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9sXf36Ou, HV_BINOP_MAX, 0, m, &cBinop_9sXf36Ou_sendMessage);
}

void Heavy_FourPointDelay::sTabread_gnRw7hUq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_Shw3cB8X, HV_BINOP_SUBTRACT, 0, m, &cBinop_Shw3cB8X_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cMsg_gclqPGrq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Dcui3spf_sendMessage);
}

void Heavy_FourPointDelay::cMsg_KlX0970t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_aOca7fKM, 0, m, &cDelay_aOca7fKM_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_73TFrCT0, 0, m, &cDelay_73TFrCT0_sendMessage);
}

void Heavy_FourPointDelay::cDelay_aOca7fKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_aOca7fKM, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_73TFrCT0, 0, m, &cDelay_73TFrCT0_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_gnRw7hUq, 0, m, &sTabread_gnRw7hUq_sendMessage);
}

void Heavy_FourPointDelay::cSystem_Dcui3spf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Shw3cB8X, HV_BINOP_SUBTRACT, 1, m, &cBinop_Shw3cB8X_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_73TFrCT0, 2, m, &cDelay_73TFrCT0_sendMessage);
}

void Heavy_FourPointDelay::cCast_g3vu5LPa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QpvQnXjU, 0, m, &cVar_QpvQnXjU_sendMessage);
  cMsg_5Pfr0qVr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_opE0dtuL, 0, m, &cTabhead_opE0dtuL_sendMessage);
}

void Heavy_FourPointDelay::cSystem_JVnORKwB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jvzcgCss_sendMessage);
}

void Heavy_FourPointDelay::cMsg_hyYaRkKM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JVnORKwB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_HY3Z4und_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DQrofQ0, 2, m, &cDelay_7DQrofQ0_sendMessage);
}

void Heavy_FourPointDelay::cCast_G4zwA028_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DQrofQ0, 0, m, &cDelay_7DQrofQ0_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Kq8y9kHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_m739B3K7, HV_BINOP_MAX, 1, m, &cBinop_m739B3K7_sendMessage);
}

void Heavy_FourPointDelay::cDelay_dyT7X4VP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dyT7X4VP, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AuTAmAp8, 0, m, &sTabread_AuTAmAp8_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dyT7X4VP, 0, m, &cDelay_dyT7X4VP_sendMessage);
}

void Heavy_FourPointDelay::cSystem_nQdEevA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fkgXijhN, HV_BINOP_SUBTRACT, 1, m, &cBinop_fkgXijhN_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dyT7X4VP, 2, m, &cDelay_dyT7X4VP_sendMessage);
}

void Heavy_FourPointDelay::cMsg_cOYclelF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_nQdEevA2_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4aYQd68l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ysLvKmE7_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AuTAmAp8, 0, m, &sTabread_AuTAmAp8_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_G4zwA028_sendMessage);
}

void Heavy_FourPointDelay::cMsg_ysLvKmE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7DQrofQ0, 0, m, &cDelay_7DQrofQ0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dyT7X4VP, 0, m, &cDelay_dyT7X4VP_sendMessage);
}

void Heavy_FourPointDelay::cBinop_fkgXijhN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HY3Z4und_sendMessage);
}

void Heavy_FourPointDelay::cBinop_WX3kSbYn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_m739B3K7, HV_BINOP_MAX, 0, m, &cBinop_m739B3K7_sendMessage);
}

void Heavy_FourPointDelay::cDelay_7DQrofQ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7DQrofQ0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_dyT7X4VP, 0, m, &cDelay_dyT7X4VP_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_AuTAmAp8, 0, m, &sTabread_AuTAmAp8_sendMessage);
}

void Heavy_FourPointDelay::sTabread_AuTAmAp8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_fkgXijhN, HV_BINOP_SUBTRACT, 0, m, &cBinop_fkgXijhN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cCast_lJJU9fmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_W1l3IdNt, 0, m, &cVar_W1l3IdNt_sendMessage);
  cMsg_hyYaRkKM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_L833PIYM, 0, m, &cTabhead_L833PIYM_sendMessage);
}

void Heavy_FourPointDelay::cBinop_m739B3K7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4aYQd68l, HV_BINOP_SUBTRACT, 1, m, &cBinop_4aYQd68l_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_L833PIYM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4aYQd68l, HV_BINOP_SUBTRACT, 0, m, &cBinop_4aYQd68l_sendMessage);
}

void Heavy_FourPointDelay::cBinop_jvzcgCss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WX3kSbYn, HV_BINOP_MULTIPLY, 0, m, &cBinop_WX3kSbYn_sendMessage);
}

void Heavy_FourPointDelay::cVar_W1l3IdNt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cOYclelF_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cVar_LNBSlOKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VrcowatB, HV_BINOP_MULTIPLY, 0, m, &cBinop_VrcowatB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_VrcowatB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AsOfZCny_sendMessage);
}

void Heavy_FourPointDelay::cBinop_sxAtDvxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VrcowatB, HV_BINOP_MULTIPLY, 1, m, &cBinop_VrcowatB_sendMessage);
}

void Heavy_FourPointDelay::cSystem_inhD6NzC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bMLH3Q61_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_lPHDoFLA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_inhD6NzC_sendMessage);
}

void Heavy_FourPointDelay::cMsg_bMLH3Q61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_sxAtDvxl_sendMessage);
}

void Heavy_FourPointDelay::cBinop_2KhGQ8Ap_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_exz7bRT9_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hbPtLKFX, m);
}

void Heavy_FourPointDelay::cBinop_AsOfZCny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2KhGQ8Ap_sendMessage);
}

void Heavy_FourPointDelay::cBinop_exz7bRT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_5bGcG39A, m);
}

void Heavy_FourPointDelay::cMsg_cAvzrLLn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_GjFTquZx, 0, m, &hTable_GjFTquZx_sendMessage);
}

void Heavy_FourPointDelay::cCast_X42DMK1M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kymT769C, 0, m, &cDelay_kymT769C_sendMessage);
}

void Heavy_FourPointDelay::cMsg_iyODfMZY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_GjFTquZx, 0, m, &hTable_GjFTquZx_sendMessage);
}

void Heavy_FourPointDelay::cMsg_W6fzmHwc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHI3jBvz, 2, m, &cDelay_RHI3jBvz_sendMessage);
}

void Heavy_FourPointDelay::hTable_GjFTquZx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W6fzmHwc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kymT769C, 2, m, &cDelay_kymT769C_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_X42DMK1M_sendMessage);
}

void Heavy_FourPointDelay::cDelay_kymT769C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kymT769C, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RHI3jBvz, 0, m, &cDelay_RHI3jBvz_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kymT769C, 0, m, &cDelay_kymT769C_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_zmIkBDFH, 1, m, NULL);
}

void Heavy_FourPointDelay::cDelay_RHI3jBvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RHI3jBvz, m);
  cMsg_cAvzrLLn_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_wGbG2hS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iyODfMZY_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_yuFtnhp7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_wGbG2hS3_sendMessage);
}

void Heavy_FourPointDelay::cSystem_O2UpTunX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yuFtnhp7_sendMessage);
}

void Heavy_FourPointDelay::cMsg_jAjQKJLm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O2UpTunX_sendMessage);
}

void Heavy_FourPointDelay::cVar_YlGbMeLo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HlQ4oakN, HV_BINOP_MULTIPLY, 0, m, &cBinop_HlQ4oakN_sendMessage);
}

void Heavy_FourPointDelay::cBinop_lFYji7Qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VUGnP38E, m);
}

void Heavy_FourPointDelay::cBinop_08uFU1J9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_lFYji7Qm_sendMessage);
}

void Heavy_FourPointDelay::cMsg_e5CP5VFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_RvQAY7cB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_RvQAY7cB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ZbNUm0Cx_sendMessage);
}

void Heavy_FourPointDelay::cBinop_ZbNUm0Cx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RZJT300U_sendMessage);
}

void Heavy_FourPointDelay::cBinop_RZJT300U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_08uFU1J9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DgPoh391_sendMessage);
}

void Heavy_FourPointDelay::cBinop_HlQ4oakN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e5CP5VFi_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cUnop_4xMq7u6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_zBJx6W4G_sendMessage);
}

void Heavy_FourPointDelay::cBinop_zBJx6W4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S7UP71Lw, HV_BINOP_DIVIDE, 0, m, &cBinop_S7UP71Lw_sendMessage);
}

void Heavy_FourPointDelay::cBinop_S7UP71Lw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HlQ4oakN, HV_BINOP_MULTIPLY, 1, m, &cBinop_HlQ4oakN_sendMessage);
}

void Heavy_FourPointDelay::cMsg_jTVc5uez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_4xMq7u6g_sendMessage);
}

void Heavy_FourPointDelay::cSystem_K2O0qmRw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S7UP71Lw, HV_BINOP_DIVIDE, 1, m, &cBinop_S7UP71Lw_sendMessage);
  cMsg_jTVc5uez_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_0pUC1bd6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_K2O0qmRw_sendMessage);
}

void Heavy_FourPointDelay::cBinop_DgPoh391_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FdQuW9Po, m);
}

void Heavy_FourPointDelay::cVar_n097wKv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2dLyrJj2, HV_BINOP_MULTIPLY, 0, m, &cBinop_2dLyrJj2_sendMessage);
}

void Heavy_FourPointDelay::cBinop_7PemUeR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5wIFvBxj_sendMessage);
}

void Heavy_FourPointDelay::cBinop_5wIFvBxj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_mGinOfHE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_cXVvrOHR, m);
}

void Heavy_FourPointDelay::cBinop_mGinOfHE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nadW8d7Y, m);
}

void Heavy_FourPointDelay::cMsg_qVxm1Uq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Yl7epg1Y_sendMessage);
}

void Heavy_FourPointDelay::cSystem_NRPzFXcv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qVxm1Uq8_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_vUfCvowe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NRPzFXcv_sendMessage);
}

void Heavy_FourPointDelay::cBinop_2dLyrJj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_7PemUeR3_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Yl7epg1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2dLyrJj2, HV_BINOP_MULTIPLY, 1, m, &cBinop_2dLyrJj2_sendMessage);
}

void Heavy_FourPointDelay::cMsg_H9OGSi9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_afcYp1dh_sendMessage);
}

void Heavy_FourPointDelay::cBinop_6jc2fmaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uigZTkGO, HV_BINOP_MULTIPLY, 1, m, &cBinop_uigZTkGO_sendMessage);
}

void Heavy_FourPointDelay::cUnop_afcYp1dh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_U8bEE0XV_sendMessage);
}

void Heavy_FourPointDelay::cBinop_uigZTkGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wE2pC6sI_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_U8bEE0XV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jc2fmaI, HV_BINOP_DIVIDE, 0, m, &cBinop_6jc2fmaI_sendMessage);
}

void Heavy_FourPointDelay::cMsg_jsc6WzvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_SA6wKHfU_sendMessage);
}

void Heavy_FourPointDelay::cSystem_SA6wKHfU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6jc2fmaI, HV_BINOP_DIVIDE, 1, m, &cBinop_6jc2fmaI_sendMessage);
  cMsg_H9OGSi9M_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_BjeuESjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MfPGX9g8_sendMessage);
}

void Heavy_FourPointDelay::cBinop_MfPGX9g8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_p3KdWiMi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ebZZmwR4_sendMessage);
}

void Heavy_FourPointDelay::cBinop_gTs73ZkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OQPTZQHY, m);
}

void Heavy_FourPointDelay::cMsg_wE2pC6sI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_BU0TsEgX_sendMessage);
}

void Heavy_FourPointDelay::cVar_5NbEMODr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uigZTkGO, HV_BINOP_MULTIPLY, 0, m, &cBinop_uigZTkGO_sendMessage);
}

void Heavy_FourPointDelay::cBinop_ebZZmwR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VF0439iW, m);
}

void Heavy_FourPointDelay::cBinop_p3KdWiMi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_gTs73ZkX_sendMessage);
}

void Heavy_FourPointDelay::cBinop_BU0TsEgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_BjeuESjn_sendMessage);
}

void Heavy_FourPointDelay::cBinop_IprA9dFw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_25JDctGq_sendMessage);
}

void Heavy_FourPointDelay::cBinop_25JDctGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_H3vJKZCw_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_eoo1hzVy, m);
}

void Heavy_FourPointDelay::cVar_bdc53X4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gWWfIfPV, HV_BINOP_MULTIPLY, 0, m, &cBinop_gWWfIfPV_sendMessage);
}

void Heavy_FourPointDelay::cBinop_H3vJKZCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fqQuRH6f, m);
}

void Heavy_FourPointDelay::cBinop_gWWfIfPV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_IprA9dFw_sendMessage);
}

void Heavy_FourPointDelay::cBinop_k4KSwpMU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gWWfIfPV, HV_BINOP_MULTIPLY, 1, m, &cBinop_gWWfIfPV_sendMessage);
}

void Heavy_FourPointDelay::cMsg_OBSilwHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_k4KSwpMU_sendMessage);
}

void Heavy_FourPointDelay::cMsg_jKDYYrI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uTUl0OF2_sendMessage);
}

void Heavy_FourPointDelay::cSystem_uTUl0OF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OBSilwHJ_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_MpX3k005_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vrRSo3OE, m);
}

void Heavy_FourPointDelay::cVar_mGaudv4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_96zH4ITk, HV_BINOP_MULTIPLY, 0, m, &cBinop_96zH4ITk_sendMessage);
}

void Heavy_FourPointDelay::cBinop_WBhXfmg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_4jby28Qr_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4jby28Qr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MpX3k005_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Do5DnuB8, m);
}

void Heavy_FourPointDelay::cBinop_8w14LGlw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_96zH4ITk, HV_BINOP_MULTIPLY, 1, m, &cBinop_96zH4ITk_sendMessage);
}

void Heavy_FourPointDelay::cMsg_imiOdjmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LbV7ALOw_sendMessage);
}

void Heavy_FourPointDelay::cSystem_LbV7ALOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9fwYzlGH_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_96zH4ITk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WBhXfmg8_sendMessage);
}

void Heavy_FourPointDelay::cMsg_9fwYzlGH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8w14LGlw_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Cn0XTabr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_iE9Atkq1_sendMessage);
}

void Heavy_FourPointDelay::cBinop_iE9Atkq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UZ7tb2Tm_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UEH1tYov_sendMessage);
}

void Heavy_FourPointDelay::cMsg_GZJkLvPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_OfBMPJBY_sendMessage);
}

void Heavy_FourPointDelay::cVar_MaBUDMon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nfJmxzGz, HV_BINOP_MULTIPLY, 0, m, &cBinop_nfJmxzGz_sendMessage);
}

void Heavy_FourPointDelay::cBinop_UEH1tYov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CqbCLuGo, m);
}

void Heavy_FourPointDelay::cBinop_nfJmxzGz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GZJkLvPA_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_fDfz2YUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_1pEKIJCY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_PZj9pliq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nfJmxzGz, HV_BINOP_MULTIPLY, 1, m, &cBinop_nfJmxzGz_sendMessage);
}

void Heavy_FourPointDelay::cUnop_1pEKIJCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_y0Tba8oL_sendMessage);
}

void Heavy_FourPointDelay::cBinop_y0Tba8oL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PZj9pliq, HV_BINOP_DIVIDE, 0, m, &cBinop_PZj9pliq_sendMessage);
}

void Heavy_FourPointDelay::cSystem_LTeTxniY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PZj9pliq, HV_BINOP_DIVIDE, 1, m, &cBinop_PZj9pliq_sendMessage);
  cMsg_fDfz2YUE_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_xpT7Vj7U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LTeTxniY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_1lzdmTkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_1Abz8Jfk, m);
}

void Heavy_FourPointDelay::cBinop_UZ7tb2Tm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_1lzdmTkz_sendMessage);
}

void Heavy_FourPointDelay::cBinop_OfBMPJBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Cn0XTabr_sendMessage);
}

void Heavy_FourPointDelay::cBinop_af7z2F2n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_FRe54Gnj, m);
}

void Heavy_FourPointDelay::cSystem_DUy2ZhHA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JZEQ04M8, HV_BINOP_DIVIDE, 1, m, &cBinop_JZEQ04M8_sendMessage);
  cMsg_QpQPPodt_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_ul0G0LnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DUy2ZhHA_sendMessage);
}

void Heavy_FourPointDelay::cBinop_ytsxAqX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_83iUiu7M_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_QpQPPodt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_BjvZWtDe_sendMessage);
}

void Heavy_FourPointDelay::cBinop_DBQWIiQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JZEQ04M8, HV_BINOP_DIVIDE, 0, m, &cBinop_JZEQ04M8_sendMessage);
}

void Heavy_FourPointDelay::cUnop_BjvZWtDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_DBQWIiQq_sendMessage);
}

void Heavy_FourPointDelay::cBinop_JZEQ04M8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ytsxAqX8, HV_BINOP_MULTIPLY, 1, m, &cBinop_ytsxAqX8_sendMessage);
}

void Heavy_FourPointDelay::cMsg_83iUiu7M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_jzLBsIVF_sendMessage);
}

void Heavy_FourPointDelay::cBinop_r4WuZ0bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_56EONPLN_sendMessage);
}

void Heavy_FourPointDelay::cVar_ulKdRyYG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ytsxAqX8, HV_BINOP_MULTIPLY, 0, m, &cBinop_ytsxAqX8_sendMessage);
}

void Heavy_FourPointDelay::cBinop_UG5TwyrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_srprzOOJ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_srprzOOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_r4WuZ0bh_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_af7z2F2n_sendMessage);
}

void Heavy_FourPointDelay::cBinop_56EONPLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_X7UHm64o, m);
}

void Heavy_FourPointDelay::cBinop_jzLBsIVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_UG5TwyrX_sendMessage);
}

void Heavy_FourPointDelay::cVar_6QYRuIyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pog5mjIh, HV_BINOP_MULTIPLY, 0, m, &cBinop_Pog5mjIh_sendMessage);
}

void Heavy_FourPointDelay::cBinop_o5tfFyBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SyXgHt5p, m);
}

void Heavy_FourPointDelay::cBinop_tcGuC0ML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1FnH85b9_sendMessage);
}

void Heavy_FourPointDelay::cMsg_1cELwNNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_tcGuC0ML_sendMessage);
}

void Heavy_FourPointDelay::cBinop_NCJlKAMa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_o5tfFyBT_sendMessage);
}

void Heavy_FourPointDelay::cBinop_LCDUFKqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y5v3cnxz, HV_BINOP_DIVIDE, 0, m, &cBinop_y5v3cnxz_sendMessage);
}

void Heavy_FourPointDelay::cMsg_ZJPrtuQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YQZnhVGp_sendMessage);
}

void Heavy_FourPointDelay::cSystem_YQZnhVGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_y5v3cnxz, HV_BINOP_DIVIDE, 1, m, &cBinop_y5v3cnxz_sendMessage);
  cMsg_7Fkphlxl_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_7Fkphlxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_lB3zEtQt_sendMessage);
}

void Heavy_FourPointDelay::cUnop_lB3zEtQt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_LCDUFKqW_sendMessage);
}

void Heavy_FourPointDelay::cBinop_y5v3cnxz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Pog5mjIh, HV_BINOP_MULTIPLY, 1, m, &cBinop_Pog5mjIh_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Pog5mjIh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1cELwNNl_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_1FnH85b9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_S9ScoFX0_sendMessage);
}

void Heavy_FourPointDelay::cBinop_S9ScoFX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NCJlKAMa_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_K9kIJ2zz_sendMessage);
}

void Heavy_FourPointDelay::cBinop_K9kIJ2zz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VwYkcQ4r, m);
}

void Heavy_FourPointDelay::cBinop_FgWRfrA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_d7BPSZLO_sendMessage);
}

void Heavy_FourPointDelay::cUnop_iRtve92P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_UyTnUtBL_sendMessage);
}

void Heavy_FourPointDelay::cSystem_reTg83XC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DpRhVzgb, HV_BINOP_DIVIDE, 1, m, &cBinop_DpRhVzgb_sendMessage);
  cMsg_iLjw3OgJ_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_lNKpXDyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_reTg83XC_sendMessage);
}

void Heavy_FourPointDelay::cMsg_iLjw3OgJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_iRtve92P_sendMessage);
}

void Heavy_FourPointDelay::cBinop_UyTnUtBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DpRhVzgb, HV_BINOP_DIVIDE, 0, m, &cBinop_DpRhVzgb_sendMessage);
}

void Heavy_FourPointDelay::cBinop_DpRhVzgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4MVWZWoQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_4MVWZWoQ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4MVWZWoQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RVWQuaNl_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cVar_pEDDYb1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4MVWZWoQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_4MVWZWoQ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_tomYUhJ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SYj90OhX, m);
}

void Heavy_FourPointDelay::cBinop_OCvPP4Pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_xvIJlHmV_sendMessage);
}

void Heavy_FourPointDelay::cMsg_RVWQuaNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_FgWRfrA3_sendMessage);
}

void Heavy_FourPointDelay::cBinop_xvIJlHmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_fEQUvPH9, m);
}

void Heavy_FourPointDelay::cBinop_GwxB9zU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OCvPP4Pc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_tomYUhJ7_sendMessage);
}

void Heavy_FourPointDelay::cBinop_d7BPSZLO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GwxB9zU2_sendMessage);
}

void Heavy_FourPointDelay::cBinop_WcZ4xhwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_jG9KgBdL_sendMessage);
}

void Heavy_FourPointDelay::cBinop_jG9KgBdL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_HjmtAx3Q_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TboFzg5Z, m);
}

void Heavy_FourPointDelay::cSystem_7mFe3LwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G4LYy6Ps_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_2uo0nIV4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7mFe3LwH_sendMessage);
}

void Heavy_FourPointDelay::cMsg_G4LYy6Ps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_lVSe2vgj_sendMessage);
}

void Heavy_FourPointDelay::cBinop_lVSe2vgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7DPi7d86, HV_BINOP_MULTIPLY, 1, m, &cBinop_7DPi7d86_sendMessage);
}

void Heavy_FourPointDelay::cBinop_7DPi7d86_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_WcZ4xhwF_sendMessage);
}

void Heavy_FourPointDelay::cVar_yeQ1voel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7DPi7d86, HV_BINOP_MULTIPLY, 0, m, &cBinop_7DPi7d86_sendMessage);
}

void Heavy_FourPointDelay::cBinop_HjmtAx3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Xzjw74kC, m);
}

void Heavy_FourPointDelay::cMsg_jHHAV3Ra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_vyNPPRND, 2, m, &cDelay_vyNPPRND_sendMessage);
}

void Heavy_FourPointDelay::cBinop_prMUn6cG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PWQDyFfY_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_Z3j5opBi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_TLD5TOQ5, 0, m, &hTable_TLD5TOQ5_sendMessage);
}

void Heavy_FourPointDelay::cMsg_PWQDyFfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_TLD5TOQ5, 0, m, &hTable_TLD5TOQ5_sendMessage);
}

void Heavy_FourPointDelay::cBinop_qQ0ln4tk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_prMUn6cG_sendMessage);
}

void Heavy_FourPointDelay::cSystem_RYSKRZ0u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qQ0ln4tk_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Qkz7zoCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RYSKRZ0u_sendMessage);
}

void Heavy_FourPointDelay::cDelay_5ZfE8uQG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5ZfE8uQG, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_vyNPPRND, 0, m, &cDelay_vyNPPRND_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ZfE8uQG, 0, m, &cDelay_5ZfE8uQG_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_VRY7zSue, 1, m, NULL);
}

void Heavy_FourPointDelay::cCast_vm6XeiPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ZfE8uQG, 0, m, &cDelay_5ZfE8uQG_sendMessage);
}

void Heavy_FourPointDelay::hTable_TLD5TOQ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jHHAV3Ra_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5ZfE8uQG, 2, m, &cDelay_5ZfE8uQG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vm6XeiPm_sendMessage);
}

void Heavy_FourPointDelay::cDelay_vyNPPRND_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_vyNPPRND, m);
  cMsg_Z3j5opBi_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_Dy4K9bH1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_8ahjfSsC, m);
}

void Heavy_FourPointDelay::cVar_1xFEHBax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSJTL9zT, HV_BINOP_MULTIPLY, 0, m, &cBinop_NSJTL9zT_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Hi4XVQFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_QejuHFov_sendMessage);
}

void Heavy_FourPointDelay::cBinop_NSJTL9zT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_poqWCozx_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_lC6NHqbW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Aee1ppuB, HV_BINOP_DIVIDE, 0, m, &cBinop_Aee1ppuB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Aee1ppuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NSJTL9zT, HV_BINOP_MULTIPLY, 1, m, &cBinop_NSJTL9zT_sendMessage);
}

void Heavy_FourPointDelay::cMsg_VhBHVEga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gONuXQVe_sendMessage);
}

void Heavy_FourPointDelay::cSystem_gONuXQVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Aee1ppuB, HV_BINOP_DIVIDE, 1, m, &cBinop_Aee1ppuB_sendMessage);
  cMsg_Hi4XVQFo_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cUnop_QejuHFov_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_lC6NHqbW_sendMessage);
}

void Heavy_FourPointDelay::cBinop_dZWkoRlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Lvqy1WkL_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Lvqy1WkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KAb8IrnW_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RGgZ891L_sendMessage);
}

void Heavy_FourPointDelay::cBinop_RGgZ891L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xmmgLQoL, m);
}

void Heavy_FourPointDelay::cBinop_1YPfczBY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_dZWkoRlx_sendMessage);
}

void Heavy_FourPointDelay::cBinop_KAb8IrnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Dy4K9bH1_sendMessage);
}

void Heavy_FourPointDelay::cMsg_poqWCozx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_1YPfczBY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_bcrlYl2e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_flHC2h6T_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_UjzeVdJo, m);
}

void Heavy_FourPointDelay::cBinop_0tgKivqI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bcrlYl2e_sendMessage);
}

void Heavy_FourPointDelay::cBinop_kvB3X9cl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vWXoAVPZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_vWXoAVPZ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_vWXoAVPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_0tgKivqI_sendMessage);
}

void Heavy_FourPointDelay::cMsg_ZI27fz83_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_kvB3X9cl_sendMessage);
}

void Heavy_FourPointDelay::cSystem_5RH6Ti0T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZI27fz83_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_26X6PnhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_5RH6Ti0T_sendMessage);
}

void Heavy_FourPointDelay::cBinop_flHC2h6T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MlJYf3SE, m);
}

void Heavy_FourPointDelay::cVar_T4kPX42T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vWXoAVPZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_vWXoAVPZ_sendMessage);
}

void Heavy_FourPointDelay::cReceive_FclOS2TR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_qGAvfWAn, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NjWamTgd, m);
}

void Heavy_FourPointDelay::cReceive_jU5jZEC0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_k4TXKi72, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_s2ZhNE5o, m);
}

void Heavy_FourPointDelay::cMsg_auag3hlO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_JXzxbYpP_sendMessage);
}

void Heavy_FourPointDelay::cBinop_MhMYiLdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_wIq851rJ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_JXzxbYpP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MhMYiLdH, HV_BINOP_MULTIPLY, 1, m, &cBinop_MhMYiLdH_sendMessage);
}

void Heavy_FourPointDelay::cMsg_IyOH1IkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_h9x5YRjt_sendMessage);
}

void Heavy_FourPointDelay::cSystem_h9x5YRjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_auag3hlO_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_4jdjpE4y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SQuPZAME, m);
}

void Heavy_FourPointDelay::cBinop_k5mcXTq6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4jdjpE4y_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q1FuC71z, m);
}

void Heavy_FourPointDelay::cBinop_wIq851rJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_k5mcXTq6_sendMessage);
}

void Heavy_FourPointDelay::cVar_L8IeMbtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MhMYiLdH, HV_BINOP_MULTIPLY, 0, m, &cBinop_MhMYiLdH_sendMessage);
}

void Heavy_FourPointDelay::cBinop_VK4CERLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_TUBsIq9Q_sendMessage);
}

void Heavy_FourPointDelay::cMsg_dUPsPBLE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_J0gnbe1T_sendMessage);
}

void Heavy_FourPointDelay::cBinop_J0gnbe1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ATJ65TkL_sendMessage);
}

void Heavy_FourPointDelay::cBinop_XBa93xCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ep4U7JVy, m);
}

void Heavy_FourPointDelay::cBinop_ATJ65TkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_YSBJCvkJ_sendMessage);
}

void Heavy_FourPointDelay::cBinop_YSBJCvkJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_VK4CERLi_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XBa93xCW_sendMessage);
}

void Heavy_FourPointDelay::cBinop_TUBsIq9Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0YZxaRxf, m);
}

void Heavy_FourPointDelay::cMsg_R9HIljNu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_dAX425fJ_sendMessage);
}

void Heavy_FourPointDelay::cMsg_EzR0wf1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_k1166JMS_sendMessage);
}

void Heavy_FourPointDelay::cSystem_k1166JMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q8RbFUhW, HV_BINOP_DIVIDE, 1, m, &cBinop_q8RbFUhW_sendMessage);
  cMsg_R9HIljNu_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_r4dNK0ZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_q8RbFUhW, HV_BINOP_DIVIDE, 0, m, &cBinop_q8RbFUhW_sendMessage);
}

void Heavy_FourPointDelay::cUnop_dAX425fJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_r4dNK0ZA_sendMessage);
}

void Heavy_FourPointDelay::cBinop_q8RbFUhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xod0FLvd, HV_BINOP_MULTIPLY, 1, m, &cBinop_Xod0FLvd_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Xod0FLvd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dUPsPBLE_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cVar_xZoLYLfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xod0FLvd, HV_BINOP_MULTIPLY, 0, m, &cBinop_Xod0FLvd_sendMessage);
}

void Heavy_FourPointDelay::cVar_kRtmec7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CbS9coFt, HV_BINOP_MULTIPLY, 0, m, &cBinop_CbS9coFt_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Qd9kXtfZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h0Mu0Otk, m);
}

void Heavy_FourPointDelay::cBinop_CbS9coFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_nEFeTs5g_sendMessage);
}

void Heavy_FourPointDelay::cSystem_3fhxLP9A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L0mL3wtW_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_qNofqhTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3fhxLP9A_sendMessage);
}

void Heavy_FourPointDelay::cMsg_L0mL3wtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_EkgCZVOl_sendMessage);
}

void Heavy_FourPointDelay::cBinop_EkgCZVOl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CbS9coFt, HV_BINOP_MULTIPLY, 1, m, &cBinop_CbS9coFt_sendMessage);
}

void Heavy_FourPointDelay::cBinop_nEFeTs5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_w1xsyJkS_sendMessage);
}

void Heavy_FourPointDelay::cBinop_w1xsyJkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Qd9kXtfZ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WJyTO7UI, m);
}

void Heavy_FourPointDelay::cCast_CcGO3vqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DmPVtxII, 0, m, &cVar_DmPVtxII_sendMessage);
  cMsg_4HhMOjDY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mvpJuAaN, 0, m, &cTabhead_mvpJuAaN_sendMessage);
}

void Heavy_FourPointDelay::cBinop_FAuHB0kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aOS6ZHRQ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TzwpoU0A, 0, m, &sTabread_TzwpoU0A_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rsKgpQ0G_sendMessage);
}

void Heavy_FourPointDelay::cDelay_XiEaZFmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XiEaZFmT, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TzwpoU0A, 0, m, &sTabread_TzwpoU0A_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XiEaZFmT, 0, m, &cDelay_XiEaZFmT_sendMessage);
}

void Heavy_FourPointDelay::cMsg_zDaoBlk5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_vqXFoBru_sendMessage);
}

void Heavy_FourPointDelay::cDelay_PUsPBQAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PUsPBQAT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XiEaZFmT, 0, m, &cDelay_XiEaZFmT_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_TzwpoU0A, 0, m, &sTabread_TzwpoU0A_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_mvpJuAaN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FAuHB0kb, HV_BINOP_SUBTRACT, 0, m, &cBinop_FAuHB0kb_sendMessage);
}

void Heavy_FourPointDelay::cSystem_jvT8LwCx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qEAodYbl_sendMessage);
}

void Heavy_FourPointDelay::cMsg_4HhMOjDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_jvT8LwCx_sendMessage);
}

void Heavy_FourPointDelay::cVar_DmPVtxII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zDaoBlk5_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_qEAodYbl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_htrxMPUA, HV_BINOP_MULTIPLY, 0, m, &cBinop_htrxMPUA_sendMessage);
}

void Heavy_FourPointDelay::cMsg_sUQoYl2O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxINkrN3, HV_BINOP_MAX, 1, m, &cBinop_vxINkrN3_sendMessage);
}

void Heavy_FourPointDelay::cSystem_vqXFoBru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ujGOOR1I, HV_BINOP_SUBTRACT, 1, m, &cBinop_ujGOOR1I_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XiEaZFmT, 2, m, &cDelay_XiEaZFmT_sendMessage);
}

void Heavy_FourPointDelay::cCast_rsKgpQ0G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PUsPBQAT, 0, m, &cDelay_PUsPBQAT_sendMessage);
}

void Heavy_FourPointDelay::cBinop_wNRRnHem_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PUsPBQAT, 2, m, &cDelay_PUsPBQAT_sendMessage);
}

void Heavy_FourPointDelay::sTabread_TzwpoU0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ujGOOR1I, HV_BINOP_SUBTRACT, 0, m, &cBinop_ujGOOR1I_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cMsg_aOS6ZHRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PUsPBQAT, 0, m, &cDelay_PUsPBQAT_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_XiEaZFmT, 0, m, &cDelay_XiEaZFmT_sendMessage);
}

void Heavy_FourPointDelay::cBinop_ujGOOR1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_wNRRnHem_sendMessage);
}

void Heavy_FourPointDelay::cBinop_htrxMPUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vxINkrN3, HV_BINOP_MAX, 0, m, &cBinop_vxINkrN3_sendMessage);
}

void Heavy_FourPointDelay::cBinop_vxINkrN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FAuHB0kb, HV_BINOP_SUBTRACT, 1, m, &cBinop_FAuHB0kb_sendMessage);
}

void Heavy_FourPointDelay::cBinop_41zt0KxG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KGDNUNTd_sendMessage);
}

void Heavy_FourPointDelay::cBinop_rpiutubU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_41zt0KxG, HV_BINOP_MULTIPLY, 1, m, &cBinop_41zt0KxG_sendMessage);
}

void Heavy_FourPointDelay::cSystem_zHDqWsrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wzFFKbFo_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_nPPJaS94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_zHDqWsrH_sendMessage);
}

void Heavy_FourPointDelay::cMsg_wzFFKbFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_rpiutubU_sendMessage);
}

void Heavy_FourPointDelay::cBinop_xzyL5Vnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_E5QQZHOY_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hmvZWCHT, m);
}

void Heavy_FourPointDelay::cBinop_KGDNUNTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xzyL5Vnz_sendMessage);
}

void Heavy_FourPointDelay::cVar_pS28cUWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_41zt0KxG, HV_BINOP_MULTIPLY, 0, m, &cBinop_41zt0KxG_sendMessage);
}

void Heavy_FourPointDelay::cBinop_E5QQZHOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yF2shCCN, m);
}

void Heavy_FourPointDelay::cBinop_HyHrsFRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_MNPqUf0k_sendMessage);
}

void Heavy_FourPointDelay::cMsg_W1Cxw4jM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Mkkmspss_sendMessage);
}

void Heavy_FourPointDelay::cBinop_7JZPouZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_HsxVLfWX, m);
}

void Heavy_FourPointDelay::cVar_eDKUTEqv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4cwtMhAT, HV_BINOP_MULTIPLY, 0, m, &cBinop_4cwtMhAT_sendMessage);
}

void Heavy_FourPointDelay::cBinop_MNPqUf0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q8OY2Pwy, m);
}

void Heavy_FourPointDelay::cBinop_YikQlYGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_s2GpDNio_sendMessage);
}

void Heavy_FourPointDelay::cBinop_s2GpDNio_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HyHrsFRJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_7JZPouZQ_sendMessage);
}

void Heavy_FourPointDelay::cMsg_RBUCX9Mm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6608E4JM_sendMessage);
}

void Heavy_FourPointDelay::cSystem_6608E4JM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hTjPYtgl, HV_BINOP_DIVIDE, 1, m, &cBinop_hTjPYtgl_sendMessage);
  cMsg_o8rA76NT_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_4cwtMhAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W1Cxw4jM_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_o8rA76NT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_mQ28dfvG_sendMessage);
}

void Heavy_FourPointDelay::cUnop_mQ28dfvG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_8CeGikQI_sendMessage);
}

void Heavy_FourPointDelay::cBinop_hTjPYtgl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4cwtMhAT, HV_BINOP_MULTIPLY, 1, m, &cBinop_4cwtMhAT_sendMessage);
}

void Heavy_FourPointDelay::cBinop_8CeGikQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hTjPYtgl, HV_BINOP_DIVIDE, 0, m, &cBinop_hTjPYtgl_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Mkkmspss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_YikQlYGs_sendMessage);
}

void Heavy_FourPointDelay::cMsg_lEY3evRX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_wYtsomyi, 2, m, &cDelay_wYtsomyi_sendMessage);
}

void Heavy_FourPointDelay::cSystem_DLGdDzF4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_pLKVKur3_sendMessage);
}

void Heavy_FourPointDelay::cMsg_gTJABe8a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_DLGdDzF4_sendMessage);
}

void Heavy_FourPointDelay::cBinop_pLKVKur3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_QSrYhAwG_sendMessage);
}

void Heavy_FourPointDelay::cCast_rGcBF5nd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_WP5iKiTX, 0, m, &cDelay_WP5iKiTX_sendMessage);
}

void Heavy_FourPointDelay::cDelay_WP5iKiTX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_WP5iKiTX, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wYtsomyi, 0, m, &cDelay_wYtsomyi_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WP5iKiTX, 0, m, &cDelay_WP5iKiTX_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_1hwD5EJe, 1, m, NULL);
}

void Heavy_FourPointDelay::cBinop_QSrYhAwG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xaOJOXpS_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cDelay_wYtsomyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wYtsomyi, m);
  cMsg_Yb7baM8n_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_xaOJOXpS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_mF8kKd6s, 0, m, &hTable_mF8kKd6s_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Yb7baM8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_mF8kKd6s, 0, m, &hTable_mF8kKd6s_sendMessage);
}

void Heavy_FourPointDelay::hTable_mF8kKd6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lEY3evRX_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_WP5iKiTX, 2, m, &cDelay_WP5iKiTX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rGcBF5nd_sendMessage);
}

void Heavy_FourPointDelay::cSystem_NFiwY6Jr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hBOQGXC4_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_DTSReGUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NFiwY6Jr_sendMessage);
}

void Heavy_FourPointDelay::cBinop_aZzPIFn7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kiL0Onfe, HV_BINOP_MULTIPLY, 1, m, &cBinop_kiL0Onfe_sendMessage);
}

void Heavy_FourPointDelay::cBinop_kiL0Onfe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_MwpFYvkE_sendMessage);
}

void Heavy_FourPointDelay::cMsg_hBOQGXC4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_aZzPIFn7_sendMessage);
}

void Heavy_FourPointDelay::cBinop_bsI2fw5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sYGkoL2w_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_tWfaBUVP, m);
}

void Heavy_FourPointDelay::cBinop_MwpFYvkE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bsI2fw5s_sendMessage);
}

void Heavy_FourPointDelay::cVar_R0zeIQWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kiL0Onfe, HV_BINOP_MULTIPLY, 0, m, &cBinop_kiL0Onfe_sendMessage);
}

void Heavy_FourPointDelay::cBinop_sYGkoL2w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wntEjsdW, m);
}

void Heavy_FourPointDelay::sTabread_zKRg1vzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_sYLa6tJR, HV_BINOP_SUBTRACT, 0, m, &cBinop_sYLa6tJR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cDelay_J61rSkgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J61rSkgV, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zKRg1vzk, 0, m, &sTabread_zKRg1vzk_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_J61rSkgV, 0, m, &cDelay_J61rSkgV_sendMessage);
}

void Heavy_FourPointDelay::cBinop_yILQPhht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGh8oTqu, HV_BINOP_SUBTRACT, 1, m, &cBinop_oGh8oTqu_sendMessage);
}

void Heavy_FourPointDelay::cBinop_oGh8oTqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FKMnCjoZ_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zKRg1vzk, 0, m, &sTabread_zKRg1vzk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pRF5lWva_sendMessage);
}

void Heavy_FourPointDelay::cMsg_FKMnCjoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_SrDixsh7, 0, m, &cDelay_SrDixsh7_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_J61rSkgV, 0, m, &cDelay_J61rSkgV_sendMessage);
}

void Heavy_FourPointDelay::cBinop_sYLa6tJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ey3MTSBc_sendMessage);
}

void Heavy_FourPointDelay::cBinop_uUgn6P8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OGwJ0aFU, HV_BINOP_MULTIPLY, 0, m, &cBinop_OGwJ0aFU_sendMessage);
}

void Heavy_FourPointDelay::cMsg_T7xdd33r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_yILQPhht, HV_BINOP_MAX, 1, m, &cBinop_yILQPhht_sendMessage);
}

void Heavy_FourPointDelay::cCast_pRF5lWva_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SrDixsh7, 0, m, &cDelay_SrDixsh7_sendMessage);
}

void Heavy_FourPointDelay::cDelay_SrDixsh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_SrDixsh7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_J61rSkgV, 0, m, &cDelay_J61rSkgV_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_zKRg1vzk, 0, m, &sTabread_zKRg1vzk_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_lQsAq9zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oGh8oTqu, HV_BINOP_SUBTRACT, 0, m, &cBinop_oGh8oTqu_sendMessage);
}

void Heavy_FourPointDelay::cMsg_UZQXKAI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IqyGi3aQ_sendMessage);
}

void Heavy_FourPointDelay::cSystem_IqyGi3aQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_uUgn6P8v_sendMessage);
}

void Heavy_FourPointDelay::cVar_k6spZMyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ajEfU7JN_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_ey3MTSBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_SrDixsh7, 2, m, &cDelay_SrDixsh7_sendMessage);
}

void Heavy_FourPointDelay::cMsg_ajEfU7JN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JkyvjqZN_sendMessage);
}

void Heavy_FourPointDelay::cBinop_OGwJ0aFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yILQPhht, HV_BINOP_MAX, 0, m, &cBinop_yILQPhht_sendMessage);
}

void Heavy_FourPointDelay::cCast_tJUiQuHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k6spZMyh, 0, m, &cVar_k6spZMyh_sendMessage);
  cMsg_UZQXKAI0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lQsAq9zw, 0, m, &cTabhead_lQsAq9zw_sendMessage);
}

void Heavy_FourPointDelay::cSystem_JkyvjqZN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sYLa6tJR, HV_BINOP_SUBTRACT, 1, m, &cBinop_sYLa6tJR_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_J61rSkgV, 2, m, &cDelay_J61rSkgV_sendMessage);
}

void Heavy_FourPointDelay::cBinop_NsNdI495_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_jsMfcp4T_sendMessage);
}

void Heavy_FourPointDelay::cMsg_NJeQsa61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_NsNdI495_sendMessage);
}

void Heavy_FourPointDelay::cBinop_kiIynGxx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_lmAFaxAu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_w8cNz0lE_sendMessage);
}

void Heavy_FourPointDelay::cBinop_jsMfcp4T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kiIynGxx_sendMessage);
}

void Heavy_FourPointDelay::cVar_O9rQUjPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uMJNoFME, HV_BINOP_MULTIPLY, 0, m, &cBinop_uMJNoFME_sendMessage);
}

void Heavy_FourPointDelay::cBinop_I3YMTr1u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HgohTVdt, HV_BINOP_DIVIDE, 0, m, &cBinop_HgohTVdt_sendMessage);
}

void Heavy_FourPointDelay::cBinop_uMJNoFME_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NJeQsa61_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_HgohTVdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uMJNoFME, HV_BINOP_MULTIPLY, 1, m, &cBinop_uMJNoFME_sendMessage);
}

void Heavy_FourPointDelay::cMsg_MZ2V6ATO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hvYLWN8X_sendMessage);
}

void Heavy_FourPointDelay::cSystem_hvYLWN8X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HgohTVdt, HV_BINOP_DIVIDE, 1, m, &cBinop_HgohTVdt_sendMessage);
  cMsg_722L6GFa_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_722L6GFa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_9ZcqsKU1_sendMessage);
}

void Heavy_FourPointDelay::cUnop_9ZcqsKU1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_I3YMTr1u_sendMessage);
}

void Heavy_FourPointDelay::cBinop_BkoZ7aae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_iiGV3lku, m);
}

void Heavy_FourPointDelay::cBinop_lmAFaxAu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_BkoZ7aae_sendMessage);
}

void Heavy_FourPointDelay::cBinop_w8cNz0lE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BAQYFNHd, m);
}

void Heavy_FourPointDelay::cBinop_n9ha9koK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_VA05wjpL_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Kf5jFoof_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Q0AYXQmj_sendMessage);
}

void Heavy_FourPointDelay::cBinop_By6jcfu4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wBQfIboz, m);
}

void Heavy_FourPointDelay::cBinop_VA05wjpL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ADbFej9x, m);
}

void Heavy_FourPointDelay::cBinop_Q0AYXQmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lD7f4hH7_sendMessage);
}

void Heavy_FourPointDelay::cVar_iFOLStnK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wSfxQBMm, HV_BINOP_MULTIPLY, 0, m, &cBinop_wSfxQBMm_sendMessage);
}

void Heavy_FourPointDelay::cBinop_lD7f4hH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Tvd0Y02q_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Tvd0Y02q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_n9ha9koK_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_By6jcfu4_sendMessage);
}

void Heavy_FourPointDelay::cMsg_b38sfLRP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Buixwfn3_sendMessage);
}

void Heavy_FourPointDelay::cSystem_Buixwfn3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1JChjE64, HV_BINOP_DIVIDE, 1, m, &cBinop_1JChjE64_sendMessage);
  cMsg_9EgIrJMX_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cUnop_MBXCvVgW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_5ItsrHsM_sendMessage);
}

void Heavy_FourPointDelay::cMsg_9EgIrJMX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_MBXCvVgW_sendMessage);
}

void Heavy_FourPointDelay::cBinop_wSfxQBMm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Kf5jFoof_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_5ItsrHsM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1JChjE64, HV_BINOP_DIVIDE, 0, m, &cBinop_1JChjE64_sendMessage);
}

void Heavy_FourPointDelay::cBinop_1JChjE64_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wSfxQBMm, HV_BINOP_MULTIPLY, 1, m, &cBinop_wSfxQBMm_sendMessage);
}

void Heavy_FourPointDelay::cMsg_7Le2cV8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_UqOprwv3_sendMessage);
}

void Heavy_FourPointDelay::cMsg_g3kANJ77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_O6mCoLrX_sendMessage);
}

void Heavy_FourPointDelay::cSystem_O6mCoLrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LuBBZr1i_sendMessage);
}

void Heavy_FourPointDelay::sTabread_3juhxaOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_hMcDcid5, HV_BINOP_SUBTRACT, 0, m, &cBinop_hMcDcid5_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cVar_QfgtRGmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7Le2cV8K_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_BWRtRgXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XIYWlf2D, 2, m, &cDelay_XIYWlf2D_sendMessage);
}

void Heavy_FourPointDelay::cBinop_LuBBZr1i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iGUZL5Sv, HV_BINOP_MULTIPLY, 0, m, &cBinop_iGUZL5Sv_sendMessage);
}

void Heavy_FourPointDelay::cBinop_hMcDcid5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BWRtRgXh_sendMessage);
}

void Heavy_FourPointDelay::cCast_U3vEEbyB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_XIYWlf2D, 0, m, &cDelay_XIYWlf2D_sendMessage);
}

void Heavy_FourPointDelay::cCast_ZyBd7Wb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QfgtRGmo, 0, m, &cVar_QfgtRGmo_sendMessage);
  cMsg_g3kANJ77_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8Y8TFryn, 0, m, &cTabhead_8Y8TFryn_sendMessage);
}

void Heavy_FourPointDelay::cTabhead_8Y8TFryn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c0rNLeiO, HV_BINOP_SUBTRACT, 0, m, &cBinop_c0rNLeiO_sendMessage);
}

void Heavy_FourPointDelay::cSystem_UqOprwv3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hMcDcid5, HV_BINOP_SUBTRACT, 1, m, &cBinop_hMcDcid5_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCgSttXM, 2, m, &cDelay_wCgSttXM_sendMessage);
}

void Heavy_FourPointDelay::cMsg_qWHC2geU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_XIYWlf2D, 0, m, &cDelay_XIYWlf2D_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCgSttXM, 0, m, &cDelay_wCgSttXM_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Bg801iiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_c0rNLeiO, HV_BINOP_SUBTRACT, 1, m, &cBinop_c0rNLeiO_sendMessage);
}

void Heavy_FourPointDelay::cBinop_iGUZL5Sv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bg801iiP, HV_BINOP_MAX, 0, m, &cBinop_Bg801iiP_sendMessage);
}

void Heavy_FourPointDelay::cMsg_SPblYGu5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_Bg801iiP, HV_BINOP_MAX, 1, m, &cBinop_Bg801iiP_sendMessage);
}

void Heavy_FourPointDelay::cDelay_XIYWlf2D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_XIYWlf2D, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCgSttXM, 0, m, &cDelay_wCgSttXM_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3juhxaOr, 0, m, &sTabread_3juhxaOr_sendMessage);
}

void Heavy_FourPointDelay::cBinop_c0rNLeiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qWHC2geU_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3juhxaOr, 0, m, &sTabread_3juhxaOr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_U3vEEbyB_sendMessage);
}

void Heavy_FourPointDelay::cDelay_wCgSttXM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_wCgSttXM, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3juhxaOr, 0, m, &sTabread_3juhxaOr_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_wCgSttXM, 0, m, &cDelay_wCgSttXM_sendMessage);
}

void Heavy_FourPointDelay::cBinop_cmAz1Nwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_StIyfqKJ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BIt4fwxB_sendMessage);
}

void Heavy_FourPointDelay::cBinop_roNWT6P6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_cmAz1Nwl_sendMessage);
}

void Heavy_FourPointDelay::cBinop_BIt4fwxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wuIzaLUT, m);
}

void Heavy_FourPointDelay::cVar_x820zk5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3mGtNMNd, HV_BINOP_MULTIPLY, 0, m, &cBinop_3mGtNMNd_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Cfp3ZfTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_roNWT6P6_sendMessage);
}

void Heavy_FourPointDelay::cBinop_3mGtNMNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Cju1Gmno_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_o5J9Krbb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3mGtNMNd, HV_BINOP_MULTIPLY, 1, m, &cBinop_3mGtNMNd_sendMessage);
}

void Heavy_FourPointDelay::cMsg_hjueflVU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_59B1XioG_sendMessage);
}

void Heavy_FourPointDelay::cSystem_59B1XioG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o5J9Krbb, HV_BINOP_DIVIDE, 1, m, &cBinop_o5J9Krbb_sendMessage);
  cMsg_OxsJZwuV_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cUnop_lyIbhbtE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_fXOd3l9h_sendMessage);
}

void Heavy_FourPointDelay::cBinop_fXOd3l9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_o5J9Krbb, HV_BINOP_DIVIDE, 0, m, &cBinop_o5J9Krbb_sendMessage);
}

void Heavy_FourPointDelay::cMsg_OxsJZwuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_lyIbhbtE_sendMessage);
}

void Heavy_FourPointDelay::cBinop_StIyfqKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_iBp8yW18_sendMessage);
}

void Heavy_FourPointDelay::cBinop_iBp8yW18_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_muSgF83r, m);
}

void Heavy_FourPointDelay::cMsg_Cju1Gmno_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Cfp3ZfTR_sendMessage);
}

void Heavy_FourPointDelay::cVar_iOzj3DQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4cvooVTj, HV_BINOP_MULTIPLY, 0, m, &cBinop_4cvooVTj_sendMessage);
}

void Heavy_FourPointDelay::cBinop_D6f2xEDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_NPHf93WY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_NPHf93WY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_FFT4tqNM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_4PZJbPTw_sendMessage);
}

void Heavy_FourPointDelay::cBinop_FFT4tqNM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_S4iCfCfx_sendMessage);
}

void Heavy_FourPointDelay::cBinop_n2v6QB5f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_D6f2xEDO_sendMessage);
}

void Heavy_FourPointDelay::cBinop_S4iCfCfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ied3wZPo, m);
}

void Heavy_FourPointDelay::cMsg_5Caw9AY4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CpvFAPai_sendMessage);
}

void Heavy_FourPointDelay::cSystem_CpvFAPai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l73Go3d5, HV_BINOP_DIVIDE, 1, m, &cBinop_l73Go3d5_sendMessage);
  cMsg_lqIBJrLh_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cUnop_IOVrF76V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_G7cNwO7x_sendMessage);
}

void Heavy_FourPointDelay::cBinop_l73Go3d5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4cvooVTj, HV_BINOP_MULTIPLY, 1, m, &cBinop_4cvooVTj_sendMessage);
}

void Heavy_FourPointDelay::cMsg_lqIBJrLh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_IOVrF76V_sendMessage);
}

void Heavy_FourPointDelay::cBinop_G7cNwO7x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l73Go3d5, HV_BINOP_DIVIDE, 0, m, &cBinop_l73Go3d5_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4cvooVTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ZU39qqiM_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_ZU39qqiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_n2v6QB5f_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4PZJbPTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_3zCdI0dE, m);
}

void Heavy_FourPointDelay::cBinop_uOSQSbNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_RNgkevKj, m);
}

void Heavy_FourPointDelay::cVar_cYGFBKJl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SCjdaW0C, HV_BINOP_MULTIPLY, 0, m, &cBinop_SCjdaW0C_sendMessage);
}

void Heavy_FourPointDelay::cSystem_f4GIPghY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bcLK4V4G_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_M8yByORl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_f4GIPghY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4S0MTOcL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SCjdaW0C, HV_BINOP_MULTIPLY, 1, m, &cBinop_SCjdaW0C_sendMessage);
}

void Heavy_FourPointDelay::cBinop_SCjdaW0C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Lful1H4U_sendMessage);
}

void Heavy_FourPointDelay::cMsg_bcLK4V4G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4S0MTOcL_sendMessage);
}

void Heavy_FourPointDelay::cBinop_E0IOTs3g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uOSQSbNE_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_z2KcLVJB, m);
}

void Heavy_FourPointDelay::cBinop_Lful1H4U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_E0IOTs3g_sendMessage);
}

void Heavy_FourPointDelay::cBinop_o7YCBxmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PMS1iv9E, m);
}

void Heavy_FourPointDelay::cMsg_8OoVH7zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yZrCrP6f_sendMessage);
}

void Heavy_FourPointDelay::cSystem_yZrCrP6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4SmEAPOP_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_w9vt0lH7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4T9VgUBr, HV_BINOP_MULTIPLY, 1, m, &cBinop_4T9VgUBr_sendMessage);
}

void Heavy_FourPointDelay::cMsg_4SmEAPOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_w9vt0lH7_sendMessage);
}

void Heavy_FourPointDelay::cBinop_4T9VgUBr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_n8MT5c3a_sendMessage);
}

void Heavy_FourPointDelay::cBinop_n8MT5c3a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UogU5IZF_sendMessage);
}

void Heavy_FourPointDelay::cBinop_UogU5IZF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_o7YCBxmV_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_bbXb0eCS, m);
}

void Heavy_FourPointDelay::cVar_KWXnR5GT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4T9VgUBr, HV_BINOP_MULTIPLY, 0, m, &cBinop_4T9VgUBr_sendMessage);
}

void Heavy_FourPointDelay::cBinop_atBm1jgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oljs6H1c, HV_BINOP_MULTIPLY, 1, m, &cBinop_oljs6H1c_sendMessage);
}

void Heavy_FourPointDelay::cMsg_aG3kp6t1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_atBm1jgF_sendMessage);
}

void Heavy_FourPointDelay::cBinop_oljs6H1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AgiNJvyw_sendMessage);
}

void Heavy_FourPointDelay::cSystem_mu9bCGpG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aG3kp6t1_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_CB4zzk1v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mu9bCGpG_sendMessage);
}

void Heavy_FourPointDelay::cBinop_inXwlZjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CFbKekWm_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lBao26Hz, m);
}

void Heavy_FourPointDelay::cBinop_AgiNJvyw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_inXwlZjy_sendMessage);
}

void Heavy_FourPointDelay::cVar_Xg6tMOXL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oljs6H1c, HV_BINOP_MULTIPLY, 0, m, &cBinop_oljs6H1c_sendMessage);
}

void Heavy_FourPointDelay::cBinop_CFbKekWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_AC5vakgn, m);
}

void Heavy_FourPointDelay::hTable_MAtR0uMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LnpC899Y_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pn87nQdq, 2, m, &cDelay_pn87nQdq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dXKUDhmx_sendMessage);
}

void Heavy_FourPointDelay::cMsg_7ihv7tQ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_MAtR0uMN, 0, m, &hTable_MAtR0uMN_sendMessage);
}

void Heavy_FourPointDelay::cDelay_pn87nQdq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pn87nQdq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_LnDG4lTD, 0, m, &cDelay_LnDG4lTD_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pn87nQdq, 0, m, &cDelay_pn87nQdq_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_5bBPMslL, 1, m, NULL);
}

void Heavy_FourPointDelay::cBinop_0vfv9LDL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7ihv7tQ8_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_LnpC899Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_LnDG4lTD, 2, m, &cDelay_LnDG4lTD_sendMessage);
}

void Heavy_FourPointDelay::cMsg_Ngcv0ori_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BmBgHBKn_sendMessage);
}

void Heavy_FourPointDelay::cSystem_BmBgHBKn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_GaVE4KUz_sendMessage);
}

void Heavy_FourPointDelay::cMsg_rThkn3DX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_MAtR0uMN, 0, m, &hTable_MAtR0uMN_sendMessage);
}

void Heavy_FourPointDelay::cCast_dXKUDhmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pn87nQdq, 0, m, &cDelay_pn87nQdq_sendMessage);
}

void Heavy_FourPointDelay::cDelay_LnDG4lTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_LnDG4lTD, m);
  cMsg_rThkn3DX_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_GaVE4KUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_0vfv9LDL_sendMessage);
}

void Heavy_FourPointDelay::cMsg_qaDTg2so_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NtRm4Wh1_sendMessage);
}

void Heavy_FourPointDelay::cSystem_NtRm4Wh1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_nIFnojsF_sendMessage);
}

void Heavy_FourPointDelay::cMsg_mlyYKalG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_yBLVO9sc_sendMessage);
}

void Heavy_FourPointDelay::cMsg_FdItVN2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cBinop_onMessage(_c, &Context(_c)->cBinop_dLOtAXm1, HV_BINOP_MAX, 1, m, &cBinop_dLOtAXm1_sendMessage);
}

void Heavy_FourPointDelay::cVar_AusJ3DLY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mlyYKalG_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cTabhead_VlSl8OZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LmjH6dMY, HV_BINOP_SUBTRACT, 0, m, &cBinop_LmjH6dMY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_LmjH6dMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RglOuTxq_sendMessage(_c, 0, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3JW8lI6g, 0, m, &sTabread_3JW8lI6g_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YQ4V3zNB_sendMessage);
}

void Heavy_FourPointDelay::cSystem_yBLVO9sc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GusbIrAX, HV_BINOP_SUBTRACT, 1, m, &cBinop_GusbIrAX_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pkarhCwq, 2, m, &cDelay_pkarhCwq_sendMessage);
}

void Heavy_FourPointDelay::sTabread_3JW8lI6g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_GusbIrAX, HV_BINOP_SUBTRACT, 0, m, &cBinop_GusbIrAX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_FourPointDelay::cBinop_nIFnojsF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u1Lv98Sz, HV_BINOP_MULTIPLY, 0, m, &cBinop_u1Lv98Sz_sendMessage);
}

void Heavy_FourPointDelay::cCast_gM0DxMAU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AusJ3DLY, 0, m, &cVar_AusJ3DLY_sendMessage);
  cMsg_qaDTg2so_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VlSl8OZR, 0, m, &cTabhead_VlSl8OZR_sendMessage);
}

void Heavy_FourPointDelay::cDelay_6p4HlBZ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_6p4HlBZ9, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pkarhCwq, 0, m, &cDelay_pkarhCwq_sendMessage);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3JW8lI6g, 0, m, &sTabread_3JW8lI6g_sendMessage);
}

void Heavy_FourPointDelay::cBinop_GusbIrAX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_EmZ2tF2z_sendMessage);
}

void Heavy_FourPointDelay::cBinop_u1Lv98Sz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dLOtAXm1, HV_BINOP_MAX, 0, m, &cBinop_dLOtAXm1_sendMessage);
}

void Heavy_FourPointDelay::cDelay_pkarhCwq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pkarhCwq, m);
  sTabread_onMessage(_c, &Context(_c)->sTabread_3JW8lI6g, 0, m, &sTabread_3JW8lI6g_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pkarhCwq, 0, m, &cDelay_pkarhCwq_sendMessage);
}

void Heavy_FourPointDelay::cBinop_dLOtAXm1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LmjH6dMY, HV_BINOP_SUBTRACT, 1, m, &cBinop_LmjH6dMY_sendMessage);
}

void Heavy_FourPointDelay::cCast_YQ4V3zNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6p4HlBZ9, 0, m, &cDelay_6p4HlBZ9_sendMessage);
}

void Heavy_FourPointDelay::cMsg_RglOuTxq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_6p4HlBZ9, 0, m, &cDelay_6p4HlBZ9_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pkarhCwq, 0, m, &cDelay_pkarhCwq_sendMessage);
}

void Heavy_FourPointDelay::cBinop_EmZ2tF2z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_6p4HlBZ9, 2, m, &cDelay_6p4HlBZ9_sendMessage);
}

void Heavy_FourPointDelay::cDelay_y3BNyf2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_y3BNyf2i, m);
  cMsg_lBAfG0Wy_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_0JrcCtXv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_y3BNyf2i, 2, m, &cDelay_y3BNyf2i_sendMessage);
}

void Heavy_FourPointDelay::hTable_WzANuIJk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0JrcCtXv_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PtPQ2Ro, 2, m, &cDelay_9PtPQ2Ro_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_u4pxLYoX_sendMessage);
}

void Heavy_FourPointDelay::cBinop_jJUUTTbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_NNvrMW2r_sendMessage);
}

void Heavy_FourPointDelay::cSystem_0D8Akw4N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jJUUTTbm_sendMessage);
}

void Heavy_FourPointDelay::cMsg_lSDvHTgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0D8Akw4N_sendMessage);
}

void Heavy_FourPointDelay::cCast_u4pxLYoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PtPQ2Ro, 0, m, &cDelay_9PtPQ2Ro_sendMessage);
}

void Heavy_FourPointDelay::cBinop_NNvrMW2r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_33Vu7s3X_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cDelay_9PtPQ2Ro_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9PtPQ2Ro, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_y3BNyf2i, 0, m, &cDelay_y3BNyf2i_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9PtPQ2Ro, 0, m, &cDelay_9PtPQ2Ro_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_UnfirIcJ, 1, m, NULL);
}

void Heavy_FourPointDelay::cMsg_lBAfG0Wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_WzANuIJk, 0, m, &hTable_WzANuIJk_sendMessage);
}

void Heavy_FourPointDelay::cMsg_33Vu7s3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_WzANuIJk, 0, m, &hTable_WzANuIJk_sendMessage);
}

void Heavy_FourPointDelay::cVar_oAwyxlop_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qSe6krMG, HV_BINOP_MULTIPLY, 0, m, &cBinop_qSe6krMG_sendMessage);
}

void Heavy_FourPointDelay::cBinop_DisErO7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OPh0S5Kb_sendMessage);
}

void Heavy_FourPointDelay::cBinop_OPh0S5Kb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_N3fbr6Pe_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_c6x9p2qe, m);
}

void Heavy_FourPointDelay::cMsg_GplO5mWE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ToKFr3Hn_sendMessage);
}

void Heavy_FourPointDelay::cSystem_ToKFr3Hn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wsuno0Yx_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cBinop_eoWf6X5R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qSe6krMG, HV_BINOP_MULTIPLY, 1, m, &cBinop_qSe6krMG_sendMessage);
}

void Heavy_FourPointDelay::cBinop_qSe6krMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DisErO7p_sendMessage);
}

void Heavy_FourPointDelay::cMsg_wsuno0Yx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_eoWf6X5R_sendMessage);
}

void Heavy_FourPointDelay::cBinop_N3fbr6Pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rC7JHJDw, m);
}

void Heavy_FourPointDelay::cMsg_POSv5SE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_misQBCyf, 2, m, &cDelay_misQBCyf_sendMessage);
}

void Heavy_FourPointDelay::cCast_o6mX44M4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FyENiaYA, 0, m, &cDelay_FyENiaYA_sendMessage);
}

void Heavy_FourPointDelay::cDelay_misQBCyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_misQBCyf, m);
  cMsg_xrcb4gk4_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_xrcb4gk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_6w65nCNQ, 0, m, &hTable_6w65nCNQ_sendMessage);
}

void Heavy_FourPointDelay::cDelay_FyENiaYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FyENiaYA, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_misQBCyf, 0, m, &cDelay_misQBCyf_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FyENiaYA, 0, m, &cDelay_FyENiaYA_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_z79K5GKw, 1, m, NULL);
}

void Heavy_FourPointDelay::cMsg_JsboMAHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_6w65nCNQ, 0, m, &hTable_6w65nCNQ_sendMessage);
}

void Heavy_FourPointDelay::cSystem_mODXlSSU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Z7UPTsbN_sendMessage);
}

void Heavy_FourPointDelay::cMsg_VlUXDoyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mODXlSSU_sendMessage);
}

void Heavy_FourPointDelay::cBinop_rOKKTwE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JsboMAHm_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::hTable_6w65nCNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_POSv5SE7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FyENiaYA, 2, m, &cDelay_FyENiaYA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_o6mX44M4_sendMessage);
}

void Heavy_FourPointDelay::cBinop_Z7UPTsbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_rOKKTwE1_sendMessage);
}

void Heavy_FourPointDelay::cBinop_JPAZmUfR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_kDulTmEI_sendMessage);
}

void Heavy_FourPointDelay::cBinop_zU6GSL2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_ASQ9XyN8_sendMessage);
}

void Heavy_FourPointDelay::cBinop_DStlXiI7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xfxyDFX5, m);
}

void Heavy_FourPointDelay::cVar_nRLdOSPP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5MsCqrcH, HV_BINOP_MULTIPLY, 0, m, &cBinop_5MsCqrcH_sendMessage);
}

void Heavy_FourPointDelay::cUnop_wM7MoYAl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_XC987M7h_sendMessage);
}

void Heavy_FourPointDelay::cSystem_X2R0afiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z1E8xoRV, HV_BINOP_DIVIDE, 1, m, &cBinop_z1E8xoRV_sendMessage);
  cMsg_Zjy8AlXh_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_FuaZZdCH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X2R0afiE_sendMessage);
}

void Heavy_FourPointDelay::cBinop_5MsCqrcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_siLJ4egJ_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_Zjy8AlXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_wM7MoYAl_sendMessage);
}

void Heavy_FourPointDelay::cBinop_z1E8xoRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5MsCqrcH, HV_BINOP_MULTIPLY, 1, m, &cBinop_5MsCqrcH_sendMessage);
}

void Heavy_FourPointDelay::cBinop_XC987M7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_z1E8xoRV, HV_BINOP_DIVIDE, 0, m, &cBinop_z1E8xoRV_sendMessage);
}

void Heavy_FourPointDelay::cMsg_siLJ4egJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_JPAZmUfR_sendMessage);
}

void Heavy_FourPointDelay::cBinop_ASQ9XyN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MYBSk5PR, m);
}

void Heavy_FourPointDelay::cBinop_GXZKlN0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_zU6GSL2A_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_DStlXiI7_sendMessage);
}

void Heavy_FourPointDelay::cBinop_kDulTmEI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GXZKlN0l_sendMessage);
}

void Heavy_FourPointDelay::cBinop_iFA8u9qk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_wWLj5vym_sendMessage);
}

void Heavy_FourPointDelay::cBinop_wWLj5vym_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wUbnLsX9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_fHjG8eq4_sendMessage);
}

void Heavy_FourPointDelay::cBinop_tKpo6VKe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_QDh1Ip88, m);
}

void Heavy_FourPointDelay::cMsg_9ZrSbDEO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_tuzXwb5d_sendMessage);
}

void Heavy_FourPointDelay::cVar_hdCf90mK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rarWEnSY, HV_BINOP_MULTIPLY, 0, m, &cBinop_rarWEnSY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_tuzXwb5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_iFA8u9qk_sendMessage);
}

void Heavy_FourPointDelay::cBinop_wUbnLsX9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_tKpo6VKe_sendMessage);
}

void Heavy_FourPointDelay::cBinop_fHjG8eq4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_M2KLtQSW, m);
}

void Heavy_FourPointDelay::cMsg_Af5DR0U0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_mtF3oFhp_sendMessage);
}

void Heavy_FourPointDelay::cBinop_3LEsia1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mBzwumgF, HV_BINOP_DIVIDE, 0, m, &cBinop_mBzwumgF_sendMessage);
}

void Heavy_FourPointDelay::cBinop_mBzwumgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rarWEnSY, HV_BINOP_MULTIPLY, 1, m, &cBinop_rarWEnSY_sendMessage);
}

void Heavy_FourPointDelay::cBinop_rarWEnSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_9ZrSbDEO_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cUnop_mtF3oFhp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_3LEsia1L_sendMessage);
}

void Heavy_FourPointDelay::cSystem_Ubl1hqWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mBzwumgF, HV_BINOP_DIVIDE, 1, m, &cBinop_mBzwumgF_sendMessage);
  cMsg_Af5DR0U0_sendMessage(_c, 0, m);
}

void Heavy_FourPointDelay::cMsg_4FD1DA1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ubl1hqWi_sendMessage);
}

void Heavy_FourPointDelay::cReceive_WlRdU2qY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8OoVH7zw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KWXnR5GT, 0, m, &cVar_KWXnR5GT_sendMessage);
  cMsg_DTSReGUM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_R0zeIQWC, 0, m, &cVar_R0zeIQWC_sendMessage);
  cMsg_FuaZZdCH_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_nRLdOSPP, 0, m, &cVar_nRLdOSPP_sendMessage);
  cMsg_RBUCX9Mm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eDKUTEqv, 0, m, &cVar_eDKUTEqv_sendMessage);
  cMsg_M8yByORl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cYGFBKJl, 0, m, &cVar_cYGFBKJl_sendMessage);
  cMsg_GplO5mWE_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_oAwyxlop, 0, m, &cVar_oAwyxlop_sendMessage);
  cMsg_5Caw9AY4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iOzj3DQ7, 0, m, &cVar_iOzj3DQ7_sendMessage);
  cMsg_MZ2V6ATO_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_O9rQUjPA, 0, m, &cVar_O9rQUjPA_sendMessage);
  cMsg_IyOH1IkC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_L8IeMbtY, 0, m, &cVar_L8IeMbtY_sendMessage);
  cMsg_nPPJaS94_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pS28cUWI, 0, m, &cVar_pS28cUWI_sendMessage);
  cMsg_hjueflVU_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_x820zk5s, 0, m, &cVar_x820zk5s_sendMessage);
  cMsg_b38sfLRP_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iFOLStnK, 0, m, &cVar_iFOLStnK_sendMessage);
  cMsg_qNofqhTj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_kRtmec7K, 0, m, &cVar_kRtmec7K_sendMessage);
  cMsg_CB4zzk1v_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Xg6tMOXL, 0, m, &cVar_Xg6tMOXL_sendMessage);
  cMsg_EzR0wf1i_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xZoLYLfZ, 0, m, &cVar_xZoLYLfZ_sendMessage);
  cMsg_4FD1DA1Y_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hdCf90mK, 0, m, &cVar_hdCf90mK_sendMessage);
  cMsg_VlUXDoyr_sendMessage(_c, 0, m);
  cMsg_lSDvHTgZ_sendMessage(_c, 0, m);
  cMsg_Ngcv0ori_sendMessage(_c, 0, m);
  cMsg_gTJABe8a_sendMessage(_c, 0, m);
  cMsg_vUfCvowe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_n097wKv9, 0, m, &cVar_n097wKv9_sendMessage);
  cMsg_26X6PnhJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_T4kPX42T, 0, m, &cVar_T4kPX42T_sendMessage);
  cMsg_ul0G0LnR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ulKdRyYG, 0, m, &cVar_ulKdRyYG_sendMessage);
  cMsg_0pUC1bd6_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YlGbMeLo, 0, m, &cVar_YlGbMeLo_sendMessage);
  cMsg_SWot9rGF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BQVFIQgx, 0, m, &cVar_BQVFIQgx_sendMessage);
  cMsg_DT9DDGPC_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YH8xXBAK, 0, m, &cVar_YH8xXBAK_sendMessage);
  cMsg_2oE6zIFZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ySDtUde9, 0, m, &cVar_ySDtUde9_sendMessage);
  cMsg_xpT7Vj7U_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MaBUDMon, 0, m, &cVar_MaBUDMon_sendMessage);
  cMsg_imiOdjmo_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mGaudv4N, 0, m, &cVar_mGaudv4N_sendMessage);
  cMsg_jKDYYrI5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bdc53X4y, 0, m, &cVar_bdc53X4y_sendMessage);
  cMsg_VhBHVEga_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1xFEHBax, 0, m, &cVar_1xFEHBax_sendMessage);
  cMsg_lNKpXDyB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pEDDYb1R, 0, m, &cVar_pEDDYb1R_sendMessage);
  cMsg_2uo0nIV4_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yeQ1voel, 0, m, &cVar_yeQ1voel_sendMessage);
  cMsg_lPHDoFLA_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LNBSlOKc, 0, m, &cVar_LNBSlOKc_sendMessage);
  cMsg_ZJPrtuQi_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_6QYRuIyf, 0, m, &cVar_6QYRuIyf_sendMessage);
  cMsg_jsc6WzvJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_5NbEMODr, 0, m, &cVar_5NbEMODr_sendMessage);
  cMsg_PlShWRFQ_sendMessage(_c, 0, m);
  cMsg_jAjQKJLm_sendMessage(_c, 0, m);
  cMsg_Qkz7zoCz_sendMessage(_c, 0, m);
  cMsg_j5wmEXY4_sendMessage(_c, 0, m);
  cMsg_T7xdd33r_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_k6spZMyh, 0, m, &cVar_k6spZMyh_sendMessage);
  cMsg_UZQXKAI0_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_lQsAq9zw, 0, m, &cTabhead_lQsAq9zw_sendMessage);
  cMsg_FdItVN2k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AusJ3DLY, 0, m, &cVar_AusJ3DLY_sendMessage);
  cMsg_qaDTg2so_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_VlSl8OZR, 0, m, &cTabhead_VlSl8OZR_sendMessage);
  cMsg_SPblYGu5_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QfgtRGmo, 0, m, &cVar_QfgtRGmo_sendMessage);
  cMsg_g3kANJ77_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_8Y8TFryn, 0, m, &cTabhead_8Y8TFryn_sendMessage);
  cMsg_sUQoYl2O_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_DmPVtxII, 0, m, &cVar_DmPVtxII_sendMessage);
  cMsg_4HhMOjDY_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_mvpJuAaN, 0, m, &cTabhead_mvpJuAaN_sendMessage);
  cMsg_Kq8y9kHr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_W1l3IdNt, 0, m, &cVar_W1l3IdNt_sendMessage);
  cMsg_hyYaRkKM_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_L833PIYM, 0, m, &cTabhead_L833PIYM_sendMessage);
  cMsg_xlFEQ4qF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_24KBTlEa, 0, m, &cVar_24KBTlEa_sendMessage);
  cMsg_PELxfkAk_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_QYtQyXyt, 0, m, &cTabhead_QYtQyXyt_sendMessage);
  cMsg_hG0VG47i_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QpvQnXjU, 0, m, &cVar_QpvQnXjU_sendMessage);
  cMsg_5Pfr0qVr_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_opE0dtuL, 0, m, &cTabhead_opE0dtuL_sendMessage);
  cMsg_tJjl5sIe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_O1QyEYjN, 0, m, &cVar_O1QyEYjN_sendMessage);
  cMsg_czeqsrWv_sendMessage(_c, 0, m);
  cTabhead_onMessage(_c, &Context(_c)->cTabhead_qX0yovRY, 0, m, &cTabhead_qX0yovRY_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_FourPointDelay::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9;

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
    __hv_varread_f(&sVarf_fofyc2LC, VOf(Bf0));
    __hv_tabread_f(&sTabread_a2LgDYTc, VOf(Bf1));
    __hv_varread_f(&sVarf_pKq1Hsw6, VOf(Bf2));
    __hv_varread_f(&sVarf_TboFzg5Z, VOf(Bf3));
    __hv_mul_f(VIf(I1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Xzjw74kC, VOf(Bf4));
    __hv_rpole_f(&sRPole_UBsurWGr, VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_hbPtLKFX, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_5bGcG39A, VOf(Bf4));
    __hv_rpole_f(&sRPole_VKUfYP6m, VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_VwYkcQ4r, VOf(Bf3));
    __hv_rpole_f(&sRPole_4k9fbaH7, VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Kw3Fsl4N, VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_SyXgHt5p, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_VF0439iW, VOf(Bf4));
    __hv_rpole_f(&sRPole_ZD0u1Wu9, VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_3KwxjCYG, VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_OQPTZQHY, VOf(Bf4));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_tabwrite_f(&sTabwrite_TsdC26oq, VIf(Bf4));
    __hv_tabread_f(&sTabread_AuTAmAp8, VOf(Bf4));
    __hv_varread_f(&sVarf_zhg6RBt6, VOf(Bf2));
    __hv_varread_f(&sVarf_cXVvrOHR, VOf(Bf3));
    __hv_mul_f(VIf(I1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_nadW8d7Y, VOf(Bf5));
    __hv_rpole_f(&sRPole_T50XDFGh, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_UjzeVdJo, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_MlJYf3SE, VOf(Bf5));
    __hv_rpole_f(&sRPole_zoJUTz7W, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_FRe54Gnj, VOf(Bf3));
    __hv_rpole_f(&sRPole_dp7fsKAx, VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_nejanQ8j, VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_X7UHm64o, VOf(Bf3));
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_FdQuW9Po, VOf(Bf5));
    __hv_rpole_f(&sRPole_T2D06U0K, VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_ej899vUK, VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_VUGnP38E, VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf4), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_oUoR0KbL, VIf(Bf5));
    __hv_tabread_f(&sTabread_CjeLMNLG, VOf(Bf5));
    __hv_varread_f(&sVarf_CmQr4cUf, VOf(Bf2));
    __hv_tabread_f(&sTabread_gnRw7hUq, VOf(Bf3));
    __hv_varread_f(&sVarf_s2ZhNE5o, VOf(Bf6));
    __hv_varread_f(&sVarf_RAKpPlIH, VOf(Bf7));
    __hv_varread_f(&sVarf_yqxuikFY, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_gYYUUzip, VOf(Bf2));
    __hv_mul_f(VIf(Bf8), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_NjWamTgd, VOf(Bf8));
    __hv_varread_f(&sVarf_5bxZRUjQ, VOf(Bf6));
    __hv_mul_f(VIf(I1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_YU7yLrXC, VOf(Bf7));
    __hv_rpole_f(&sRPole_T5Pu5PHa, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_gYm5muES, VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_5wc0mCHZ, VOf(Bf7));
    __hv_rpole_f(&sRPole_Slfhv0J1, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_RJoPmadP, VOf(Bf6));
    __hv_rpole_f(&sRPole_BbCThNPe, VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_MFzNAKvR, VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_c7Gle2Dy, VOf(Bf6));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_CqbCLuGo, VOf(Bf7));
    __hv_rpole_f(&sRPole_u21iyTgF, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_QP3HLtIi, VIf(Bf7), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_1Abz8Jfk, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_zmIkBDFH, VIf(Bf7));
    __hv_varread_f(&sVarf_Y6vFUXlD, VOf(Bf7));
    __hv_varread_f(&sVarf_Do5DnuB8, VOf(Bf8));
    __hv_mul_f(VIf(I1), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_vrRSo3OE, VOf(Bf5));
    __hv_rpole_f(&sRPole_sLXthXKC, VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_eoo1hzVy, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_fqQuRH6f, VOf(Bf5));
    __hv_rpole_f(&sRPole_ltPKGIxb, VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_xmmgLQoL, VOf(Bf8));
    __hv_rpole_f(&sRPole_1bClSnrK, VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_0HZ6dsPv, VIf(Bf8), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_8ahjfSsC, VOf(Bf8));
    __hv_mul_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_SYj90OhX, VOf(Bf5));
    __hv_rpole_f(&sRPole_NyLGVpL3, VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_w3Y2IXNw, VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_fEQUvPH9, VOf(Bf5));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_tabwrite_f(&sTabwrite_VRY7zSue, VIf(Bf5));
    __hv_fma_f(VIf(I1), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_ZN1n8ftU, VOf(Bf2));
    __hv_tabread_f(&sTabread_3JW8lI6g, VOf(Bf0));
    __hv_varread_f(&sVarf_4BHFk7BO, VOf(Bf5));
    __hv_tabread_f(&sTabread_TzwpoU0A, VOf(Bf7));
    __hv_varread_f(&sVarf_j7NLiNJK, VOf(Bf3));
    __hv_tabread_f(&sTabread_zKRg1vzk, VOf(Bf8));
    __hv_varread_f(&sVarf_k4TXKi72, VOf(Bf6));
    __hv_tabread_f(&sTabread_3juhxaOr, VOf(Bf1));
    __hv_varread_f(&sVarf_PW3AD4rj, VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_3civjISe, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_pSsfj5nZ, VOf(Bf4));
    __hv_varread_f(&sVarf_WJyTO7UI, VOf(Bf3));
    __hv_mul_f(VIf(I0), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_h0Mu0Otk, VOf(Bf6));
    __hv_rpole_f(&sRPole_quzzZuNF, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_lBao26Hz, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_AC5vakgn, VOf(Bf6));
    __hv_rpole_f(&sRPole_j2XQRrnM, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_ep4U7JVy, VOf(Bf3));
    __hv_rpole_f(&sRPole_9d3vY41T, VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_9ASft9rr, VIf(Bf3), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_0YZxaRxf, VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_M2KLtQSW, VOf(Bf6));
    __hv_rpole_f(&sRPole_ui1BRscN, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_VsOanfky, VIf(Bf6), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_QDh1Ip88, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf7), VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_tabwrite_f(&sTabwrite_1hwD5EJe, VIf(Bf6));
    __hv_varread_f(&sVarf_eQwBpGWo, VOf(Bf6));
    __hv_varread_f(&sVarf_Q1FuC71z, VOf(Bf4));
    __hv_mul_f(VIf(I0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_SQuPZAME, VOf(Bf7));
    __hv_rpole_f(&sRPole_KGMAfATO, VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_hmvZWCHT, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_yF2shCCN, VOf(Bf7));
    __hv_rpole_f(&sRPole_eBjMDA3e, VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_wuIzaLUT, VOf(Bf4));
    __hv_rpole_f(&sRPole_GsMsm4g7, VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_kahCY8mO, VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_muSgF83r, VOf(Bf4));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_wBQfIboz, VOf(Bf7));
    __hv_rpole_f(&sRPole_UO5nT8sf, VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_ZJqlNPTX, VIf(Bf7), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_ADbFej9x, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_tabwrite_f(&sTabwrite_5bBPMslL, VIf(Bf7));
    __hv_varread_f(&sVarf_qGAvfWAn, VOf(Bf7));
    __hv_varread_f(&sVarf_z2KcLVJB, VOf(Bf6));
    __hv_mul_f(VIf(I0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_RNgkevKj, VOf(Bf8));
    __hv_rpole_f(&sRPole_emoHZ5c7, VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_c6x9p2qe, VOf(Bf6));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_rC7JHJDw, VOf(Bf8));
    __hv_rpole_f(&sRPole_q8R9kvfz, VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_3zCdI0dE, VOf(Bf6));
    __hv_rpole_f(&sRPole_RZVqGk4Q, VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf8), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_ADQAL5SB, VIf(Bf6), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_Ied3wZPo, VOf(Bf6));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_BAQYFNHd, VOf(Bf8));
    __hv_rpole_f(&sRPole_CFqcxNY2, VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_G0klFKf8, VIf(Bf8), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_iiGV3lku, VOf(Bf8));
    __hv_mul_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_tabwrite_f(&sTabwrite_UnfirIcJ, VIf(Bf8));
    __hv_varread_f(&sVarf_N0hYUKKy, VOf(Bf8));
    __hv_varread_f(&sVarf_bbXb0eCS, VOf(Bf7));
    __hv_mul_f(VIf(I0), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_PMS1iv9E, VOf(Bf1));
    __hv_rpole_f(&sRPole_H5edj5Iu, VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_tWfaBUVP, VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_wntEjsdW, VOf(Bf1));
    __hv_rpole_f(&sRPole_6SAoLY13, VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_xfxyDFX5, VOf(Bf7));
    __hv_rpole_f(&sRPole_c0n9gWoA, VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_slEy5wtu, VIf(Bf7), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_MYBSk5PR, VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_HsxVLfWX, VOf(Bf1));
    __hv_rpole_f(&sRPole_yXZCbYqb, VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_idyo6xFa, VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Q8OY2Pwy, VOf(Bf1));
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_z79K5GKw, VIf(Bf1));
    __hv_fma_f(VIf(I0), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_FourPointDelay::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_FourPointDelay::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
