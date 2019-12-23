#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
long long piles[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        for(int i2=0;i2<3;++i2){
            cin>>piles[i2];
        }
        sort(piles,piles+3);
        cout<<(piles[2]-piles[1]+piles[0])/2+piles[1]<<endl;
    }
return 0;
}