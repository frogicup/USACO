#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, start, end;
    int ons = 0;
    int one = 0;
    int offs = 0;
    int offe = 0;
    cin >> n;
    string pos;
    int starts[100];
    int ends[100];
    int stat[100];
    for (int i = 0; i < n; i++) {
        cin >> pos >> start >> end;
        if (pos == "on") {
            stat[i] = 1;
        }
        else if (pos == "off") {
            stat[i] = 2;
        }
        else {
            stat[i] = 3;
        }
        starts[i] = start;
        ends[i] = end;
    }
    // ------
    int s = n-1;
    while (stat[s] != 3) {
        s--;
    }
    ons = starts[s];
    one = ends[s];
    for (int i = s-1; i >= 0; i--) {
        if (stat[i] == 1) {
            ons -= max(starts[i], ends[i]);
            one -= min(starts[i], ends[i]);
        }
        else if (stat[i] == 2) {
            ons += min(starts[i], ends[i]);
            one += max(starts[i], ends[i]);
        }
        else {
            if (starts[i] > ons) {
                ons = starts[i];
            }
            if (ends[i] < one) {
                one = ends[i];
            }
        }
    }
    if (ons < 0) {
        ons = 0;
    }
    if (one < 0) {
        one = 0;
    }
    cout << ons << " " << one << endl;
    s = 0;
    while (stat[s] != 3) {
        s++;
    }
    offs = starts[s];
    offe = ends[s];
    for (int i = s+1; i < n; i++) {
        if (stat[i] == 1) {
            offs += min(starts[i], ends[i]);
            offe += max(starts[i], ends[i]);
        }
        else if (stat[i] == 2) {
            offs -= max(starts[i], ends[i]);
            offe -= min(starts[i], ends[i]);
        }
        else {
            if (starts[i] > offs) {
                offs = starts[i];
            }
            if (ends[i] < offe) {
                offe = ends[i];
            }
        }
    }
    if (offs < 0) {
        offs = 0;
    }
    if (offe < 0) {
        offe = 0;
    }
    cout << offs << " " << offe << endl;
    /*int maxlow = -1000;
    int minupp = 1000;
    int low = 0;
    int high = n;
    if (ons != 0) {
        low = 1;
    }
    if (offs != 0) {
        high = n-1;
    }
    for (int i = low; i < high; i++) {
        //cout << maxlow << " " << minupp << " " << starts[i] << " " << ends[i] << endl;
        if (starts[i] > maxlow) {
            maxlow = starts[i];
        }
        if (ends[i] < minupp) {
            minupp = ends[i];
        }
    }
    //cout << maxlow << " " << minupp << endl;
    cout << maxlow - max(ons,one) << " " <<  minupp - min(ons,one) << endl;
    cout << maxlow - max(offs, offe) << " " << minupp - min(offs,offe);*/
}