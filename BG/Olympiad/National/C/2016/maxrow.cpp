#include<iostream>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
string res[MAXN];
int dp[MAXN],parent[MAXN];

bool check(string s1, string s2){
    int n=(int)s1.size(),m=(int)s2.size();
    return ((n==m and s2>=s1) or m>n);
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
    cout<<dp[(int)s.size()-1]<<endl;
    
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