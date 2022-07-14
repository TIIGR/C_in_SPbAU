#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
     
double f(float x) {return log(x)*cos(x);}
double df(float x) {return cos(x)/x-log(x)*sin(x);}

int main()
{
    float xn, eps;
    printf ("Let's find the roots of ln(x)*cos(x).\n");
    printf ("Enter xn to continue: \n");
    scanf ("%f",&xn);
    if (xn <= 0) {
        printf("Incorrect data!\n");
        return -1;
    }
    printf("Epsilon:\n");
    scanf("%f", &eps);
    float x1 = xn - f(xn)/df(xn);
    float x0 = xn;
    while(fabs(x0-x1) > eps) {
        x0 = x1;
        x1 -= f(x1)/df(x1);
    }
    printf("Answer: %f", x1);
    return 0;    
}