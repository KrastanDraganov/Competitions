#define MAX_N 30000
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int G[MAX_N], R[MAX_N], B[MAX_N];

int main() {
    ios::sync_with_stdio(false);

    cin>>n;
    char color;
    int len;
    int gN=0, rN=0, bN=0;
    for(int i=0; i<n; i++) {
        cin.ignore();
        cin>>color>>len;
        switch(color) {
            case 'r' : R[rN++] = len; break;
            case 'g' : G[gN++] = len; break;
            case 'b' : B[bN++] = len; break;
        }
    }

    long long count=0;
    for(int i=0; i<rN; i++){
        for(int j=0; j<gN; j++)
            for(int k=0; k<bN; k++) {
                if (R[i]+G[j]>B[k] &&
                    R[i]+B[k]>G[j] &&
                    B[k]+G[j]>R[i]) count++;

            }
    }

    cout<<count<<endl;
    return 0;
}

