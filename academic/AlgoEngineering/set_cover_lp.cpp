#include<bits/stdc++.h>
using namespace std;
#define MAX 107
#define INF 1000000007
#define EPS (1e-12)
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
    dp[nowConsiderIndex][coveredMask]=min(valChoose,valNotChoose);
    return  min( valChoose, valNotChoose );

}
void Pivot( long m,long n,double A[][MAX+7],long *B,long *N,long r,long c )
{
    long i,j;
    swap( N[c],B[r] );
    A[r][c] = 1/A[r][c];
    for( j=0;j<=n;j++ ) if( j!=c ) A[r][j] *= A[r][c];
    for( i=0;i<=m;i++ ){
        if( i!=r ){
            for( j=0;j<=n;j++ ) if( j!=c ) A[i][j] -= A[i][c]*A[r][j];
            A[i][c] = -A[i][c]*A[r][c];
        }
    }
}
long Feasible( long m,long n,double A[][MAX+7],long *B,long *N )
{
    long r,c,i;
    double p,v;
    while( 1 ){
        for( p=INF,i=0;i<m;i++ ) if( A[i][n]<p ) p = A[r=i][n];
        if( p > -EPS ) return 1;
        for( p=0,i=0;i<n;i++ ) if( A[r][i]<p ) p = A[r][c=i];
        if( p > -EPS ) return 0;
        p = A[r][n]/A[r][c];
        for( i=r+1;i<m;i++ ){
            if( A[i][c] > EPS ){
                v = A[i][n]/A[i][c];
                if( v<p ) r=i,p=v;
            }
        }
        Pivot( m,n,A,B,N,r,c );
    }
}
long Simplex( long m,long n,double A[][MAX+7],double *b,double &Ret )
{
    long B[MAX+7],N[MAX+7],r,c,i;
    double p,v;
    for( i=0;i<n;i++ ) N[i] = i;
    for( i=0;i<m;i++ ) B[i] = n+i;
    if( !Feasible( m,n,A,B,N ) ) return 0;
    while( 1 ){
        for( p=0,i=0;i<n;i++ ) if( A[m][i] > p ) p = A[m][c=i];
        if( p<EPS ){
            for( i=0;i<n;i++ ) if( N[i]<n ) b[N[i]] = 0;
            for( i=0;i<m;i++ ) if( B[i]<n ) b[B[i]] = A[i][n];
            Ret = -A[m][n];
            return 1;
        }
        for( p=INF,i=0;i<m;i++ ){
            if( A[i][c] > EPS ){
                v = A[i][n]/A[i][c];
                if( v<p ) p = v,r = i;
            }
        }
        if( p==INF ) return -1;
        Pivot( m,n,A,B,N,r,c );
    }
}

int main(){
   // printf("%d\n",f(10,10));
    freopen("D:\\googleDrive\\_CSE\\Code\\in.txt","r",stdin);
    int tc;scanf("%d",&tc);//test cases
    while(tc--){
        //cout << "! " << tc << endl;
        weight.clear();
        mask.clear();

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
        //declaring the lp mask
        double mat[MAX+7][MAX+ 7];
        for(int i=0;i<=element_number;i++){
            for(int j=0;j<=subset_number;j++){
               // printf("%d ",mat[i][j]);
                mat[i][j] = 0;
                if(j == subset_number && i!=element_number)mat[i][j] = -1.0;
            }
            //cout << endl;
        }
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
            //    c = c | ( 1 <<in);
                s.insert(in);
            }
           // printf("-> -> %d\n",c ); // masked...
            mask.push_back(c);
            costs[s] = cost;
            v.push_back(s);
           // cout << "--> " << cost << endl;
        }
//        for(int i=0;i<v.size();i++){
//            int x=0;
//            for(auto it = v[i].begin();it!=v[i].end();it++,x++){
//               // cout << " " << (int) *it;
//                if( i == (int)*it){
//
//                }
//            }
//            //cout << endl;
//        }
        for(int i=0;i<=element_number;i++){
            for(int j=0;j<=subset_number;j++){
                // printf("%d ",mat[i][j]);
                mat[i][j] = 0;
                if(j == subset_number && i!=element_number)mat[i][j] = -1.0;
                if(i == element_number){
                    mat[i][j] = -weight[j];
                }
            }
            //cout << endl;
        }
        //setting constraitns
        vector<int> find_max_element;
        for(int i=0;i<subset_number;i++){
            find_max_element.push_back(0);
        }
        for(int i=0;i<element_number;i++){
            int x=0;
            for(int j=0;j<v.size();j++) {
                set<int> si(v[j]);
                if(si.find(i) != si.end()){
                   // cout << "dhuki nai "<< endl;
                    mat[i][j] = -1.0;
                    find_max_element[i]++;
                }

//                for (auto it = v[j].begin(); it != v[j].end(); it++, x++) {
//                    // cout << " " << (int) *it;
//                    if (i == (int) *it) {
//
//                    }
//
//
//                }
            }
            //cout << endl;
        }


        //finding maximum frequency number
        int mx = INT_MIN;
        for(int i=0;i<element_number;i++){
            if(find_max_element[i]>mx){
                mx = find_max_element[i];
            }
        }
       // cout << "frequency -> " << mx << endl;



        //long Simplex( long m,long n,double A[MAX+7][MAX+7],double *b,double &Ret )
        long m = M;
        long n = N;
        double b[MAX + 7];
        double Ret;



        //printing the matrix
//        for(int i=0;i<=element_number;i++){ // 0 to the main set number // (7) 0,1,2,3,4,5,6,7
//            for(int j=0;j<=subset_number;j++){
//                if( i == element_number)
//                printf("%3.1f ",mat[i][j]);
//                else printf("%3.0f ",mat[i][j]);
//            }
//            cout << endl;
//        }
        double cst = 0;
       // cout << (double) mx << endl;

        long ans = Simplex(n,m,mat,b,Ret);

        for(int i=0;i<M;i++){
            //cout << "--> " << b[i] << endl;
            if( b[i] >= (1.0/(double)mx)){

                cst = cst + weight[i];
                cout << " " << i ;
            }
        }

        cout << endl << cst << endl;



//        double cst = 0;





        //still useless
        //int p = (int)(double)pow(2,N) -1 ;
        //cout << "!!!!!!!1 " << p << " _> " << N  << endl;


        //cout << f(0,0) << endl;



       // cout << mask.size() << endl;
        //vector<set<int> >list;
       // cout << "---> " << msk << endl;
    }

    return 0;
}