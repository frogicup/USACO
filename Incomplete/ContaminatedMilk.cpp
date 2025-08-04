#include <iostream>
#include <set>
using namespace std;

int find(int arr[50], int n, int p) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == p) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n,m,d,s;
    cin >> n >> m >> d >> s;
    int people[1000];
    int milks[1000];
    int times[1000];
    int sick[50];
    int sicktimes[50];
    int milksickpos[50];
    for (int i = 0; i < d; i++) {
        cin >> people[i] >> milks[i] >> times[i];
    }
    int mm = -100;
    for (int i = 0; i < s; i++) {
        cin >> sick[i] >> sicktimes[i];
        milksickpos[i] = -1;
        if (sicktimes[i] > mm) {
            mm = sicktimes[i];
        }
    }
    int medicine = 0;
    set<int> drankmilkb4;
    for (int i = 1; i <= m; i++) {
        bool cant = false;
        /*for (int j = 0; j < s; j++) {
            if ()
        }*/
        for (int j = 0; j < d; j++) {
            if (find(sick, s, people[j]) != -1) {
                int count = 0;
                for (int k = 0; k < d; k++) {
                    if (milks[k] == i && people[k] == people[j]) {
                        count++;
                    }
                }
                if (count == 0) {
                    cant = true;
                    break;
                }
            }
            if (find(sick, s, people[j]) != -1 || (milks[j] == i && find(sick, s, people[j]) == -1)) {//sicktimes[people[j-1]])) {
                drankmilkb4.insert(people[j]);
                //cout << "peple j " << people[j] << endl;
            }
            if (drankmilkb4.size() >= s) {
                for (int k = 0; k < d; k++) {
                    //cout << i << " k " << people[k] << endl;
                    if (milks[k] == i) {
                        int count = 0;
                        /*if (i == 2) {
                            cout << "asfasd" << endl;
                        }*/
                        for (int l = 0; l < s; l++) {
                            if (people[k] != people[l]) {
                                count++;
                            }
                        }
                        if (count == s){
                            //cout << i << " k " << people[k] << endl;
                            drankmilkb4.insert(people[k]);
                            break;
                            //cout << "k " << people[k] << endl;
                        }
                    }
                }
            }
        }
        //cout << i << " milk" << endl;
        for (const int &person : drankmilkb4) {
            //cout << person << endl;
        }
        if (cant == false) {
            milksickpos[i-1] = (int)drankmilkb4.size();
            drankmilkb4.clear();
        }
        //cout << milksickpos[i-1] << endl;
        if (cant) {
            drankmilkb4.clear();
            continue;
        }
    }
    for (int i = 0; i < m; i++) {
        if (milksickpos[i] > medicine) {
            medicine = milksickpos[i];
        }
        //cout << i << " " << milksickpos[i] << endl;
    }
    if (medicine > n) {
        medicine = n;
    }
    cout << medicine << endl;
}