#include<stdio.h>
int main() {
    printf("Enter a year to check if it is a leap year: ");
    int number;
    scanf("%d", &number);
    if (number %4 != 0){
        printf("not a leap year");
    }
    else if(number %100 != 0){
        printf("not a leap year");
    }
    else if(number %400 != 0){
        printf("not a leap year");
    }
    else {
        printf("leap year");
    }
    return 0;
}
