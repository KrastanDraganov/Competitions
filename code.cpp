#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
#define endl '\n'
using namespace std;
unordered_map<string,long long> dp;
long long sol(string s, int n){
    if(s.size()==0) return 1;
    if(dp.find(s)!=dp.end()) return dp[s];
    long long counter=1;
    for(int i=0;i<s.size()-1;++i){
        string snum="";
        snum+=s[i];
        snum+=s[i+1];
        int num=atoi(snum.c_str());
        if(10<=num and num<=n){
            counter+=sol(s.substr(i+2),n);
        }
    }
    return dp[s]=counter;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin>>n>>s;
    n+=9;
    cout<<sol(s,n)<<endl;
return 0;
}