#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,r,k;
    cin>>n>>m>>r>>k;
    --r;
    
    int posx=r/m,posy=r%m,res=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            int dist=abs(i-posx)+abs(i2-posy);
            if(dist<=k and dist%2==k%2){
                res+=(i*m+i2+1);
            }
        }
    }
    cout<<res<<endl;
return 0;
}