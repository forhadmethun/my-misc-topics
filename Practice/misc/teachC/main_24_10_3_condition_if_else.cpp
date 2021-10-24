#include<stdio.h>
// positive > 0, negative < 0, zero
// number >= 70 && number <79
/*
    && and comparison
    || or comparison
    > greater than
    < less than
    >= greater equal
    <= less equal
    != not equal
 */
int main() {
    printf("Enter your number");
    int number;
    scanf("%d", &number);
    if (number >= 33 && number <= 100){
        printf("pass");
    }
    else if(number <33 && number >= 0){
        printf("fail");
    }
    else {
        printf("wrong input");
    }
    return 0;

}
