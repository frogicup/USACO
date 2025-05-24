#include <iostream>
using namespace std;

int main() {
    int t, n, a, b;
    cin >> t;
    //t = 1;
    for (int i = 0; i < t; i++) {
        int count = 0;
        cin >> n >> a >> b;
        n = 3;
        a = 0;
        b = 0;
        string arr[1000][1000];
        string temp;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> arr[j][k];
                /*cin >> temp;
                if (temp == "W") {
                    arr[j][k] = 0;
                }
                else if (temp == "G") {
                    arr[j][k] = 1;
                }
                else if (temp == "B") {
                    arr[j][k] = 2;
                }*/
            }
        }
        if (a == 0 && b == 0) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (arr[j][k] == "G" || arr[j][k] == "B") {
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
}