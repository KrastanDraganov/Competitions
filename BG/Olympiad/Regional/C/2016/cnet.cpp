#include<iostream>
#include<vector>
#include<queue>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3,INF=1<<30;
vector<int> graph[MAXN],result;
int dist[MAXN][MAXN];
bool used[MAXN];

void calculate(int start_point, int n, int& min_time){
    bool check=true;
    int curr=-1;
    
    for(int i=0;i<n;i++){
        if(i!=start_point and dist[start_point][i]==0){
            check=false;
            break;
        }
        curr=max(curr,dist[start_point][i]);
    }
    
    if(check){
        if(curr<min_time){
            result.clear();
            result.push_back(start_point);
            min_time=curr;
        }else if(curr==min_time){
            result.push_back(start_point);
        }
        return;
    }

    for(int i=0;i<n;i++){
        if(dist[start_point][i]>0){
            used[i]=true;
        }
    }
}

void bfs(int start_point){
    queue<int> q;
    q.push(start_point);
    used[start_point]=true;
    
    while(!q.empty()){
        int currv=q.front();
        for(int nextv : graph[currv]){
            if(dist[start_point][nextv]==0){
                dist[start_point][nextv]=dist[start_point][currv]+1;
                q.push(nextv);
            }
        }
        q.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    
    int min_time=INF;
    for(int i=0;i<n;i++){
        if(!used[i]){
            bfs(i);
            calculate(i,n,min_time);
        }
    }
    
    cout<<(int)result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
return 0;
}
