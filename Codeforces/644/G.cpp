#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=53;
bool table[MAXN][MAXN];

bool check(int n, int m, int a, int b){
    if(n*a!=m*b){
        return false;
    }
    int col=0;
    for(int row=0;row<n;++row){
        for(int i=0;i<a;++i){
            table[row][col++]=true;
            if(col==m){
                col=0;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        for(int i=0;i<MAXN;++i){
            for(int i2=0;i2<MAXN;++i2){
                table[i][i2]=false;
            }
        }

        bool is_res=check(n,m,a,b);
        if(is_res){
            cout<<"YES\n";
            for(int i=0;i<n;++i){
                for(int i2=0;i2<m;++i2){
                    cout<<table[i][i2];
                }
                cout<<endl;
            }
        }else{
            cout<<"NO\n";
        }
    }
return 0;
}