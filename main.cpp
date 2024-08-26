#include "constants.h"
#include "input_functions.h"
#include "poltorashka_function.h"
#include "solver_functions.h"
#include "output_functions.h"

//#include <TXlib.h>
/*BACKLOG
-новая функция "квадратка" и "тесты"   +
-распихать по файлам                   +
*/

// TODO: побить по файлам (ввод, решалка, вывод),
// rename this file to main.cpp

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
            cat ();
            break;
        }
        default:
        {
            printf ( "Somehow ERROR in main input\n" );
            break;
        }
    }
}
