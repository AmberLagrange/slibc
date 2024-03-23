#ifndef ASSERT_H
#define ASSERT_H

extern void abort(void);

#ifndef NDEBUG
    #define assert(x) if (((int)(x)) == 0) abort();
#else
    #define assert(_) ((void)0)
#endif

#endif /* ASSERT_H */
