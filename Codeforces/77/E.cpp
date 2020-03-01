#include<iostream>
#include<vector>
#include<deque>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN=1e5+1,INF=1e9;
vector<int> graph[MAXN];
int islands[MAXN],dp[MAXN];
bool used[MAXN];
deque<pair<int,int>> window;

int dfs(int curr){
    used[curr]=true;
    int counter=1;
    for(int nextv : graph[curr]){
        if(!used[nextv]){
            counter+=dfs(nextv);
        }
    }
    return counter;
}

bool is_lucky(int num){
    while(num>0){
        int curr_digit=num%10;
        if(curr_digit!=4 and curr_digit!=7){
            return false;
        }
        num/=10;
    }
    return true;
}

void change_window(int weight, int ind1){
    if(weight<0 or dp[weight]==INF){
        return;
    }
    int changed_weight=dp[weight]-(weight/ind1);
    if(!window.empty() and changed_weight<=window.front().second){
        window.pop_front();
    }
    window.push_front({weight,changed_weight});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=1;i<=n;++i){
        if(!used[i]){
            ++islands[dfs(i)];
        }
    }
    for(int i=1;i<MAXN;++i){
        dp[i]=INF;
    }
    for(int i=1;i<MAXN;++i){
        if(islands[i]>0){
            for(int i2=MAXN-1;i2>MAXN-1-i;--i2){
                for(int i3=1;i3<=islands[i];++i3){
                    int curr_weight=i2-i*i3;
                    if(curr_weight<0){
                        break;
                    }
                    change_window(curr_weight,i);
                }
                for(int i3=i2;i3>=0;i3-=i){
                    if(!window.empty()){
                        dp[i3]=min(dp[i3],dp[window.back().first]+((i3-window.back().first)/i));
                    }
                    while(!window.empty() and i3-i<=window.back().first){
                        window.pop_back();
                    }
                    int curr_weight=i3-(islands[i]+1)*i;
                    change_window(curr_weight,i);
                }
            }
        }
    }
    int ans=INF;
    for(int i=1;i<MAXN;++i){
        if(is_lucky(i)){
            ans=min(ans,dp[i]);
        }
    }
    cout<<(ans==INF ? -1 : ans-1)<<endl;
return 0;
}