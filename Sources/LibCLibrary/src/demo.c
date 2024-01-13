#include "demo.h"

int demo_number() {
    return 123;
}

char* demo_string() {
    return "Hello Skip!";
}

double demo_compute(int n, double a, double b) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += (a * b) / (a + b + i);
    }
    return result;
}

long add_with_assembly(long x, long y) {
    long result;

    #ifdef __i386__ // Intel 32-bit
    __asm__ ("add %1, %0" : "=r" (result) : "r" (y), "0" (x));
    #elif __x86_64__ // Intel 64-bit
    __asm__ ("addq %1, %0;" : "=r" (result) : "r" (y), "0" (x));
    #elif __arm__ // ARM 32-bit
    __asm__ ("adds %0, %1, %2" : "=r" (result) : "r" (x), "r" (y));
    #elif __aarch64__ // ARM 64-bit
    __asm__ ("add %0, %1, %2" : "=r" (result) : "r" (x), "r" (y));
    #elif __riscv_64 // RISC-V 64-bit (future)
    __asm__ ("add %0, %1, %2" : "=r" (result) : "r" (x), "r" (y));
    #else
        #error "Unsupported architecture"
    #endif

    return result;
}
