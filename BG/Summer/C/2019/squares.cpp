#include<iostream>

#define endl '\n'

using namespace std;

const int MAXS=2e7+3;
bool check[MAXS];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s;
    cin>>s;
    
    for(int i=1;i*i<=s;++i){
        for(int i2=0;i2<=i and i2*i2<=s-i*i;++i2){
            check[i*i+i2*i2]=true;
        }
    }
    
    int res=0;
    for(int i=1;i<=s;++i){
        if(check[i]){
            ++res;
        }
    }
    cout<<res<<endl;
return 0;
}