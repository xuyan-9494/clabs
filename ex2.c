#include <stdio.h>

int main()
{
    printf("请输入一个五位数及五位数以下的非负整数：");
   
    int num = 0;
    
    char c = getchar();
    while(c != '\n' && c != EOF) {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    
    if (num < 0 || num > 99999) {
        printf("输入的数据不合法！\n");
        return 0;
    }

    int count = 0;
    while(num) {
        count++;
        num = num & (num - 1);
    }
    printf("1出现的次数是: %d\n", count);
    return 0;
}
