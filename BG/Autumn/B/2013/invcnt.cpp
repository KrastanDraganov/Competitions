#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int curr[MAXN];

void print_array(int nums[], int l, int r){
    for(int i=l;i<=r;++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void merge_arrays(int nums[], int l, int mid, int r, long long& res){
    int indl=l,indr=mid+1;
    for(int i=0;indl<=mid or indr<=r;++i){
        if(indl>mid or (indr<=r and nums[indr]<nums[indl])){
            res+=(long long)mid-indl+1;
            curr[i]=nums[indr++];
        }else{
            curr[i]=nums[indl++];
        }
    }
    for(int i=l;i<=r;++i){
        nums[i]=curr[i-l];
    }
}

void merge_sort(int nums[], int l, int r, long long& res){
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    merge_sort(nums,l,mid,res);
    merge_sort(nums,mid+1,r,res);
    merge_arrays(nums,l,mid,r,res);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int nums[n];
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    
    long long res=0;
    merge_sort(nums,0,n-1,res);
    cout<<res<<endl;
return 0;
}