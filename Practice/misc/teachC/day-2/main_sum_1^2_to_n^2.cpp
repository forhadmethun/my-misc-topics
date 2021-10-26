#include <stdio.h>
// write a program that adds 1^2 to n^2
// n = 3
// sum = 0 + 1^1 + 1^2 + 2^2 + 3^2
int main(){
    int n, i = 1 , sum = 0;
    scanf("%d", &n);
    while (i <= n) {
        sum = sum + i * i;
        i = i + 1;
    }
    /*
     for(i = 1; i <= n; i++){
        sum = sum + i * i;
     }
     */
    printf("%d", sum);
}