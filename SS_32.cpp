#include <stdio.h>
#include <math.h>
const int UNREAL_PIZDETS = -1;
//������� ���������� ���������

int main()
{
    double a=0,b=0,c=0;
    printf("Insert koeff a,b,c:");
    scanf("%lf %lf %lf",&a,&b,&c);
    double x1=0,x2=0;
    int Amount_of_Square_Roots;
    Amount_of_Square_Roots=SS(a,b,c,&x1,&x2);
    switch(Amount_of_Square_Roots)
    {
        case 0: printf("0 korney");
                break;
        case 1: printf("1 koren, x1=%g",x1);
                break;
        case 2: printf("2 kornya, %g and %g",x1,x2);
                break;
        case UNREAL_PIZDETS: printf("Impressive! Ochen mnogo korney!");
                break;
        default: printf("a!=0");
                break;
    }
    return 0;
}
int SS(a,b,c,&x1,&x2,Amount_of_Square_Roots)
{
    if (a==0)
        Amount_of_Square_Roots=60;
        break;
    else
        int d;
        d=b*b-4*a*c;
        if (d<0)
            Amount_of_Square_Roots=0;
            break;
        else:
            if (d==0)
                Amount_of_Square_Roots=1;
                x1=x2=-b/2/a
                break;
            if (d>0)
                Amount_of_Square_Roots=2;
                x1=(-b+sqrt(d))/(2*a);
                x2=(-b-sqrt(d))/(2*a);
                break;


}
