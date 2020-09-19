#include<iostream>
#include<map>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    map<long long,int> start_sum;
    start_sum[0]=1;
    long long res=0,sum=0;

    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        curr%=n;

        sum=(sum+curr+n)%n;
        res+=start_sum[sum];
        ++start_sum[sum];
    }

    cout<<res<<endl;
return 0;
}