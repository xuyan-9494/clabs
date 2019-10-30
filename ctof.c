#include <stdio.h>
main()
{
    int fahr,celsius;
    int lower,upper,step;
    lower=0;
    upper=100;
    step=5;
    celsius=lower;
    printf("celsius , fahr");
    while(celsius<=upper){;
        fahr=32+(celsius*1.8);
        printf("%d\t%d\n",celsius,fahr);
        celsius=celsius+step;
    }
}