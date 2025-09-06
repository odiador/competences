#include <bits/stdc++.h>
using namespace std;

bool validateHyphen(const string &isbn) {
    int hyphens = 0;
    int digits = 0;
    int n = isbn.size();
    if (n < 10 || n > 13) return false;
    if (isbn.front() == '-' || isbn.back() == '-') return false;

    for (int i = 0; i < n; ++i) {
        char c = isbn[i];
        if (c == '-') {
            if (i > 0 && isbn[i-1] == '-') return false; // No guiones consecutivos
            hyphens++;
        } else if (isdigit(c) || (c == 'X' && i == n-1)) {
            digits++;
        } else {
            return false; // Carácter inválido
        }
    }

    if (digits != 10 || hyphens > 3) return false;

    // Si hay 3 guiones, uno debe estar justo antes del último dígito
    if (hyphens == 3) {
        bool hyphenBeforeChecksum = false;
        for (int i = 0; i < n-1; ++i) {
            if (isbn[i] == '-' && (isdigit(isbn[i+1]) || isbn[i+1] == 'X') && i+1 == n-1) {
                hyphenBeforeChecksum = true;
                break;
            }
        }
        if (!hyphenBeforeChecksum) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string isbn;
        cin >> isbn;
        if (!validateHyphen(isbn)) {
            cout << "invalid\n";
            continue;
        }
        // extract digits and hyphen positions
        vector<int> hyphenPos;
        string digits;
        for (int i = 0; i < isbn.size(); ++i) {
            if (isbn[i] == '-') hyphenPos.push_back(digits.size());
            else digits += isbn[i];
        }
        // check checksum ISBN-10
        int sum10 = 0;
        for (int i = 0; i < 10; ++i) {
            if (i == 9 && digits[i] == 'X') sum10 += 10;
            else if (isdigit(digits[i])) sum10 += (digits[i] - '0') * (10 - i);
            else sum10 = -1000;
        }
        if (sum10 % 11 != 0) {
            cout << "invalid\n";
            continue;
        }
        // build core and compute ISBN-13 checksum
        string core = digits.substr(0, 9);
        string isbn13digits = "978" + core;
        int sum13 = 0;
        for (int i = 0; i < 12; ++i) {
            int d = isbn13digits[i] - '0';
            sum13 += (i % 2 == 0 ? d : d * 3);
        }
        int cd = (10 - (sum13 % 10)) % 10;
        // reconstruct with hyphens: prefix 978-, then core with original hyphens, then checksum
        string result = "978-";
        for (int i = 0; i < core.size(); ++i) {
            if (!hyphenPos.empty() && hyphenPos.front() == i) {
                result += '-';
                hyphenPos.erase(hyphenPos.begin());
            }
            result += core[i];
        }
        result += to_string(cd);
        cout << result << "\n";
    }
    return 0;
}
