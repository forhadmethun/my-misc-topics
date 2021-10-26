#include<stdio.h>
int main() {
    int number;
    scanf("%d", &number);
    if(number % 2 == 0) {
        printf("jor");
    }
    else if(number %2 != 0) { // number = true
        printf("bijor");
    }

}
