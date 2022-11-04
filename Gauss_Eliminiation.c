#include <stdio.h>
#include <stdlib.h>

void input(int n, float eq_arr[n][n+1])
{
    printf("INPUT THE COEFFICIENTS OF");
   for(int i = 0; i < n; i++)
   {
     printf(" EQUATION %d :\n", (i+1));
     for(int j = 0; j < n; j++)
       scanf("%f", &eq_arr[i][j]);
      printf(" = ");
      scanf("%f", &eq_arr[i][n]);
   }
}

void display(int n, float eq_arr[n][n+1])
{
  printf("\nTHE MATRIX OF EQUATIONS :\n");
    for(int i = 0; i < n; i++)
      {
        for(int j = 0; j <= n; j++)
            printf("%f ", eq_arr[i][j]);
        printf("\n");
      }
}
void swap_rows(int n, float eq_arr[][n+1], int r_i, int r_j)
{
  for(int i = 0; i < n; i++)
  {
    int t = eq_arr[r_i][i];
    eq_arr[r_i][i] = eq_arr[r_j][i];
    eq_arr[r_j][i] = t;
  }
}
void eval(int n, float ar[][n+1])
{
  int var[n];
  for(int i = 0; i < n; i++)
   var[i] = 0;

  for(int i = n-1; i > 0; i--)
  {
      for(int j = i; j < n-1; j++)
        var[i] = var[i] + ar[i][j]*var[i+1];
      var[i] = ar[n-1][n]/var[i];
  }
}
int main()
{
    int n;
    printf("Enter the Number of Equations\n");
    scanf("%d",&n);
     
    float ar[n][n+1];
    input(n, ar);
    int c = 0, r = 0;
   
   for(int c = 0; c < n-1;c++)
   {
      for(int i = c+1; i < n; i++)
      {
        float temp = ar[i][c];
        for(int j = c; j <= n; j++)
          {
            ar[i][j] = ar[i][j] - temp/ar[c][c]*ar[c][j];  
          }
      }
   }
    display(n, ar);
    eval(n, ar);
    
}