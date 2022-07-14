#include <stdio.h>
 
void squeeze (char s1[], char s2[]);
 
int main()
{
    char str1[128], str2[128];
    printf("Строка 1: ");
    gets(str1);
    printf("Строка 2: ");
    gets(str2);
    squeeze(str1, str2);
    printf("Результат: %s\n", str1);
    return 0;
}
 
void squeeze (char s1[], char s2[])
 
    {
        int i, j, k;
        for (i = k = 0; s1[i] != '\0'; i++) {
            for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
                ;
            if (s2[j] == '\0')
                s1[k++] = s1[i];
        }
        s1[k] = '\0';
    }