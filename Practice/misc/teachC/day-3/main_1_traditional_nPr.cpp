#include <stdio.h>
// find, nPr = n!/ (n-r)!
int main(){
    // fact_n is the variable where we store factorial of n
    // fact_n_r is the variable where we store factorial of n-r
    // input n & r then output fact_n / fact_n_r
    int fact_n = 1, fact_n_r = 1, n,r, i; // fact_r
    scanf("%d%d",&n, &r);
    // find factorial of n
    for(i = 1; i <= n; i++){
        fact_n = fact_n * i;
    }
    // find factorial of n - r
    for(i = 1; i <= n - r; i++) {
        fact_n_r = fact_n_r * i;
    }
    /*
   for(i = 1; i <= r; i++){
   fact_r = fact_r * i;
   }
   */
    printf("%d", fact_n/fact_n_r);


    return 0;
}


// hometask: nCr = n! / (r! * (n-r)!)
