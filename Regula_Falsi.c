#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double value_eqn(double x)
{
   double res = x*exp(x) - cos(x);
   return res;
}
double eqn(int a, int b, int c, int d, double x)
{
    printf("INPUT THE COEFFICIENTS FOR THE EQUATION :\ a.x^3 + b.x^2 + c.x + d\n");
    scanf("%d%d%d%d", &a,&b,&c,&d);

    double res = a*x*x*x + b*x*x+ c*x + d;
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
double Regula_Falsi(double x_0, double x_1)
{
    double prev;
    double x_2 = 0.0;
     double dif = 0.0;
    int itr = 0;
       do 
       {
           printf("\n%d . \n%.4f & %.4f", itr+1, x_0,x_1);
           double y_1 = value_eqn(x_1);
           double y_0 = value_eqn(x_0);
           
           double num = x_0*y_1 - x_1*y_0;
           double denom = y_1 - y_0;
              
           //printf("\n%f %f", num, denom);
           x_2 = num/denom;

           //x_2 = ((x_0*(value_eqn(x_1) - x_1*(value_eqn(x_0))))/(value_eqn(x_1) - value_eqn(x_0)));
           double y_2 = value_eqn(x_2);
           if(y_0*y_2 < 0)
                {
                    prev = x_1;
                    x_1 = x_2; 
                }
            else
                {
                    prev = x_0;
                    x_0 = x_2;
                }
            itr++;

            dif = x_2 - prev;
       }while(dif >= 0.0001);
    return x_2;
}
void main()
{
    double h = 0;
    double l = -1;
    while(value_eqn(h) < 0)
    {
        l = h;
        h++;
    }
    printf("Lower Limit : %.4f\nUpper Limit : %.4f\n", l,h);
    printf("LOWER LIMIT VALUE : %.4f\n UPPER LIMIT VALUE : %.4f\n\n",value_eqn(l),value_eqn(h));


    double res = Regula_Falsi(l, h);
    printf("\nRegula Falsi Method : %.3f", Trunc_n(res, 3));
}