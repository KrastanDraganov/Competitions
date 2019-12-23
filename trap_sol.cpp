#include<iostream>
#define endl '\n'
using namespace std;
long long res[]={0,0,0,0,0,0,1,2,11,25,95,228,752,1860,5741,14477,42939,109758,317147,818229,2322512,6030293,16900541,44079555,122379267,320227677};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<res[n-1]<<endl;
return 0;
}