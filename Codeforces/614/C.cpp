#include<iostream>
#include<bitset>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
bitset<MAXN> is_lava[2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    int blocked=0;
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        --x;
        --y;
        is_lava[x].flip(y);
        int change=(is_lava[x][y] ? 1 : -1);
        for(int i2=-1;i2<2;++i2){
            if(y+i2<0 or y+i2>=n){
                continue;
            }
            if(is_lava[1-x][y+i2]){
                blocked+=change;
            }
        }
        cout<<(!blocked ? "Yes" : "No")<<endl;
    }
return 0;
}