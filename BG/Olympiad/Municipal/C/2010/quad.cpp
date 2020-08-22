#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103;
int table[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k,x,y;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>table[i][i2];
            if((i*m+i2+1)==k){
                x=i;
                y=i2;
            }
        }
    }
    
    int kv1=0,kv2=0,kv3=0,kv4=0;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(i<x and i2<y){
                kv2+=table[i][i2];
            }else if(i<x and i2>y){
                kv1+=table[i][i2];
            }else if(i>x and i2<y){
                kv3+=table[i][i2];
            }else if(i>x and i2>y){
                kv4+=table[i][i2];
            }
        }
    }
    
    cout<<kv1<<" "<<kv2<<" "<<kv3<<" "<<kv4<<endl;
return 0;
}