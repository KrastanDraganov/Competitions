#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<pair<int,int>> graph[MAXN];
vector<int> points,bridges;
bool used[MAXN],is_point[MAXN];
int timer,in[MAXN],min_time[MAXN];

void dfs(int curr, int parent){
    used[curr]=true;
    in[curr]=min_time[curr]=timer++;
    int children=0;

    for(pair<int,int> nextv : graph[curr]){
        if(nextv.first==parent){
            continue;
        }
        if(!used[nextv.first]){
            ++children;
            dfs(nextv.first,curr);
            min_time[curr]=min(min_time[curr],min_time[nextv.first]);
            if(parent>-1 && min_time[nextv.first]>=in[curr] && !is_point[curr]){
                points.push_back(curr);
                is_point[curr]=true;
            }
            if(min_time[nextv.first]>in[curr]){
                bridges.push_back(nextv.second+1);
            }
        }else{
            min_time[curr]=min(min_time[curr],in[nextv.first]);
        }
    }
    
    if(parent==-1 && children>1 && !is_point[curr]){
        points.push_back(curr);
        is_point[curr]=true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        graph[from].push_back({to,i});
        graph[to].push_back({from,i});
    }
    
    for(int i=1;i<=n;++i){
        if(!used[i]){
            dfs(i,-1);
        }
    }
    
    sort(bridges.begin(),bridges.end());
    sort(points.begin(),points.end());
    
    cout<<(int)bridges.size()<<endl;
    for(int bridge : bridges){
        cout<<bridge<<endl;
    }
    cout<<(int)points.size()<<endl;
    for(int point : points){
        cout<<point<<endl;
    }
return 0;
}