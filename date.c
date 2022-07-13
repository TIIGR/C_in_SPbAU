#include <stdio.h>

  
int main()
{
    int d1, m1, y1, d2, m2, y2;
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_month_v[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("Enter first date (dd.mm.yyyy): \n");
    scanf("%d.%d.%d", &d1, &m1, &y1);
    printf("Enter second date (dd.mm.yyyy): \n");
    scanf("%d.%d.%d", &d2, &m2, &y2);

    if (y1 < 1 || y2 < 1 || m1 < 1 || m1 > 12 || m2 < 1 || m2 > 12) {
        printf("Incorrect data!\n");
        return -1;
    }
    if (y1 == y2 && m1 == m2 && d1 == d2) {
        printf("These dates are equivalent!\n");
        return 0;
    }

    if (y1 % 4 == 0) {
        if ((y1 % 100 != 0) && (d1 > days_in_month_v[m1 - 1])) {
            printf("Incorrect data!\n");
            return -1;
        } else if (y1 % 100 == 0) {
            if ((y1 % 400 == 0) && (d1 > days_in_month_v[m1 - 1])) {
                printf("Incorrect data!\n");
                return -1;
            } else if ((y1 % 400 != 0) && (d1 > days_in_month[m1 - 1])) {
                printf("Incorrect data!\n");
                return -1;
            }
        }
    } else {
        if (d1 > days_in_month[m1 - 1]) {
            printf("Incorrect data!\n");
            return -1;
        }
    }
    if (y2 % 4 == 0) {
        if ((y2 % 100 != 0) && (d2 > days_in_month_v[m2 - 1])) {
            printf("Incorrect data!\n");
            return -1;
        } else if (y2 % 100 == 0) {
            if ((y2 % 400 == 0) && (d2 > days_in_month_v[m2 - 1])) {
                printf("Incorrect data!\n");
                return -1;
            } else if ((y2 % 400 != 0) && (d2 > days_in_month[m2 - 1])) {
                printf("Incorrect data!\n");
                return -1;
            }
        }
    } else {
        if (d2 > days_in_month[m2 - 1]) {
            printf("Incorrect data!\n");
            return -1;
        }
    }

    if (y1 > y2) {
        printf("%02d.%02d.%04d > %02d.%02d.%04d", d1, m1, y1, d2, m2, y2);
        return 0;
    } else if (y1 < y2) {
        printf("%02d.%02d.%04d < %02d.%02d.%04d", d1, m1, y1, d2, m2, y2);
        return 0;
    } else {
        if (m1 > m2) {
            printf("%02d.%02d.%04d > %02d.%02d.%04d", d1, m1, y1, d2, m2, y2);
            return 0; 
        } else if (m1 < m2) {
            printf("%02d.%02d.%04d < %02d.%02d.%04d", d1, m1, y1, d2, m2, y2);
            return 0;
        } else {
            if (d1 > d2) {
                printf("%02d.%02d.%04d > %02d.%02d.%04d", d1, m1, y1, d2, m2, y2);
                return 0;
            } else if (d1 < d2) {
                printf("%02d.%02d.%04d < %02d.%02d.%04d", d1, m1, y1, d2, m2, y2);
                return 0;
            }
        }
    }
} 