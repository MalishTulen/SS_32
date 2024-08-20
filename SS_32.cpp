#include <stdio.h>
#include <math.h>
const int UNREAL_PIZDETS = -1;
//Решение квадратных уравнений

int main()
{
    double a=0,b=0,c=0;
    printf("Insert koeff a,b,c:");
    scanf("%lf %lf %lf",&a,&b,&c);
    double x1=0,x2=0;
    AMSR=SS(a,b,c,&x1,&x2);
    switch(AMSR)
    {
        case 0: printf("0 korney");
                break;
        case 1: printf("1 koren, x1=%g",x1);
                break;
        case 2: printf("2 kornya, %g and %g",x1,x2);
                break;
        case UNREAL_PIZDETS: printf("Impressive! Ochen mnogo korney!");
                break;
        default: printf("WTF, HOW????");
                break;
    }
    return 0;
}
int SS(a,b,c,&x1,&x2)
{

}
