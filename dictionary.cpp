#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>
#define endl '\n'
#define MAXN 103
using namespace std;
vector<int> graph[MAXN];
int parent[MAXN];
unordered_map<string,bool> is_word;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n;
    cin>>s>>n;
    for(int i=0;i<n;++i){
        string word;
        cin>>word;
        is_word[word]=true;
    }
    for(int i=0;i<s.size();++i){
        string curr="";
        for(int i2=i;i2<s.size();++i2){
            curr+=s[i2];
            if(is_word[curr]){
                graph[i].push_back(i2+1);
            }
        }
    }
    queue<int> bfs;
    bfs.push(0);
    for(int i=0;i<MAXN;++i){
        parent[i]=-1;
    }
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(int next : graph[curr]){
            if(parent[next]==-1){
                parent[next]=curr;
                bfs.push(next);
            }
        }
    }
    stack<int> path;
    int curr=s.size();
    while(parent[curr]!=0){
        curr=parent[curr];
        path.push(curr);
    }
    cout<<path.size()+1<<endl;
    for(int i=0;i<s.size();++i){
        if(!path.empty() and i==path.top()){
            cout<<" ";
            path.pop();
        }
        cout<<s[i];
    }
    cout<<endl;
return 0;
}