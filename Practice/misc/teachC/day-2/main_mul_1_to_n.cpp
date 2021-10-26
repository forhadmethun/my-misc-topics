#include <stdio.h>
// write a program that adds 1^2 to n^2
// n= 5, sum = 1^2 + 2^2 + 3^2 + 4^2 + 5^2
int main(){
    int n, i = 1 , sum = 0;
    scanf("%d", &n);
    while (i <= n) {
        sum = sum + i * i; // 0 + 1^2 + 2^2 + 3^2 + 4^2 + 5^2
        i = i + 1;
    }
    printf("%d", sum);
}