#include <stdio.h>
// write a program that adds 1 to n
// n = 10
// 1 + 2 + 3 + 4 + 5 + 6 +7 + 8 + 9 + 10 = 55
// arithmetic progression
// sum = 0
// protita i er jonno sum = sum + i
// n= 5, sum = 1 + 2 + 3 + 4 + 5 = 15
int main(){
    int n, i = 1 , sum = 0;
    scanf("%d", &n);
    while (i <= n) {
        sum = sum + i; // 0 + 1 + 2 + 3 + 4 + 5
        i = i + 1;
    }

    /*
    for (i = 1; i <= n; i++) {
        sum = sum + i;
     }
     */
    printf("%d", sum);
}