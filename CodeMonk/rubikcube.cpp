#include<iostream>
#define endl '\n'
#define MAXN 1005
using namespace std;
int cube[MAXN][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,r,c;
    cin>>n>>r>>c;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>cube[i][i2];
        }
    }
    for(int i=0;i<r;++i){
        int row,prev;
        cin>>row;
        --row;
        prev=cube[row][0];
        cube[row][0]=cube[row][n-1];
        for(int i2=1;i2<n;++i2){
            int curr=cube[row][i2];
            cube[row][i2]=prev;
            prev=curr;
        }
    }
    for(int i=0;i<c;++i){
        int col,prev;
        cin>>col;
        --col;
        prev=cube[0][col];
        cube[0][col]=cube[n-1][col];
        for(int i2=1;i2<n;++i2){
            int curr=cube[i2][col];
            cube[i2][col]=prev;
            prev=curr;
        }
    }
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cout<<cube[i][i2]<<" ";
        }
        cout<<endl;
    }
return 0;
}