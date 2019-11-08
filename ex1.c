#include <stdio.h>

int main()
{
    // 先设置max为二进制全0
    unsigned int max = 0;
    
    // 对max按位取反，得到全1，即可得到最大值
    max = ~max;
    int bit_count = 0;
    printf("unsinged int 能表示的最大整数是: %u\n", max);
    // 当max大于0时，右移一位，记录右移的次数，因为此时的max为全1，所以右移次数即为bit位数
    while(max > 0) {
        max = max >> 1;
        bit_count++;
    }
    printf("最大整数的bit位数是: %d\n", bit_count);
    return 0;
}
© 2019 GitHub, Inc.
