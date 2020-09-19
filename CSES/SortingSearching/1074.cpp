#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int sticks[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>sticks[i];
    }
    sort(sticks,sticks+n);

    int mid=sticks[n/2];
    long long res=0;
    for(int i=0;i<n;++i){
        res+=abs(sticks[i]-mid);
    }

    cout<<res<<endl;
return 0;
}