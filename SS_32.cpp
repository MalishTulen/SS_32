#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "constants_and_ints.h"
#include "functions.cpp"

//#include <TXlib.h>
/*BACKLOG
-новая функция "квадратка" и "тесты"   +
-распихать по файлам                   +
*/

int main ()
{
    switch ( inputer () )
    {
        case INPUT_1:
        {
            kvadratka ();
            break;
        }
        case INPUT_2:
        {
            tests ();
            break;
        }
        case INPUT_3:
        {
            poltorashka ();
            break;
        }
        default:
        {
            printf ( "Somehow ERROR in main input\n" );
            break;
        }
    }
}
