#include<stdio.h>
// positive > 0, negative < 0, zero
// number >= 70 && number <79
int main() {
    int number;
    scanf("%d", &number);
    if(number > 0) {
        printf("positive");
    }
    else if(number == 0) {
        printf("zero");
    }
    else if(number < 0) {
        printf("smaller than zero");
    } else {

    }

}
