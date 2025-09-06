#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    double long n;
    vector<double long> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    for (int i = 3; i < 100; i++)
    {
        v.push_back(v[i - 1] * i);
    }

    cout << setiosflags(ios_base::fixed) << std::setprecision(0);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    // int i = 2;
    // cin >> n;
    // while (n >= 1)
    // {
    //     n /= i;
    //     i++;
    // }
    // cout << (i-1) << endl;
    return 0;
}