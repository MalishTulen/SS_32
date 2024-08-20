#include <stdio.h>
#include <math.h>
#include <assert.h>
const int ALLZERO = -1;
const double Epc = 0.000001;
//Решение квадратных уравнений
int SS(double a, double b, double c, double *x1, double *x2);

//-----------------------------------------------------------------------
int main()
{
    double a = 0, b = 0, c = 0;
    printf ("Insert koeff a, b, c:");
    while ((scanf("%lf %lf %lf", &a, &b, &c)) != 3)
        {
            a = 0, b = 0, c = 0;
            printf("Insert koeff a, b, c:");
            scanf("%lf %lf %lf", &a, &b, &c);
        }
    scanf("%lf %lf %lf", &a, &b, &c);
    double x1 = 0, x2 = 0;
    int Amount_of_Square_Roots = 0;
    Amount_of_Square_Roots = SS(a, b, c, &x1, &x2);
    switch(Amount_of_Square_Roots)
    {
        case 0: printf("0 korney");
                break;
        case 1: printf("1 koren, x1=%g", x1);
                break;
        case 2: printf("2 kornya, %g and %g", x1, x2);
                break;
        case ALLZERO: printf("Impressive! Ochen mnogo korney!");
                break;
        default: printf("a!=0");
                break;
    }
    return 0;
}

//----------------------------------------------------------------


int SS(double a, double b, double c, double *x1, double *x2)
{
    if (fabs(a) < Epc)
    {
        if (fabs(b) < Epc && fabs(c) < Epc)
        {
            return ALLZERO;
        }
        else
        {
            return 60;
        }
    }
    else
    {
        double d = b*b - 4*a*c;
        if (d < 0)
        {
            return 0;
        }
        else
        {
            if (fabs(d) < Epc)
            {
                *x1 = *x2 = -b/2/a;
                return 1;
            }
            if (d > 0)
            {
                *x1 = (-b+sqrt(d))/(2*a);
                *x2 = (-b-sqrt(d))/(2*a);
                return 2;
            }
        }
    }
    return 0;
}
