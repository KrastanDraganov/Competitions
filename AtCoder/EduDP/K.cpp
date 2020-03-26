#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXK=1e5+3;
int stones[MAXN];
bool dp[MAXK];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>stones[i];
    }
    for(int i=0;i<=k;++i){
        for(int i2=0;i2<n and stones[i2]<=i;++i2){
            if(!dp[i-stones[i2]]){
                dp[i]=true;
            }
        }
    }
    cout<<(dp[k] ? "First" : "Second")<<endl;
return 0;
}