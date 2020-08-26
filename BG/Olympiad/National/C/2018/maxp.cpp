#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
long long nums[MAXN],prefix[MAXN],l[MAXN],r[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>nums[i];
        
        prefix[i+1]=nums[i];
        if(i>0){
            prefix[i+1]+=prefix[i];
        }
        
        l[i]=0;
        if(nums[i]!=0){
            for(int i2=i-1;i2>=0;i2--){
                if(nums[i2]<nums[i]){
                    l[i]=i2+1;
                    break;
                }
            }
        }
    }
    
    long long res=-1;
    for(int i=0;i<n;i++){
        r[i]=n-1;
        if(nums[i]!=0){
            for(int i2=i+1;i2<n;i2++){
                if(nums[i2]<nums[i]){
                    r[i]=i2-1;
                    break;
                }
            }
        }
        
        long long curr=nums[i]*(prefix[r[i]+1]-prefix[l[i]]);
        res=max(res,curr);
    }
    cout<<res<<endl;
return 0;
}