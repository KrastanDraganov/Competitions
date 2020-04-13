#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    int prev=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> diffs;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        if(i>0 and curr!=prev){
            diffs.push({curr-prev,i-1});
        }
        prev=curr;
    }
    
    long long res=0;
    while(!diffs.empty() and diffs.top().first<k){
        res+=(long long)diffs.top().first;
        diffs.pop();
    }
    if(!diffs.empty()){
        res+=(long long)diffs.size()*k;
    }
    cout<<res<<endl;
return 0;
}