#include <stdio.h>
#include <stdlib.h>

void input(int n, float ar[])
{
    for(int i = 0; i < n; i++)
        scanf("%f", &ar[i]);
}

void Lagrange(int n, float x_ar[], float y_ar[], float x)
{
    float res = 0;
    for(int i = 0; i < n; i++)
    {
        float num = 1, denom = 1;
        for(int j = 0; j < n; j++)
            if(j != i)
                {
                    num = num * (x - x_ar[j]);
                    denom = denom * (x_ar[i] - x_ar[j]);
                }
        res = res + (num/denom)* y_ar[i];
    }

    printf("RESULT : %.4f", res);
}

int main()
{
    int n;
    printf("Enter the number of Data Points :\n");
    scanf("%d", &n);

    float x_ar[n];
    float y_ar[n];

    printf("Enter the values of X :\n");
    input(n, x_ar);

    printf("Enter the values of Y :\n");
    input(n, y_ar);

    float x;
    printf("Enter the values of X at which Y = ? : ");
    scanf("%f", &x);

    Lagrange(n, x_ar, y_ar, x);
}