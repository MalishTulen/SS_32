//Решение квадратных уравнений
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

enum Roots
{
ALLZERO = -1,
NO_ROOTS = 0,
ONE_ROOT = 1,
TWO_ROOTS = 2,
A_IS_ZERO = 3,
};

const double EPC = 0.000001;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int SquareSolver ( double a, double b, double c, double *x1, double *x2 );
int inputin_32 ( char input, double *x );
int switch_to_answer ( double a, double b, double c, double x1, double x2, int amount_of_Square_Roots );
void run_testicals ( int test_number, double a, double b, double c,
                    double x1_expedo, double x2_expedo, int amount_of_Square_Roots );
int abs ( double x );

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct test
{
    double a, b, c;
    double  x1_expedo, x2_expedo;
    int amount_of_Square_Roots;
};

test all_tests[5] = {};

//TB all_tests = { .test1.a = 1, .test1.b = 0, .c = -4, .x1_expedo = 2, .x2_expedo = -2, .amount_of_Square_Roots = 2};
//test1 = { .a = 1, .b = 0, .c = -4, .x1_expedo = 2, .x2_expedo = -2, .amount_of_Square_Roots = 2};
//test2 = { 1, 0, -9, 3, -3, 2};
//TESTO_BASE test3 = { 1, 0, -16, 4, -4, 2};

//-----------------------------------------------------------------------
int main ()
{
    double a = 0, b = 0, c = 0;

    inputin_32 ( 'a', &a );
    inputin_32 ( 'b', &b );
    inputin_32 ( 'c', &c );

    //printf ( "%lf %lf %lf", a, b, c );

    double x1 = 0, x2 = 0;
    int amount_of_Square_Roots = 0;

    switch_to_answer ( a, b, c, x1, x2, amount_of_Square_Roots );

    run_testicals( 1, 1, 0, -4, 2, -2, 2 );
}

//----------------------------------------------------------------
int switch_to_answer ( double a, double b, double c, double x1, double x2, int amount_of_Square_Roots )
{
    amount_of_Square_Roots = SquareSolver ( a, b, c, &x1, &x2 );

    switch ( amount_of_Square_Roots )
    {
        case NO_ROOTS: printf ( "0 korney" );
                break;

        case ONE_ROOT: printf ( "1 koren, x1 = %g", x1 );
                break;

        case TWO_ROOTS: printf ( "2 kornya:\nx1 = %g\nx2 = %g", x1, x2 );
                break;

        case ALLZERO: printf ( "Impressive! Ochen mnogo korney!" );
                break;

        case A_IS_ZERO: printf ( "Erm What da sigma?" );
                break;

        default: printf ( "HOW????" );

    }
    return 0;
}


//----------------------------------------------------------------


int SquareSolver ( double a, double b, double c, double *x1, double *x2 )
{
    if ( abs(a) == 0 )
    {
        if ( abs(b) == 0 && abs(c) == 0 )
        {
            return ALLZERO;
        }
        else
        {
            return A_IS_ZERO;
        }
    }
    else
    {
        double d = b * b - 4 * a * c;
        if ( d < 0 )
        {
            return NO_ROOTS;
        }
        else
        {
            if ( abs ( d ) == 0 )
            {
                *x1 = *x2 = -b / (2 * a);

                return ONE_ROOT;
            }
            if (d > 0)
            {
                *x1 = ( -b + sqrt ( d ) ) / (2 * a);
                *x2 = ( -b - sqrt ( d ) ) / (2 * a);

                return TWO_ROOTS;
            }
        }
    }
    return 0;
}

//------------------------------------------------


int inputin_32 ( char input, double *x )
{
    int scanf_status = 0;
    printf ( "Insert koeff %c:", input );

    while ( scanf_status != 1 )
    {
        scanf_status = scanf ( "%lg", x );

        if ( scanf_status == 1 )
        {
            break;
        }

        while ( getchar() != '\n' )
        {
            continue;
        }

        printf ( "Insert again:" );
    }

    return 0;
}


//-------------------------------------------------------------------------------


void run_testicals ( int test_number, double a, double b, double c,
                    double x1_expedo, double x2_expedo, int amount_of_Square_Roots )
{
    double x1 = 0, x2 = 0;

    printf ( "\nTest %d:\n a = %lg, b = %lg, c = %lg, pri etom  ", test_number, a, b, c );

    switch_to_answer ( a, b, c, x1, x2, amount_of_Square_Roots );

    printf ( "\nExpected: x1 = %lg, x2 = %lg and %d korney", x1_expedo, x2_expedo, amount_of_Square_Roots );

}

//----------------------------------------------------------------------------------

int abs ( double x )
{
    if ( ( fabs ( x ) > EPC ) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
