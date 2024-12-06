#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> icons(2 * N);

    for (int i = 0; i < 2 * N; i++)
    {
        cin >> icons[i];
    }

    int h = icons[0] + icons[2 * N - 1];

    int w = 0;
    for (int i = 0; i < N; i++)
    {
        w += icons[i];
    }

    cout << h * w << endl;

    return 0;
}
