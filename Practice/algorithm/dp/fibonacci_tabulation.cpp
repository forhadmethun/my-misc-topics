#include<bits/stdc++.h>
//bottom up fashion
using namespace std;

class Fibonacci {
public:

    int fib(int n) {
        int f[n+1];
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i <=n; i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};

int main() {
    Fibonacci fibonacci;
    int fib5 = fibonacci.fib(5);
    return 0;
}