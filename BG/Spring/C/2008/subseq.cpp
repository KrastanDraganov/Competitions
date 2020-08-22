#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long s;
    cin>>n>>s;
    int res=0,start_ind=0;
    long long sum=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        
        sum+=(long long) nums[i];
        while(sum>s and start_ind<=i){
            sum-=nums[start_ind++];
        }
        
        if(sum==s){
            ++res;
        }
    }
    cout<<res<<endl;
return 0;

}