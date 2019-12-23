#define MAX_N 30000
#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch1(int *A, int n, int x) {
    if (n==0) return 0;
    if (n==1) return (x<A[0])? 0: 1;
    int k = n / 2;
    if (A[k] > x) return binarySearch1(A, k, x);
    else return k + binarySearch1(A+k, n-k, x);
}

int binarySearch2(int *A, int n, int x) {
    if (n==0) return 0;
    if (n==1) return (x<=A[0])? 0: 1;
    int k = n / 2;
    if (A[k] >= x) return binarySearch2(A, k, x);
    else return k + binarySearch2(A+k, n-k, x);
}

long long findCountTriangle(int *A, int aN, int *B, int bN, int *C, int cN) {
    sort(C, C+cN);
    long long count=0;
    for(int i=0; i<aN; i++)
        for(int j=0; j<bN; j++) {
            int x = (A[i]<B[j])? B[j]-A[i] : A[i]-B[j]; // abs(A[i]-B[j])
            int y = A[i] + B[j];
            int k = binarySearch1(C, cN, x);
            int l = binarySearch2(C, cN, y);
            if (l-k > 0) count += (l-k);
        }
    return count;
}


int main() {
    int n;
    int G[MAX_N], R[MAX_N], B[MAX_N];
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
    if (rN>=gN && rN>=bN) {
        count = findCountTriangle(G, gN, B, bN, R, rN);
    } else if (gN>=rN && gN>=bN) {
        count = findCountTriangle(R, rN, B, bN, G, gN);
    } else {
        count = findCountTriangle(R, rN, G, gN, B, bN);
    }
    cout<<count<<endl;
    return 0;
}

