#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float Abs_Error(float x, float x_)
{
   float Ea =  x - x_;
   return Ea;
}

float Rel_Error(float x, float x_)
{
    float Rel_Er = (x-x_)/x;
    return Rel_Er;
}

float Rel_Error_per(float Er)
{
    Er = Er*100;
    return Er;
}
float Round(float x)
{
    printf("ROUNDED VALUE OF x : %.4f",x);
}

float Trunc_n(float x, int n)
{
    int mult = pow(10,n);
    x = (int)(x * mult);
    x = x/mult;
    printf("\nTRUNCATED VALUE OF x : %.4f\n",x);
    return x;
}

float Round_n(float x, int n)
{
    int mult = pow(10,n+1);
    x = x * mult;
    int r = (int)x % 10;

    if(r >=5)
    {
        x = (int)x/10;
        x = x + 1;
    }
    else
    x = (int)x/10;

    x = x/mult*10;
    return x;

    printf("ROUNDED VALUE OF x upto %d digits : %.4f\n", n,x);
}
int main()
{
   float x,x_;
   printf("Enter the value of x : \n");
   scanf("%f", &x);

   while((int) x != 0)
      x = x/10;
     
     x_ = Round_n(x, 4);
     //x_ = Trunc(x);
   
   printf("X : %f && X_ : %.4f", x,x_);
   float Ea = Abs_Error(x,x_);
   float Er = Rel_Error(x,x_);
   float Ep = Rel_Error_per(Er);

   printf("\nABSOLUTE ERROR : %.4f \nRELATIVE ERROR : %.4f \nRELATIVE ERROR PERCENTAGE : %.4f\n", fabs(Ea), fabs(Er), fabs(Ep));
}
