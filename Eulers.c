#include <stdio.h>
#include <stdlib.h>

float eqn(float x, float y)
{
    return x + y;
}

void Eulers(float x, float y, float p, float _x)
{

    while(_x - x >= 0.0001)
    {
        y = y + p*eqn(x,y);
        x = x + p;
    }

    printf("Result : %f", y);
}

int main()
{
    float x;
    float y;
    printf("Enter the intitial values of the Equation :\n");
    scanf("%f %f", &x, &y);

    int h;
    printf("Enter the step size :\n");
    scanf("%d", &h);

    float _x;
    printf("Enter the values of X at which Y = ? : ");
    scanf("%f", &_x);

    float p = (_x - x)*1.0/h;
    printf("%.3f", p);
    Eulers(x,y,p, _x);

}