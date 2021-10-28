#include <stdio.h>
/*
factorial(n) = 1 * 2 * 3 * ... * (n-1) * n;


factorial(5) = 1 * 2 * 3 * 4 * 5;
factorial(3) = 1 * 2 * 3;
factorial(7) = 1 * 2 * 3 * 4 * 5 * 6 * 7;
factorial(2) = 1 * 2;

7P5 = factorial(7) / factorial(7-5) = factorial(7) / factorial(2)
*/
int factorial(int n) {
    int mul = 1, i;
    for(i = 1; i <= n; i++){
        mul = mul * i;
    }
    return mul;
}
int main(){
    int x, fact;
    scanf("%d",&x);
    fact = factorial(x);
    printf("%d", fact);
    return 0;
}
