//Only 0/100 points

#include<iostream>
#include<algorithm>
#include<stdio.h>

#define endl '\n'

using namespace std;

const int MAXN=2e3+3;
int prices[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("shopcheat.in","r",stdin);
    freopen("shopcheat.out","w",stdout);
    
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>prices[i];
    }
    sort(prices,prices+n);
    
    long long max_sum=0;
    int groups=0;
    for(int i=1;i<=(n/k);++i){
        long long curr=0;
        int step=n/i,starti=0;
        
        if(n%i!=0){
            starti=step+(n%i);
            for(int i2=0;i2<starti/k;++i2){
                curr+=(long long)prices[i2];
            }
        }
        
        for(int i2=starti;i2<n;i2+=step){
            for(int i3=0;i3<step/k and i3+i2<n;++i3){
                curr+=(long long)prices[i2+i3];
            }
        }
        
        if(curr>max_sum){
            max_sum=curr;
            groups=i;
        }
    }
    cout<<max_sum<<" "<<groups<<endl;
return 0;
}
