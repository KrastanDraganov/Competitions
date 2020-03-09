#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=5e5+3;
long long price[MAXN];
vector<int> graph[MAXN];
map<vector<int>,long long> sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            cin>>price[i];
            graph[i].clear();
        }
        for(int i=0;i<m;++i){
            int from,to;
            cin>>to>>from;
            --from;
            --to;
            graph[from].push_back(to);
        }
        sum.clear();
        for(int i=0;i<n;++i){
            if(graph[i].size()>0){
                sort(graph[i].begin(),graph[i].end());
                sum[graph[i]]+=price[i];
            }
        }
        long long res=0;
        for(auto curr : sum){
            res=__gcd(res,curr.second);
        }
        cout<<res<<endl;
    }
return 0;
}