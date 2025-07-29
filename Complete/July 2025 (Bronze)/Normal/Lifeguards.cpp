#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int starts[100];
    int ends[100];
    for (int i = 0; i < n; i++) {
        cin >> starts[i] >> ends[i];
    }
    int max = -1000;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int start, end;
            if (j != i) {
                start = starts[j];
                end = ends[j];
                /*if (j == 0 || (i == 0 && j == 1)) {
                    start = starts[j];
                    end = ends[j];
                }*/
                if (j >= 1) {
                    //start = starts[j];
                    //end = ends[j];
                    for (int k = 0; k < j; k++) {
                        if (k != i) {
                            if (start < ends[k] && start > starts[k]) {
                                start = ends[k];
                            }
                            if (end > starts[k] && end < ends[k]) {
                                end = starts[k];
                            }
                        }
                    }
                    /*if (end-start < 0) {
                        end = 0;
                        start = 0;
                    }*/
                    
                    //sum += end-start;
                }
                //cout << "start and end " << start << " " << end << endl;
                sum += (end - start);
            }
            
            //cout << sum <<endl;
        }
        //cout << sum << " " << i << endl;
        if (sum > max) {
            max = sum;
        }
        sum = 0;
    }
    cout << max << endl;
}