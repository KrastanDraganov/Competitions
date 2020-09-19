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

    stack<pair<int,int>> smaller;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;

        while(!smaller.empty() and curr<=smaller.top().first){
            smaller.pop();
        }

        cout<<(smaller.empty() ? 0 : smaller.top().second)<<" ";

        smaller.push({curr,i+1});
    }
    cout<<endl;
return 0;
}