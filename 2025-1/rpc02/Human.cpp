#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n <= 2)
    {
        cout << 1 << endl;
        return 0;
    }

    long long maxByLevel = 2, ant = 2, l = 0;
    while (n >= maxByLevel)
    {
        l++;
        maxByLevel = (l + 1) * (l / 2);
        maxByLevel += l % 2 == 1 ? (l + 1) / 2 : 0;
    }
    cout << (l - 1) << endl;
    return 0;
}