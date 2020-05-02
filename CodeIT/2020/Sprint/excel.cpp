#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    freopen("excel.in","r",stdin);
    freopen("excel.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long col;
    cin>>col;

    string res="";
    while(col>0){
        long long curr=col%26;
        col/=26;
        if(curr==0){
            curr=26;
            --col;
        }
        char added=curr-1+'A';
        res+=added;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
return 0;
}