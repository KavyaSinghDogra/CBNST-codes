//Newton-Raphson method 
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
double fn(double x){
    return x*log10(x)-1.2;
}
double fn1(double x){
    return (log10(x)+0.43429);
}
int main()
{
    double x0,x1,prev,err;
    int itr,i=0;
    printf("Enter the initial guess: ");
    scanf("%lf",&x0);
    printf("Enter tolerable error: ");
    scanf("%lf",&err);
    printf("Iteration\tx\n");
    do{
        prev=x0;
        x1=x0-(fn(x0)/fn1(x0));
        x0=x1;
        i++;
        printf("%d\t\t%lf\n",i,x0);
        
    } while(fabs(x1-prev)>err);
}