#include<bits/stdc++.h>
#define endl '\n'
#define MAXN 205
using namespace std;
int edges[MAXN],counter[MAXN][MAXN],all;
vector<int>graph[MAXN];
vector<vector<int>>cycles[MAXN];
bool used[MAXN],visited[MAXN];
void dfs(int x){
    vector<int>st;
    int i=x;
    do{
        for(int element : graph[i]){
            if(counter[i][element]>0){
                st.push_back(element);
                counter[i][element]--;
                counter[element][i]--;
                edges[i]--;
                edges[element]--;
                all-=2;
                used[element]=true;
                i=element;
                break;
            }
        }
    }while(i!=x);
    cycles[x].push_back(st);
}
void print_result(int x){
    visited[x]=true;
    for(int i=0;i<cycles[x].size();i++){
        for(int element : cycles[x][i]){
            cout<<" "<<element;
            if(!visited[element]){
                print_result(element);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        counter[x][y]++;
        counter[y][x]++;
        edges[x]++;
        edges[y]++;
        all+=2;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    used[1]=true;
    while(all>0){
        int i;
        for(i=1;i<=n;i++){
            if(used[i] and edges[i]>0){
                break;
            }
        }
        if(i>n) break;
        dfs(i);
    }
    cout<<m<<endl<<1;
    print_result(1);
    cout<<endl;
return 0;
}