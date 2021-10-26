#include <stdio.h>
// write a program to check if divisible by 5 and 11
int main(){
    int a;
    scanf("%d", &a);
    if(a % 5 == 0 && a % 11 == 0){
        printf("divisiable by 5 and 11");
    } else {
        printf("not divisible");
    }
    return 0;
}

