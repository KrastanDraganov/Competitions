#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
#define endl '\n'
using namespace std;
const int MAXN = 1e4+3;
unordered_map<string,int> code;
unordered_map<int,string> decode;
vector<int> graph[MAXN];
int counter[MAXN],parent[MAXN];
void register_id(string s, int& ind){
    if(code.find(s)==code.end()){
        code[s]=ind;
        decode[ind++]=s;
    }
}
bool comp(string s1, string s2){
    if(s1.size()==s2.size()){
        for(int i=0;i<s1.size();++i){
            if(s1[i]!=s2[i]){
                return s1[i]>s2[i];
            }
        }
    }
    return s1.size()>s2.size();
}
void dfs(int v){
    for(int next : graph[v]){
        if(counter[next]==0){
            dfs(next);
        }
        counter[v]+=1+counter[next];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,id_size=1;
    cin>>n;
    string error="";
    bool is_error=false;
    for(int i=0;i<n;++i){
        string father,son;
        cin>>father>>son;
        register_id(father,id_size);
        register_id(son,id_size);
        if(parent[code[son]]==code[father]){
            continue;
        }
        if(parent[code[son]]==0){
            parent[code[son]]=code[father];
            graph[code[father]].push_back(code[son]);
        }else if(!is_error){
            is_error=true;
            error=son;
        }
    }
    if(is_error){
        cout<<error<<endl;
        return 0;
    }
    int res_size=-1;
    string res="";
    for(int i=1;i<id_size;++i){
        if(counter[i]==0){
            dfs(i);
            if(counter[i]>res_size){
                res_size=counter[i];
                res=decode[i];
            }else if(counter[i]==res_size and comp(decode[i],res)){
                res=decode[i];
            }
        }
    }
    cout<<res<<endl;
return 0;
}