#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int weight[53],n,sum;
pair<bool,int> dp[53][50003];
bool is_used[53][50003];
pair<bool,int> sol(int i,int counter){
    if(counter>25000 or (i==n and counter>0)) return {0,0};
    else if(i==n and counter==0) return {1,0};
    if(is_used[i][counter]) return dp[i][counter];
    is_used[i][counter]=true;
    if(weight[i]>counter){
        dp[i][counter]=sol(i+1,weight[i]-counter);
        dp[i][counter].second+=weight[i]-counter;
    }else{
        dp[i][counter]=sol(i+1,counter-weight[i]);
    }
    pair<bool,int> check=sol(i+1,counter);
    dp[i][counter]=max(dp[i][counter],check);
    check=sol(i+1,counter+weight[i]);
    check.second+=weight[i];
    dp[i][counter]=max(dp[i][counter],check);
    //cout<<boolalpha<<dp[i][counter].first<<" "<<dp[i][counter].second<<endl;
    return dp[i][counter];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        sum+=weight[i];
    }
    cout<<sum-2*sol(0,0).second<<endl;
return 0;
}