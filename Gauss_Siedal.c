#include <stdio.h>
#include <stdlib.h>

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

   int var[n];
   for(int i = 0; i < n; i++)
      var[i] = 1;
   do
   {
      for(int i = 0; i < n; i++)
      {
        for(int j = n; j > i)
      }
   }
   display(n, ar);
}