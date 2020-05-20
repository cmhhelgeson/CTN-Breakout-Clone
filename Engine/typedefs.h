//Taken wholesale from Godogt Engine typedefs

#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#ifndef _ALWAYS_INLINE_
#if defined(__GNUC__)
#define _ALWAYS_INLINE_ __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
#define _ALWAYS_INLINE_ __forceinline
#else
#define _ALWAYS_INLINE_ inline
#endif
#endif

#endif //Typedefs.h