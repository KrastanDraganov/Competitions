#include<iostream>
#include<set>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
set<int> horizontal[MAXN],vertical[MAXN];
int counter[3];

// 0 - inside, 1 - nothing, 2 - extreme
int point_type(int x, int y){
    int type=0;
    if(x==*horizontal[y].begin() or x==*horizontal[y].rbegin()){
        ++type;
    }
    if(y==*vertical[x].begin() or y==*vertical[x].rbegin()){
        ++type;
    }
    return type;
}

vector<pair<int, int>> get_neighbours(int x, int y){
    vector<pair<int, int>> res;

    auto it=vertical[x].find(y);
    if(it!=vertical[x].begin()){
        --it;
        res.push_back({x, *it});
        ++it;
    }
    ++it;
    if(it!=vertical[x].end()){
        res.push_back({x, *it});
    }

    it=horizontal[y].find(x);
    if(it!=horizontal[y].begin()){
        --it;
        res.push_back({*it, y});
        ++it;
    }
    ++it;
    if(it!=horizontal[y].end()){
        res.push_back({*it, y});
    }

    return res;
}

void add_point(int x, int y){
    vertical[x].insert(y);
    horizontal[y].insert(x);
    vector<pair<int, int>> neighbours=get_neighbours(x,y);

    vertical[x].erase(y);
    horizontal[y].erase(x);
    for(pair<int, int> curr : neighbours){
        --counter[point_type(curr.first, curr.second)];
    }

    vertical[x].insert(y);
    horizontal[y].insert(x);
    ++counter[point_type(x, y)];
    for(pair<int, int> curr : neighbours){
        ++counter[point_type(curr.first, curr.second)];
    }
}

void remove_point(int x, int y){
    vector<pair<int, int>> neighbours=get_neighbours(x, y);

    --counter[point_type(x, y)];
    for(pair<int, int> curr : neighbours){
        --counter[point_type(curr.first, curr.second)];
    }

    vertical[x].erase(y);
    horizontal[y].erase(x);
    for(pair<int, int> curr : neighbours){
        ++counter[point_type(curr.first, curr.second)];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        add_point(x, y);
    }

    cout<<counter[2]<<" "<<counter[0]<<endl;

    int q;
    cin>>q;

    while(q--){
        int type,x,y;
        cin>>type>>x>>y;

        if(type==1){
            add_point(x, y);
        }else{
            remove_point(x, y);
        }

        cout<<counter[2]<<" "<<counter[0]<<endl;
    }
return 0;
}