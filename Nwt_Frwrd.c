#include <stdio.h>
#include <stdlib.h>

void input(int n, float mat[][n+1])
{
    printf("Enter the values of X :\n");
    for(int i = 0; i < n; i++)
    scanf("%f", &mat[i][0]);

    printf("Enter the values of Y :\n");
    for(int i = 0; i < n; i++)
    scanf("%f", &mat[i][1]);
}

void Frw_table(int n, float mat[][n+1])
{
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n-1; j++)
            mat[j][i+1] = mat[j+1][i] - mat[j][i];
}

void display(int n, float mat[][n+1])
{
    printf("\n\nX\tY\n");
    for(int i = 0; i < n; i++)
        {
            printf("%.1f %.3f ", mat[i][0], mat[i][1]);
            for(int j = 2; j <= n-i; j++)
                printf("%.4f ", mat[i][j]);
            printf("\n");
        }

}

int fact(int x)
{
    if(x == 0)
        return 1;
    return x * fact(x - 1);
}

void calc(int i, int n, float mat[][n+1], float p)
{
   
    float res = mat[i][1];
    for(int j = 2; j <= n-i; j++)
    {
        res = res + (mat[i][j]*p)/fact(j-1);
        p = p * (p-1);
    }
    printf("\nVALUE : %f", res);
}

int index_x(int n, int x, float mat[][n+1])
{
    int i = 0;
    while(x > mat[i][0])
        i++;
    return i-1;
}
int main()
{
    int n;
    printf("Enter the number of DATA POINTS :\n");
    scanf("%d", &n);

    int x;
    printf("Enter the value of X at which Y = ?");
    scanf("%d", &x);

    float mat_Forward[n][n+1];
    input(n, mat_Forward);

    
    int index = index_x(n, x, mat_Forward);
    printf("[%d]", index);

    float h = mat_Forward[1][0] - mat_Forward[0][0];
    float p = (x - mat_Forward[index][0])*1.0/h;

    Frw_table(n,mat_Forward);
    display(n, mat_Forward);
    calc(index, n, mat_Forward, p);

}