#include<iostream>
#include<vector>
#include<unordered_map>
#include<iomanip>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3;
vector<int> graph[MAXN];
unordered_map<string, int> encode;
bool visited[MAXN],dp[MAXN];
int people[MAXN];

string repair(string s){
    for(int i=0;i<s.size();++i){
        if(s[i]>='A' and s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
    return s;
}

void add_name(string name, int& counter){
    if(encode.count(name)==0){
        encode[name]=counter++;
    }
}

int dfs(int currv){
    visited[currv]=true;
    int res=1;
    for(int nextv : graph[currv]){
        if(!visited[nextv]){
            res+=dfs(nextv);
        }
    }
    return res;
}

double sol(int n, int hotel1, int hotel2, double p1, double p2, int all){
    dp[0]=true;
    for(int i=0;i<all;++i){
        int curr=people[i];
        for(int i2=0;i2+curr<=hotel1;++i2){
            if(dp[i2]){
                dp[curr+i2]=true;
            }
        }
    }
    double res=1e9;
    for(int i=0;i<=hotel1;++i){
        if(dp[i] and n-i<=hotel2){
            res=min(res,p1*i+(n-i)*p2);
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,v1,v2;
    double p1,p2;
    cin>>n>>m>>p1>>v1>>p2>>v2;
    int counter=0;
    for(int i=0;i<m;++i){
        string s1,s2;
        cin>>s1>>s2;
        s1=repair(s1);
        s2=repair(s2);
        add_name(s1,counter);
        add_name(s2,counter);
        graph[encode[s1]].push_back(encode[s2]);
        graph[encode[s2]].push_back(encode[s1]);
    }
    
    int all=0,sum=0;
    for(int i=0;i<counter;++i){
        if(!visited[i]){
            people[all++]=dfs(i);
            sum+=people[all-1];
        }
    }
    if(sum<n){
        for(int i=0;i<n-sum;++i){
            people[all++]=1;
        }
    }
    cout<<setprecision(2)<<fixed<<sol(n,v1,v2,p1,p2,all)<<endl;
return 0;
}