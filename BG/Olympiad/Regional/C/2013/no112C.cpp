#include<iostream>
#include<vector>


using namespace std;

const int MAXN=1e3+3;
vector<int>graph[MAXN];
bool used[MAXN];
int checker[MAXN];

int dfs(int currv, int counter){
    used[currv]=true;
    checker[currv]=counter;
    for(int nextv : graph[currv]){
        if(!used[nextv]){
            dfs(nextv,counter);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int counter=1;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i,counter);
            counter++;
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(checker[a]==checker[b]){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    cout<<endl;
return 0;
}