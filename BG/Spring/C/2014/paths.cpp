#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=630,INF=1e9;
int dist[MAXN][MAXN],sol[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXN;++i2){
            dist[i][i2]=INF;
            sol[i][i2]=0;
        }
    }
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        dist[from][to]=1;
        dist[to][from]=1;
        sol[to][from]=1;
        sol[from][to]=1;
    }
    
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            for(int i3=0;i3<n;++i3){
                if(dist[i2][i]+dist[i][i3]<dist[i2][i3]){
                    dist[i2][i3]=dist[i2][i]+dist[i][i3];
                    sol[i2][i3]=sol[i2][i]*sol[i][i3];   
                }else if(dist[i2][i]+dist[i][i3]==dist[i2][i3]){
                    sol[i2][i3]+=sol[i2][i]*sol[i][i3];  
                }
            }
        }
    }
    
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        cout<<sol[from][to]<<" ";
    }
    cout<<endl;
return 0;
}