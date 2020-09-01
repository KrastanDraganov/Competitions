#include<iostream>
#include<algorithm>
#include<utility>
#include<set>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int res[MAXN];
bool visited[MAXN];
pair<long long,int> sticks[MAXN];
pair<long long,pair<long long,int>> dist[MAXN];
set<pair<long long,pair<long long,int>>> available;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    long long prevx,prevy;
    cin>>prevx>>prevy;
    for(int i=0;i<n-1;++i){
        long long currx,curry;
        cin>>currx>>curry;
        long long diff=curry-prevx,diff2=currx-prevy;
        dist[i]={diff2,{diff,i}};
        prevx=currx;
        prevy=curry;
    }
    for(int i=0;i<m;++i){
        long long curr;
        cin>>curr;
        sticks[i]={curr,i};
    }
    sort(dist,dist+n-1);
    sort(sticks,sticks+m);
    int ind=n-2;
    for(int i=m-1;i>=0;--i){
        while(ind>=0 and dist[ind].first<=sticks[i].first){
            cout<<"a: "<<i<<" "<<dist[ind].second.second<<endl;
            available.insert(dist[ind--]);
        }
        while(!available.empty() and (*available.begin()).second.first<sticks[i].first){
            cout<<"b: "<<i<<" "<<dist[ind].second.second<<endl;
            available.erase(available.begin());
        }
        if(!available.empty()){
            cout<<"c: "<<i<<" "<<(*available.begin()).second.second<<endl;
            res[(*available.begin()).second.second]=sticks[i].second;
            available.erase(available.begin());
        }
    }
    for(int i=0;i<n-1;++i){
        cout<<res[i]+1<<" ";
    }
    cout<<endl;
return 0;
}