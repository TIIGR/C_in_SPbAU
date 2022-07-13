#include <stdio.h>


int binarySearch(int prime[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (prime[mid] == x) 
            return mid; 
        if (prime[mid] > x) 
            return binarySearch(prime, l, mid - 1, x); 
        return binarySearch(prime, mid + 1, r, x); 
    } 
    return -1; 
}  
int main() 
{ 
    int x, prime[] = {1, 2, 3, 5, 7, 9, 11, 13}; 
    int n = sizeof(prime) / sizeof(prime[0]);
    printf("Enter you'r number:\n");
    scanf("%d", &x);
    int result = binarySearch(prime, 0, n - 1, x); 
    (result == -1) ? printf("The element is not present in array") 
    : printf("The element is present at index %d", result); 
    return 0; 
}