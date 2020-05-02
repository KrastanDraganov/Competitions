#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int power[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>power[i];
    }

    sort(power,power+n);
    int max_power=0,min_power=1e9;
    for(int i=0;i<n/2;++i){
        int curr=power[i]+power[n-i-1];
        max_power=max(max_power,curr);
        min_power=min(min_power,curr);
    }
    cout<<max_power-min_power<<endl;
return 0;
}