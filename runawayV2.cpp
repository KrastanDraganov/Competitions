//O(2*N*K)
#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int table[MAXN][MAXN];

int calc_res(int exit, int row, int col, int n){
    if(row>=n or col<0){
        return -1;
    }
    if(table[row][col]==exit){
        return row+(n-1-col);
    }
    if(table[row][col]>exit){
        return calc_res(exit,row,col-1,n);
    }
    return calc_res(exit,row+1,col,n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>table[i][i2];
        }
    }

    int q;
    cin>>q;
    while(q--){
        int exit;
        cin>>exit;
        int res=calc_res(exit,0,n-1,n);
        if(res==-1){
            cout<<"No Solution\n";
        }else{
            cout<<res<<endl;
        }
    }
return 0;
}