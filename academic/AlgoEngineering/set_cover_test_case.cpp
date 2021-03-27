#include <bits/stdc++.h>
using namespace std;
double random_range(double from, double to) {
    return from + (double) (rand() % (int) (to - from + 1));

}
int random_range(int from, int to) {
    return from + (rand() % (to - from + 1));

}

int main(){
    srand(time(NULL));
    //freopen("D:\\googleDrive\\_CSE\\Code\\Others\\AlgoEngineering\\in.txt","w",stdout);
    freopen("in.txt","w",stdout);
    int tc = rand()%5;
    cout << tc << endl;
    for(int i=0;i<tc;i++){
        int m = random_range(2,15); // size of total set
        cout << m << endl;
        int n = random_range(5,15);// number of sub sets
        cout << n << endl;

        for(int j=0;j<n;j++){
            double cost =  random_range(0.2,2.0);
            cout << cost;
            int  t = rand() % m;
            cout << " " << t << " ";
            set<int> s;

            while(t--){
                int num = rand()%m ;
               // cout << "--> " << num << endl;
                if(s.find(num)!=s.end()){
                    t++;
                }
                s.insert(num);
                //if((int)s.size() == t)break;
            }

            while(!s.empty()){
                cout << *s.begin() << " ";
                s.erase(*s.begin());
            }
            cout << endl;



        }

    }


    return 0;
}