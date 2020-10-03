#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int trees[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=n;++i2){
            char curr;
            cin>>curr;
            
            if(curr=='*'){
                trees[i][i2]=1;
            }

            trees[i][i2]+=trees[i-1][i2]+trees[i][i2-1]-trees[i-1][i2-1];
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<trees[x2][y2]-trees[x2][y1-1]-trees[x1-1][y2]+trees[x1-1][y1-1]<<endl;
    }
return 0;
}