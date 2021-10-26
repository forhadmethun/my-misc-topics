#include <stdio.h>
// write a program that prints from 1 to n
int main(){
    int i = 1;
    int n;
    scanf("%d",&n);
    while (i < n) {
        printf("%d ", i);
        i = i + 1;
    }
}