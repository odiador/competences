#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;

#define DEBUG
#define pb push_back
#define mp make_pair

const ll INF = 1e18;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve()
{
    
    string dum,s1,s2, r;

    int x;
    getline(cin,dum);
    x = stoi(dum);
    getline(cin,s1);
    getline(cin,s2);
    int formed = 0;
    bool start = false;
    for (int i = 0; i<x;i++){
        char ch1 = s1[i];
        if(ch1=='\\'){
            start = true;
        } else if (ch1=='/'){
            formed++;
            start = false;
        } else {
            if (!start){
                r+=formed==1?'v':'w';
                formed = 0;
            }
        }

    }
    r+=formed==1?'v':'w';
    cout<<r<<endl;
        
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    return 0;
}