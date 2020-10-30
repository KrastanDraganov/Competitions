#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=203;
int sum[MAXN][MAXN][MAXN];

int query(int x1, int y1, int z1, int x2, int y2, int z2){
    return sum[x2][y2][z2]-sum[x2][y1-1][z2]-sum[x2][y2][z1-1]+sum[x2][y1-1][z1-1]
        -sum[x1-1][y2][z2]+sum[x1-1][y1-1][z2]+sum[x1-1][y2][z1-1]-sum[x1-1][y1-1][z1-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int x=1;x<=n;++x){
        for(int y=1;y<=n;++y){
            for(int z=1;z<=n;++z){
                char curr;
                cin>>curr;
                sum[x][y][z]=(curr=='G');
                sum[x][y][z]+=sum[x][y-1][z]+sum[x][y][z-1]-sum[x][y-1][z-1]
                            +sum[x-1][y][z]-sum[x-1][y-1][z]-sum[x-1][y][z-1]+sum[x-1][y-1][z-1];
            }
        }
    }

    while(q--){
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        cout<<query(x1, y1, z1, x2, y2, z2)<<endl;
    }
return 0;
}