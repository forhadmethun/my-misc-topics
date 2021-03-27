#include<bits/stdc++.h>
//top down fashion
using namespace std;
#define NIL -1
#define MAX 10


class Fibonacci {
public:
    int lookup[MAX];

    void _initialize() {
        for (int i = 0; i < MAX; i++) {
            lookup[i] = NIL;
        }
    }

    int fib(int n) {
        if (lookup[n] == NIL) {
            if (n <= 1) {
                lookup[n] = n;
            } else {
                lookup[n] = fib(n - 1) + fib(n - 2);
            }
        }
        return lookup[n];


    }
};

int main() {
    Fibonacci fibonacci;
    fibonacci._initialize();

    int fib5 = fibonacci.fib(5);
    return 0;
}