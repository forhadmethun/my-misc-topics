#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("food_data_generation.txt","w",stdout);
    int i,j,k,l;
    int count = 1;
    for(i=1;i<=19;i++){
        for(j=1;j<=7;j++){
            for(k=1;k<=21;k++){
               // printf("%d %d %d\n",i,j,k);
               printf("insert into meal(meal_id) values (%d);\n",count++);
            }
        }
    }



    return 0;
}
