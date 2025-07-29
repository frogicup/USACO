#include <iostream>
#include <cmath>
using namespace std;

/* COMMENTS ARE IN CAPS B/C THE LOWERCASE STUFF WAS USED TO TEST AND PRINT STUFF */

/*// FUNCTION FOR NORMAL ROUNDING
int roundResultFunct(int n, int length) { // N IS THE NUMBER YOU WANT TO ROUND, LENGTH IS THE NUMBER OF DIGITS THE NUMBER HAS
    // DUMMYN IS THE NUMBER YOU CHANGE TO MAKE N ROUNDED TO THE NEAREST 10^LENGTH
    int dummyn = n;
    // X IS THE REMAINDER THAT HELPS ROUND TO NEAREST 10^LENGTH
    int x =(n % (int)pow(10,(length-1)));
    //cout << "x" << x << endl;
    // FOR ROUND DOWN (IF IT'S ROUNDING UP, IT WILL DO THAT IN THE IF CONDITION)
    dummyn -= x;
    //cout << "dummyn before" << dummyn << endl;
    // CHECKS TO SEE IF IT IS ROUNDING UP WITH THE 2ND DIGIT FROM THE LEFT
    if ((x-(x%(int)pow(10,length-2)))/(int)pow(10,length-2) >= 5) {
        //cout << (dummyn-(x%(int)pow(10,length-2)))/(int)pow(10,length-2) << endl;
        //cout << "hi" << dummyn << endl;
        // IF IT'S ROUNDING UP, YOU ADD 10^LENGTH TO THE NUMBER WITHOUT THE REMAINDER WHICH IS DUMMYN
        dummyn += pow(10, length-1);
    }
    //cout << "dummyn after" << dummyn << endl;
    //dummyn-=(dummyn%(int)pow(10, length-1));
    // RETURN ROUNDED NUMBER
    return dummyn;
}

// FUNCTION FOR CHAIN ROUNDING AS DESCRIBED IN THE PROBLEM
int chainRoundResultFunct(int n, int length) { // N IS THE NUMBER YOU WANT TO ROUND, LENGTH IS THE NUMBER OF DIGITS THE NUMBER HAS
    //length = int(log10(n)) + 1;
    //cout << "start chain" << endl;
    // DUMMYN IS THE NUMBER YOU CHANGE TO MAKE N ROUNDED TO THE NEAREST 10^LENGTH
    int dummyn = n;
    // USES  THE NORMAL ROUNDING FUNCTION MULTIPLE TIMES WITH THE NUMBER OF DIGITS TO ROUND (I) INCREASING
    for (int i = 2; i <= length; i++) {
        dummyn = roundResultFunct(dummyn, i);
        //cout << dummyn << endl;
    }
    //cout << "end chain" << endl;
    // RETURN CHAIN ROUNDED NUMBER
    return dummyn;
}*/

int totalDifferences (int numDigits) {
    int count = 0;
    int temp5 = 5;
    for (int j = numDigits-2; j >= 0; j--){
        for (int i = 0; i < j; i++) {
            temp5*=10;
            temp5+=5;
        }
        count += temp5;
        //cout << temp5 << endl;
        temp5 = 5;
    }
    //cout << count << endl;
    return count;
}

