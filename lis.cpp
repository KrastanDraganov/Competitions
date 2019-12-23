#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN = 1e5+2;
int n,nums[MAXN],tail[MAXN];
vector<pair<int,int>>links;
int binarySearch(int left, int right, int x){
    while(left+1<right){
        int mid=(left+right)/2;
        if(tail[mid]>=x){
            right=mid;
        }else{
            left=mid;
        }
    }
    return right;
}
int sol(){
    if(n==0){
        return 0;
    }
    int result=1;
    tail[0]=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]<tail[0]){
            tail[0]=nums[i];
        }else if(nums[i]>tail[result-1]){
            tail[result++]=nums[i];
        }else{
            tail[binarySearch(-1,result-1,nums[i])]=nums[i];
        }
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    cout<<sol()<<endl;
return 0;
}