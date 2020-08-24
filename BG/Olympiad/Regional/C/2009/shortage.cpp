#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    
    string revs="";
    for(int i=0;i<s.size();++i){
        revs+=s[s.size()-i-1];
    }
    
    int res=0;
    for(int i=0;i<s.size();++i){
        if(s[i]==s[s.size()-1] and revs.substr(0,(s.size()-i)/2)==s.substr(i,(s.size()-i)/2)){
            res=i;
            break;
        }
    }
    cout<<res<<endl;
return 0;
}