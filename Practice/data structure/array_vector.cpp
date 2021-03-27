#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int arr[5] = {7,7,7};
    vector<int> v(5,5);

    printf("arr[2] =%d and v[2] = %d\n",arr[2],v[2]);

    for(int i=0;i<5;i++){
        arr[i] = i;
        v[i] = i;
    }
    printf("arr[2] =%d and v[2] = %d\n",arr[2],v[2]);
    v.push_back(5);
    printf("v[5] = %d\n",v[5]);
    return 0;
}