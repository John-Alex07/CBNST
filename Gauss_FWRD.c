#include <stdio.h>
#include <stdlib.h>

void input(int n, float mat[][n+1])
{
    printf("Enter the values of X :\n");
    for(int i = 0; i < n; i++)
        scanf("%f", &mat[i][0]);
    
    printf("Enter the values of Y :\n");
    for(int j = 0; j < n; j++)
        scanf("%f", &mat[j][1]);
}

void display(int n, float mat[][n+1])
{
    for(int i = 0; i < n; i++)
    {
        printf("%.3f  %.3f ", mat[i][0], mat[i][1]);
        for(int j = 2; j <= n-i; j++)
            printf("%.3f ", mat[i][j]);
        printf("\n");
    }
}

void fwd_table(int n, float mat[][n+1])
{
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++)
            mat[j][i+1] = mat[j+1][i] - mat[j][i];
}

int index_x(int n, float mat[][n+1], float x)
{
    int i = 0;
    while(x > mat[i][0])
        i++;
    return i-1;
    
}

int fact(int x)
{
    if( x == 0)
        return 1;
    return x * fact(x - 1);
}

void calc(int n, float mat[][n+1], int index, float p)
{

    float res = 0;
    res = mat[index][1];
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
            {
                res = res + (p * mat[index][i]/fact(i-1));
                p = p*(p - 1);
            }
            else
            {
                res = res + (p * mat[index - 1][i]/fact(i-1));
                p = p *(p + 1);
            }

    }
    printf("RESULT : %.2f", res);
}

int main()
{
    int n;
    printf("Enter the number of Data Points :\n");
    scanf("%d", &n);

    float mat[n][n+1];
    input(n, mat);

    float x;
    printf("Enter the value of X at which Y = ? : ");
    scanf("%f", &x);
    
    int index = index_x(n, mat, x);
    printf("[%d]\n", index);

    float p = (x - mat[index][0])/(mat[1][0] - mat[0][0]);
    printf("%.3f\n", p);

    fwd_table(n, mat);
    display(n, mat);
    calc(n, mat, index, p);
}