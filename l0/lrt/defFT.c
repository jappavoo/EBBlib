/*
 * Copyright (C) 2011 by Project SESA, Boston University
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <config.h>
#include <stdint.h>
#include <l0/lrt/trans.h>
#include <l0/lrt/defFT.h>

//takes the function table pointer and function number and
//invokes the miss handler then
//returns the function pointer to be called
void *lrt_trans_default_func(lrt_trans_rep_ref *_self, lrt_trans_func_num fnum) {
  //the default ftable is the second word in the trans, subtract 1
  //word to get the LTrans
  lrt_trans_ltrans *self = (lrt_trans_ltrans *)(*_self-1);
  lrt_trans_gtrans *gt = lrt_trans_lt2gt(self);
  rwlock_rdlock(&gt->rwlock);
  lrt_trans_rc ret = gt->mf(_self, self, fnum, gt->arg);
  rwlock_rdunlock(&gt->rwlock);
  if(LRT_TRANS_RC_SUCCESS(ret)) {
    //return the function we wanted to call originally
    return (*_self)->ft[fnum];
  }
  return (void *)ret; //return the error code
}

#define LRT_TRANS_MAX_FUNCS 256
static lrt_trans_func lrt_trans_def_ft[LRT_TRANS_MAX_FUNCS];

lrt_trans_rep lrt_trans_def_rep = {
  .ft = lrt_trans_def_ft
};

static lrt_trans_func lrt_trans_def_ft[LRT_TRANS_MAX_FUNCS] = {
  (lrt_trans_func)lrt_trans_def_func_0,
  (lrt_trans_func)lrt_trans_def_func_1,
  (lrt_trans_func)lrt_trans_def_func_2,
  (lrt_trans_func)lrt_trans_def_func_3,
  (lrt_trans_func)lrt_trans_def_func_4,
  (lrt_trans_func)lrt_trans_def_func_5,
  (lrt_trans_func)lrt_trans_def_func_6,
  (lrt_trans_func)lrt_trans_def_func_7,
  (lrt_trans_func)lrt_trans_def_func_8,
  (lrt_trans_func)lrt_trans_def_func_9,
  (lrt_trans_func)lrt_trans_def_func_10,
  (lrt_trans_func)lrt_trans_def_func_11,
  (lrt_trans_func)lrt_trans_def_func_12,
  (lrt_trans_func)lrt_trans_def_func_13,
  (lrt_trans_func)lrt_trans_def_func_14,
  (lrt_trans_func)lrt_trans_def_func_15,
  (lrt_trans_func)lrt_trans_def_func_16,
  (lrt_trans_func)lrt_trans_def_func_17,
  (lrt_trans_func)lrt_trans_def_func_18,
  (lrt_trans_func)lrt_trans_def_func_19,
  (lrt_trans_func)lrt_trans_def_func_20,
  (lrt_trans_func)lrt_trans_def_func_21,
  (lrt_trans_func)lrt_trans_def_func_22,
  (lrt_trans_func)lrt_trans_def_func_23,
  (lrt_trans_func)lrt_trans_def_func_24,
  (lrt_trans_func)lrt_trans_def_func_25,
  (lrt_trans_func)lrt_trans_def_func_26,
  (lrt_trans_func)lrt_trans_def_func_27,
  (lrt_trans_func)lrt_trans_def_func_28,
  (lrt_trans_func)lrt_trans_def_func_29,
  (lrt_trans_func)lrt_trans_def_func_30,
  (lrt_trans_func)lrt_trans_def_func_31,
  (lrt_trans_func)lrt_trans_def_func_32,
  (lrt_trans_func)lrt_trans_def_func_33,
  (lrt_trans_func)lrt_trans_def_func_34,
  (lrt_trans_func)lrt_trans_def_func_35,
  (lrt_trans_func)lrt_trans_def_func_36,
  (lrt_trans_func)lrt_trans_def_func_37,
  (lrt_trans_func)lrt_trans_def_func_38,
  (lrt_trans_func)lrt_trans_def_func_39,
  (lrt_trans_func)lrt_trans_def_func_40,
  (lrt_trans_func)lrt_trans_def_func_41,
  (lrt_trans_func)lrt_trans_def_func_42,
  (lrt_trans_func)lrt_trans_def_func_43,
  (lrt_trans_func)lrt_trans_def_func_44,
  (lrt_trans_func)lrt_trans_def_func_45,
  (lrt_trans_func)lrt_trans_def_func_46,
  (lrt_trans_func)lrt_trans_def_func_47,
  (lrt_trans_func)lrt_trans_def_func_48,
  (lrt_trans_func)lrt_trans_def_func_49,
  (lrt_trans_func)lrt_trans_def_func_50,
  (lrt_trans_func)lrt_trans_def_func_51,
  (lrt_trans_func)lrt_trans_def_func_52,
  (lrt_trans_func)lrt_trans_def_func_53,
  (lrt_trans_func)lrt_trans_def_func_54,
  (lrt_trans_func)lrt_trans_def_func_55,
  (lrt_trans_func)lrt_trans_def_func_56,
  (lrt_trans_func)lrt_trans_def_func_57,
  (lrt_trans_func)lrt_trans_def_func_58,
  (lrt_trans_func)lrt_trans_def_func_59,
  (lrt_trans_func)lrt_trans_def_func_60,
  (lrt_trans_func)lrt_trans_def_func_61,
  (lrt_trans_func)lrt_trans_def_func_62,
  (lrt_trans_func)lrt_trans_def_func_63,
  (lrt_trans_func)lrt_trans_def_func_64,
  (lrt_trans_func)lrt_trans_def_func_65,
  (lrt_trans_func)lrt_trans_def_func_66,
  (lrt_trans_func)lrt_trans_def_func_67,
  (lrt_trans_func)lrt_trans_def_func_68,
  (lrt_trans_func)lrt_trans_def_func_69,
  (lrt_trans_func)lrt_trans_def_func_70,
  (lrt_trans_func)lrt_trans_def_func_71,
  (lrt_trans_func)lrt_trans_def_func_72,
  (lrt_trans_func)lrt_trans_def_func_73,
  (lrt_trans_func)lrt_trans_def_func_74,
  (lrt_trans_func)lrt_trans_def_func_75,
  (lrt_trans_func)lrt_trans_def_func_76,
  (lrt_trans_func)lrt_trans_def_func_77,
  (lrt_trans_func)lrt_trans_def_func_78,
  (lrt_trans_func)lrt_trans_def_func_79,
  (lrt_trans_func)lrt_trans_def_func_80,
  (lrt_trans_func)lrt_trans_def_func_81,
  (lrt_trans_func)lrt_trans_def_func_82,
  (lrt_trans_func)lrt_trans_def_func_83,
  (lrt_trans_func)lrt_trans_def_func_84,
  (lrt_trans_func)lrt_trans_def_func_85,
  (lrt_trans_func)lrt_trans_def_func_86,
  (lrt_trans_func)lrt_trans_def_func_87,
  (lrt_trans_func)lrt_trans_def_func_88,
  (lrt_trans_func)lrt_trans_def_func_89,
  (lrt_trans_func)lrt_trans_def_func_90,
  (lrt_trans_func)lrt_trans_def_func_91,
  (lrt_trans_func)lrt_trans_def_func_92,
  (lrt_trans_func)lrt_trans_def_func_93,
  (lrt_trans_func)lrt_trans_def_func_94,
  (lrt_trans_func)lrt_trans_def_func_95,
  (lrt_trans_func)lrt_trans_def_func_96,
  (lrt_trans_func)lrt_trans_def_func_97,
  (lrt_trans_func)lrt_trans_def_func_98,
  (lrt_trans_func)lrt_trans_def_func_99,
  (lrt_trans_func)lrt_trans_def_func_100,
  (lrt_trans_func)lrt_trans_def_func_101,
  (lrt_trans_func)lrt_trans_def_func_102,
  (lrt_trans_func)lrt_trans_def_func_103,
  (lrt_trans_func)lrt_trans_def_func_104,
  (lrt_trans_func)lrt_trans_def_func_105,
  (lrt_trans_func)lrt_trans_def_func_106,
  (lrt_trans_func)lrt_trans_def_func_107,
  (lrt_trans_func)lrt_trans_def_func_108,
  (lrt_trans_func)lrt_trans_def_func_109,
  (lrt_trans_func)lrt_trans_def_func_110,
  (lrt_trans_func)lrt_trans_def_func_111,
  (lrt_trans_func)lrt_trans_def_func_112,
  (lrt_trans_func)lrt_trans_def_func_113,
  (lrt_trans_func)lrt_trans_def_func_114,
  (lrt_trans_func)lrt_trans_def_func_115,
  (lrt_trans_func)lrt_trans_def_func_116,
  (lrt_trans_func)lrt_trans_def_func_117,
  (lrt_trans_func)lrt_trans_def_func_118,
  (lrt_trans_func)lrt_trans_def_func_119,
  (lrt_trans_func)lrt_trans_def_func_120,
  (lrt_trans_func)lrt_trans_def_func_121,
  (lrt_trans_func)lrt_trans_def_func_122,
  (lrt_trans_func)lrt_trans_def_func_123,
  (lrt_trans_func)lrt_trans_def_func_124,
  (lrt_trans_func)lrt_trans_def_func_125,
  (lrt_trans_func)lrt_trans_def_func_126,
  (lrt_trans_func)lrt_trans_def_func_127,
  (lrt_trans_func)lrt_trans_def_func_128,
  (lrt_trans_func)lrt_trans_def_func_129,
  (lrt_trans_func)lrt_trans_def_func_130,
  (lrt_trans_func)lrt_trans_def_func_131,
  (lrt_trans_func)lrt_trans_def_func_132,
  (lrt_trans_func)lrt_trans_def_func_133,
  (lrt_trans_func)lrt_trans_def_func_134,
  (lrt_trans_func)lrt_trans_def_func_135,
  (lrt_trans_func)lrt_trans_def_func_136,
  (lrt_trans_func)lrt_trans_def_func_137,
  (lrt_trans_func)lrt_trans_def_func_138,
  (lrt_trans_func)lrt_trans_def_func_139,
  (lrt_trans_func)lrt_trans_def_func_140,
  (lrt_trans_func)lrt_trans_def_func_141,
  (lrt_trans_func)lrt_trans_def_func_142,
  (lrt_trans_func)lrt_trans_def_func_143,
  (lrt_trans_func)lrt_trans_def_func_144,
  (lrt_trans_func)lrt_trans_def_func_145,
  (lrt_trans_func)lrt_trans_def_func_146,
  (lrt_trans_func)lrt_trans_def_func_147,
  (lrt_trans_func)lrt_trans_def_func_148,
  (lrt_trans_func)lrt_trans_def_func_149,
  (lrt_trans_func)lrt_trans_def_func_150,
  (lrt_trans_func)lrt_trans_def_func_151,
  (lrt_trans_func)lrt_trans_def_func_152,
  (lrt_trans_func)lrt_trans_def_func_153,
  (lrt_trans_func)lrt_trans_def_func_154,
  (lrt_trans_func)lrt_trans_def_func_155,
  (lrt_trans_func)lrt_trans_def_func_156,
  (lrt_trans_func)lrt_trans_def_func_157,
  (lrt_trans_func)lrt_trans_def_func_158,
  (lrt_trans_func)lrt_trans_def_func_159,
  (lrt_trans_func)lrt_trans_def_func_160,
  (lrt_trans_func)lrt_trans_def_func_161,
  (lrt_trans_func)lrt_trans_def_func_162,
  (lrt_trans_func)lrt_trans_def_func_163,
  (lrt_trans_func)lrt_trans_def_func_164,
  (lrt_trans_func)lrt_trans_def_func_165,
  (lrt_trans_func)lrt_trans_def_func_166,
  (lrt_trans_func)lrt_trans_def_func_167,
  (lrt_trans_func)lrt_trans_def_func_168,
  (lrt_trans_func)lrt_trans_def_func_169,
  (lrt_trans_func)lrt_trans_def_func_170,
  (lrt_trans_func)lrt_trans_def_func_171,
  (lrt_trans_func)lrt_trans_def_func_172,
  (lrt_trans_func)lrt_trans_def_func_173,
  (lrt_trans_func)lrt_trans_def_func_174,
  (lrt_trans_func)lrt_trans_def_func_175,
  (lrt_trans_func)lrt_trans_def_func_176,
  (lrt_trans_func)lrt_trans_def_func_177,
  (lrt_trans_func)lrt_trans_def_func_178,
  (lrt_trans_func)lrt_trans_def_func_179,
  (lrt_trans_func)lrt_trans_def_func_180,
  (lrt_trans_func)lrt_trans_def_func_181,
  (lrt_trans_func)lrt_trans_def_func_182,
  (lrt_trans_func)lrt_trans_def_func_183,
  (lrt_trans_func)lrt_trans_def_func_184,
  (lrt_trans_func)lrt_trans_def_func_185,
  (lrt_trans_func)lrt_trans_def_func_186,
  (lrt_trans_func)lrt_trans_def_func_187,
  (lrt_trans_func)lrt_trans_def_func_188,
  (lrt_trans_func)lrt_trans_def_func_189,
  (lrt_trans_func)lrt_trans_def_func_190,
  (lrt_trans_func)lrt_trans_def_func_191,
  (lrt_trans_func)lrt_trans_def_func_192,
  (lrt_trans_func)lrt_trans_def_func_193,
  (lrt_trans_func)lrt_trans_def_func_194,
  (lrt_trans_func)lrt_trans_def_func_195,
  (lrt_trans_func)lrt_trans_def_func_196,
  (lrt_trans_func)lrt_trans_def_func_197,
  (lrt_trans_func)lrt_trans_def_func_198,
  (lrt_trans_func)lrt_trans_def_func_199,
  (lrt_trans_func)lrt_trans_def_func_200,
  (lrt_trans_func)lrt_trans_def_func_201,
  (lrt_trans_func)lrt_trans_def_func_202,
  (lrt_trans_func)lrt_trans_def_func_203,
  (lrt_trans_func)lrt_trans_def_func_204,
  (lrt_trans_func)lrt_trans_def_func_205,
  (lrt_trans_func)lrt_trans_def_func_206,
  (lrt_trans_func)lrt_trans_def_func_207,
  (lrt_trans_func)lrt_trans_def_func_208,
  (lrt_trans_func)lrt_trans_def_func_209,
  (lrt_trans_func)lrt_trans_def_func_210,
  (lrt_trans_func)lrt_trans_def_func_211,
  (lrt_trans_func)lrt_trans_def_func_212,
  (lrt_trans_func)lrt_trans_def_func_213,
  (lrt_trans_func)lrt_trans_def_func_214,
  (lrt_trans_func)lrt_trans_def_func_215,
  (lrt_trans_func)lrt_trans_def_func_216,
  (lrt_trans_func)lrt_trans_def_func_217,
  (lrt_trans_func)lrt_trans_def_func_218,
  (lrt_trans_func)lrt_trans_def_func_219,
  (lrt_trans_func)lrt_trans_def_func_220,
  (lrt_trans_func)lrt_trans_def_func_221,
  (lrt_trans_func)lrt_trans_def_func_222,
  (lrt_trans_func)lrt_trans_def_func_223,
  (lrt_trans_func)lrt_trans_def_func_224,
  (lrt_trans_func)lrt_trans_def_func_225,
  (lrt_trans_func)lrt_trans_def_func_226,
  (lrt_trans_func)lrt_trans_def_func_227,
  (lrt_trans_func)lrt_trans_def_func_228,
  (lrt_trans_func)lrt_trans_def_func_229,
  (lrt_trans_func)lrt_trans_def_func_230,
  (lrt_trans_func)lrt_trans_def_func_231,
  (lrt_trans_func)lrt_trans_def_func_232,
  (lrt_trans_func)lrt_trans_def_func_233,
  (lrt_trans_func)lrt_trans_def_func_234,
  (lrt_trans_func)lrt_trans_def_func_235,
  (lrt_trans_func)lrt_trans_def_func_236,
  (lrt_trans_func)lrt_trans_def_func_237,
  (lrt_trans_func)lrt_trans_def_func_238,
  (lrt_trans_func)lrt_trans_def_func_239,
  (lrt_trans_func)lrt_trans_def_func_240,
  (lrt_trans_func)lrt_trans_def_func_241,
  (lrt_trans_func)lrt_trans_def_func_242,
  (lrt_trans_func)lrt_trans_def_func_243,
  (lrt_trans_func)lrt_trans_def_func_244,
  (lrt_trans_func)lrt_trans_def_func_245,
  (lrt_trans_func)lrt_trans_def_func_246,
  (lrt_trans_func)lrt_trans_def_func_247,
  (lrt_trans_func)lrt_trans_def_func_248,
  (lrt_trans_func)lrt_trans_def_func_249,
  (lrt_trans_func)lrt_trans_def_func_250,
  (lrt_trans_func)lrt_trans_def_func_251,
  (lrt_trans_func)lrt_trans_def_func_252,
  (lrt_trans_func)lrt_trans_def_func_253,
  (lrt_trans_func)lrt_trans_def_func_254,
  (lrt_trans_func)lrt_trans_def_func_255
};
