#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=53;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        int odd=0,even=0;
        for(int i=0;i<n;++i){
            cin>>nums[i];
            if(nums[i]%2==1){
                ++odd;
            }else{
                ++even;
            }
        }

        odd=(odd%2);
        even=(even%2);
        if(odd>0 and even>0){
            sort(nums,nums+n);
            for(int i=1;i<n;++i){
                if(nums[i]-1==nums[i-1]){
                    odd=0;
                    even=0;
                    break;
                }
            }
        }
        cout<<((!odd and !even) ? "YES" : "NO")<<endl;
    }
return 0;
}