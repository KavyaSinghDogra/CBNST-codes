// Iteration method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (cos(x) - 3 * x + 1)
#define g(x) ((1 + cos(x)) / 3)
int main(){
    int iteration = 1;
    double x0, x1, e;
    printf("Enter initial guess: ");
    scanf("%lf", &x0);
    printf("Enter tolerable error : ");
    scanf("%lf", &e);
    printf("\nstep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do{
        x1 = g(x0);
        printf("%d\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n", iteration, x0, f(x0), x1, f(x1));
        iteration = iteration + 1;
        x0 = x1;
    } 
    while (fabs(f(x1)) > e);
    printf("\nRoot is %.4lf\n", x1);
    return 0;
}
