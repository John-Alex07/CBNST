#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double value_eqn(double x)
{
   double res = x*x*x - 2*x;
   return res;
}
double value_derivate(double x)
{
   double res = 3*x*x - 2;
   return res;
}
double Trunc_n(double x, int n)
{
    int mult = pow(10,n);
    x = (int)(x * mult);
    x = x/mult;
   // printf("\nTRUNCATED VALUE OF x : %.4f\n",x);
    return x;
}
double Newton_Raption(double x_0)
{
    double x_1 = 0 ;
    double prev;
   do
   {
      //printf("X_0 : %d\n", x_0);
      double f_x = value_eqn(x_0);
	  //printf("%f\n", f_x);
      double f_X = value_derivate(x_0);
	  //printf("%f\n",f_X);
      double sub = f_x/f_X;
      //printf("%f\n",x_1);
	  //printf("%f\n\n",x_0);
      x_1 = x_0 - sub;
	  prev = x_0;
	  x_0 = x_1;
   }while(fabs(x_1 - prev) >= 0.0001);

   return x_1;
}
void main()
{
    double h = -4;
    double l = -5;
    while(value_eqn(h) < 0)
    {
        l = h;
        h++;
    }
    printf("Lower Limit : %.4f\nUpper Limit : %.4f\n", l,h);
    printf("LOWER LIMIT VALUE : %.4f\n UPPER LIMIT VALUE : %.4f\n\n",value_eqn(l),value_eqn(h));

   double x_0 = (l+h)/2;
   double res = Newton_Raption(x_0);
    printf("\nNewton_Raption Method : %.3f", Trunc_n(res, 3));
}