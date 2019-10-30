#include <stdio.h>
main()
{
    int fahr,celsius;
    int lower,upper,step;
    lower=0;
    upper=100;
    step=5;
    celsius=lower;
    printf("celsius fahr\n");
    printf("\n");
    while(celsius<=upper){;
        fahr=32+(celsius*1.8);
        printf("%d\t%d\r\n",celsius,fahr);
        celsius=celsius+step;
    }
}