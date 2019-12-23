#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

const string PROBLEM_NAME = "howmany";
const int NUM_TESTS = 10;

int getRandom(int minV, int maxV) {
    return rand() %(maxV - minV) + minV;
}

bool getChance(double p) {
    return (rand()%1000 / 1000.0) < p;
}

string getRandomString(int minLength, int maxLength) {
    int length = getRandom(minLength, maxLength);
    string res = "";
    for(int i = 0; i < length; i++) {
        res += char('a' + getRandom(0, 26));
    }
    return res;
}


const int MAXN = 205;
char arr[MAXN][MAXN][MAXN];
int gold[MAXN][MAXN][MAXN];

void generateTest(fstream& input, fstream& output, bool small, bool oneD, bool twoD) {
    int n;
    if(small) {
        n = getRandom(10, 50);
    } else {
        n = getRandom(150, 200);
    }

    int maxm = min(n*n*n, 250000);
    int m = getRandom(maxm/2, maxm);

    input << n << " " << m << endl;
    for(int i = 1; i <= n; i++) { // sloi
        for(int j = 1; j <= n; j++) { // red
            for(int k = 1; k <= n; k++) { //kolona
                if(getChance(0.55)) {
                    arr[i][j][k] = 'G';
                } else {
                    arr[i][j][k] = 'S';
                }
                input << arr[i][j][k];
            }
        }
    }
    input << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                gold[i][j][k] = gold[i-1][j][k] + gold[i][j-1][k] + gold[i][j][k-1]
                                - gold[i-1][j-1][k] - gold[i-1][j][k-1] - gold[i][j-1][k-1]
                                + gold[i-1][j-1][k-1];

                if(arr[i][j][k] == 'G') {
                   gold[i][j][k]++;
                }
            }
        }
    }

    while(m-- > 0) {
        int a1, a2, a3, b1, b2, b3;
        a1 = getRandom(1, n/3);
        a2 = getRandom(1, n/3);
        a3 = getRandom(1, n/3);

        if(twoD || oneD) b1 = a1;
        else b1 = getRandom(2*n/3, n+1);

        if(oneD) b2 = a2;
        else b2 = getRandom(2*n/3, n+1);

        b3 = getRandom(2*n/3, n+1);

        input << a1 << " " << a2 << " " << a3 << " " << b1 << " " << b2 << " " << b3 << endl;
        int res = gold[b1][b2][b3]
            - gold[a1-1][b2][b3] - gold[b1][a2-1][b3] - gold[b1][b2][a3-1]
            + gold[a1-1][a2-1][b3] + gold[a1-1][b2][a3-1] + gold[b1][a2-1][a3-1]
            - gold[a1-1][a2-1][a3-1];
        output << res << endl;
    }
}

void generateTest(int testIndex) {
    fstream input(PROBLEM_NAME + "." + to_string(testIndex) + ".in", ios::out);
    fstream output(PROBLEM_NAME + "." + to_string(testIndex) + ".out", ios::out);

    if(testIndex == 1) generateTest(input, output, true, true, false); // 1D
    if(testIndex == 2) generateTest(input, output, true, false, true); // 2D

    if (3 <= testIndex && testIndex <= 5) {
        // small
        generateTest(input, output, true, false, false); // SMALL
    }

    if(6 <= testIndex && testIndex <= 10) {
        // big
        generateTest(input, output, false, false, false); // BIG
    }


    input.close();
    output.close();
}

void generateAll() {
    for(int i = 1; i <= NUM_TESTS; i++) {
        cout << "Generating test #" << i << endl;
        generateTest(i);
    }
}

int main() {
    srand(time(NULL));
    generateAll();
}

