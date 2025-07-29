#include <iostream>
using namespace std;

int main() {
    int n;
    int rooms[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }
    int sum = 0;
    int min = 2147483647;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            //cout << (rooms[(i+j)%(n)] * j) << endl;
            sum += (rooms[(i+j)%(n)] * j);
            //cout << i << " " << j << " " << sum << endl;
        }
        //cout << "asdhkj" << endl;
        if (sum < min) {
            min = sum;
        }
    }
    cout << min << endl;
}