#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n;
    string directions[50];
    int xs[50];
    int ys[50];
    int cstats[50];
    int allcst[50][50];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> directions[i] >> xs[i] >> ys[i];
        cstats[i] = -1;// -1 is infinity
        for (int j = 0; j < n; j++) {
            allcst[i][j] = -100; // not yet
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (directions[i] != directions[j]) {
                int idif;
                if (directions[j] == "E") {
                    if (ys[j] > ys[i] && xs[i] > xs[j]) {
                        idif = ys[j]-ys[i];
                        /*if (cstats[j] != -1 && idif > cstats[j]) {
                            continue;
                        }*/
                        allcst[i][j] = idif;
                        //cout << xs[i]-xs[j] << " " << idif << " " << cstats[i] << endl;
                        if (xs[i]-xs[j] <= idif){// && idif > 0) {
                            //cout << "i got here " << cstats[i] << endl;
                            if (cstats[i] == -1 || idif < cstats[i]) {
                                cstats[i] = idif;
                                allcst[i][j] = cstats[i];
                            }
                        }
                        //allcst[i][j] = cstats[i];
                    }
                }
                else {
                    if (xs[j] > xs[i] && ys[i] > ys[j]) {
                        //cout << ys[i] << " " << ys[j] << endl;
                        idif = xs[j]-xs[i];
                        /*if (cstats[j] != -1 && idif > cstats[j]) {
                            continue;
                        }*/
                        allcst[i][j] = idif;
                        //cout << abs(ys[i]-ys[j]) << " " << idif << endl;
                        if (ys[i]-ys[j] <= idif){//&& idif > 0) {
                            //cout << j << i << " i got here " << cstats[i] << endl;
                            if (cstats[i] == -1 || idif < cstats[i]) {
                                cstats[i] = idif;
                                allcst[i][j] = cstats[i];
                                //cout << cstats[i] << endl;
                            }
                        }
                        //allcst[i][j] = cstats[i];
                    }
                }
                //cout << i << " " << idif << endl;
                //cout << i << " " << cstats[i] << endl;
            }
        }
    }
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (allcst[j][i] != -100) {
                bool yes = false;
                //bool repeat = false;
                if (allcst[j][i] >= allcst[i][j]) {
                    for (int k = n-1; k >= 0; k--) {
                        if (allcst[j][k] != allcst[j][i] && allcst[j][k] != -100) {
                            //cstats[j] = allcst[j][k];
                            allcst[j][i] = cstats[j];
                            yes = true; 
                            break;
                        }
                    }
                }
                if (!yes) {
                    cstats[j] = -1;
                }
            }
            temp = i;
            i = j;
            j = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (cstats[i] == -1) {
            cout << "Infinity" << endl;
        }
        else {
            cout << cstats[i] << endl;
        }
    }
}