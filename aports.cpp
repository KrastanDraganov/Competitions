#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=503;
int onboard[MAXN],ftime[MAXN][MAXN],dist[MAXN][MAXN],visited[MAXN],combined[MAXN];

struct FlightDetails {
    
    int from,to,fstart;
    
    FlightDetails(){
        from=-1;
        to=-1;
        fstart=-1;
    }
    
    FlightDetails(int _from, int _to, int _fstart){
        from=_from;
        to=_to;
        fstart=_fstart;
    }
} flights[MAXN];

bool dfs(int currv, int m, int ind){
    visited[currv]=ind;
    for(int i=0;i<m;++i){
        int time1=ftime[flights[currv].from][flights[currv].to]+onboard[flights[currv].to]+dist[flights[currv].to][flights[i].from];
        int time2=flights[i].fstart-flights[currv].fstart;
        if(time1<=time2 and (combined[i]==-1 or (visited[combined[i]]!=ind and dfs(combined[i],m,ind)))){
            combined[i]=currv;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            dist[i][i2]=1e9;
        }
    }
    for(int i=0;i<n;++i){
        cin>>onboard[i];
    }
    for(int from=0;from<n;++from){
        for(int to=0;to<n;++to){
            cin>>ftime[from][to];
            dist[from][to]=ftime[from][to];
            if(from!=to){
                dist[from][to]+=onboard[to];
            }
        }
    }
    for(int i=0;i<m;++i){
        int from,to,fstart;
        cin>>from>>to>>fstart;
        --from;
        --to;
        flights[i]=FlightDetails(from,to,fstart);
        combined[i]=-1;
    }

    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            for(int i3=0;i3<n;++i3){
                dist[i2][i3]=min(dist[i2][i3],dist[i2][i]+dist[i][i3]);
            }
        }
    }
    
    int excluded=0;
    for(int i=0;i<m;++i){
        excluded+=dfs(i,m,i+1);
    }
    cout<<m-excluded<<endl;
return 0;
}