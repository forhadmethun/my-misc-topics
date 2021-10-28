#include <stdio.h>
/*
factorial(n) = 1 * 2 * 3 * ... * (n-1) * n;
nPr = n!/ (n-r)!
*/
int factorial(int n) {
    int mul = 1, i;
    for(i = 1; i <= n; i++){
        mul = mul * i;
    }
    return mul;
}
int main(){
    int n, r, fact_n, fact_n_r; // fact_r
    scanf("%d%d",&n, &r);
    fact_n = factorial(n);
    fact_n_r = factorial(n-r);
    // fact_r = factorial(r);
    printf("%d", fact_n/fact_n_r);
    return 0;
}

// Write a program for: nCr = n!/ (r! * (n-r)!)