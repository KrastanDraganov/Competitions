#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio();
    cin.tie(nullptr);

    int l,r;
    cin>>l>>r;
    
    int res=0;
    for(int x=l;x<=r;++x){
        for(int y=l;y<=r;++y){
            int z=0;
            bool check=false;
            for(int i=31;i>=0;--i){
                bool bitx=(x & (1<<i)),bity=(y & (1<<i));
                if(bitx or bity){
                    check=true;
                }
                if(check and !bitx and bity){
                    z |= (1<<i);
                }
            }
            res+=(l<=z and z<=r);
        }
    }
    cout<<res<<endl;
return 0;
}