#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char spotted[100][100];
    char plain[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> spotted[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plain[i][j];
        }
    }
    int count = 0;
    for (int j = 0; j < m; j++) {
        int correct = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                //cout << spotted[i][j] << " " << plain[k][j];
                if (spotted[i][j] != plain[k][j]) {
                    correct++;
                }
            }
        }
        //cout << correct << endl;
        if (correct == n*n) {
            count++;
        }
    }
    cout << count << endl;
}