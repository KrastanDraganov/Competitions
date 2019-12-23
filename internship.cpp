#include<bits/stdc++.h>
#define endl '\n'
#define MAXN 500005
#define MAXM 10000005
using namespace std;
const unsigned long long ULL_MAX = 2*1e18;
int n,a,b,graph_decoding[2*MAXN];
unsigned long long dist[MAXM];
vector<pair<int,unsigned long long>> graph[MAXM];
priority_queue<pair<unsigned long long,int>> dijkstra;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>a>>b;
	++b;
	int max_end=b;
	for(int i=0;i<n;++i){
		int s,e,p;
		cin>>s>>e>>p;
		++e;
		if(e>max_end) max_end=e;
		graph[s].push_back({e,p});
		graph_decoding[2*i]=s;
		graph_decoding[2*i+1]=e;
	}
	graph_decoding[2*n]=a;
	graph_decoding[2*n+1]=b;
	sort(graph_decoding,graph_decoding+2*n+2);
	for(int i=1;i<2*n+2;++i){
		if(graph_decoding[i-1]!=graph_decoding[i]){
			graph[graph_decoding[i]].push_back({graph_decoding[i-1],0});
		}
	}
    fill(dist,dist+max_end+1,ULL_MAX);
	dist[a]=0;
	dijkstra.push({-dist[a],a});
	while(!dijkstra.empty()){
		int curr=dijkstra.top().second;
		dijkstra.pop();
		for(pair<int,unsigned long long> next : graph[curr]){
			if(dist[curr]+next.second<dist[next.first]){
				dist[next.first]=dist[curr]+next.second;
				dijkstra.push({-dist[next.first],next.first});
			}
		}
	}
	if(dist[b]==ULL_MAX){
		cout<<"Impossible"<<endl;
	}else{
		cout<<dist[b]<<endl;
	}
return 0;
}
