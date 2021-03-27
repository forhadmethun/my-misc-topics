#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

int main()
{

    //freopen("D:\\googleDrive\\_CSE\\_dayWise_work\\2016\\july_august_september_oct_nov_dec\\Oct\\URI_BEGINNER\\in.txt","r",stdin);

    int input;
    scanf("%d",&input);
    char ch = input  + '0';
    cout <<"----  " << ch << endl;
    string str= "%"  + string(1,ch) ;//
    str = str + "s";
    // + "s";
    cout << "--->" << str << endl;//"%5s";
    printf(str.c_str(),"h");
    return 0;
}
