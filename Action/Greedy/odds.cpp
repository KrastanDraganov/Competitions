#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

vector<int> even;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int res=0,min_odd=1e9;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        if(curr%2==0){
            even.push_back(curr);
        }else{
            min_odd=min(min_odd,curr);
            ++res;
        }
    }

    for(int curr : even){
        if(min_odd+curr<=m){
            ++res;
        }
    }
    cout<<res<<endl;
return 0;
}