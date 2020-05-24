#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=53;
bool table[MAXN][MAXN];
int counter[2][MAXN];

bool check(int n, int m, int a, int b){
    int start_pos=0,columns=0;
    for(int i=0;i<n;++i){
        if(start_pos+a>m){
            return false;
        }
        for(int i2=start_pos;i2<start_pos+a;++i2){
            table[i][i2]=true;
            ++counter[0][i];
            ++counter[1][i2];
        }
        ++columns;
        if(columns==b){
            columns=0;
            start_pos+=a;
        }
    }
    for(int i=0;i<n;++i){
        if(counter[0][i]!=a){
            return false;
        }
    }
    for(int i=0;i<m;++i){
        if(counter[1][i]!=b){
            return false;
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
            counter[0][i]=0;
            counter[1][i]=0;
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