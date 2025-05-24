#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    //n = 1000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, vector<int>> index_positions;
    for (int i = 0; i < n; i++) {
        index_positions[arr[i]].push_back(i);
    }
    set<long long> seen_double;
    for (const auto&pair : index_positions) {
        if(pair.second.size() > 1) {
            seen_double.insert(pair.first);
        }
    }
    set<long long> unique_before;
    vector<long long> unique_size(n);
    for (int i = 0; i < n; i++) {
        unique_before.insert(arr[i]);
        unique_size[i] = unique_before.size();
    }
    long long count = 0;
    long long temp = 0;
    for (auto d : seen_double) {
        temp = unique_size[index_positions[d][index_positions[d].size()-2]];
        if (index_positions[d].size() > 2) {
            temp--;
        }
        count += temp;
    }
    cout << count;
    /*set<long> usedmoo;
    set<int> useddouble;
    int temp = 0;
    int tempcount = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        temp = arr[i];
        if (usedmoo.find(temp) != usedmoo.end()) {
            continue;
        }
        tempcount = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == temp) {
                tempcount++;
            }
        }
        if (tempcount > 1) {
            useddouble.insert(temp);
            for (int k = 0; k < n; k++) {
                if (arr[k] != temp) {
                    int counttemp = 0;
                    for (int l = k; l < n; l++) {
                        if (arr[l] == temp) {
                            counttemp++;
                        }
                    }
                    if (counttemp > 1) {
                        usedmoo.insert(stol(to_string(arr[k]) + to_string(temp) + to_string(temp)));
                    }
                }
                if (k < i) {
                    //cout << arr[k] << temp << temp << endl;
                    usedmoo.insert(stoi(to_string(arr[k]) + to_string(temp) + to_string(temp)));
                }
            }
        }
    }
    cout << usedmoo.size();*/
    /*set<int> nums;
    for (int i = 0; i < n; i++) {
        nums.insert(arr[i]);
    }
    for (const auto&element : nums) {
        temp = element;
        tempcount = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == temp) {
                tempcount++;
            }
        }
        //cout << tempcount << endl;
        if (tempcount > 1) {
            count++;
        }
    }
    cout << count * (nums.size()-1);*/
}