#include <stdio.h>
// write a program that prints from m to n
// [5,10] => 5, 6, 7, 8, 9 , 10
// [m, n]
int main(){
    int m, n;
    scanf("%d%d",&m, &n);
    while (m <= n) {
        printf("%d ", m);
        m = m + 1;
    }
    /*
     for(;m<=n; m = m +1){
        printf("%d", m);
     }
     */
}