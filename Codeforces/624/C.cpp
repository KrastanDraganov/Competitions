#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
const int MAXN=2e5+3;
int precounter[MAXN][26];
long long res[26];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            char curr;
            cin>>curr;
            int pos=curr-'a';
            for(int i2=0;i2<26;++i2){
                precounter[i+1][i2]=precounter[i][i2];
                if(i2==pos){
                    ++precounter[i+1][i2];
                }
            }
        }
        for(int i=0;i<26;++i){
            res[i]=0;
        }
        for(int i=0;i<m;++i){
            int wrong_button;
            cin>>wrong_button;
            for(int i2=0;i2<26;++i2){
                res[i2]+=precounter[wrong_button][i2];
            }
        }
        for(int i=0;i<26;++i){
            res[i]+=precounter[n][i];
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}