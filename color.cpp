#include<bits/stdc++.h>
#define N 100005
#define endl '\n'
using namespace std;
int br[N];
vector<int>graph[15][N];
bool j[N];
int bfs(int t,int y){
    queue<int>q;
    q.push(y);
    int func_rez=-1,br2=1;
    j[y]=true;
    while(!q.empty()){
        int curr_top=q.front();
        //cout<<curr_top<<" ";
        func_rez=max(func_rez,br[curr_top]);
        for(int i3=0;i3<graph[t][curr_top].size();i3++){
            if(!j[graph[t][curr_top][i3]]){
                j[graph[t][curr_top][i3]]=true;
                br2++;
                q.push(graph[t][curr_top][i3]);
            }
        }
        q.pop();
    }
    //cout<<endl<<br2<<endl;
    if(br2%2==0) return max(func_rez,2);
    else return max(func_rez,3);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n;
        memset(br,0,N);
        for(int i2=1;i2<=n;i2++){
            cin>>x;
            br[i2]++;
            br[x]++;
            graph[i][i2].push_back(x);
            graph[i][x].push_back(i2);
        }
        int rez=-1;
        memset(j,0,N);
        for(int i2=1;i2<=n;i2++){
            if(!j[i2]){
                int curr=bfs(i,i2);
                //cout<<i2<<" "<<curr<<" "<<rez<<endl;
                rez=max(rez,curr);
            }
        }
        cout<<rez<<endl;
    }
return 0;
}