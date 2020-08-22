#include<iostream>
#include<cstring>
#include<queue>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXS=900,MAXP=8100;
int dp[MAXS+3][MAXP+3],last_digit[MAXS+3][MAXP+3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp,-1,sizeof(dp));
    memset(last_digit,-1,sizeof(last_digit));
    
    queue<pair<int,int>> bfs;
    bfs.push({0,0});
    dp[0][0]=0;
    last_digit[0][0]=0;
    while(!bfs.empty()){
        pair<int,int> curr=bfs.front();
        bfs.pop();
        for(int digit=last_digit[curr.first][curr.second];digit<=9;++digit){
            int nexts=curr.first+digit,nextp=curr.second+digit*digit;
            if(nexts<=MAXS and nextp<=MAXP and dp[nexts][nextp]==-1){
                dp[nexts][nextp]=dp[curr.first][curr.second]+1;
                last_digit[nexts][nextp]=digit;
                bfs.push({nexts,nextp});
            }
        }
    }
    
    int tests;
    cin>>tests;
    while(tests--){
        int s,p;
        cin>>s>>p;
        if(s>MAXS or p>MAXP or dp[s][p]>100 or dp[s][p]==-1){
            cout<<"No solution\n";
        }else{
            string res="";
            while(s>0 and p>0){
                int curr=last_digit[s][p];
                char attach='0'+curr;
                res=attach+res;
                s-=curr;
                p-=curr*curr;
            }
            cout<<res<<endl;
        }
    }
return 0;
}