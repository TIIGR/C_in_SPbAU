#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
     
double f(float x) {
    return x*x+6*x-3;
}
 
int main()
{
    int s;
    float a,b,c,k,eps,x=0;
    printf ("Let's find the roots of x*x+6*x-3.\n");
    printf ("Enter [a,b] to continue: \n");
    scanf ("%f %f",&a,&b);
    printf("Epsilon:\n");
    scanf("%f", &eps);
    if (f(a)*f(b) <= 0) {
        while (fabs(b-a)>eps) {
            c=(b+a)/2;
            if (f(c)*f(b)<0) a=c;
            else b=c;
        }
        printf("Answer: %.10f\n",c);
        return 0;
    } else {
        printf("Error! No roots or 2 roots in [a,b]");
        return -1;
    }
}