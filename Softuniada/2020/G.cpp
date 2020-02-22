#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=2e3+3;
map<string,int> decoder;
vector<pair<int,int>> graph[MAXN];
int trucks[MAXN];
bool in_queue[MAXN];
void add_city(string city, int& ind){
    if(decoder.find(city)==decoder.end()){
        decoder[city]=ind++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string start_city,end_city;
    cin>>start_city>>end_city;
    int counter=0;
    add_city(start_city,counter);
    add_city(end_city,counter);
    int paths;
    cin>>paths;
    while(paths--){
        string from,to;
        int max_trucks;
        cin>>from>>to>>max_trucks;
        add_city(from,counter);
        add_city(to,counter);
        graph[decoder[from]].push_back({decoder[to],max_trucks});
    }
    queue<int> bfs;
    bfs.push(decoder[start_city]);
    in_queue[decoder[start_city]]=true;
    trucks[decoder[start_city]]=1e9;
    while(!bfs.empty()){
        int curr=bfs.front();
        bfs.pop();
        in_queue[curr]=false;
        //cout<<curr<<" "<<trucks[curr]<<endl;
        for(pair<int,int> nextp : graph[curr]){
            trucks[nextp.first]+=min(trucks[curr],nextp.second);
            if(!in_queue[nextp.first]){
                in_queue[nextp.first]=true;
                bfs.push(nextp.first);
            }
        }
    }
    cout<<trucks[decoder[end_city]]<<endl;
return 0;
}