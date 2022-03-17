#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a;
    int b=0;
    int c[100];
    int count=0;
    printf("输入一个四位数的正整数:\n");
    scanf("%d",&a);
    printf("二进制:");
    while (a){
        c[b]=a%2;
        b++;
        a/=2;
    }
    for(int j=b-1;j>=0;j--){
        printf("%d",c[j]);
        if(c[j]==1){
            count++;
            }
    }
    printf("\n\"1\"出现的次数是%d\n",count);
    system("pause");
    return 0;
}
