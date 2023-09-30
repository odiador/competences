
#include <iostream>

using namespace std;

int main() {
    int cases, width, height;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        cin >> width >> height;
        char arr[height][width];
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) {
                cin >> arr[i][j];
            }
        int cont = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (arr[i][j] >= 'A' && arr[i][j] <= 'Z')cont++;
            }
        }
        if (cont >= ((width * height) / 2)) cout << "IT IS A PICASSO PAINTING" << endl;
        else cout << "IT IS NOT A PICASSO PAINTING" << endl;
    }
    return 0;
}