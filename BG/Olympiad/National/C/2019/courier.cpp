#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<functional>

#define endl '\n'

using namespace std;

const int MAXN=153,MAXV=503;
const double INF=5e8;

struct Edge {
    int to,speed,length;
    
    Edge(int _to, int _speed, int _length){
        to=_to;
        speed=_speed;
        length=_length;
    }
};

struct DijkstraEntry {
    double total_time;
    int current_node,current_speed;
    
    DijkstraEntry(double _total_time, int _current_node, int _current_speed){
        total_time=_total_time;
        current_node=_current_node;
        current_speed=_current_speed;
    }
    
    bool operator>(DijkstraEntry x) const {
        return total_time > x.total_time;
    }
};

vector<Edge> graph[MAXN];
double min_time[MAXN][MAXV];
pair<int,int> parent[MAXN][MAXV];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXV;++i2){
            min_time[i][i2]=INF;
        }
    }
    
    int n,m,final_node;
    cin>>n>>m>>final_node;
    for(int i=0;i<m;++i){
        int from,to,speed,length;
        cin>>from>>to>>speed>>length;
        graph[from].push_back(Edge(to, speed, length));
    }
    
    min_time[0][70]=0;
    priority_queue<DijkstraEntry, vector<DijkstraEntry>, greater<DijkstraEntry>> dijkstra;
    dijkstra.push(DijkstraEntry(0, 0, 70));
    
    while(!dijkstra.empty()){
        DijkstraEntry curr=dijkstra.top();
        dijkstra.pop();
        
        double curr_time=curr.total_time;
        int curr_speed=curr.current_speed,curr_node=curr.current_node;
        if(curr_time>min_time[curr_node][curr_speed]){
            continue;
        }
        
        for(Edge next : graph[curr_node]){
            int next_speed=-1;
            if(next.speed!=0){
                next_speed=next.speed;
            }else{
                next_speed=curr_speed;
            }
            
            double next_time=curr_time+((double) next.length/next_speed);
            if(min_time[next.to][next_speed]>next_time){
                min_time[next.to][next_speed]=next_time;
                dijkstra.push(DijkstraEntry(next_time,next.to,next_speed));
                parent[next.to][next_speed]={curr_node,curr_speed};
            }
        }
    }
    
    int cnode=final_node,cspeed=1;
    for(int i=2;i<MAXV;++i){
        if(min_time[final_node][i]<min_time[final_node][cspeed]){
            cspeed=i;
        }
    }
    
    stack<int> path;
    while(cnode!=0 or cspeed!=70){
        path.push(cnode);
        pair<int, int> nextp=parent[cnode][cspeed];
        cnode=nextp.first;
        cspeed=nextp.second;
    }
    
    cout<<0<<" ";
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
return 0;
}