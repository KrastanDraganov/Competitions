#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<unordered_set>
#define endl '\n'
using namespace std;
unordered_set<int>possible;
int main(){
    freopen("subtasks.in","r",stdin);
    freopen("subtasks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,result=1,g,co=0,g2;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        int curr = 100/__gcd(100,x);
        if(possible.find(curr)==possible.end()){
            if(co==0){
                result=curr;
            }else{
                result=(result*curr)/__gcd(result,curr);
            }
            co++;
            possible.insert(curr);
        }
        //cout<<curr<<" "<<result<<" "<<g<<endl;
    }
    cout<<result<<endl;
return 0;
}