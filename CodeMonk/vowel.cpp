#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
bool vowel(char c){
    if(c=='u' or c=='o' or c=='e' or c=='i' or c=='a' or c=='A' or c=='I' or c=='E' or c=='O' or c=='U'){
        return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
        string s;
        cin>>s;
        long long res=0;
        for(int i=0;i<s.size();++i){
            if(vowel(s[i])){
                res+=(s.size()-i)*(i+1);
            }
        }
        cout<<res<<endl;
    }
return 0;
}