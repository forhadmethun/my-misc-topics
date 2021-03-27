#include<stdio.h>
/*

N is in a range [0, 100], and B is any number of the range
A is given number
find max gcd

*/
int gcd(int A, int B){
    if( A == 0 ) return B;
    return gcd(B%A, A);
}
int maxGCD(int A, int N){
    int max = -100000;
    for(int i = N ; i >= 2; i--){
        int val = gcd(A,i);
        if( val > max){
            max = val;
        }
    }
    return max;
}
int make_positive(int x){
    if(x < 0) return -x;
    return x;
}
int main(){
    int A, N;
    scanf("%d %d", &A, &N);
    if(A <= N && A > 0){
        printf("%d\n", A);
    }
    else{
        printf("%d\n",maxGCD(make_positive(A),make_positive(N)));
    }
    return 0;
}

