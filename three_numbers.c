#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int i, j, k;
    printf("Please, enter your three-digit positive number:\n");
    scanf("%d", &k);
    i = 0; j = k;
    while(j != 0) {
        j /= 10;
        i++;
    }
    if (i != 3 || k < 0) {
        printf("Incorrect data!\n");
        return -1;
    } else {
        int a = k / 100;
        int b = (k / 10) % 10;
        int c = k % 10;
        printf("Sum and product for number is: %d %d\n", a + b + c, a * b * c);
        return 0;
    }
}