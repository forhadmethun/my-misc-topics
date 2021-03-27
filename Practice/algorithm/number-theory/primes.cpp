#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef vector<int> vi; 

vi primes; 
bitset<10000010> bs;
ll _sieve_size; 

void generatePrimesBySieve(ll upperbound){
    _sieve_size =  upperbound + 1; 
    bs.set(); 
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++){
        if(bs[i]){
            for(ll j = i*i; j <= _sieve_size; j+=i){
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

bool isPrime(ll N){
    if(N < _sieve_size) return bs[N];
    for(int i = 0; i < (int)primes.size(); i++){
        if(N % primes[i] == 0)return false;
    }
    return true;
}

int main(){
    generatePrimesBySieve(10000000); 
    printf("%d\n", isPrime(2147483647));
// 10-digits prime
    printf("%d\n", isPrime(136117223861LL));
    return 0;
}