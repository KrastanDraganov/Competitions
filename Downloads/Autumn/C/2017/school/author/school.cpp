#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n;



int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    vector<int> T(n);
    vector<int> times(2*m);
    int tN = 0;
    int k;
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>T[i];
        cin>>k;
        vector<int> B(k);
        for(int j=0; j<k; j++) {
            cin>>B[j];
            B[j] = (B[j]<sum) ? 0 : B[j]-sum;
        }

        if (k>m) B.resize(m);
        vector<int> A(tN);;
        for (int p=0; p<tN; p++)
            A[p] = times[p];

        merge(A.begin(), A.end(), B.begin(), B.end(), times.begin());
        tN += k;
        if (tN > m) tN = m;
        sum += T[i];
    }

   cout<<sum + times[tN-1]<<endl;

    cout<<endl;

    return 0;
}

/*
2 5
5 3 1 4 9
7 3 2 8 12
*/
