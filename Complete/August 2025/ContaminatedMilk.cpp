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
    for (int i = 0; i < s; i++) {
        cin >> sick[i] >> sicktimes[i];
        milksickpos[i] = -1;
    }
    int medicine = 0;
    set<int> drankmilkb4;
    for (int i = 1; i <= m; i++) {
        bool cant = true;
        for (int j = 0; j < s; j++) {
            bool drank = false;
            for (int k = 0; k < d; k++) {
                if (sick[j] == people[k] && milks[k] == i && times[k] < sicktimes[j]) {
                    drank = true;
                    break;
                }
            }
            if (!drank) {
                cant = false;
                break;
            }
        }
        if (!cant) {
            continue;
        }
        for (int j = 0; j < d; j++) {
            if (milks[j] == i) {
                drankmilkb4.insert(people[j]);
            }
        }
        if ((int)drankmilkb4.size() > medicine) {
            medicine = drankmilkb4.size();
        }
        drankmilkb4.clear();
    }
    cout << medicine << endl;
}
