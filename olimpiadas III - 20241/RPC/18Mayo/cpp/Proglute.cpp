#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull m=1000000007;

ull eb (ull a, ull b){

    ull res=1;
    ull x= a%m;

    while(b>0){
        if(b%2)
            res= (res*x)%m;
        x = (x*x)%m;
        b/=2;
    }

    return res;
}

ull mul(ull  a, ull b, ull  mod) {
    ull  ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)    ret -= mod;
        }
    }
    return ret;
}

int main(){

    ull n;
    cin >> n;
    ull ans = mul( eb( 2, n-3), n, m );
    cout << ans << "\n";
    return 0;
}
