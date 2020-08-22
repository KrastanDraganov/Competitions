#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int nums[MAXN],tail[MAXN];
vector<pair<int,int>> links;

int find_pos(int l, int r, int x){
    while(l<=r){
        int mid=(l+r)/2;
        if(tail[mid]>=x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return r+1;
}

int sol(int n){
    if(n==0){
        return 0;
    }
    int res=1;
    tail[0]=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]<tail[0]){
            tail[0]=nums[i];
        }else if(nums[i]>tail[res-1]){
            tail[res++]=nums[i];
        }else{
            tail[find_pos(0,res-1,nums[i])]=nums[i];
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        links.push_back({nums[i],x});
    }
    
    sort(links.begin(),links.end());
    for(int i=0;i<n;i++){
        nums[i]=links[i].second;
    }
    cout<<sol(n)<<endl;
return 0;
}