#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int res[MAXN];
bool visited[MAXN];
pair<long long,int> sticks[MAXN];
pair<long long,pair<long long,int>> dist[MAXN];

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
    int last=m-1;
    for(int i=n-2;i>=0;--i){
        int r=last,l=0;
        /*while(sticks[ind].first>dist[i].second.first or visited[ind]){
            --ind;
        }*/
        while(l<=r){
            int mid=(l+r)/2;
            if(sticks[mid].first>dist[i].second.first){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int ind=l-1;
        while(visited[ind]){
            --ind;
        }
        visited[ind]=true;
        if(ind==last){
            while(visited[last]){
                --last;
            }
        }
        res[dist[i].second.second]=sticks[ind].second;
    }
    for(int i=0;i<n-1;++i){
        cout<<res[i]+1<<" ";
    }
    cout<<endl;
return 0;
}