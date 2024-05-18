#include <iostream>
#include <vector>

using namespace std;

int main() {
    int nStudent, nSch, cup;

    cin >> nStudent >> nSch >> cup;

    int opc1 = 0, opc2 = 0;

    vector<vector<int>> vStudent(nStudent, vector<int>(2));

    for (int i = 0; i < nStudent; i++) {
        cin >> vStudent[i][0] >> vStudent[i][1];
    }

    vector<int> vSchool(nSch + 1, cup);

    for (int i = 0; i < nStudent; i++) {
        if (vSchool[vStudent[i][0]] > 0) {
            ++opc1;
            vSchool[vStudent[i][0]] -= 1;
        } else if (vSchool[vStudent[i][1]] > 0) {
            ++opc2;
            vSchool[vStudent[i][1]] -= 1;
        }
    }

    cout << opc1 << " " << opc2 << endl;

    return 0;
}
