#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
int nums[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    long long res=0,res2=0;
    /*for(int i=0;i<n-2;++i){
        for(int i2=i+1;i2<n-1;++i2){
            for(int i3=i2+1;i3<n;++i3){
                int diff1=nums[i2]-nums[i],diff2=nums[i3]-nums[i2];
                if(diff2>=diff1 and diff2<=2*diff1){
                    ++res2;
                    //cout<<nums[i]<<" "<<nums[i2]<<" "<<nums[i3]<<endl;
                }
            }
        }
    }
    cout<<res2<<endl;*/
    for(int i=0;i<n-2;++i){
        for(int i2=i+1;i2<n-1;++i2){
            int l=i2,r=n,diff=nums[i2]-nums[i];
            while(l+1<r){
                int mid=(l+r)/2;
                int curr_diff=nums[mid]-nums[i2];
                if(diff<=curr_diff and curr_diff<=2*diff){
                    l=mid;
                }else{
                    r=mid;
                }
            }
            if(l>i2 and l<n){
                int l2=i2,r2=l;
                while(l2+1<r2){
                    int mid=(l2+r2)/2;
                    int curr_diff=nums[mid]-nums[i2];
                    if(diff<=curr_diff and curr_diff<=2*diff){
                        r2=mid;
                    }else{
                        l2=mid;
                    }
                }
                //cout<<nums[i]<<" "<<nums[i2]<<" "<<l<<" "<<l2<<" "<<r2<<" ";
                res+=(long long)(l-r2+1);
                //cout<<res<<endl;
            }
        }
    }
    cout<<res<<endl;
return 0;
}