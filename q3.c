//Secant method
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
double fn(double x){return x*log10(x)-1.2;}
int main(){
    double x0,x1,x2,err;
    int itr,i=0;
    printf("Enter the initial guesses: ");
    scanf("%lf %lf",&x0,&x1);
    printf("Enter the maximum number of iterations: ");
    scanf("%d",&itr);
    printf("Enter tolerable error: ");
    scanf("%lf",&err);
    do{
        x2= x1-((x1-x0)/(fn(x1)-fn(x0)))*fn(x1);
        x0=x1;
        x1=x2;
        i++;
        if(i>itr){
            exit(0);
        }
        printf("For Iteration no. %d, x0=%lf and x1=%lf\n",i,x0,x1);        
    } 
    while(fabs(x1-x0)>err);
    printf("Root is %.4lf\n", x1);
}