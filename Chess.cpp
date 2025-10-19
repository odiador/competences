/*
==========================================================
|  Archivo       : ISBN.cpp
|  Autor         : Miguel Betancourt
|--------------------------------------------------------
|  Descripción   :
|--------------------------------------------------------
|  Temas utilizados:
|--------------------------------------------------------
==========================================================
*/

// C++ headers
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
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
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

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
#define DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repA(i, a, n) for (int i = (a); i <= (n); ++i)
#define repD(i, a, n) for (int i = (a); i >= (n); --i)
#define pq(x) priority_queue<x, vector<x>, greater<x>>
#define rpq(x) priority_queue<x, vector<x>, less<x>>

#define fbo find_by_order

#define loop(i, start, end) for (auto i = (start < end) ? start : start - 1; (start < end) ? i < end : i >= end; (start < end) ? i++ : i--)

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int numberRook(int row, int col, int n, vector<vector<bool>> &m)
{
    int total = 0;
    if (!m[row - 1][col - 1])
    {
        total = 1;
        m[row - 1][col - 1] = true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!m[row - 1][i])
        {
            total++;
            m[row - 1][i] = true;
        }
        if (!m[i][col - 1])
        {
            total++;
            m[i][col - 1] = true;
        }
    }

    return total;
}

int numberQueen(int row, int col, int n, vector<vector<bool>> &m)
{
    int total = 0;

    total = total + numberRook(row, col, n, m);

    total = 2 * total;

    return total;
}

int numberKnight(int row, int col, int n, vector<vector<bool>> &m)
{
    int total = 0;
    if (!m[row - 1][col - 1])
    {
        total = 1;
        m[row - 1][col - 1] = true;
    }
    if (row - 2 > 0 && col - 1 > 0 && !m[row - 3][col - 2])
    {
        total++;
        m[row - 3][col - 2] = true;
    }
    if (row + 2 <= n && col - 1 > 0 && !m[row + 1][col - 2])
    {
        total++;
        m[row + 1][col - 2] = true;
    }
    if (row - 2 > 0 && col + 1 <= n && !m[row - 3][col])
    {
        total++;
        m[row - 3][col] = true;
    }
    if (row + 2 <= n && col + 1 <= n && !m[row + 1][col])
    {
        total++;
        m[row + 1][col] = true;
    }
    if (col - 2 > 0 && row - 1 > 0 && !m[row - 2][col - 3])
    {
        total++;
        m[row - 2][col - 3] = true;
    }
    if (col + 2 <= n && row - 1 > 0 && !m[row - 2][col + 1])
    {
        total++;
        m[row - 2][col + 1] = true;
    }
    if (col - 2 > 0 && row + 1 <= n && !m[row][col - 3])
    {
        total++;
        m[row][col - 3] = true;
    }
    if (col + 2 <= n && row + 1 <= n && !m[row][col + 1])
    {
        total++;
        m[row][col + 1] = true;
    }

    return total;
}

void solve()
{

    int size;
    cin >> size;

    vector<vector<bool>> m;
    for (int i = 0; i < size; i++)
    {
        vector<bool> x;
        for (int j = 0; j < size; j++)
        {
            x.push_back(false);
        }
        m.push_back(x);
    }

    int n;
    cin >> n;

    char piece;

    int total = 0;

    int row, col;

    while (n > 0)
    {
        cin >> piece;
        cin >> row >> col;

        if (piece == 'Q')
        {
            total = total + numberQueen(row, col, size, m);
        }
        if (piece == 'R')
        {
            total = total + numberRook(row, col, size, m);
        }
        if (piece == 'N')
        {
            total = total + numberKnight(row, col, size, m);
        }

        n--;
    }

    cout << total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}

// clang++ -DDEBUG -std=c++14 chess.cpp -o chess && ./chess < input.txt > output.txt