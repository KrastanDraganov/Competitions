#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=21;
long long factorial[MAXN];

long long combinations(int k, int n){
    return factorial[n]/(factorial[k]*factorial[n-k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    factorial[0]=1;
    for(int i=1;i<MAXN;++i){
        factorial[i]=factorial[i-1]*i;
    }

    int n;
    cin>>n;

    long long res=combinations(n/2, n)/2;
    res*=factorial[n/2-1]*factorial[n/2-1];

    cout<<res<<endl;
return 0;
}