#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int res=0,pos=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='B'){
            res+=abs(pos-i);
            pos+=2;
        }
    }
    cout<<res<<endl;
return 0;
}