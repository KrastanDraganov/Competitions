#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3;
int needed[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;
    
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            needed[i][i2]=MAXN*MAXN;
        }
    }
    
    for(int i=0;i<k;++i){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        for(int i=0;i<n;++i){
            for(int i2=0;i2<m;++i2){
                int dist=abs(x-i)+abs(y-i2);
                needed[i][i2]=min(dist,needed[i][i2]);
            }
        }
    }
    
    int res=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            res=max(res,needed[i][i2]);
        }
    }
    cout<<res<<endl;
return 0;
}