#include <stdio.h>
// n! = 1 * 2 * 3 * 4 * ... * (n-1) * n
int factorial(int n) {
    int mul = 1, i;
    for(i = 1; i <= n; i++){
        mul = mul * i;
    }
    return mul;
}
//nPr = n!/ (n-r)!
int nPr(int n, int r){
    return factorial(n) / factorial(n-r);
}
int main(){
    int n, r, ans;
    scanf("%d%d",&n, &r);
    ans = nPr(n, r);
    printf("%d", fact_n/fact_n_r);
    return 0;
}
