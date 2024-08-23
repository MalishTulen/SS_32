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
enum inputs
{
    INPUT_1 = '1',
    INPUT_2 = '2',
};
enum ntests
{
    N_kg_TESTA = 5,
};

const double EPC = 0.000001;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int SquareSolver ( double a, double b, double c, double *x1, double *x2 );
int inputin_32 ( char input, double *x );
int switch_to_answer ( double a, double b, double c, double *x1, double *x2, int amount_of_square_roots );
int run_testicals (   struct test * pointer  );
int moduler ( double x );
void kvadratka ( double a, double b, double c, double x1, double x2, int amount_of_square_roots );
void linear_solver ( double b, double c, double x1, int amount_of_square_roots );
int inputer ( );

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct test
{
    int test_number;
    double a, b, c;
    double  x1_expedo, x2_expedo;
    int amount_of_square_roots_expedo;
};


test test_base[N_kg_TESTA] =
{
    { .test_number = 1, .a = 1,  .b = 0,  .c = -4,  .x1_expedo = 2,  .x2_expedo = -2, .amount_of_square_roots_expedo = 2 },
    { .test_number = 2, .a = 1,  .b = 0,  .c = -9,  .x1_expedo = 3,  .x2_expedo = -3, .amount_of_square_roots_expedo = 2 },
    { .test_number = 3, .a = 1,  .b = -4, .c = 3,   .x1_expedo = 3,  .x2_expedo = 1,  .amount_of_square_roots_expedo = 2 },
    { .test_number = 4, .a = 1,  .b = 2,  .c = 1,   .x1_expedo = -1, .x2_expedo = -1, .amount_of_square_roots_expedo = 2 },
    { .test_number = 5, .a = 9,  .b = 0,  .c = -81, .x1_expedo = 3,  .x2_expedo = -3, .amount_of_square_roots_expedo = 2 },
};



//-----------------------------------------------------------------------
//-------------------------------------------------------------------------
int main ()
{
    switch ( inputer () )
    {
        case INPUT_1:
        {
            double a = 0, b = 0, c = 0;

            inputin_32 ( 'a', &a );
            inputin_32 ( 'b', &b );
            inputin_32 ( 'c', &c );

            //printf ( "%lf %lf %lf", a, b, c );

            double x1 = 0, x2 = 0;
            int amount_of_square_roots = 0;

            switch_to_answer ( a, b, c, &x1, &x2, amount_of_square_roots );
            break;
        }
        case INPUT_2:
        {
            int right_test_count = 0;
            for ( int i = 0; i < N_kg_TESTA; i++ )
            {
                right_test_count += run_testicals ( &test_base[i] );
            }
            printf ( "\n\n*************************************\n*****"
            "Amount of right tests: %d/%d******\n*************************************", right_test_count, N_kg_TESTA );
            break;
        }
        default:
        {
            printf("Somehow ERROR in main input\n");
            break;
        }
    }
}
//----------------------------------------------------------------
//----------------------------------------------------------------


int switch_to_answer ( double a, double b, double c, double *x1, double *x2, int amount_of_square_roots )
{
    amount_of_square_roots = SquareSolver ( a, b, c, x1, x2 );

    switch ( amount_of_square_roots )
    {
        case NO_ROOTS:
            printf ( "%d korney ", amount_of_square_roots );
            break;

        case ONE_ROOT:
            printf ( "%d koren:\n x1 = x2 = %lg", amount_of_square_roots, *x1 );
            break;

        case TWO_ROOTS:
            printf ( "%d kornya:\nx1 = %lg\nx2 = %lg", amount_of_square_roots, *x1, *x2 );
            break;

        case ALLZERO:
            printf ( "Impressive! Ochen mnogo korney!" );
            break;

        case A_IS_ZERO:
            linear_solver ( b, c, *x1, amount_of_square_roots );
            break;

        default:
            printf ( "HOW????" );

    }
    return 0;
}


//----------------------------------------------------------------


int SquareSolver ( double a, double b, double c, double *x1, double *x2 )
{
    if ( moduler ( a ) == 1 )
    {
        if ( moduler ( b ) == 1)
        {
            if (moduler ( c ) == 1 )
            {
                return ALLZERO;
            }
            else
            {
                return NO_ROOTS;
            }
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
            if ( moduler ( d ) == 1 )
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


int run_testicals ( struct test * pointer  )
{
    double x1 = 0, x2 = 0;
    int amount_of_square_roots = 0;

    printf ( "\n----------------------------------------------\n\nTest %d:\n a = %lg, b = %lg, c = %lg, pri etom  ", pointer -> test_number,
    pointer -> a, pointer -> b, pointer -> c );

    switch_to_answer ( pointer -> a, pointer -> b, pointer -> c, &x1, &x2, amount_of_square_roots );

    printf ( "\nExpected: x1 = %lg, x2 = %lg and %d korney\n", pointer -> x1_expedo, pointer -> x2_expedo, pointer -> amount_of_square_roots_expedo );

    if ( ( moduler ( x1 - pointer -> x1_expedo ) == 1 ) && ( moduler ( x2 - pointer -> x2_expedo ) == 1 )  )
    {
        return 1;
    }
    else
    {
        printf ( "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n       TEST %d IS WRONG\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", pointer -> test_number );
        return 0;
    }
}

//----------------------------------------------------------------------------------

int moduler ( double x )
{
    if ( ( fabs ( x ) > EPC ) )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//----------------------------------------------------------------------------------

void linear_solver ( double b, double c, double x1, int amount_of_square_roots )
{
    x1 = -c / b;
    amount_of_square_roots = 1;
    printf ( "%d koren:\nx1 = %lg", amount_of_square_roots, x1 );
}

int inputer (  )
{
    int checker = 0;
    printf ( "~~~~KVADRATKA~~~~\n\nHello!\npress 1 to solve qudratnoe uravnenie\npress 2 to run tests\nYour input:");
    while ( ( checker = getchar () ) != EOF )
    {
        if ( checker != '1' && checker != '2' )
        {
            while ( getchar() != '\n')
            {
                continue;
            }
            printf ( "Wrong input! Try again:" );
        }
        else
        {
            return checker;
        }
    }
    return 0;
}
