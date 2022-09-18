#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846


int main()
{
      int q;
      float a, b, c, P;
      printf("Area and perimeter for triangle (type 0), rectangle (type 1) or circle (type 2)?\n");
      scanf("%d", &q);
      if (q == 0) {
            printf("Please, enter three sides of the triangle: ");
            scanf("%f %f %f", &a, &b, &c);
            if (c >= b + a || b >= c + a || a >= b + c) {
                  printf("Incorrect data!");
                  return -1;
            } else {
            P = a + b + c;
            printf("Perimeter and area for triange is: %f %f\n", P, sqrt(P/2 * (P/2 - a) * (P/2 - b) * (P/2 - c)));
            return 0;
            }
      } else if (q == 1) {
            printf("Please, enter two sides of the rectangle: ");
            scanf("%f %f", &a, &b);
            printf("Perimeter and area for rectange is: %f %f\n", 2 * (a + b), a * b);
            return 0;
      } else if (q == 2) {
            printf("Please, enter radius of circle: ");
            scanf("%f", &a);
            printf("Perimeter and area for circle is: %f %f\n", 2 * M_PI * a, M_PI * pow(a, 2));
            return 0;
      } else {
            printf("Incorrect data!");
            return -1;
      }
}