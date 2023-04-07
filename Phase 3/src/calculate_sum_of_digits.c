#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[])
{
    int number = atoi(argv[1]);
    int saved_ebx;
    asm volatile (
        "movl %%ebx, %0;"
        "movl %1, %%ebx;"
        : "=r" (saved_ebx)
        : "r"(number) /* input is variable a */
        :   /* clobbered register */      
    );
    printf(1, "%d\n", calculate_sum_of_digits());
    asm("movl %0, %%ebx" : : "r"(saved_ebx) );
    exit();
} 