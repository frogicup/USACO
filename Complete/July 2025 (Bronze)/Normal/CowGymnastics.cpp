#include <iostream>
using namespace std;

int search(int arr[20], int n, int t) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == t) {
            return i;
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int rankings[10][20];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rankings[i][j];
        }
    }
    int pairs = 0;
    for (int k = 0; k < n; k++) {
        int correlation = 0;
        for (int i = 0; i < n; i++) {
            if (k != i) {
                for (int j = 0; j < m; j++) {
                    if (search(rankings[j], n, rankings[0][i]) < search(rankings[j], n, rankings[0][k])) {
                        correlation++;
                    }
                }
                if (correlation == m) {
                    //cout << rankings[0][k] << " " << rankings[0][i] << endl;
                    pairs++;
                }
            }
            correlation = 0;
        }
    }
    cout << pairs << endl;
}