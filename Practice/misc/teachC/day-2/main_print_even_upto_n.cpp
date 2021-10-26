#include <stdio.h>
// write a program that prints even number upto n
int main(){
    int n, i;
    scanf("%d", &n);
    i = 2;
    while (i <= n) {
        printf("%d ", i);
        i = i + 2;
    }
    /*
     for(i=2; i <=n;i= i+2){
        printf("%d ", i);
     }
     */
}