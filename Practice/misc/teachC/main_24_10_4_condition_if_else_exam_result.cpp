#include<stdio.h>
int main() {
    printf("Enter your number");
    float number;
    scanf("%f", &number);
    if(number>= 80.0 && number <= 100.0){
        printf("A+");
    }
    else if(number >= 70.0 && number < 80.0){
        printf("A");
    }
    else if(number >= 60.0 && number < 70.0){
        printf("A-");
    }

    return 0;
}
