#include <stdio.h>
#include <string.h>


int strlen2(char *str)
{
    int c = 0;
    while (str[c] != '\0') {
        c++;
    }
    return c;
}

int main()
{
    char str[128];
    printf("Enter string: \n");
    gets(str);
    printf("strlen() result = %i\n", strlen(str));
    printf("strlen2() result = %i\n", strlen2(str));
    return 0;
}