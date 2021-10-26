#include <stdio.h>
// write a program that counts digits of numbers
// n = 1234
// n / 10 => 123   (1)
// n /10 => 12  (2)
// n /10 => 1  (3)
// n/10 => 0  (4)
int main(){
    int n, i;
    scanf("%d", &n);
    int count = 0;
    while(n != 0){
        n = n / 10;
        count = count + 1;
    }
    printf("%d", count);
    return 0;
}

