#ifndef __EBB_CONSTS_H__
#define __EBB_CONSTS_H__
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

#include <l0/lrt/const.h>
#include <l0/const-asm.h>

enum {EBB_TRANS_MAX_NODES = EBB_TRANS_MAX_NODES_ASM};
enum {EBB_TRANS_PAGE_SIZE = EBB_TRANS_PAGE_SIZE_ASM};
enum {EBB_TRANS_NUM_PAGES = EBB_TRANS_NUM_PAGES_ASM};
enum {EBB_TRANS_MAX_ELS = LRT_TRANS_MAX_ELS};
enum {EBB_TRANS_MAX_FUNCS = EBB_TRANS_MAX_FUNCS_ASM};

#endif
