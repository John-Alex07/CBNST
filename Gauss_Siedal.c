#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(int n, float ar[n][n+1])
{
    printf("Enter the coefficients of \n");
    for(int i = 0; i < n; i++)
    {
        printf("Equation %d :\n", i+1);
        for(int j = 0; j <= n; j++)
        {
            if(j == n)
            printf(" = ");
            scanf("%f", &ar[i][j]);
        }
    }
}
void display(int n, float ar[n][n+1])
{
    printf("Augmented Matrix : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <=n; j++)
        {
            if(j == n)
                printf(" | ");
            printf("%.2f ", ar[i][j]);
        }
        printf("\n");
    }
}
int main()
{
   int n;
   printf("Input the number of Equations :\n");
   scanf("%d", &n);
   float ar[n][n+1];
   input(n, ar);

   float var[n];
   float temp_var[n];
   for(int i = 0; i < n; i++)
      var[i] = 0, temp_var[i] = -1;
   
    int c = 1;
    while(c)
    {
      for(int i = 0; i < n; i++)
      {
        if(fabs(var[i] - temp_var[i]) < 0.0001)
            continue;
        temp_var[i] = var[i];
        var[i] = 0;
        for(int j = 0; j < n; j++)
        {
            if(j != i)
                var[i] = var[i] + ar[i][j]*var[j]; 
        }
        var[i] = (ar[i][n] - var[i])/ar[i][i];
        printf("Var %d = %f ", (i+1), var[i]);
      }
      printf("\n");
      for(int i = 0; i < n; i++)
      {
        if(fabs(var[i] - temp_var[i]) > 0.0001)
        {
            c = 1;
            break;
        }
        else
            c = 0;
      }
    }
    display(n, ar);
    
    printf("The Value of Variables :\n");
    for(int i = 0; i < n; i++)
        printf("Variable %d = %.3f\n", i+1, var[i]);
}