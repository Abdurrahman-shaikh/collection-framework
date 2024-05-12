/* debug.h
 *
 * This file is part of libcoll, a generic collections library for C.
 *
 * Copyright (c) 2010-2020 Mika Wahlroos (mika.wahlroos@iki.fi)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>

#ifndef LIBCOLL_DEBUG_H
#define LIBCOLL_DEBUG_H

/* disable debug output by default;
 * can be enabled by defining ENABLE_DEBUG=1 on the compiler command line.
 */
#ifndef ENABLE_DEBUG
#define ENABLE_DEBUG    0
#endif

#define DEBUGF(fmt, ...)        if (ENABLE_DEBUG) printf(fmt, __VA_ARGS__)
#define DEBUG(msg)              DEBUGF("%s", msg)

#define ERRORF(fmt, ...)        printf(fmt, __VA_ARGS__)
#define ERROR(msg)              ERRORF("%s", msg)


#endif  /* LIBCOLL_DEBUG_H */
