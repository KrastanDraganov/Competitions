#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=5e3+3;
int gangs[MAXN];

vector<pair<int, int>> connect_gangs(int n){
    vector<pair<int, int>> edges;

    // Different from the first gang
    int other_gang=-1;
    for(int i=1;i<n;++i){
        if(gangs[0]==gangs[i]){
            continue;
        }
        edges.push_back({0, i});
        other_gang=i;
    }

    if(edges.empty()){
        return {};
    }

    for(int i=1;i<n;++i){
        if(gangs[0]!=gangs[i]){
            continue;
        }
        edges.push_back({other_gang, i});
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