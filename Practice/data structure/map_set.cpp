#include<bits/stdc++.h>
using namespace std;

int main(){
    char name[20];
    int value;
    set<int> used_values;
    map<string, int> mapper;

    mapper["forhad"] = 77; used_values.insert(77);
    mapper["methun"] = 69; used_values.insert(69);
    mapper["jodu"] = 88; used_values.insert(88);
    mapper["modu"] = 99; used_values.insert(99);
    mapper["lau"] = 11; used_values.insert(11);

    for(auto it=mapper.begin();it!=mapper.end();it++){
        printf("%s %d\n",((string)it->first).c_str(),it->second);
    }

    printf("fofrhad is %d,lau is %d\n",mapper["forhad"],mapper["lau"]);

    printf("%d\n",used_values.find(77) !=used_values.end());


    return 0;
}