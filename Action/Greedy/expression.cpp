#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=103;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    
    sort(nums,nums+n);
    int res=0;
    for(int i=n-1;i>=0;--i){
        if(n-i-1<=p){
            res+=nums[i];
        }else{
            res-=nums[i];
        }
    }
    cout<<res<<endl;
return 0;
}