#include<iostream>
#include<stdio.h>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int nums[MAXN];

int main(){
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        nums[i]=curr-i;
    }

    sort(nums,nums+n);
    for(int i=0;i<n;++i){
        if(i>0){
            cout<<" ";
        }
        cout<<nums[i]+i;
    }
    cout<<endl;
return 0;
}