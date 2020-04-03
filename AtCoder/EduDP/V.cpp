#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+5;
int mod,in[MAXN],out[MAXN],prefix[MAXN],suffix[MAXN];
vector<int> graph[MAXN];

int mul(int x, int y){
    return (long long) x*y/*%mod*/;
}

void dfs1(int currv, int parent){
    in[currv]=1;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            dfs1(nextv,currv);
            in[currv]=mul(in[currv],in[nextv]+1);
        }
    }
}

void dfs2(int currv, int parent){
    vector<int> children;
    for(int nextv : graph[currv]){
         if(nextv!=parent){
             children.push_back(nextv);
         }
    }
    for(int i=0;i<children.size()+4;++i){
        prefix[i]=0;
        suffix[i]=0;
    }
    prefix[0]=1;
    suffix[children.size()+1]=1;
    cout<<"kzl: "<<currv<<" "<<(int)children.size()<<endl;
    for(int i=1;i<=children.size();++i){
        prefix[i]=mul(prefix[i-1],in[children[i-1]]+1);
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    for(int i=children.size();i>0;--i){
        suffix[i]=mul(suffix[i+1],in[children[i-1]]+1);
        cout<<suffix[i]<<" ";
    }
    cout<<endl;

    int counter=1;
    for(int nextv : graph[currv]){
        if(nextv!=parent){
            out[nextv]=(mul(mul(out[currv],prefix[counter-1]),suffix[counter+1])+1)/*%mod*/;
            ++counter;
            dfs2(nextv,currv);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n>>mod;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    dfs1(0,-1);
    out[0]=1;
    dfs2(0,-1);

    for(int i=0;i<n;++i){
        cout<<in[i]<<" "<<out[i]<<endl;
        int res=mul(in[i],out[i]);
        cout<<"res: "<<res<<endl;
    }
return 0;
}