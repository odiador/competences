#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int x;
    cin >> x;
    vector<int> v(x);
    for (int i = 0; i < x; i++)
    {
        cin >> v[i];
    }
    deque<int> q1, q2;
    int mxx1 = 0, mxx2 = 0, cnt1 = 0, cnt2 = 0;
    q1.push_front(-100000);
    q2.push_front(-100000);

    for (int i = 0; i < x; i++)
    {
        if (v[i] > 0)
        {
            q1.push_front(1);
        }
        else if (v[i] < 0)
        {
            if (q1.front() == -100000)
            {
                cnt1 = 0;
            }
            else
            {
                q1.pop_front();
                cnt1 += 2;

                if (q1.size() == 1 && q1.front() == -100000)
                {
                    mxx1 = max(mxx1, cnt1);
                }
            }
        }
        else
        {
            cnt1++;

            if (q1.size() == 1 && q1.front() == -100000)
            {
                mxx1 = max(mxx1, cnt1);
            }
        }
    }

    for (int i = 0; i < x; i++)
    {
        if (v[i] < 0)
        {
            q2.push_front(1);
        }
        else if (v[i] > 0)
        {
            if (q2.front() == -100000)
            {
                cnt2 = 0;
            }
            else
            {
                q2.pop_front();
                cnt2 += 2;

                if (q2.size() == 1 && q2.front() == -100000)
                {
                    mxx2 = max(mxx2, cnt2);
                }
            }
        }
        else
        {
            cnt2++;

            if (q2.size() == 1 && q2.front() == -100000)
            {
                mxx2 = max(mxx2, cnt2);
            }
        }
    }

    int result = max(mxx1, mxx2);
    cout << result << endl;

    return 0;
}
