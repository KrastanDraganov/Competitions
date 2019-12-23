#include<iostream>
#include<string>
#include<stdio.h>
#define endl '\n'
using namespace std;
bool check(string num){
    if(num.size()<2){
        return false;
    }
    int sum=0,last=10*(num[num.size()-2]-'0')+num[num.size()-1]-'0';
    for(int i=0;i<num.size();++i){
        sum+=num[i]-'0';
    }
    return (sum%3==0 and last%4==0);
}
int main(){
    freopen("twelve.in","r",stdin);
    freopen("twelve.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    cout<<(check(s) ? "Yes" : "No")<<endl;
return 0;
}