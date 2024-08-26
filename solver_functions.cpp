#include "constants.h"
#include "input_functions.h"
#include "poltorashka_function.h"
#include "solver_functions.h"
#include "output_functions.h"

void kvadratka ()
{
    double a = 0, b = 0, c = 0;

    inputin_32 ( 'a', &a );
    inputin_32 ( 'b', &b );
    inputin_32 ( 'c', &c );

    double x1 = 0, x2 = 0;
    int amount_of_square_roots = 0;

    switch_to_answer ( a, b, c, &x1, &x2, &amount_of_square_roots );
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void switch_to_answer ( double a, double b, double c, double *x1,
                        double *x2, int *amount_of_square_roots )
{
    assert ( x1 && "ERROR: adress x1" );
    assert ( x2 && "ERROR: adress x2" );
    assert ( x1 != x2 && "ERROR: adress x1 = adress x2");

    *amount_of_square_roots = SquareSolver ( a, b, c, x1, x2 );
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void linear_solver ( double b, double c, double *x1 )
{
    assert ( x1 && "ERROR: adress x1" );

    *x1 = -c / b;
}

//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int run_testicals ( const test * ptr_to_test )  // TODO: new file
{
    double x1 = 0, x2 = 0;
    int amount_of_square_roots = 0;

    switch_to_answer ( ptr_to_test -> koeffs.a, ptr_to_test -> koeffs.b,
                       ptr_to_test -> koeffs.c, &x1, &x2, &amount_of_square_roots );

    // TODO: make as func
    printf ( "\n----------------------------------------------\n\nTest %d:\n a = %lg, b = %lg, c = %lg, pri etom  ",
             ptr_to_test -> test_number, ptr_to_test -> koeffs.a, ptr_to_test -> koeffs.b, ptr_to_test -> koeffs.c );
    output_giver ( amount_of_square_roots, &x1, &x2);
    printf ( "\nExpected: x1 = %lg, x2 = %lg and %d korney\n", ptr_to_test -> answers.x1_expedo, ptr_to_test -> answers.x2_expedo,
                                                               ptr_to_test -> amount_of_square_roots_expedo );

    if ( ( moduler ( x1 - ptr_to_test -> answers.x1_expedo ) == 1 ) && ( moduler ( x2 - ptr_to_test -> answers.x2_expedo ) == 1 )  )
    {
        return 1;
    }
    else
    {
        printf ( "\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n       TEST %d IS WRONG\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n", ptr_to_test -> test_number );
        return 0;
    }
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int SquareSolver ( double a, double b, double c, double *x1, double *x2 )
{
    assert ( x1 && "ERROR: adress x1" );
    assert ( x2 && "ERROR: adress x2" );
    assert ( x1 != x2 && "ERROR: adress x1 = adress x2");

    if ( ( int checker_result = linear_checker ( a, b, c, x1, x2 ) ) != ERROR_ROOT )
    {
        return checker_result;
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
            return main_solver ( a, b, c, x1, x2 );
        }
    }

    return ERROR_ROOT;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||

int moduler ( double x ) // TODO: make as bool
{
    return !( fabs ( x ) > EPC );
}


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

int linear_checker ( double a, double b, double c, double *x1, double *x2 )
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
             linear_solver ( b, c, x1 );
             return ONE_ROOT;
        }
    }
    else // TODO: remove else
    {
        return ERROR_ROOT;
    }
}


int main_solver ( double a, double b, double c, double *x1, double *x2 )
{
    double d = b * b - 4 * a * c;

    if ( moduler ( d ) == 1 )
    {
        *x1 = *x2 = -b / (2 * a);  // TODO: second root as NAN

        return ONE_ROOT;
    }

    if (d > 0)
    {
        *x1 = ( -b + sqrt ( d ) ) / (2 * a);
        *x2 = ( -b - sqrt ( d ) ) / (2 * a);

        return TWO_ROOTS;
    }
}
