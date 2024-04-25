#import <iostream>
#import <vector>

using namespace std;

int main() {
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> matrix1;
    vector<string> matrix2;
    for (int i = 0; i < r; i++) {
        string cad1, cad2;
        cin >> cad1 >> cad2;
        matrix1.push_back(cad1);
        matrix2.push_back(cad2);
    }

    char possible = 'Y';
    for (int x = 0; x < r; x++) {
        if (matrix1[x].find('-') != string::npos && matrix2[x].find('*') != string::npos) {
            possible = 'N';
            break;
        }
    }
    cout << possible << endl;

    return 0;
}