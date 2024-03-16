// truncation and round off
#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    printf("Enter true/exact value: ");
    scanf("%lf", &x);
    int a;
    printf("Enter decimal places upto which truncation & roundoff to be done: ");
    scanf("%d", &a);
    printf("For Truncation case - \n");
    long long int b = x * pow(10, a);
    double y = (double)b / pow(10, a);
    printf("Truncated value: %lf\n", y);
    double A_E = fabs(x - y);
    printf("Absolute Error: %lf\n", A_E);
    double R_E = fabs(A_E / x);
    printf("Relative Error: %lf\n", R_E);
    double P_E = R_E * 100;
    printf("Percentage Error: %lf\n", P_E);
    printf("For Roundoff Case - \n");
    b = x * pow(10, a + 1);
    int c = b % 10;
    b = b / (float)10;
    if (c > 5)
    {
        b++;
    }
    y = (double)b / pow(10, a);
    printf("Roundoff: %lf\n", y);
    A_E = fabs(x - y);
    printf("Absolute Error: %lf\n", A_E);
    R_E = fabs(A_E / x);
    printf("Relative Error: %lf\n", R_E);
    P_E = R_E * 100;
    printf("Percentage Error: %lf\n", P_E);
    return 0;
}