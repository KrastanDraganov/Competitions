#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int counter[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        ++counter[num];
    }
    
    int ans=0;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        if(x-num>=0){
            ans+=counter[x-num];
        }
    }
    cout<<ans<<endl;
return 0;
}