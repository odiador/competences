#include <iostream>
#include <cctype>

using namespace std;


// NOT SOLVED
int main() {
    string s;
    while (getline(cin, s)) {
        long word = 0;
        while (!s.empty()) {
            word++;
            unsigned long long pos = s.find(' ');
            if (pos == string::npos)
                break;
            s.substr(0, pos)
            if (isalpha())
                s = s.substr(pos + 1);
            cout << word << " " << s << endl;
        }
        cout << word << endl;
    }
    return 0;
}