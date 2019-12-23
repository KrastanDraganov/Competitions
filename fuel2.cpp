#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN = 5e3+3, MAXQ = 2e5+3;
struct Query {
    int startp,endp,ind;
    long long ans;
    Query(){}
    Query(int _startp, int _endp, int _ind, long long _ans){
        startp=_startp;
        endp=_endp;
        ind=_ind;
        ans=_ans;
    }
} queries[MAXQ];
vector<pair<int,int>> graph[MAXN];
long long dist[MAXN];
bool cmp1(Query q1, Query q2){
    return q1.startp<q2.startp;
}
bool cmp2(Query q1, Query q2){
    return q1.ind<q2.ind;
}
void calc_bfs(int startp){
    queue<int> bfs;
    bfs.push(startp);
    dist[startp]=0;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        for(pair<int,int> next : graph[curr]){
            if(dist[next.first]==-1){
                dist[next.first]=dist[curr]+next.second;
                bfs.push(next.first);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;++i){
        int from,to,fuel;
        cin>>from>>to>>fuel;
        --from;
        --to;
        graph[from].push_back({to,fuel});
        graph[to].push_back({from,fuel});
    }
    for(int i=0;i<q;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        queries[i]=Query(from,to,i,0);
    }
    sort(queries,queries+q,cmp1);
    int last=-1;
    for(int i=0;i<q;++i){
        Query& curr=queries[i];
        if(curr.startp==last){
            curr.ans=dist[curr.endp];
        }else{
            for(int i=0;i<n;++i){
                dist[i]=-1;
            }
            calc_bfs(curr.startp);
            curr.ans=dist[curr.endp];
            last=curr.startp;
        }
    }
    sort(queries,queries+q,cmp2);
    for(int i=0;i<q;++i){
        cout<<queries[i].ans<<endl;
    }
return 0;
}