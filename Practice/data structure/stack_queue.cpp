#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<char> s;
    queue<char> q;
    deque<char> d;

    printf("%d\n",s.empty());
    printf("=====================\n");
    s.push('a');
    s.push('b');
    s.push('c');

    printf("%c\n",s.top());
    s.pop();
    printf("%c\n",s.top());
    printf("%d\n",s.empty());
    printf("===================\n");

    printf("%d\n",q.empty());
    printf("===================\n");
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    q.push('z');
    printf("%c\n",q.front());
    printf("%c\n",q.back());

    printf("====================\n");
    while(!q.empty()){
        printf("%c\n",q.front());
        q.pop();
    }
    printf("========================\n");
    d.push_back('a');
    d.push_back('b');
    d.push_back('c');
    printf("%c - %c\n",d.front(),d.back());
    d.push_front('d');
    printf("%c - %c\n",d.front(),d.back());
    d.pop_back();
    printf("%c - %c\n",d.front(),d.back());
    d.pop_front();
    printf("%c - %c\n",d.front(),d.back());


    return 0;
}