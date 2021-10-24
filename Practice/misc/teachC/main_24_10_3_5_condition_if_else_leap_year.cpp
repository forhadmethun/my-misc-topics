#include<stdio.h>
int main() {
    printf("Enter a year to check if it is a leap year: ");
    int number;
    scanf("%d", &number);

    if(condition) {
        // code
    }

    if((number % 4 == 0 && number % 100 !=0) || number % 400 ==0)
    {
        printf("leap year");
    }
    else {
        printf("not a leap year");
    }
    return 0;
}
