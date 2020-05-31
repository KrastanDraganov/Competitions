#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

#define endl '\n'

using namespace std;

const int MAXN=5e5+3,MAXB=803;
int nums[MAXN];
vector<int> buckets[MAXB];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int block_size=sqrt(n),curr=0,counter=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        buckets[curr].push_back(nums[i]);
        ++counter;
        if(counter==block_size){
            ++curr;
            counter=0;
        }
    }
    for(int i=0;i<MAXB;++i){
        sort(buckets[i].begin(),buckets[i].end());
    }

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==0){
            int l,r,target;
            cin>>l>>r>>target;
            --l;
            --r;
            int res=(r-l+1);
            while(l%block_size!=0 and l<=r){
                if(nums[l]<target){
                    --res;
                }
                ++l;
            }
            curr=l/block_size;
            while(l+block_size-1<=r){
                res-=(lower_bound(buckets[curr].begin(),buckets[curr].end(),target)-buckets[curr].begin());
                l+=block_size;
                ++curr;
            }
            while(l<=r){
                if(nums[l]<target){
                    --res;
                }
                ++l;
            }
            cout<<res<<endl;
        }else{
            int ind,num;
            cin>>ind>>num;
            --ind;
            int target=nums[ind];
            nums[ind]=num;
            curr=ind/block_size;
            int l=0,r=(int)buckets[curr].size()-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(buckets[curr][mid]>=target){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            buckets[curr][r+1]=num;
            sort(buckets[curr].begin(),buckets[curr].end());
        }
    }
return 0;
}