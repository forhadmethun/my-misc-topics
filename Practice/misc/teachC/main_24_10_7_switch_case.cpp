#include<stdio.h>
/*

 switch(condition){
    case value:
        //print  or any other processing
        break;
    case another_value:
        // processing
        break;
    default:
        // always kaj korbe
 }

 */
int main() {
    printf("Enter a year to check if it is a leap year: ");
    int number;
    scanf("%d", &number);
    switch (number) {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 5:
            printf("five");
            break;
        default:
            printf("not supported");

    }
    return 0;
}
