#include<iostream>
#include<stack>
#define endl '\n'
#define MAXN 3005
using namespace std;
int m,n,k,p,q,a,b,c,dp[MAXN][MAXN];
stack<int>st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>k>>p>>q>>a>>b>>c;
    for(int i=0;i<p;i++){
        int x=(q-1)%m+1,y=(q-1)/m+1;
        dp[x][y]=-1;
        q=((long long)(q)*a+b)%c+1;
    }
    int result=0,last=0;
    for(int i=1;i<=n;i++){
        for(int i2=1;i2<=m;i2++){
            if(dp[i2][i]!=-1){
                dp[i2][i]=1+max(max(dp[i2][i-1],dp[i2-1][i-1]),max(dp[i2-1][i],0));
            }
            if(dp[i2][i]>result){
                result=dp[i2][i];
                last=i2+(i-1)*m;
            }
        }
    }
    if(result<k){
        cout<<-1<<endl;
        return 0;
    }
    cout<<result<<endl;
    while(result>0){
        st.push(last);
        int x=(last-1)%m+1,y=(last-1)/m+1;
        if(dp[x][y]==dp[x-1][y]+1){
            --last;
        }else if(dp[x][y]==dp[x][y-1]+1){
            last-=m;
        }else if(dp[x][y]==dp[x-1][y-1]+1){
            last-=m+1;
        }
        --result;
    }
    cout<<st.top()<<" ";
    st.pop();
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
return 0;
}