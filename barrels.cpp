#include<iostream>
#include<algorithm>
#define endl '\n'
#define MAXN 103
using namespace std;
int nums[MAXN];
void calc(int ind, int weight, int counter, int s, int n, int& res){
    if(weight>s) return;
    int curr=(s-weight)/nums[ind];
    if(counter+curr<res){
        if(weight+curr*nums[ind]==s){
            res=counter+curr;
        }else if(ind>0){
            while(curr>=0){
                calc(ind-1,weight+curr*nums[ind],counter+curr,s,n,res);
                --curr;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    int res=1e9;
    calc(n-1,0,0,s,n,res);
    cout<<res<<endl;
return 0;
}