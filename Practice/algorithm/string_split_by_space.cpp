#include<bits/stdc++.h>
using namespace std;

int main() {
    istringstream iss("This  is a string");
    string s;
    while ( getline( iss, s, ' ' ) ) {
        printf( "`%s'\n", s.c_str() );
    }
}