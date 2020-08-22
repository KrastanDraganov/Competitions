#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    
    while((int)s.size()%3>0){
        s='0'+s;
    }
    
    int sum=0;
    for(int i=0;i<s.size();i+=3){
        sum+=(s[i]-'0')*4+(s[i+1]-'0')*2+(s[i+2]-'0');
    }
    
    if(sum%7==0){
        cout<<"YES\n";
    }else{
        cout<<7-(sum%7)<<endl;
    }
return 0;
}