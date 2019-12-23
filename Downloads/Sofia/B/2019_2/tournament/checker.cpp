#include<iostream>
#include<fstream>
using namespace std;

const int MAX_N = 1000;

int n;
bool edge[MAX_N][MAX_N];

int totalOutputNodes;
bool nodeInOutput[MAX_N];

int main (int argc, const char * argv[]) {
    // argv[1] - input
    // argv[2] - correct out
    // argv[3] - contestant out

    ifstream inputFile(argv[1]);
    ifstream correctOutputFile(argv[2]);
    ifstream contestantOutputFile(argv[3]);

    if(inputFile.fail()
           || correctOutputFile.fail()
           || contestantOutputFile.fail()) {
        // failure opening one of the required files
        cout << "0\n";
        cerr << "error opening files";
        return 0;
    }

    inputFile >> n;
    for(int i = 0; i < n; ++i) {
        int currCount;
        inputFile >> currCount;

        for(int j = 0; j < currCount; ++j) {
            int to;
            inputFile >> to;

            edge[i][to] = true;
        }
    }

    int lastNode = -1;

    while(true) {
        int currentNode;
        contestantOutputFile >> currentNode;

        if(contestantOutputFile.eof()) {
            break;
        }

        // invalid format
        if(contestantOutputFile.fail()) {
            // TODO: check if whitespace breaks anything
            cout << "0\n";
            cerr << "invalid format\n";
            return 0;
        }

        // node out of range
        if(currentNode < 0 || currentNode >= n) {
            cout << "0\n";
            cerr << "node out of range\n";
            return 0;
        }

        // node already encountered
        if(nodeInOutput[currentNode]) {
            cout << "0\n";
            cerr << "node already encountered\n";
            return 0;
        }

        // no edge to node
        if(lastNode != -1 && !edge[lastNode][currentNode]) {
            cout << "0\n";
            cerr << "no edge to node\n";
            return 0;
        }

        ++totalOutputNodes;
        nodeInOutput[currentNode] = true;
        lastNode = currentNode;
    }

    if(totalOutputNodes == n) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
        cerr << "some nodes missing from output\n";
    }

    return 0;
}
