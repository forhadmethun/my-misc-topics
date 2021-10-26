#include <stdio.h>
// write a program that prints from 1 to n
// input : 5
// output: 5 *1 = 5
// 5 * 2 = 10
// 5 * 3 = 15
//... 5 * 10 =
int main(){
    int n, i;
    scanf("%d", &n);
    for(i = 1; i <= 100; i=i+1){
        printf("%d * %d = %d\n",n, i, n * i);
    }
    /*
    while(i <= 10){
        printf("%d * %d = %d\n",n, i, n * i);
        i = i + 1;
    }

     */
    return 0;
}