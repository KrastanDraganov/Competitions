#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MAXM=1e5+3;
pair<int,pair<int,int>> edges[MAXM];
int parent[MAXN],depth[MAXN];

int find_parent(int city){
    if(city==parent[city]){
        return city;
    }
    return parent[city]=find_parent(parent[city]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int min_speed=1e9,max_speed=-1;
    for(int i=0;i<m;++i){
        int from,to,speed;
        cin>>from>>to>>speed;
        --from;
        --to;
        edges[i]={speed,{from,to}};
        min_speed=min(min_speed,speed);
        max_speed=max(max_speed,speed);
    }
    
    sort(edges,edges+m);
    for(int i=0;i<m;++i){
        for(int i2=0;i2<n;++i2){
            parent[i2]=i2;
            depth[i2]=1;
        }
        int components=n;
        for(int i2=i;i2<m and components>1;++i2){
            int root1=find_parent(edges[i2].second.first);
            int root2=find_parent(edges[i2].second.second);
            if(root1!=root2){
                --components;
                if(depth[root1]<depth[root2]){
                    swap(root1,root2);
                }
                parent[root2]=root1;
                depth[root1]+=depth[root2];
                if(components==1){
                    if(edges[i2].first-edges[i].first<max_speed-min_speed){
                        max_speed=edges[i2].first;
                        min_speed=edges[i].first;
                    }
                }
            }
        }
        if(components>1){
            break;
        }
    }
    cout<<min_speed<<" "<<max_speed<<endl;
return 0;
}