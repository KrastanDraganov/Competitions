#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    int l=0,r=1,sum=nums[0];
    int res=(sum==x);
    
    while(r<n){
        if(sum+nums[r]>x){
            sum-=nums[l++];
        }else{
            sum+=nums[r++];
        }

        if(sum==x){
            ++res;
        }
    }
    
    cout<<res<<endl;
return 0;
}