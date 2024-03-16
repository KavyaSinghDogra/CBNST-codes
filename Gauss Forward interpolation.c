// Gauss Forward interpolation
#include <stdio.h>
// Function to calculate factorial
int factorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * factorial(n - 1);
    }
}
int main(){
    int n; // Number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n][n]; // Arrays to store x and y values and the forward difference table
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++){
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i][0]);
    }
    // Calculate forward difference table
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    // Display the forward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.4lf\t", x[i]);
        for (int j = 0; j < n - i; j++)
        {
            printf("%.4lf\t", y[i][j]);
        }
        printf("\n");
    }
    double target_x;
    printf("\nEnter the value of x for interpolation: ");
    scanf("%lf", &target_x);
    double result = y[0][0];
    double u = (target_x - x[0]) / (x[1] - x[0]);
    double term = 1.0;
    for (int i = 1; i < n; i++)
    {
        term = term * (u - i + 1) / i;
        result = result + term * y[0][i];
    }
    printf("Interpolated value at x = %.4lf is %.4lf\n", target_x, result);
    return 0;
}
