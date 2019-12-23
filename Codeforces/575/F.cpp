#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN = (int) 1e3+3;
const long long INF = (long long) 1e18;
long long dist[MAXN][MAXN];
vector<int> vertex;
vector<long long> all_dist;
vector<pair<int,pair<int,int>>> input;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXN;++i2){
            dist[i][i2]=INF;
        }
    }
    for(int i=0;i<m;++i){
        int x,y;
        long long w;
        cin>>x>>y>>w;
        --x;
        --y;
        input.push_back({w,{x,y}});
    }
    sort(input.begin(),input.end());
    for(int i=0;i<min(k,m);++i){
        vertex.push_back(input[i].second.first);
        vertex.push_back(input[i].second.second);
    }
    sort(vertex.begin(),vertex.end());
    vertex.resize(unique(vertex.begin(),vertex.end())-vertex.begin());
    for(int i=0;i<vertex.size();++i){
        dist[i][i]=0;
    }
    for(int i=0;i<min(m,k);++i){
        int x=lower_bound(vertex.begin(),vertex.end(),input[i].second.first)-vertex.begin(),y=lower_bound(vertex.begin(),vertex.end(),input[i].second.second)-vertex.begin();
        dist[x][y]=dist[y][x]=min((long long)input[i].first,dist[x][y]);
    }
    for(int i=0;i<vertex.size();++i){
        for(int i2=0;i2<vertex.size();++i2){
            for(int i3=0;i3<vertex.size();++i3){
                dist[i2][i3]=min(dist[i2][i3],dist[i2][i]+dist[i][i3]);
            }
        }
    }
    for(int i=0;i<vertex.size();++i){
        for(int i2=i+1;i2<vertex.size();++i2){
            all_dist.push_back(dist[i][i2]);
        }
    }
    sort(all_dist.begin(),all_dist.end());
    cout<<all_dist[k-1]<<endl;
return 0;
}