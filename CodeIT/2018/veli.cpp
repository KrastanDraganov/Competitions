#include <bits/stdc++.h>
using namespace std;
int NOD(int a, int b) {
    if (b==0) return a;
    else return NOD(b,a%b);
}
int main () {
    freopen("subtasks.out","w",stdout);
    freopen("subtasks.in","r",stdin);
    int n, nod, a;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (i==0) nod=a;
        else {
            nod=NOD(a,nod);
        }
    }
    cout << 100/nod << endl;
    return 0;
}
