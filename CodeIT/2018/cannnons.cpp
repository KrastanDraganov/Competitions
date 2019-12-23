#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<deque>
#define endl '\n'
using namespace std;
vector<pair<int,int>> borders;
deque<pair<int,int>> q;
int main(){
    freopen("cannons.in","r",stdin);
    freopen("cannons.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        borders.push_back({l,r});
    }
    sort(borders.begin(),borders.end());
    int result=borders[0].second-borders[0].first+1,curr;
    q.push_front(borders[0]);
    curr=result;
    for(int i=1;i<n;i++){
        if(q.size()<k){
            q.push_front(borders[i]);
            curr+=abs(q.back().second-borders[i].first+1)+(borders[i].second-borders[i].first+1);
        }else{
            if(curr>result){
                result=curr;
            }
            curr-=q[0].second-q[0].first+1;
            if(q[0].second>=q[1].first){
                curr+=q[0].second-q[0].first+1;
            }
            q.pop_back();
            q.push_front(borders[i]);
        }
    }
    cout<<result<<endl;
return 0;
}