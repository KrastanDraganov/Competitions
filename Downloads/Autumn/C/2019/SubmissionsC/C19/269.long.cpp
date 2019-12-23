#include<bits/stdc++.h>
using namespace std;

int seen[27];
bool flag[27];
int n, m, k;

int main(){
    cin>>n>>m>>k;
    if(k!=1){
        cout<<0;
        return 1;
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int i=0;i<27;i++){
            flag[i]=true;
        }
        for(int j=0;j<s.size();j++){
            seen[s[j]-'a']+=flag[s[j]-'a'];
            flags[s[j]-'a']=false;
        }
    }
    int ans1=0, ans2=0, ans3=0;
    for(int i=0;i<27;i++){
        if(seen[i]>ans1){
            ans1=seen[i];
            ans2='a'+i;
            ans3=0;
        }
        if(seen[i]==ans1)ans3++;
    }
    cout<<ans1<<' '<<char(ans2)<<' '<<ans3<<'\n';
}

