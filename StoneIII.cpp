/*
==========================================================
|  Archivo       : dominoTromino.cpp
|  Autor         : Miguel Betancourt
|--------------------------------------------------------
|  Descripción   : Find all the ways to tile a 2 x n board
|                  using dominoes and trominoes.
|--------------------------------------------------------
|  Temas utilizados: Dynamic Programming (unnoptimized)
==========================================================
*/

// custom_bits/stdc++.h
// Drop this file in a "bits" folder, then #include <bits/stdc++.h>
// Covers almost all standard C++ headers.

// C headers (from C standard library)
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>

// C++ headers
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <codecvt>
#include <complex>
#include <condition_variable>
#include <deque>
#include <exception>
#include <execution>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <shared_mutex>
#include <span>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>

// Experimental (not always available)
// #include <experimental/any>
// #include <experimental/optional>
// #include <experimental/string_view>
// #include <experimental/filesystem>

using namespace std;

// Typedefs
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vi = vector<int>;
using vii = vector<pii>;
using vc = vector<char>;

typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;
typedef vector<long long int>::iterator vllit;

// Constants
const ll INF = 1e18;
const int INF_INT = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

// Macros
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define _ % MOD
#define __ %= MOD

#define each(it, s) for (vit it = (s).begin(); it != (s).end(); ++it)
#define sortA(v) sort((v).begin(), (v).end())
#define sortD(v) sort((v).begin(), (v).end(), greater<decltype((v)[0])>())
#define fill(a) memset(a, 0, sizeof(a))

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = (a); i <= (n); ++i)
#define repD(i, a, n) for (int i = (a); i >= (n); --i)
#define pq(x) priority_queue<x, vector<x>, greater<x>>
#define rpq(x) priority_queue<x, vector<x>, less<x>>

#define fbo find_by_order
#define ook order_of_key
#define DEBUG

#define COMPILE_DEBUG "clang++ -DDEBUG -std=c++17 Plantilla.cpp -o Plantilla"

#define loop(i, start, end) for (auto i = (start < end) ? start : start - 1; (start < end) ? i < end : i >= end; (start < end) ? i++ : i--)

// Utility functions
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    if (n == 1)
    {
        if (stoneValue[0] == 0)
            return "Tie";
        if (stoneValue[0] < 0)
            return "Bob";
        if (stoneValue[0] > 0)
            return "Alice";
    }
    map<pair<int, int>, int> mp;

    return calc(mp,stoneValue,0,n-1);
}

int calc(map<pair<int, int>, int> &mp, vector<int> &stoneValue, int i, int j)
{
    if (i == j)
    {
        mp[{i, i}] = stoneValue[i];
        return mp[{i, i}];
    }
    if (mp[{i, j}])
        return mp[{i, j}];

    int res = stoneValue[i];

    int mx = calc(mp, stoneValue, i, j);
    for (int k = 2; k <= 3; k++)
    {
        if (k > j % 3)
            mx = max(mx, calc(mp, stoneValue, i + k, j));
    }
    return mx;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++)
        cin >> values[i];
    cout<<stoneGameIII(values)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    while (cin)
    {
        solve();
    }

    return 0;
}