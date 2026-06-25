#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int lims[100];
    int speeds[100];
    int length, speed;
    int place = 0;
    // importing speed limits
    for (int i = 0; i < n; i++) {
        cin >> length >> speed;
        for (int j = 0; j < length; j++) {
            lims[place] = speed;
            place++;
        }
    }
    place = 0;
    // importing bessie's speeds
    for (int i = 0; i < m; i++) {
        cin >> length >> speed;
        for (int j = 0; j < length; j++) {
            speeds[place] = speed;
            place++;
        }
    }
    int max = 0;
    for (int i = 0; i < 100; i++) {
        if ((speeds[i]-lims[i]) > max) {
            max = (speeds[i]-lims[i]);
        }
    }
    cout << max << endl;
}