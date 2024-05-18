#include <bits/stdc++.h>

using namespace std;

int getNumber(char b1, char b2, char b3){
    int ans1 = (b1 =='.')? 0:1;
    int ans2 = (b2 =='.')? 0:1;
    int ans3 = (b3 =='.')? 0:1;
    return (ans1*4) + (ans2*2) + (ans3);
}

int main(){

    int rule, k;
    cin >> rule >> k;

    string s;

    cin >> s;
    s = "." + s + "." ;

    while(k--){
        string aux = "";
        for(int i= 1; i <s.size()-1;i++){
            int number = getNumber(s[i-1], s[i], s[i+1]);
            if(( rule & ( 1 << number ) ) != 0){
                aux += 'X';
            }else{
                aux += '.';
            }
        }
        cout << aux << "\n";
        s= "." + aux + ".";
    }
    return 0;
}
