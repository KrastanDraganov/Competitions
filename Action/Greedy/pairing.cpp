#include<iostream>
#include<string>
#include<unordered_map>

#define endl '\n'

using namespace std;

unordered_map<string,int> counter;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int most=0;
    for(int i=0;i<n;++i){
        string curr;
        cin>>curr;
        ++counter[curr];
        most=max(most,counter[curr]);
    }

    int res=(n/2);
    if(most>res){
        most-=res;
        res-=most;
    }
    cout<<res<<endl;
return 0;
}