#include <stdio.h>
#include <string.h>
 
 
 int main()
 {
    int i;
    char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("Enter number of month: ");
    scanf("%d", &i);
    if ((1 <= i) && (i <= 12)) {
        printf("%s", months[i-1]);
        return 0;
    } else {
        printf("Incorrect data!");
        return -1;
    }
 }