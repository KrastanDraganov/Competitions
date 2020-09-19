#include<iostream>
#include<map>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin>>n>>x;

    map<long long,int> start_sum;
    start_sum[0]=1;
    long long res=0,sum=0;

    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;

        sum+=curr;
        res+=start_sum[sum-x];
        ++start_sum[sum];
    }

    cout<<res<<endl;
}