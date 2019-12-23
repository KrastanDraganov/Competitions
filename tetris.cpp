#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int res=0,counter=0;
    for(int i=0;i<n;++i){
        bool check=true;
        for(int i2=0;i2<m;++i2){
            char c;
            cin>>c;
            if(c=='.'){
                check=false;
            }
        }
        if(check){
            ++counter;
        }else{
            counter=0;
        }
        res+=counter;
    }
    cout<<res<<endl;
return 0;
}