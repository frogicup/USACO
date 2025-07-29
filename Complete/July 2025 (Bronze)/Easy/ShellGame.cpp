#include <iostream>
using namespace std;

int main() {
    int n, a, b, g;
    cin >> n;
    int places[3];
    int correct[3];
    for (int i = 0; i < 3; i++) {
        places[i] = i;
        correct[i] = 0;
    }
    int placeholder;
    //int currnum = 0;
    //places[currnum] = true;
    for (int j = 0; j < n; j++) {
        cin >> a >> b >> g;
        //places[currnum] = true;
        placeholder = places[a-1];
        places[a-1] = places[b-1];
        places[b-1] = placeholder;
        for (int i = 0; i < 3; i++) {
            if (places[g-1]==i) {
                correct[i]++;
            }
            /*if (j==0&&i==0) {
                currnum++;
            }*/
        }
        /*if (j==0){
            currnum++;
        }*/
    }
    int max = -1000;
    for (int i = 0; i < 3; i++) {
        if (correct[i] > max) {
            max = correct[i];
        }
    }
    cout << max << endl;
}