#include <stdio.h>
#include <stdlib.h>

void input(int n, float eq_ar[n][n+1])
{
    printf("Input the Coefficients of\n");
    for(int i = 0; i < n; i++)
    {
        printf("Equation %d :\n", (i+1));
        for(int j = 0; j <=n; j++)
        {
            if(j == n)
                printf(" = ");
          scanf("%f", &eq_ar[i][j]);
        }
    }
}
void display(int n, float eq_ar[n][n+1])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        { 
        if(j == n)
          printf(" | ");
          printf("%.2f ", eq_ar[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the number of Equations :\n");
    scanf("%d", &n);

    float ar[n][n+1];
    input(n, ar);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
             continue;
             float temp = ar[j][i];
            for(int k = i; k <= n; k++)
            {
                ar[j][k] = ar[j][k] - (temp/ar[i][i])*ar[i][k];
            }
        }
    }
    for(int i = 0; i < n; i++)
     {
        ar[i][n] = ar[i][n]/ar[i][i];
        ar[i][i] = 1;
     }
    display(n, ar);
}