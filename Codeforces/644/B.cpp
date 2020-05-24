#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=53;
int athletes[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>athletes[i];
        }

        sort(athletes,athletes+n);
        int res=1e9;
        for(int i=1;i<n;++i){
            res=min(res,athletes[i]-athletes[i-1]);
        }
        cout<<res<<endl;
    }
return 0;
}