#include <stdio.h>
// add two numbers using function
/*
add(x, y) = x + y; // sum
add(1, 2) = 1 + 2 = 3;
 */
int add(int x, int y) { // function
    int c;
    c = x + y;
    return c;
}
int main(){
    int p, q, sum;
    scanf("%d%d",&p, &q);
    sum = add(p, q);
    printf("%d", sum);
    int r, s;
    scanf("%d%d", &r, &s);
    sum = add(r, s);
    printf("%d", sum);
    return 0;
}
/*
return_type function_name() {
    // body line 1
    // body line 2
    // ..
    return return_value;
}
 */



/*



y = f(x);
f(x) = x^2;
f(2) = 2 * 2 = 4;



factorial(n) = 1 * 2 * 3 * ... * (n-1) * n;


factorial(5) = 1 * 2 * 3 * 4 * 5;
factorial(3) = 1 * 2 * 3;
factorial(7) = 1 * 2 * 3 * 4 * 5 * 6 * 7;
factorial(2) = 1 * 2;

7P5 = factorial(7) / factorial(7-5) = factorial(7) / factorial(2)

*/