#include <iostream>
#include <string>

using namespace std;

string getQuote(bool start) {
    return start ? "``" : "''";
}

int main() {
    bool start = true;
    string line;

    while (getline(cin, line)) {
        unsigned long long pos = line.find('"', 0);
        string result;
        while (pos != string::npos) {
            result.append(line.substr(0, pos));
            result.append(getQuote(start));
            start = !start;
            line = line.substr(pos + 1);
            pos = line.find('"');
        }
        result.append(line);
        cout << result << endl;
    }

    return 0;
}
