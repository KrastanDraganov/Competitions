#include <bits/stdc++.h>
using namespace std;
int am[27];
string s;
bool sr[27];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++){
        getline(cin,s);
        for(int kk=0;kk<27;kk++){
            sr[kk]=0;
        }
        for(int j=0;j<s.size();j++){
            if(!sr[s[j]-'a']){
                sr[s[j]-'a']=1;
                am[s[j]-'a']++;
            }
        }
    }
    int max_1=0,r=0,max_i;
    for(int i=0;i<27;i++){
        if(max_1<am[i]){
            max_i=i;
            max_1=am[i];
        }
    }
    for(int i=0;i<27;i++){
        if(max_1==am[i]){
            r++;
        }
    }
    char chirche=max_i+'a';
    cout<<max_1<<"\n"<<chirche<<"\n"<<r;
    return 0;
}
/*
5 7 1
fagcbdaga
dcdfb
acfebdc
cfc
cegdb

5 7 1
fagcbdaga
dcdfb
acfebdc
cfb
cegdb
*/
