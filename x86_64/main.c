#include <stdio.h>

void test_asm()
{
    int result = 0;
    int input = 1;

    int a = 1;
    int b = 2;

    asm volatile (
        "movl %1, %0\n"     // 通过占位符指定交互的变量
        : "=r"(result)      // 输出变量，与汇编交互
        : "r"(input)        // 输出变量，与汇编交互
                            // 这里的r指示编译器自动将通用寄存器关联到变量
        );

    printf("result = %d\n", result);
    printf("input = %d\n", input);

    asm volatile (
        "movl %%eax, %%ecx\n"
        "movl %%ebx, %%eax\n"
        "movl %%ecx, %%ebx\n"
        : "=a"(a), "=b"(b)          // 这里指明a变量使用a寄存器
        : "a"(a), "b"(b)
        );

    printf("a = %d\n", a);
    printf("b = %d\n", b);


}

int main()
{
    __asm__ volatile (
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "nop\n"
        );

    return 0;
}
