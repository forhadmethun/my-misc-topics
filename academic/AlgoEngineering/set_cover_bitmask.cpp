#include<bits/stdc++.h>
using namespace std;

//double minCostCollection(set<int> unv,vector< set<int> > sets,map<set<int>, double> costs,vector<set<int> >list,int pos){
//    if (unv.size() == 0)
//    {
//        double  cost = 0;
//        for (int i=0;i< list.size();i++)
//        {
//            cost = cost + costs[(list[i])];
//        }
//        return cost;
//    }
//    if(pos < 0) return INT_MAX;
//    set<int> unvCopy(unv);
//    vector<set<int> >list1(list);
//    set<int> s = sets[pos];
//    for(auto it=s.begin();it!=s.end();it++){
//        unv.erase(unv.find(*it));
//    }
//
//    double cost1 = minCostCollection(unv, sets, costs, list, pos - 1);
//    double cost2 = minCostCollection(unvCopy, sets, costs, list1, pos - 1);
//    return min(cost1, cost2);
//
//}
vector<double> weight;
vector<int> mask;
double dp[100][100];
int N,M;
int msk = 0;
double f(int coveredMask, int nowConsiderIndex ){
    msk = coveredMask;
  //  cout <<"-------------> " << coveredMask << endl;
    if (nowConsiderIndex == N && coveredMask!=(1<<M) - 1)return INT_MAX;
    else if (nowConsiderIndex == N && coveredMask==(1<<M) - 1) return 0;
    double valChoose= f( coveredMask | mask[nowConsiderIndex], nowConsiderIndex+1 ) + weight[nowConsiderIndex];
    double valNotChoose= f( coveredMask, nowConsiderIndex+1 );
    dp[coveredMask][nowConsiderIndex]=min(valChoose,valNotChoose);
    return  min( valChoose, valNotChoose );

}

vector<int> ans;
void printSolution(int  coveredMask,int nowConsiderIndex){
    if (nowConsiderIndex == N && coveredMask!=(1<<M) - 1)return ;
    else if (nowConsiderIndex == N && coveredMask==(1<<M) - 1) return ;

    if  ( dp[coveredMask][nowConsiderIndex] == dp[coveredMask | mask[nowConsiderIndex]][nowConsiderIndex+1] + weight[nowConsiderIndex]){
        //cout << "Ans: " <<nowConsiderIndex<<  endl;

        ans.push_back(nowConsiderIndex);

        return printSolution( coveredMask+mask[nowConsiderIndex], nowConsiderIndex+1);
    }
    else{
        //cout <<"dhuke ni " << endl;
        return  printSolution( coveredMask, nowConsiderIndex+1);
    }


}
int main(){
   // printf("%d\n",f(10,10));
    freopen("D:\\googleDrive\\_CSE\\Code\\in.txt","r",stdin);
    int tc;scanf("%d",&tc);//test cases
    while(tc--){
        weight.clear();
        mask.clear();
        ans.clear();

        int element_number;
        scanf("%d",&element_number); // set elements 0 to element_number
        M = element_number;
        set<int> unv;
        for(int i=0;i<element_number;i++){
            unv.insert(i);
        }
        int subset_number;
        scanf("%d",&subset_number); // number of subset
        N = subset_number;
        map< set<int> , double> costs; //takes input of everything...
        vector< set<int> > v;
        for(int i=0;i<subset_number;i++){ // next subset_number times input
            set<int> s;
            double cost;scanf("%lf",&cost);
            weight.push_back(cost);
            int subset_element;
            scanf("%d",&subset_element); // how many element of the subset..
            int c  = 0;
            for(int j=0;j<subset_element;j++){
                int in;scanf("%d",&in);
                c = c | ( 1 <<in);
                s.insert(in);
            }
           // printf("-> -> %d\n",c ); // masked...
            mask.push_back(c);
            costs[s] = cost;
            v.push_back(s);
           // cout << "--> " << cost << endl;
        }
        int p = (int)(double)pow(2,N) -1 ;
        //cout << "!!!!!!!1 " << p << " _> " << N  << endl;


        cout << f(0,0) << endl;
       // cout << "--> " << printSolution(0,0) << endl;
        printSolution(0,0);
        for(int i=0;i<ans.size();i++){
            cout << " " << ans[i] ;
        }
        cout << endl;



       // cout << mask.size() << endl;
       // vector<set<int> >list;
       // cout << "---> " << msk << endl;
    }

    return 0;
}