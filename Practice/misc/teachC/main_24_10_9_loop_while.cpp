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

//loop => repetitive jinish ashbe
// 1 theke 100 porjonto bijor number gulan print korbo

int main() {

    //while(condition)
    // jotokkhon porjonto condition false na hoy

    int i = 0;
    while(i <= 5){
        if(i % 2 != 0) {
            printf("bijor");
        }
       i = i + 1;
    }

    return 0;
}