// MAIN FUNCTION TO TEST AND OUTPUT SOLUTIONS
int main() {
    int n = 2147483647;
    int count = 0;
    int dummyn = n;
    int numDigits = 0;
    while (dummyn > 0) {
        dummyn/=10;
        numDigits++;
    }
    // max available for the digits (ex. 4999)
    int maftd = 4*pow(10,numDigits-1);
    int temp9 = 9;
    for (int i = 0; i < numDigits-2; i++) {
        temp9*=10;
        temp9+=9;
    }
    maftd+=temp9;
    //cout << maftd << endl;
    // min available for the digits (ex. 4445)
    int mnaftd = 4;
    for (int i = 0; i < numDigits-1; i++) {
        mnaftd*=10;
        mnaftd+=4;
    }
    mnaftd+=1;
    if (n >= maftd) {
        count = totalDifferences(numDigits);
    }
    else if (n < mnaftd) {
        count = totalDifferences(numDigits-1);
    }
    else {
        count = totalDifferences(numDigits-1) + (n-mnaftd+1);
    }
    cout << count << endl;
    /*// NUMTESTCASES IS THE NUMBER OF TEST CASES THE PROBLEM GIVES IN THE SAMPLE SET
    // N IS THE NUMBER OF TEST CASES BESSIE WANTS TO SOLVE WITH BOTH ROUNDING FUNCTIONS
    // COUNT COUNTS HOW MANY TIMES THE DIFFERENT ROUNDING FUNCTIONS GIVE DIFFERENT ANSWERS
    int numTestCases, N, count;
    //cin >> numTestCases;
    // SET AS 1 TO TEST
    numTestCases = 1;
    // GOES THROUGH THE DIFFERENT TEST CASES WITH DIFFERENT NUMBER N EACH TIME
    for (int i = 0; i < numTestCases; i++) {
        //cin >> N;
        // SET AS 4567 TO TEST
        N = 4567;
        // DUMMYN IS USED TO FIND HOW MANY DIGITS N HAS
        int dummyn = N;
        // SET COUNT TO 0
        count = 0;
        // DEFINE THE RESULTS OF BOTH ROUNDING FUNCTIONS
        int roundResult;
        int chainRoundResult;
        // GET THE NUMBER OF DIGITS N HAS
        int numDigits = 0;
        while (dummyn > 0) {
            dummyn/=10;
            numDigits++;
        }
        // GO THROUGH ALL THE NUMBERS 2 TO N TO COUNT HOW MANY TIMES THE ROUNDING FUNCTIONS GIVE DIFFERENT ANSWERS
        for (int j = 2; j <= N; j++) { // J IS THE TEST NUMBER USED TO ROUND
            //int dummyj = j;
            // FIND THE RESULT WHEN YOU ROUND NORMALLY
            if (numDigits == 1) {
                roundResult = 0;
            }
            else {
                roundResult = roundResultFunct(j, numDigits);
            }
            if (j % 1000 >= 00 && j % 1000 <=1000) { // THIS IF CONDITION WAS JUST TO SEE WHICH NUMBERS ADD TO COUNT BECAUSE THE DEBUG CONSOLE DIDN'T FIT ALL THE PRINT STATEMENTS
                //cout << j << endl;
            }
            //cout << roundResult << endl;
            if (j % 1000 >= 00 && j % 1000 <=1000) { // THIS IF CONDITION WAS JUST TO SEE WHICH NUMBERS ADD TO COUNT BECAUSE THE DEBUG CONSOLE DIDN'T FIT ALL THE PRINT STATEMENTS
                //cout << "rr" << roundResult << endl;
            }
            // FIND THE RESULT WHEN YOU USE CHAIN ROUNDING
            if (numDigits == 1) {
                chainRoundResult = 0;
            }
            else {
                chainRoundResult = chainRoundResultFunct(j, numDigits);

                if (j % 1000 >= 00 && j % 1000 <=1000) { // THIS IF CONDITION WAS JUST TO SEE WHICH NUMBERS ADD TO COUNT BECAUSE THE DEBUG CONSOLE DIDN'T FIT ALL THE PRINT STATEMENTS
                    //cout << "crr" << chainRoundResult << endl;
                }
            }
            // CHECK TO SEE IF THE TWO ROUNDING FUNCTIONS HAVE DIFFERENT ANSWERS AND ADD ONE TO COUNT
            if (roundResult!=chainRoundResult) {
                cout << j << " " << "plus one " << roundResult << " " << chainRoundResult  << endl; // USED TO TEST AND SEE WHICH VALUES ADDED TO COUNT
                count++;
            }
            
        }
        // OUTPUT COUNT
        cout << count << endl;
    }*/

}