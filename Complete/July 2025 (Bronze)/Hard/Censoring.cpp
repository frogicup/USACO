#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    //int place = (int)s.find(t);
    int tl = (int)t.length();
    string done = "";
    for (char c: s) {
        done += c;
        if (done.length() >= tl && done.substr(done.length()-tl) == t) {
            done.erase(done.length()-tl);
        }
    }
    //done.append(s);
    cout << done << endl;
}
