#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
const int ALLZERO = -1;
const double EPC = 0.000001;
//Решение квадратных уравнений
int SS(double a, double b, double c, double *x1, double *x2);
int inputin_32 ( char input, double *x );
int switch_to_answer ( double a, double b, double c, double x1, double x2, int amount_of_Square_Roots );


//-----------------------------------------------------------------------
int main()
{
    double a = 0, b = 0, c = 0;

    inputin_32 ( 'a', &a );
    inputin_32 ( 'b', &b );
    inputin_32 ( 'c', &c );

    //printf ( "%lf %lf %lf", a, b, c );

    double x1 = 0, x2 = 0;
    int amount_of_Square_Roots = 0;

    switch_to_answer ( a, b, c, x1, x2, amount_of_Square_Roots );
}

//----------------------------------------------------------------
int switch_to_answer ( double a, double b, double c, double x1, double x2, int amount_of_Square_Roots )
{
    amount_of_Square_Roots = SS(a, b, c, &x1, &x2);

    switch(amount_of_Square_Roots)
    {
        case 0: printf("0 korney");
                break;

        case 1: printf("1 koren, x1=%g", x1);
                break;

        case 2: printf("2 kornya, %g and %g", x1, x2);
                break;

        case ALLZERO: printf("Impressive! Ochen mnogo korney!");
                break;

        default: printf("Erm What da sigma?");
                break;
    }
    return 0;
}


//----------------------------------------------------------------


int SS(double a, double b, double c, double *x1, double *x2)
{
    if (fabs(a) < EPC)
    {
        if (fabs(b) < EPC && fabs(c) < EPC)
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
            if (fabs(d) < EPC)
            {
                *x1 = *x2 = -b / (2 * a);

                return 1;
            }
            if (d > 0)
            {
                *x1 = (-b + sqrt(d)) / (2 * a);
                *x2 = (-b - sqrt(d)) / (2 * a);

                return 2;
            }
        }
    }
    return 0;
}

//------------------------------------------------


int inputin_32 ( char input, double *x )
{
    int scanf_status = 0;
    printf ("Insert koeff %c:", input);

    while (scanf_status != 1)
    {
        scanf_status = scanf ("%lf",x);

        if (scanf_status == 1)
        {
            break;
        }

        while (getchar() != '\n')
        {
            continue;
        }

        printf ("Insert again:");
    }

    return 0;
}








