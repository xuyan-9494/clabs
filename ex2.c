#include <stdio.h>

int main()
{
    printf("请输入一个五位数及五位数以下的非负整数：");
    
    // 初始化num变量，用于存储即将输入的数
    int num = 0;
    
    // 当getchar没有结束时，将输入的数字字符转成对应的数字
    char c = getchar();
    while(c != '\n' && c != EOF) {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    
    // 对输入做简单的校验
    if (num < 0 || num > 99999) {
        printf("输入的数据不合法！\n");
        return 0;
    }

    // 初始化计数器
    int count = 0;
    // 当num不为0时，执行 num 和 num - 1 的按位与操作，当num为0时，计数器的值就是num中1的个数
    while(num) {
        count++;
        num = num & (num - 1);
    }
    printf("1出现的次数是: %d\n", count);
    return 0;
}
