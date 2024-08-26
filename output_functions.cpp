#include "constants.h"
#include "input_functions.h"
#include "poltorashka_function.h"
#include "solver_functions.h"
#include "output_functions.h"


void output_giver ( int amount_of_square_roots, double *x1, double *x2)
{
    switch ( amount_of_square_roots )
    {
        case NO_ROOTS:
        {
            printf ( "%d korney ", amount_of_square_roots );
            break;
        }
        case ONE_ROOT:
        {
            printf ( "%d koren:\n x1 = x2 = %lg", amount_of_square_roots, *x1 );
            break;
        }
        case TWO_ROOTS:
        {
            printf ( "%d kornya:\nx1 = %lg\nx2 = %lg", amount_of_square_roots, *x1, *x2 );
            break;
        }
        case ALLZERO:
        {
            printf ( "Impressive! Ochen mnogo korney!" );
            break;
        }
        default:
        {
            printf ( "HOW????" );
        }
    }
}


//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void tests ()
{
    int right_test_count = 0;

    for ( int i = 0; i < NUM_TESTOV; i++ )
    {
        right_test_count += run_testicals ( &test_base[i] );
    }

    printf ( "\n\n*************************************\n*****"
             "Amount of right tests: %d/%d******\n*************************************",
             right_test_count, NUM_TESTOV );
}
