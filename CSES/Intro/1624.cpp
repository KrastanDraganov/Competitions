#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=8;
int col[MAXN];
bool is_reserved[MAXN][MAXN],diag1[MAXN+MAXN],diag2[MAXN+MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<MAXN;++i){
        string input;
        cin>>input;
        
        for(int i2=0;i2<MAXN;++i2){
            if(input[i2]=='*'){
                is_reserved[i][i2]=true;
            }
        }
        
        col[i]=i;
    }

    int res=0;
    do{
        for(int i=0;i<MAXN+MAXN;++i){
            diag1[i]=diag2[i]=false;
        }

        bool check=true;
        for(int i=0;i<8;++i){
            check &= (!is_reserved[i][col[i]]);
        }

        for(int i=0;i<8;++i){
            if(diag1[i+col[i]] or diag2[i+7-col[i]]){
                check=false;
                break;
            }

            diag1[i+col[i]]=true;
            diag2[i+7-col[i]]=true;
        }

        res+=check;
    } while(next_permutation(col,col+8));
    
    cout<<res<<endl;
return 0;
}