#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,MAXW=2e5+3;
int elements[MAXN],dp[MAXN][MAXW];

int sol(int weight, int ind, int n){
    if(weight<0){
        return -1e6;
    }
    
    if(ind==n-1){
        return (elements[ind]<=weight ? elements[ind] : 0);
    }
    
    if(dp[ind][weight]!=0){
        return dp[ind][weight];
    }
    
    dp[ind][weight]=max(sol(weight,ind+1,n),sol(weight-elements[ind],ind+1,n)+elements[ind]);
    return dp[ind][weight];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin>>tests;
    
    while(tests--){
        int time,n;
        cin>>time>>n;
        
        int sum=0;
        for(int i=0;i<n;++i){
            cin>>elements[i];
            sum+=elements[i];
        }
        
        if(sum>2*time){
            cout<<0<<endl;
            continue;
        }else if(sum<=time){
            cout<<1<<endl;
            continue;
        }
        
        for(int i=0;i<MAXN;++i){
            for(int i2=0;i2<MAXW;++i2){
                dp[i][i2]=0;
            }
        }
        
        int knapsack=sol(time,0,n);
        cout<<(time>=(sum-knapsack))<<endl;
    }
return 0;
}