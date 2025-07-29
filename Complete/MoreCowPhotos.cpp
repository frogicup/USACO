#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int t, n, count, tallest;
    int heights[100000] = { 0 };
    int totalOfThatHeight[100000] = { 0 };
    count = 0;
    tallest = -100000;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> heights[j];
            //cout << "totalOfThatHeight " << totalOfThatHeight[heights[j]] << " BEFORE " << heights[j] << endl;
            if (heights[j] > tallest) {
                tallest = heights[j];
            }
            totalOfThatHeight[heights[j]]++;
            //cout << "totalOfThatHeight " << totalOfThatHeight[heights[j]] << " for " << heights[j] << endl;
        }
        for (int j = 1; j <= n; j++) {
            //cout << "tallest " << tallest << endl;
            //cout << "tothj " << totalOfThatHeight[j] << " j " << j << endl;
            if (j == tallest) {
                count++;
            }
            else {
                if (totalOfThatHeight[j] >= 2 && j != tallest) {
                    count+=2;
                }
            }
        }
        cout << count << endl;
        count = 0;
        for (int j = 0; j < n; j++) {
            heights[j] = 0;
            totalOfThatHeight[j+1] = 0;
        }
        tallest = -100000;
    }
}