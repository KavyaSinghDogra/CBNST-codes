//Bisection method
#include <stdio.h>
#include <math.h>
#define E 0.0001

//log()- use to calculate log values with base e.
//log10()- use to calculate log values with base 10.
//exp()- use to calculate e raised to power x. 

double fn(double x){
    return (x*log10(x)-1.2);
}
int main()
{
    double x0,x1,mid;
    int itr=0;
    printf("Enter the first guess: ");
    scanf("%lf",&x0);
    printf("Enter the second guess: ");
    scanf("%lf",&x1);
    do{
        mid=(x0+x1)/2;
        if(fn(mid)<0){
            x1=mid;
        }
        else{
            x0=mid;
        }
        itr++;
        printf("For Iteration no. %d, x0= %lf and x1=%lf\n",itr,x0,x1);
    } while(fabs(x1-x0)>E);
    return 0;
}
