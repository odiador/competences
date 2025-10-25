#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, mxx1, mxx2, cnt1, cnt2, mn, mx;
    deque<int> q1, q2;
    vector<int> v;
    while (cin >> x && x != 0)
    {
        vector<int> v(x);
        for (int i = 0; i < x; i++)
        {
            cin >> v[i];
        }

        mxx1 = 0, mxx2 = 0, cnt1 = 0, cnt2 = 0, mn = 0, mx = 0;
        q1.push_front(-100000);
        q2.push_front(-100000);

        for (int i = 0; i < x; i++)
        {
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
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

        q1.clear();
        q2.clear();
        v.clear();
        cout << mx << " " << mn << " " << max(mxx1, mxx2) << endl;
    }

    return 0;
}
