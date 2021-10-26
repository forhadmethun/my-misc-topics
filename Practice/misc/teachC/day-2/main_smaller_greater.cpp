#include <stdio.h>
// write a program that find maximum of two number
int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a > b) {
        printf("%d",a);
    } else {
        printf("%d", b);
    }
}