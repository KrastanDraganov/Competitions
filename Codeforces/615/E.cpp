#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int nums[n+1][m+1];
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>nums[i][i2];
        }
    }
    int res=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            int curr=i*m+i2+1;
            if(nums[i][i2]!=curr){
                int wantedx=-1;
                for(int i3=0;i3<n;++i3){
                    if(nums[i3][i2]==curr){
                        wantedx=i3;
                    }
                }
                if(wantedx>-1){
                    
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(nums[i][i2]!=(i*m+i2+1)){
                ++res;
            }
        }
    }
    cout<<res<<endl;
return 0;
}