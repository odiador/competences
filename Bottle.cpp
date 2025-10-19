#include <bits/stdc++.h>
using namespace std;


int main() {
    int days, initVolOH, initVolNorm, deltaOH, deltaNorm;
    cin>> days>>initVolOH>>initVolNorm>>deltaOH>>deltaNorm;
    double endVolOH = initVolOH-deltaOH*days;
    double endVolNorm = initVolNorm-deltaNorm*days;
    double comp = endVolNorm+endVolOH;
    double res = endVolOH*100/comp;
    int mod = 1000000;
    cout<< (res)<<endl;

}