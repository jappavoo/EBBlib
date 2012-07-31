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

#include <stddef.h>

#include <l0/lrt/bare/string.h>

size_t 
strlen(const char *s) 
{
  size_t rc = 0;
  while (s[rc]) {
    ++rc;
  }
  return rc;
}

char *
strcpy(char * restrict s1, const char * restrict s2 )
{
    char * rc = s1;
    while ((*s1++ = *s2++))
      ;
    return rc;
}

int strcmp(const char *s1, const char *s2)
{
  unsigned char uc1, uc2;
  
  while (*s1 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }

  uc1 = (*(unsigned char *) s1);
  uc2 = (*(unsigned char *) s2);
  return ((uc1 < uc2) ? -1 : (uc1 > uc2));
}
