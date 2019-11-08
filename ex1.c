#include<stdio.h>

int main()
{
    unsigned int max=0;
    max=~max;
    int bit_count=0;
    printf("unsigned int 能表达的最大整数是：%u\n",max);
    while(max>0){
        max=max>>1;
        bit_count++;
    }
    printf("最大位数的bit位数是：%d\n",bit_count);
    return 0;
}
