#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define MAXN 100002
using namespace std;
vector<int> graph[MAXN],result;
bool used[MAXN],visited[MAXN];
void dfs(int x, bool check){
    if(visited[x]){
        return;
    }
    visited[x]=true;
    if(!check){
        result.push_back(x);
    }
    for(int i=0;i<graph[x].size();++i){
        dfs(graph[x][i],!check);
    }
}
int counter(int x){
    if(used[x]){
        return 0;
    }
    used[x]=true;
    return 1+counter(graph[x][1])+counter(graph[x][0]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;++i){
        int curr=counter(i);
        //cout<<i<<" "<<curr<<endl;
        if(curr%2!=0){
            result.push_back(i);
            used[graph[i][1]]=true;
            used[graph[i][0]]=true;
            visited[graph[i][1]]=true;
            visited[graph[i][0]]=true;
            int newv1,newv2;
            for(int i2=0;i2<2;++i2){
                if(graph[graph[i][0]][i2]!=i){
                    newv1=i2;
                }
            }
            for(int i2=0;i2<2;++i2){
                if(graph[graph[i][1]][i2]!=i){
                    newv2=i2;
                }
            }
            cout<<i<<" "<<newv1<<" "<<newv2<<endl;
            graph[newv1].push_back(newv2);
            graph[newv2].push_back(newv1);
        }else{
            dfs(i,false);
        }
    }
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
return 0;
}