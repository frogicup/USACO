#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;
    string s, temp;
    cin >> s;
    int m = -1;
    //char first;
    //unordered_map<char, vector<int>> alphabet_indexes;
    for (int v = 0; v < q; v++) {
        cin >> l >> r;
        temp = s.substr(l - 1, r - l + 1);
        /*for (int i = 1; i <= temp.length(); i++) {
            alphabet_indexes[temp[i-1]].push_back(i);
            if (i == 1) {
                first = temp[0];
            }
        }
        for (const auto&pair : alphabet_indexes) {
            if (pair.first != first) {
                if ((pair.second[pair.second.size()-2]-1)*(pair.second[pair.second.size()-1]-pair.second[pair.second.size()-2]) > m) {
                    m = (pair.second[pair.second.size()-2]-1)*(pair.second[pair.second.size()-1]-pair.second[pair.second.size()-2]);
                }
            }
        }*/
        for (int i = 0; i < temp.length()-2; i++) {
            for (int j = i+1; j < temp.length()-1; j++) {
                if (temp[i] == temp[j]) {
                    continue;
                }
                for (int k = j+1; k < temp.length(); k++) {
                    if (temp[i] != temp[j] && temp[j] == temp[k]) {
                        if ((j-i) * (k-j) > m) {
                            m = (j-i) * (k-j);
                        }
                    }
                }
            }
        }
        cout << m << endl;
        m = -1;
        //alphabet_indexes.clear();
    }
}