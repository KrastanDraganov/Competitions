#include<iostream>
#include<stack>
#include<utility>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    stack<pair<int,int>> visited;
    long long res=0;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        
        int needed=1;
        while(!visited.empty() and curr>=visited.top().first){
            res+=(long long) visited.top().second;
            if(curr==visited.top().first){
                needed+=visited.top().second;
            }
            visited.pop();
        }
        
        res+=(!visited.empty());
        visited.push({curr,needed});
    }
    cout<<res<<endl;
return 0;
}