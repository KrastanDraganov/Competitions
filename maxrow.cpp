#include<iostream>
#include<string>
#include<stack>
#define endl '\n'
#define MAXN 1003
using namespace std;
string res[MAXN];
int dp[MAXN],parent[MAXN];
bool check(string s1, string s2){
    return ((s1.size()==s2.size() and s2>=s1) or s2.size()>s1.size());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    if(s[0]=='0'){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<s.size();++i){
        dp[i]=1;
        parent[i]=-1;
        res[i]+=s[i];
        for(int i2=i-1;i2>=0 and dp[i2]+1>=dp[i-1];--i2){
            if(res[i][0]!='0' and check(res[i2],res[i])){
                dp[i]=dp[i2]+1;
                parent[i]=i2;
                break;
            }
            res[i]=s[i2]+res[i];
        }
    }
    cout<<dp[s.size()-1]<<endl;
    stack<int> path;
    path.push(s.size()-1);
    while(parent[path.top()]!=-1){
        path.push(parent[path.top()]);
    }
    while(!path.empty()){
        cout<<res[path.top()]<<" ";
        path.pop();
    }
    cout<<endl;
return 0;
}