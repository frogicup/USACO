#include <iostream>
using namespace std;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    char s[m][m];
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            cin >> s[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        //cout << l << r << endl;
        for (int j = 0; j < m; j++) {
            if (s[j][l-1] == 'W' && s[j][r-1] == 'W') {
                count += (m-1)*2+1;
                if (s[l-1][j-1] == 'W') {
                    count += (m-1)*2+1;
                }
            }
            
        }
        cout << count << endl;
    }
}