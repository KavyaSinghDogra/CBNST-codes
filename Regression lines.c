#include <stdio.h>
void linearRegression(int n, double x[], double y[], double *slope, double *intercept)
{
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    *slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    *intercept = (sumY - *slope * sumX) / n;
}
int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid number of data points. Exiting...\n");
        return 1;
    }
    double x[n], y[n];
    printf("Enter the data points (x, y):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }
    double slope, intercept;
    linearRegression(n, x, y, &slope, &intercept);
    printf("\nFitted Line Equation: y = %.4lfx + %.4lf\n", slope, intercept);
    return 0;
}
