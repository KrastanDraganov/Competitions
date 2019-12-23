#define MAX_N 30000
#include <iostream>
#include <algorithm>

using namespace std;

struct Segment{
    char c;
    int l;
};

int n;
Segment A[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++) {
        cin.ignore();
        cin>>A[i].c>>A[i].l;
    }

    long long count=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++) {
                if (A[i].c!=A[j].c && A[i].c!=A[k].c && A[j].c!=A[k].c &&
                    A[i].l+A[j].l>A[k].l &&
                    A[i].l+A[k].l>A[j].l &&
                    A[k].l+A[j].l>A[i].l) count++;

            }
    }

    cout<<count<<endl;
    return 0;
}

