#include <bits/stdc++.h>

using namespace std;

int random_range(int from, int to) {
    return from + (rand() % (to - from + 1));

}

double random_range(double from, double to) {
    return from + (double) (rand() % (int) (to - from + 1));

}

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
float lb(float val){
    return 0.453592*val;
}
float fm(float val){
    return  (float).3048*val;
}
void height_to_wieght(){
    freopen("C:\\Users\\forhad\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height.txt", "r", stdin);
    freopen("C:\\Users\\forhad\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\weight.txt", "w", stdout);
    for (int i = 0; i < 1000; i++) {
        //cout <<RandomFloat(4.10,6.4) << endl;
        double f;
        cin >> f;
        if (f >= 4.1 && f <= 5) {
            printf("%0.2lf\n", RandomFloat(lb(91), lb(160)));
        }
        if (f >= 5 && f <= 5.2) {
            printf("%0.2lf\n", RandomFloat(lb(97),lb(170)));
        }
        if (f >= 5.2 && f <= 5.4) {
            printf("%0.2lf\n", RandomFloat(lb(104),lb(200)));
        }
        if (f >= 5.3 && f <= 5.5) {
            printf("%0.2lf\n", RandomFloat(lb(107),lb(220)));
        }
        if (f >= 5.5 && f <= 5.7) {
            printf("%0.2lf\n", RandomFloat(lb(114),lb(230)));
        }
        if (f >= 5.7 && f <= 5.9) {
            printf("%0.2lf\n", RandomFloat(lb(121),lb(250)));
        }

        else if (f >= 5.9 && f <= 6.2) {
            printf("%0.2lf\n", RandomFloat(lb(128), lb(280)));


        } else if (f >= 6.2 && f <= 6.4) {
            printf("%0.2lf\n", RandomFloat(lb(140),lb(300)));

        }
    }


}
void BMI()
{
    freopen("C:\\Users\\forhad\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height_weight.txt", "r", stdin);
    freopen("C:\\Users\\forhad\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\bmi.txt", "w", stdout);
    for(int i=0;i<1000;i++){
        float a,b;
        cin >> a >> b;
        cout << b/ ((fm(a))*(fm(a))) << endl;
    }

}

void random_Gender(){
   // freopen("C:\\Users\\forhad\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\height_weight.txt", "r", stdin);
    freopen("C:\\Users\\forhad\\Desktop\\_thesis_by_azad\\ThesisPrograms_by_me\\gender.txt", "w", stdout);

    for(int i=0;i<1000;i++){
        int x = rand()%20;
        if(x%2 == 0){
            cout << 'F' << endl;
        }
        else{
            cout << "M" << endl;
        }
    }
}

void age()
{
    for(int i=0;i<1000;i++){
        cout << random_range(35,55) << endl;
    }
}


void fruit()
{
    for(int i=0;i<1000;i++){
        cout << random_range(3,4) << endl;
    }
}
void starch_per_serving()
{

    for(int i=0;i<1000;i++){
        float weight ;cin >> weight;
        //cout << 5 + (weight*5.0)/100.0 << endl;
        if(weight >=40 && weight<=50){
            cout << random_range(5,7)<<endl;
        }
        else if(weight >=51 && weight<=60){
            cout << random_range(7,9) << endl;
        }
        else{
            cout << random_range(8,10) << endl;
        }

    }
}

void milk()
{

    for(int i=0;i<1000;i++){
        float weight; cin >> weight;
        if( weight <60){
            cout << 2 << endl;
        }
        else cout << 3 << endl;
    }
}

void non_starch()
{

    for(int i=0;i<1000;i++){
        float weight; cin >> weight;
        if(weight < 60){
            cout <<  3 << endl;
        }
        else if( weight >=60 && weight <=70){
            cout << 4 << endl;

        }
        else if(weight >= 71 &&  weight <= 80){
            cout << 5 << endl;
        }
        else cout << 6 << endl;
    }
}


void meat()
{

    for(int i=0;i<1000;i++){
        float weight; cin >> weight;
        if(weight < 60){
            cout <<  4 << endl;
        }
        else if( weight >=60 && weight <=70){
            cout << 6 << endl;

        }
        else if(weight >= 71 &&  weight <= 80){
            cout << 6 << endl;
        }
        else if(weight >=81 && weight <= 90){
            cout << 7 << endl;
        }

        else cout << 8 << endl;
    }
}



void fat()
{
       for(int i=0;i<1000;i++){
        float weight; cin >> weight;
        if(weight < 60){
            cout <<  3 << endl;
        }
        else if( weight >=60 && weight <=70){
            cout << 5 << endl;

        }
        else if(weight >= 71 &&  weight <= 80){
            cout << 6 << endl;
        }
        else cout << 7 << endl;
    }
}
void freeFood()
{

    for (int i=0;i<1000;i++){
        cout << random_range(20,30) << endl;
    }
}

void exercise()
{
    for(int i=0;i<1000;i++){
        cout << random_range(20,30) << endl;
    }
}

void sweet()
{

    for(int i=0;i<1000;i++){
        float f; cin >> f;
        if(f>=200)
        {

            cout << 15 << endl;
        }
        else cout << 30 << endl;
    }

}
int main() {

    srand(time(NULL));

    //freopen("weight.txt","r",stdin);
    //freopen("carbohydrate.txt","r",stdin);
    freopen("exercise.txt","w",stdout);
    exercise();

    //freeFood();
    //fruit();
    //milk();
    //non_starch();
    //meat();
    //sweet();



    //age();
   //BMI();
    //random_Gender();
    //starch_per_serving();




    return 0;
}
