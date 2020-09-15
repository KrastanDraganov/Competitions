#include<iostream>
#include<climits>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    long long res=INT_MIN,sum=0;
    while(n--){
        long long curr;
        cin>>curr;

        sum=max(curr,curr+sum);
        res=max(res,sum);
    }

    cout<<res<<endl;
return 0;
}