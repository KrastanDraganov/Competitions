#include<iostream>
#define endl '\n'
#define MAXS  20000005
using namespace std;
bool check[MAXS];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s;
    cin>>s;
    for(int i=1;i*i<=s;++i){
        for(int i2=0;i2<=i and i2*i2<=s-i*i;++i2){
            //cout<<i<<" "<<i2<<endl;
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