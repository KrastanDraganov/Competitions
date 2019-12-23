#include<iostream>
#define endl '\n'
using namespace std;
bool check(string s1, string s2){
    int i=0;
    for(int i2=0;i2<s2.size();++i2){
        if(i==s1.size() and s2[i2]!=s2[i2-1]){
            return false;
        }
        if(s1[i]==s2[i2]){
            ++i;
        }else if(s1[i]!=s2[i2] and i2>0 and s2[i2]==s2[i2-1]){
            continue;
        }else{
            return false;
        }
    }
    if(i==s1.size()){
        return true;
    }else{
        return false;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s1,s2;
        cin>>s1>>s2;
        if(check(s1,s2)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
return 0;
}