#include<iostream>

#define endl '\n'

using namespace std;

long long calc(int num){
    long long res=0;
    for(int i=31;i>=0;--i){
        if(num & (1<<i)){
            num^=(1<<i);
            res+=(long long)num+1+(1ll<<(i-1))*i;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int l,r;
    cin>>l>>r;
    
    cout<<calc(r)-calc(l-1)<<endl;
return 0;
}