#include<iostream>
#include<stdio.h>

#define endl '\n'

using namespace std;

int main(){
    freopen("exercise.in","r",stdin);
    freopen("exercise.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    int digit=1,days=1;
    while(days<n){
        ++digit;
        days+=digit;
    }
    cout<<digit<<endl;
return 0;
}