#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    float a, b; char sign;
    printf("Welcome to arithmetic calculator! List of available operations: {+,-,*,/,^}\n");
    printf("Enter your arithmetic opetation on two numbers here (for example: 2 + 3): ");
    scanf("%f %c %f", &a, &sign, &b);
    if (sign == '0') {
        printf("Bye");
        return 0;
    } else if (sign == '+') {
        printf("%f", a + b);
        return 0;
    } else if (sign == '-') {
        printf("%f", a - b);
        return 0;
    } else if (sign == '*') {
        printf("%f", a * b);
        return 0;
    } else if (sign == '/') {
        if (b == 0) {
            printf("Incorrect data!");
            return -1;
        } else {
            printf("%f", a / b);
            return 0;
        }
    } else if (sign == '^') {
        if (a < 0) {
            printf("Incorrect data!");
            return -1;
        }  else {
            printf("%f", pow(a, b));
            return 0;
        }
    } else {
        printf("Incorrect data!");
        return -1;
    }
}