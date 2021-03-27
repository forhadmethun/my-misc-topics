#include<bits/stdc++.h>
using namespace std;

int main(){
    int money;
    char name[20];
    priority_queue<pair<int, string> > pq;
    pair<int, string> result;
    pq.push(make_pair(100,"john"));
    pq.push(make_pair(10,"billy"));
    pq.push(make_pair(20,"andy"));
    pq.push(make_pair(100,"steven"));
    pq.push(make_pair(70,"felix"));
    pq.push(make_pair(2000,"grace"));
    pq.push(make_pair(70,"martin"));

    result = pq.top();
    pq.pop();
    printf("%s has %d $\n",((string)result.second).c_str(),result.first);
    result = pq.top();pq.pop();
    printf("%s has %d $\n",((string)result.second).c_str(),result.first);
    result = pq.top(); pq.pop();
    printf("%s has %d $\n",((string)result.second).c_str(),result.first);
    

    

    return 0;
}