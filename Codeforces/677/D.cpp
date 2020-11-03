#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
int gangs[MAXN];
bool is_edge[MAXN][MAXN];

vector<pair<int, int>> connect_gangs(int n){
    for(int i=0;i<n;++i){
        for(int i2=i;i2<n;++i2){
            is_edge[i][i2]=is_edge[i2][i]=false;
        }
    }

    vector<pair<int, int>> edges;
    int counter=0;

    for(int i=0;i<n and counter<n-1;++i){
        for(int i2=0;i2<n and counter<n-1;++i2){
            if(gangs[i]==gangs[i2]){
                continue;
            }
            
            if(is_edge[i][i2] or is_edge[i2][i]){
                continue;
            }
            
            is_edge[i][i2]=is_edge[i2][i]=true;
            edges.push_back({i, i2});
            ++counter;
        }
    }

    if(counter!=n-1){
        return {};
    }
    return edges;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        for(int i=0;i<n;++i){
            cin>>gangs[i];
        }

        vector<pair<int, int>> res=connect_gangs(n);
        if(res.empty()){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            for(pair<int, int> curr : res){
                cout<<curr.first+1<<" "<<curr.second+1<<endl;
            }
        }
    }
return 0;
}