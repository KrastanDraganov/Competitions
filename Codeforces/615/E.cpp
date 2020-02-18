#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> table(n,vector<int>(m));
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>table[i][i2];
            --table[i][i2];
        }
    }
    int res=0;
    vector<vector<int>> counter(m,vector<int>(n,0));
    for(int i=0;i<m;++i){
        for(int i2=0;i2<n;++i2){
            if(table[i2][i]%m==i){
                int pos=table[i2][i]/m;
                if(pos<n){
                    ++counter[i][(i2-pos+n)%n];
                }
            }
        }
        int curr=1e9;
        for(int i2=0;i2<n;++i2){
            curr=min(curr,n+i2-counter[i][i2]);
        }
        res+=curr;
    }
    cout<<res<<endl;
return 0;
}