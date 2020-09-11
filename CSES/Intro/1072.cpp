#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    for(int i=1;i<=n;++i){
        long long all=i*i;
        long long res=all*(all-1)/2;
        
        if(i>2){
            res-=4*(i-2)*(i-1);
        }
        
        cout<<res<<endl;
    }
return 0;
}