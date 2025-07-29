#include <iostream>
using namespace std;

int main() {
    int lx1, ly1, lx2, ly2, cx1, cy1, cx2, cy2;
    cin >> lx1 >> ly1 >> lx2 >> ly2 >> cx1 >> cy1 >> cx2 >> cy2;
    int area = abs((lx2-lx1) * (ly2-ly1));
    // covers all
    if ((cy2 >= ly2) && (cy1 <= ly1) && (cx1 <= lx1) && (cx2 >= lx2)) {
        area = 0;
    }
    else {
        // covers horizontally
        if ((cx1 <= lx1) && (cx2 >= lx2)) {
            // above
            if (cy2 > ly2) {
                area -= (ly2-cy1) * (lx2-lx1);
            }
            // below
            else if (cy1 <= ly1) {
                area -= (cy2-ly1) * (lx2-lx1);
            }
        }
        // covers vertically
        else if ((cy2 >= ly2) && (cy1 <= ly1)) {
            // right
            if (cx2 > lx2) {
                area -= (lx2-cx1) * (ly2-ly1);
            }
            // left
            else if (cx1 <= lx1) {
                area -= (cx2-lx1) * (ly2-ly1);
            }
        }
    }
    cout << area << endl;
}