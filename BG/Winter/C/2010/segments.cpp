#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,BEGIN=1,END=-1;
pair<int,int> points[2*MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        points[2*i]={from,BEGIN};
        points[2*i+1]={to,END};
    }
    sort(points,points+2*n);

    int curr=0,max_sum=0;
    for(int i=0;i<2*n;++i){
        curr+=points[i].second;
        max_sum=max(max_sum,curr);
    }
    int res=0,prev=-1e9;
    curr=0;
    for(int i=0;i<2*n;++i){
        curr+=points[i].second;
        if(curr==max_sum){
            res+=points[i+1].first-points[i].first;
            if(points[i].first!=prev){
                ++res;
            }
            prev=points[i+1].first;
        }
    }
    cout<<res<<endl;
return 0;
}