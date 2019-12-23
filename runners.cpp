#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define endl '\n'
using namespace std;
vector<pair<int,int>> times;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        times.push_back({((n-num)+i),num});
    }
    sort(times.begin(),times.end());
    int counter=1;
    vector<int> res;
    for(int i=1;i<n;++i){
        if(times[i].first!=times[i-1].first){
            ++counter;
            if(counter==4){
                break;
            }
        }
        if(counter==3){
            res.push_back(times[i].second);
        }
    }
    cout<<res.size()<<" ";
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}