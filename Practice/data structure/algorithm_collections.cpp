#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

typedef struct{
    int id;
    int solved;
    int penalty;
}team;

bool icpc_cmp(team a,team b){
    if(a.solved!=b.solved){
        return a.solved > b.solved;
    }else if(a.penalty != b.penalty){
        return b.penalty > a.penalty;
    }
    else a.id < b.id;
}

int main(){
    int *pos,arr[] = {10,7,2,15,4};
    vector<int> v(arr,arr+5);
    vector<int>::iterator j;

    sort(v.rbegin(),v.rend()); //reverse sort
    for(vector<int>::iterator it = v.begin();it!=v.end();it++){
        printf("%d ",*it);
    }
    printf("\n========================\n");

    sort(arr,arr+5);
    reverse(arr,arr+5);

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("==========================\n");

    random_shuffle(v.begin(),v.end());

    for(auto it=v.begin();it!=v.end();it++){
        printf("%d",*it);
    }
    printf("\n");
    printf("==========================\n");

    partial_sort(v.begin(),v.begin()+2,v.end());
    for(auto it= v.begin();it!=v.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
    printf("=========================\n");

    sort(arr,arr+5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    sort(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
    printf("===========================\n");

    team nus[4] = {
            {1,1,10},
            {2,3,60},
            {3,1,20},
            {4,3,60}
    };
    sort(nus,nus+4,icpc_cmp);
    printf("=====================\n");
    for(int i=0;i<4;i++){
        printf("id: %d, solved: %d, penalty: %d\n",nus[i].id,nus[i].solved,nus[i].penalty);
    }
    printf("=====================\n");
    typedef pair<int, pair<string, string> > state;
    state a = make_pair(10,make_pair("steven","grace"));
    state b = make_pair(7,make_pair("steven","halim"));
    state c = make_pair(7,make_pair("steven","felix"));
    state d = make_pair(9,make_pair("a","b"));

    vector<state> test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);
    for(int i=0; i<4;i++){
        printf("value: %d, name=%s , name2=%s\n",test[i].first,((string)test[i].second.first).c_str(),((string)test[i].second.second).c_str());
    }
    printf("==========================\n");
    sort(test.begin(),test.end());

    for(int i=0; i<4;i++){
        printf("value: %d, name=%s , name2=%s\n",test[i].first,((string)test[i].second.first).c_str(),((string)test[i].second.second).c_str());
    }
    printf("==========================\n");




    pos = lower_bound(arr,arr+5,7);
    printf("isPresent: %d\n",*pos);

    j = lower_bound(v.begin(),v.end(),7);
    printf("%d\n",*j);

    pos = lower_bound(arr,arr+5, 77);
    if(pos - arr == 5){
        printf("77 not found\n");
    }
    j = lower_bound(v.begin(),v.end(),77);
    if(j == v.end()){
        printf("77 not found\n");

    }
    printf("========================\n");
    next_permutation(arr,arr+5);
    next_permutation(arr,arr+5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    next_permutation(v.begin(),v.end());
    next_permutation(v.begin(),v.end());

    for(auto it=v.begin();it!=v.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
    printf("=======================\n");

    printf("min(10,7): %d\n",min(10,7));
    printf("max(10,7): %d\n",max(10,7));







    return 0;
}