
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int maxn = 0;
    for (int i = 0; i < n - m; i++)
    {
        for (int j = i + 1; j < i + m; j++)
        {
            max(maxn, array[j] - array[i]);
        }
    }

    cout << maxn << endl;
    return 0;
}