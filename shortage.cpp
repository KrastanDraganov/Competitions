#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,reverses="";
    cin>>s;
    for(int i=0;i<s.size();++i){
        reverses+=s[s.size()-i-1];
    }
    int res=0;
    //cout<<reverses<<endl;
    for(int i=0;i<s.size();++i){
        //cout<<i<<" "<<s[i]<<" "<<reverses[s.size()-1]<<endl;
        if(s[i]==s[s.size()-1] and reverses.substr(0,(s.size()-i)/2)==s.substr(i,(s.size()-i)/2)){
            res=i;
            break;
        }
    }
    cout<<res<<endl;
return 0;
}