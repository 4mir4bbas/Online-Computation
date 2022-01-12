#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

double B,C;
double x = 0;
vector<double> z;
vector<double> y;


int online_input(int today){
    int day;
    cout << "Enter 1 (vacation resumes)\n      0 (vacation ends)\n";
    cin >> day;
    if (day){
        if (x < 1){
            cout << "Rent\n";
            z.push_back(1-x);
            x = (x*(1+(1/B))) + 1/(B*C);
            y.push_back(1);
        }else{
            cout << "Buy\n";
        }
    }
    double cost = 0;
    for (int i=0; i<(int)z.size(); i++){
        cost += z[i];
    }
    cost += B*x;
    cout << "Cost Function: " << cost << "\n";
    return day;
}

void offline_input(int days){
    int thatday = 0;
    for (int i=1; i<=days; i++){
        if (x < 1){
            z.push_back(1-x);
            x = (x*(1+(1/B))) + 1/(B*C);
            y.push_back(1);
        }else{
            thatday = i;
            break;
        }
    }
    cout << "Rent for " << thatday-1 << " days then Buy\n";
    double cost = 0;
    for (int i=0; i<(int)z.size(); i++){
        cost += z[i];
    }
    cost += B*x;
    cout << "Cost Function: " << cost << "\n";
    return;
}

int main(){
    //ios::sync_with_stdio(false); cin.tie(0);
    cout << "Input the program in (O)online or (F)offline manner:\n";
    char on_off; cin >> on_off;
    int days;
    if (tolower(on_off) == 'f'){
        cout << "Enter the number of vacation days:\n";
        cin >> days;
    }
    cout << "Enter the price of skis: \n";
    cin >> B;
    C=pow(1+1/B, B)-1;
    if (tolower(on_off) == 'f') offline_input(days);
    else{
        int day = 1;
        while(day){
            day = online_input(day);
        }
    }
    return 0;
}
