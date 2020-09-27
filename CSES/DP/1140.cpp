#include<iostream>
#include<map>
#include<utility>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int from[MAXN],to[MAXN],reward[MAXN];
long long dp[2*MAXN];
vector<pair<int,int>> projects[2*MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    map<int,int> new_time;
    for(int i=0;i<n;++i){
        cin>>from[i]>>to[i]>>reward[i];
        ++to[i];
        new_time[from[i]]=new_time[to[i]]=-1;
    }

    int counter=0;
    for(pair<int,int> curr : new_time){
        new_time[curr.first]=counter++;
    }

    for(int i=0;i<n;++i){
        projects[new_time[to[i]]].push_back({new_time[from[i]], reward[i]});
    }

    for(int i=0;i<counter;++i){
        if(i>0){
            dp[i]=dp[i-1];
        }
        for(pair<int,int> curr : projects[i]){
            dp[i]=max(dp[i],dp[curr.first]+curr.second);
        }
    }
    
    cout<<dp[counter-1]<<endl;
return 0;
}