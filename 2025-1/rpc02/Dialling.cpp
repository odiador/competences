#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int lenw, lenn;
    string value;
    string result;
    vector<string> words, numbers, ans;
    cin >> lenw >> lenn;
    for (int j = 0; j < lenw; j++)
    {
        cin >> value;
        words.push_back(value);
    }
    for (int i = 0; i < lenn; i++)
    {
        cin >> value;
        numbers.push_back(value);
    }

    for (int i = 0; i < lenn; i++)
    {
        value = numbers[i];
        for (int j = 0; j < lenw; j++)
        {
            string wo = words[j];
            int wlen = value.length();
            if (wo.length() != wlen)
                continue;
            int c = 0;
            for (int x = 0; x < wlen; x++)
            {
                if (
                    value[x] == '2' && wo[x] >= 'a' && wo[x] <= 'c' ||
                    value[x] == '3' && wo[x] >= 'd' && wo[x] <= 'f' ||
                    value[x] == '4' && wo[x] >= 'g' && wo[x] <= 'i' ||
                    value[x] == '5' && wo[x] >= 'j' && wo[x] <= 'l' ||
                    value[x] == '6' && wo[x] >= 'm' && wo[x] <= 'o' ||
                    value[x] == '7' && wo[x] >= 'p' && wo[x] <= 's' ||
                    value[x] == '8' && wo[x] >= 't' && wo[x] <= 'v' ||
                    value[x] == '9' && wo[x] >= 'w' && wo[x] <= 'z')
                {
                    c++;
                    continue;
                }
                break;
            }
            if (c == wlen)
            {
                ans.push_back(wo);
            }
        }
        int sz = ans.size();
        result = "";
        result.append(to_string(sz));
        result.append(sz > 0 ? " " : "");
        for (int x = 0; x < sz - 1; x++)
        {
            result.append(ans[x]);
            result.append(" ");
        }
        if (sz - 1 >= 0)
            result.append(ans[sz - 1]);
        cout << result << endl;
        ans.clear();
    }

    return 0;
}
