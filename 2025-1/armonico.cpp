#include <iostream>

using namespace std;

double armonico(int c)
{
    double sum = 1;
    int x = 1;
    while (++x <= c)
        sum += (1.0 / x);
    return sum;
}
int main()
{
    int x;
    cin >> x;
    cout << armonico(x) << "\n";
}
