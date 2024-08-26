#include "constants.h"
#include "input_functions.h"
#include "poltorashka_function.h"
#include "solver_functions.h"
#include "output_functions.h"

int inputin_32 ( char input, double *x )
{
    assert ( x && "ERROR: adress x" );

    int scanf_status = 0;
    printf ( "Insert koeff %c:", input );

    while ( scanf_status != 1 )
    {
        scanf_status = scanf ( "%lg", x );

        if ( scanf_status == 1 )
        {
            break;
        }

        buf_cleaner();

        printf ( "Insert again:" );
    }

    return ERROR_ROOT;
}

//|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


int inputer ()
{
    printf ( "~~~~KVADRATKA~~~~\n\nHello!\npress 1 to solve qudratnoe uravnenie\npress 2 to run tests\nYour input:");

    while ( ( int checker = getchar () ) != EOF )
    {
        if ( checker != '1' && checker != '2' && checker != '3' )
        {
            buf_cleaner();

            printf ( "Wrong input! Try again:" );
        }
        else
        {
            return checker;
        }
    }

    return ERROR_ROOT;
}


//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

void buf_cleaner()
{
    while ( getchar() != '\n')
    {
        continue;
    }
}
