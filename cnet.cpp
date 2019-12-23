#include<bits/stdc++.h>
#define endl '\n'
#define N 3002
#define INF 1<<30
using namespace std;
vector<int>graph[N],result;
int n,dist[N][N],min_time=INF;
bool used[N];
void calculate(int start_point){
    bool j=true;
    int curr_max=-1;
    for(int i=0;i<n;i++){
        if(i!=start_point and dist[start_point][i]==0){
            j=false;
            break;
        }else{
            if(dist[start_point][i]>curr_max){
                curr_max=dist[start_point][i];
            }
        }
    }
    //cout<<boolalpha<<j<<" "<<start_point<<" "<<curr_max<<endl;
    if(j){
        if(curr_max<min_time){
            result.clear();
            result.push_back(start_point);
            min_time=curr_max;
        }else if(curr_max==min_time){
            result.push_back(start_point);
        }
    }else{
        for(int i=0;i<n;i++){
            if(dist[start_point][i]>0){
                used[i]=true;
            }
        }
    }
}
void bfs(int start_point){
    queue<int>q;
    q.push(start_point);
    used[start_point]=true;
    while(!q.empty()){
        int curr=q.front();
        for(int i=0;i<graph[curr].size();i++){
            int next=graph[curr][i];
            if(dist[start_point][next]==0){
                dist[start_point][next]=dist[start_point][curr]+1;
                q.push(next);
            }
        }
        q.pop();
    }
    calculate(start_point);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            bfs(i);
        }
    }
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
return 0;
}
