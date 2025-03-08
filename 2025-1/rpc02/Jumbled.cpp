#include <iostream>
using namespace std;

int main()
{
    int n, a, b, befA = 0, befB = 0;
    cin >> n;
    string s = "yes";
    while (n-- > 0)
    {
        cin >> a >> b;
        if (befA > a || befB > b)
            s = "no";
        befA = a;
        befB = b;
    }
    cout << s << endl;
    return 0;
}