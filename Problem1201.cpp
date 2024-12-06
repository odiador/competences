

#include <iostream>
using namespace std;
// 10260

int main()
{
    string s;
    string soundex = "012301200224550126230202";
    while (getline(cin, s))
    {
        int canRepeat = 0;
        int count = 0;
        string ans = soundex[s[0] - 'A'] + "";
        int len = 1;
        for (int i = 1; i < s.length(); i++)
        {

            if (ans[len - 1] != soundex[s[i] - 'A'])
            {
                ans.append(soundex[s[i] - 'A'] + "");
            }
        }
        cout << ans << endl;
    }
    return 0;
}
