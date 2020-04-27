#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,LIMIT=6e3;
int heights[MAXN];
long long prefix[MAXN],dp[MAXN];

long long sum(int x, int y){
    return prefix[y+1]-prefix[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>heights[i];
    }

    for(int i=0;i<n;++i){
        prefix[i+1]=prefix[i]+heights[i];
    }
    for(int i=1;i<n;++i){
        int med=i/2;
        long long price1=heights[med]*med-sum(0,med-1);
        long long price2=sum(med+1,i)-heights[med]*(i-med);
        dp[i]=price1+price2;
        //cout<<"pre: "<<dp[i]<<" "<<price1<<" "<<price2<<" "<<med<<endl;
    }
    if(n<=LIMIT){
        for(int i=1;i<n;++i){
            //cout<<i<<endl;
            for(int i2=0;i2<i;++i2){
                int med=(i+i2+1)/2;
                long long price1=heights[med]*(med-i2-1)-sum(i2+1,med-1);
                long long price2=sum(med+1,i)-heights[med]*(i-med);
                //cout<<dp[i2]<<" "<<price1<<" "<<price2<<endl;
                dp[i]=min(dp[i],dp[i2]+price1+price2+k);
            }
            //cout<<"res: "<<dp[i]<<endl;
        }
    }
    cout<<dp[n-1]<<endl;
return 0;
}