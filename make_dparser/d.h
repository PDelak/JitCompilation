/*
  Copyright 2002-2004 John Plevyak, All Rights Reserved
*/
#ifndef _d_H_
#define _d_H_

#ifdef MEMWATCH
#define MEMWATCH_STDIO 1
#include "../../src/memwatch-2.67/memwatch.h"
#define MEM_GROW_MACRO
#endif
#include <assert.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <time.h>
#include "stdint.h"
#include <ctype.h>
#include <string.h>
#ifdef LEAK_DETECT
#define GC_DEBUG
#include "gc.h"
#define MALLOC(n) GC_MALLOC(n)
#define CALLOC(m,n) GC_MALLOC((m)*(n))
#define FREE(p) GC_FREE(p)
#define REALLOC(p,n) GC_REALLOC((p),(n))
#define CHECK_LEAKS() GC_gcollect()
#else
#ifdef USE_GC
#include "gc.h"
#define MALLOC GC_MALLOC
#define REALLOC GC_REALLOC
#define FREE(_x)
#define malloc dont_use_malloc_use_MALLOC_instead
#define relloc dont_use_realloc_use_REALLOC_instead
#define free dont_use_free_use_FREE_instead
#else
#define MALLOC malloc
#define REALLOC realloc
#define FREE free
#endif
#endif

// enough already with the signed/unsiged char issues
#define isspace_(_c) isspace((unsigned char)(_c))
#define isdigit_(_c) isdigit((unsigned char)(_c))
#define isxdigit_(_c) isxdigit((unsigned char)(_c))
#define isprint_(_c) isprint((unsigned char)(_c))

#define D_VERSION			(\
(D_MAJOR_VERSION << 24) + (D_MINOR_VERSION << 16) + \
D_BUILD_VERSION)
                         
/* Compilation Options 
*/

#define round2(_x,_n) ((_x + ((_n)-1)) & ~((_n)-1))
#define tohex1(_x) \
((((_x)&15) > 9) ? (((_x)&15) - 10 + 'A') : (((_x)&15) + '0'))
#define tohex2(_x) \
((((_x)>>4) > 9) ? (((_x)>>4) - 10 + 'A') : (((_x)>>4) + '0'))
#define numberof(_x) ((sizeof(_x))/(sizeof((_x)[0])))

typedef char int8;
typedef unsigned char uint8;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef short int16;
typedef unsigned short uint16;
#ifdef __MINGW32__
/* already part of most systems */
typedef unsigned long ulong;
typedef uint32 uint; 
#endif

#if defined(_WIN32) || defined(_WIN64)
typedef uint32_t uint;
#endif

#include "dparse.h"
#include "arg.h"
#include "util.h"
#include "gram.h"
#include "lr.h"
#include "lex.h"
#include "scan.h"
#include "parse.h"
#include "write_tables.h"
#include "read_binary.h"

#ifdef D_DEBUG
#define DBG(_x) if (d_debug_level>1) { _x; }
#else
#define DBG(_x)
#endif

void d_version(char *);

#define USE_SCANNER		1

#endif
