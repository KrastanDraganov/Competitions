#include<iostream>
#include<vector>
#include<unordered_map>
#include<iomanip>
#include<queue>
#define endl '\n'
#define MAXN 10005
#define INF 10000002.0
using namespace std;
vector<int> graph[MAXN];
unordered_map<string, int> code;
unordered_map<int, string> decode;
bool visited[MAXN],dp[MAXN];
int n,m,people[MAXN],connected=0;
double p1,p2;
string repair(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' and s[i]<='Z'){
            s[i]+=32;
        }
    }
    return s;
}
int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    int result=1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : graph[curr]){
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
                result++;
            }
        }
    }
    return result;
}
double sol(int ind, int hotel1, int hotel2){
    double ans=INF;
    dp[0]=true;
    for(int i=0;i<connected;i++){
        int curr=people[i];
        for(int i2=0;i2+curr<=hotel1;i2++){
            if(dp[i2]){
                dp[curr+i2]=true;
            }
        }
    }
    for(int i=0;i<=hotel1;i++){
        if(dp[i] and n-i<=hotel2){
            ans=min(ans,p1*i+(n-i)*p2);
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v1,v2;
    cin>>n>>m>>p1>>v1>>p2>>v2;
    int graph_ind=0;
    for(int i=0;i<m;i++){
        string s1,s2;
        cin>>s1>>s2;
        s1=repair(s1);
        s2=repair(s2);
        if(code.find(s1)==code.end()){
            code[s1]=graph_ind;
            decode[graph_ind++]=s1;
        }
        if(code.find(s2)==code.end()){
            code[s2]=graph_ind;
            decode[graph_ind++]=s2;
        }
        //cout<<s1<<" -> "<<code[s1]<<" , "<<s2<<" -> "<<code[s2]<<endl;
        graph[code[s1]].push_back(code[s2]);
        graph[code[s2]].push_back(code[s1]);
    }
    for(int i=0;i<graph_ind;i++){
        if(!visited[i]){
            people[connected++]=bfs(i);
        }
    }
    cout<<setprecision(2)<<fixed<<sol(0,v1,v2)<<endl;
return 0;
}