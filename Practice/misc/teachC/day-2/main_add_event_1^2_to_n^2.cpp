#include <stdio.h>
// write a program that adds 1^2 to n^2 only the even numbers
// n = 3
// sum = 0  + 2^2 + 4^2
int main(){
    int n, i = 2 , sum = 0;
    scanf("%d", &n);
    while (i <= n) {
        sum = sum + i * i;
        i = i + 2;
    }
    printf("%d", sum);
}