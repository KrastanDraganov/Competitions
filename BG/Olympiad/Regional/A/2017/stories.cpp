#include<iostream>
#include<deque>
#include<utility>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,k;
    long long curr,add,mul,mod;
    cin>>n>>k>>curr>>mul>>add>>mod;
    
    deque<pair<long long,int>> funny;
    funny.push_back({curr,0});
    long long res=curr;
    for(int i=1;i<n;++i){
        curr=(curr*mul+add)%mod;
        
        while(!funny.empty() and i-funny.front().second>=k){
            funny.pop_front();
        }
        
        while(!funny.empty() and curr>=funny.back().first){
            funny.pop_back();
        }
        
        funny.push_back({curr,i});
        res+=funny.front().first;
    }
    
    cout<<res<<endl;
return 0;
}