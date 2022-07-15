#include <stdio.h>  
#include <stdlib.h>
#include <string.h> 


int main()
{
    char s[128];
    printf("\nInput you'r string (for example: a-z, 0-9): ");
    scanf("%s", &s);
    if (s[1] == '-') {
        int a = (int)s[0], b = (int)s[2];
        if (b > a) {
            for (int i = a; i <= b; i++) {
                printf("%c", i);
            }
        }
        else {
            for (int i = a; i >= b; i--) {
                printf("%c", i);
            }
        }
        printf("\n");
        return 0;
    } else {
        printf("Incorrect data!");
        return -1;
    }
}