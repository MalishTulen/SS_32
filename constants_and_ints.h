enum roots
{
    ALLZERO = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
    A_IS_ZERO = 3,
    ERROR_ROOT = 666,
};

enum inputs
{
    INPUT_1 = '1',
    INPUT_2 = '2',
    INPUT_3 = '3',
};

const int NUM_TESTOV = 5;

const double EPC = 0.000001;

int SquareSolver ( double a, double b, double c, double *x1, double *x2 );

int inputin_32 ( char input, double *x );

void switch_to_answer ( double a, double b, double c, double *x1, double *x2, int amount_of_square_roots );

int run_testicals (   struct test * pointer  );

int moduler ( double x );

void kvadratka ( double a, double b, double c, double x1, double x2, int amount_of_square_roots );

void linear_solver ( double b, double c, double *x1 );

int inputer ();

void kvadratka ();

void tests();

void poltorashka ();


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct test
{
    int test_number;

    struct koeffs
    {
        double a;
        double b;
        double c;
    } koeffs;

    struct
    {
        double x1_expedo;
        double x2_expedo;
    } answers;

    int amount_of_square_roots_expedo;
};

test test_base[NUM_TESTOV] =
{
    { .test_number = 1, {.a = 1,  .b = 0,  .c = -4},  {.x1_expedo = 2,  .x2_expedo = -2}, .amount_of_square_roots_expedo = 2 },
    { .test_number = 2, {.a = 1,  .b = 0,  .c = -9},  {.x1_expedo = 3,  .x2_expedo = -3}, .amount_of_square_roots_expedo = 2 },
    { .test_number = 3, {.a = 1,  .b = -4, .c = 3},   {.x1_expedo = 3,  .x2_expedo = 1},  .amount_of_square_roots_expedo = 2 },
    { .test_number = 4, {.a = 1,  .b = 2,  .c = 1},   {.x1_expedo = -1, .x2_expedo = -1}, .amount_of_square_roots_expedo = 2 },
    { .test_number = 5, {.a = 9,  .b = 0,  .c = -81}, {.x1_expedo = 3,  .x2_expedo = -3}, .amount_of_square_roots_expedo = 2 },
};
