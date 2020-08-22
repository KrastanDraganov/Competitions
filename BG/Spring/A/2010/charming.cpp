#include<iostream>
#include<unordered_set>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
unordered_set<string> available;
int dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dna;
    int n;
    cin>>n>>dna;
    for(int i=0;i<n;++i){
        string curr;
        cin>>curr;
        available.insert(curr);
    }

    int m=(int)dna.size();
    for(int i=0;i<m;++i){
        dp[i+1]=max(dp[i+1],dp[i]);
        string curr="";
        for(int i2=i;i2<m;++i2){
            curr+=dna[i2];
            if(available.count(curr)>0){
                dp[i2+1]=max(dp[i2+1],dp[i]+1);
                break;
            }
        }
    }
    cout<<dp[m]<<endl;
return 0;
}