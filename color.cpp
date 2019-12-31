#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int graph[MAXN],counter[MAXN],edges[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        memset(counter,0,sizeof(counter));
        memset(edges,0,sizeof(edges));
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>graph[i];
            --graph[i];
            ++counter[i];
            ++counter[graph[i]];
        }
        int max_degree=0;
        for(int i=0;i<n;++i){
            max_degree=max(max_degree,counter[i]);
        }
        if(max_degree==2){
            for(int i=0;i<n;++i){
                if(!edges[i]){
                    int curr=1,vertex=i;
                    while(!edges[vertex]){
                        edges[vertex]=curr++;
                        vertex=graph[vertex];
                    }
                    if((curr-edges[i])%2==1){
                        max_degree=3;
                        break;
                    }
                }
            }
        }
        cout<<max_degree<<endl;
    }
return 0;
}