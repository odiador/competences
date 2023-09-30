
#include <iostream>

using namespace std;

int findPeabot(int a, int b, int s, int arrS[], int arrResult[]);

int countSum(const int arrA[], int a, int num);

void sortMatr(int a, int b, int s, int arrS[], int arrResult[]);

int main() {
    int a, s;
    cin >> a >> s;
    int arrA[a];
    int arrS[s];
    int arrResultsS[s];

    for (int &i: arrA) cin >> i;
    for (int &i: arrS) cin >> i;

    for (int iS = 0; iS < s; iS++) {
        arrResultsS[iS] = countSum(arrA, a, arrS[iS]);
    }

    sortMatr(0, s - 1, s, arrS, arrResultsS);

    for (int j = 0; j < s; j++) {
        cout << arrS[j] << " " << arrResultsS[j];
        cout << endl;
    }
}

int findPeabot(int a, int b, int s, int arrS[], int arrResult[]) {
    int p = arrResult[b];
    int i = a - 1;
    for (int j = a; j < b; j++) {
        if (arrResult[j] > arrResult[i]) {
            i++;
            int aux = arrResult[i];
            arrResult[i] = arrResult[j];
            arrResult[j] = aux;
            aux = arrS[i];
            arrS[i] = arrS[j];
            arrS[j] = aux;
        } else if (arrResult[j] == arrResult[i] && arrS[i] > arrS[j]) {
            i++;
            int aux1 = arrResult[j];
            arrResult[j] = arrResult[i];
            arrResult[i] = aux1;
            aux1 = arrS[j];
            arrS[j] = arrS[i];
            arrS[i] = aux1;
        }
    }
    int aux = arrResult[i + 1];
    arrResult[i + 1] = p;
    arrResult[b] = aux;
    aux = arrS[i + 1];
    arrS[i + 1] = arrS[b];
    arrS[b] = aux;
    return i + 1;
}


int countSum(const int arrA[], int a, int num) {
    int cont = 0;
    for (int i = 0; i < a - 1; i++) {
        for (int j = i + 1; j < a; j++) {
            if (arrA[i] + arrA[j] == num) {
                cont++;
            }
        }
    }
    return cont;
}

void sortMatr(int a, int b, int s, int arrS[], int arrResult[]) {
    if (a < b) {
        int p = findPeabot(a, b, s, arrS, arrResult);
        sortMatr(a, p - 1, s, arrS, arrResult);
        sortMatr(p + 1, p, s, arrS, arrResult);
    }
}
