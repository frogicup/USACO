#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int n;
set<string> adjectives;
set<int> animalsLeft;
set<string> usedAdj;
string animals[100];
int numadj[100];
string animaladj[100][100];
string temp;
int sum = 0;
int maximum = 1;

void chooseA() {
    if (animalsLeft.size() == 1) {
        /*if (sum > maximum) {
            maximum = sum;
        }*/
        return;
    }
    for (const string& adj : adjectives) {
        if (usedAdj.find(adj) == usedAdj.end()) {
            usedAdj.insert(adj);
            for (const int& i : animalsLeft) {
                for (int j = 0; j < n; j++) {
                    if (animaladj[i][j] == adj) {
                        animalsLeft.erase(i);
                        sum++;
                        chooseA();
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> animals[i] >> numadj[i];
        animalsLeft.insert(i);
        for (int j = 0; j < numadj[i]; j++) {
            cin >> temp;
            //cout << temp << endl;
            adjectives.insert(temp);
            animaladj[i][j] = temp;
        }
    }
    /*for (const string& adj : adjectives) {
        //cout << adj << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < numadj[i]; j++) {
                if (animaladj[i][j] == adj) {
                    sum++;
                }
            }
        }
        if (sum > maximum) {
            maximum = sum;
        }
        sum = 0;
    }
    */
    chooseA();
    cout << maximum << endl;
}