#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<unordered_map>

#define endl '\n'

using namespace std;

const long long INF=1e18;
const int MAXN=5e5+3,MAXM=1e7+3;
int counter;
long long dist[MAXM];
unordered_map<int,int> decode_month;
vector<int> all_months;
vector<pair<int,long long>> graph[MAXM];

void add_month(int curr){
	if(decode_month.find(curr)==decode_month.end()){
		decode_month[curr]=counter++;
	}
}
long long calc_res(int a, int b){
	for(int i=0;i<MAXM;++i){
		dist[i]=INF;
	}
	priority_queue<pair<long long,int>> dijkstra;
	dist[a]=0;
	dijkstra.push({0,a});
	while(!dijkstra.empty()){
		int curr=dijkstra.top().second;
		dijkstra.pop();
		if(curr==b){
			return dist[curr];
		}
		for(pair<int,long long> next : graph[curr]){
			if(dist[curr]+next.second<dist[next.first]){
				dist[next.first]=dist[curr]+next.second;
				dijkstra.push({-dist[next.first],next.first});
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	++b;
	all_months.push_back(a);
	all_months.push_back(b);
	for(int i=0;i<n;++i){
		int s,e,p;
		cin>>s>>e>>p;
		++e;
		all_months.push_back(s);
		all_months.push_back(e);
		graph[s].push_back({e,p});
	}
	sort(all_months.begin(),all_months.end());
	for(int i=1;i<all_months.size();++i){
		if(all_months[i-1]!=all_months[i]){
			graph[all_months[i]].push_back({all_months[i-1],0});
		}
	}
    long long res=calc_res(a,b);
	if(res==-1){
		cout<<"Impossible\n";
	}else{
		cout<<res<<endl;
	}
return 0;
}
