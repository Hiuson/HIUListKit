//
//  HIUAssertion.h
//  HIUListKit
//
//  Created by zhouchun on 2020/5/26.
//  Copyright © 2020 Hiuson. All rights reserved.
//

#import <Foundation/Foundation.h>

//void HIUAssert(BOOL assert);
//void HIUCast(Class clss, id object);
//void HIUDynamicCast(Class clss, id object);


NS_ASSUME_NONNULL_BEGIN

// http://howtoprogram.eu/question/resumable-assertbreakpoint-on-ios-like-debugbreak-with-ms-compiler,74226
#if defined(__APPLE__) && defined(__aarch64__)
#define __debugbreak() __asm__ __volatile__(            \
    "   mov    x0, %x0;    \n" /* pid                */ \
    "   mov    x1, #0x11;  \n" /* SIGSTOP            */ \
    "   mov    x16, #0x25; \n" /* syscall 37 = kill  */ \
    "   svc    #0x80       \n" /* software interrupt */ \
    "   mov    x0, x0      \n" /* nop                */ \
    ::  "r"(getpid())                                   \
    :   "x0", "x1", "x16", "memory")
#elif defined(__APPLE__) && defined(__arm__)
#define __debugbreak() __asm__ __volatile__(            \
    "   mov    r0, %0;     \n" /* pid                */ \
    "   mov    r1, #0x11;  \n" /* SIGSTOP            */ \
    "   mov    r12, #0x25; \n" /* syscall 37 = kill  */ \
    "   svc    #0x80       \n" /* software interrupt */ \
    "   mov    r0, r0      \n" /* nop                */ \
    ::  "r"(getpid())                                   \
    :   "r0", "r1", "r12", "memory")
#elif defined(__APPLE__) && (defined(__i386__) || defined(__x86_64__))
#define __debugbreak() __asm__ __volatile__("int $3; mov %eax, %eax")
#endif

#define HIUBreakPoint() __debugbreak()

static inline void HIUBreakPointFunc() {
    __debugbreak();
}

#define HIUAssert(expr, ...) \
do { \
    if (!(expr)) { \
        NSString* extraMsg = [NSString stringWithFormat:@DTKMM_FIRST(__VA_ARGS__) "" DTKMM_REST(__VA_ARGS__)]; \
        NSLog(extraMsg); \
        HIUBreakPoint(); \
    } \
} while(0)

#define HIUUnreachable(...) \
do { \
    NSString* extraMsg = [NSString stringWithFormat:@DTKMM_FIRST(__VA_ARGS__) "" DTKMM_REST(__VA_ARGS__)]; \
    NSLog(extraMsg); \
    HIUBreakPoint(); \
} while(0)

NS_ASSUME_NONNULL_END
