#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#define endl '\n'
using namespace std;
vector<long long> coins;
long long calc_res(unsigned long long p){
    queue<pair<unsigned long long,long long>> bfs;
    bfs.push({0,0});
    while(!bfs.empty()){
        pair<unsigned long long,long long> curr=bfs.front();
        bfs.pop();
        cout<<curr.second<<endl;
        if(curr.first==p){
            return curr.second;
        }
        for(unsigned long long add_coin : coins){
            unsigned long long new_value=add_coin+curr.first;
            if(new_value<=p){
                bfs.push({new_value,curr.second+1});
            }
        }
    }
    return -1;
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    unsigned long long p;
    cin>>p;
    unsigned long long value=1;
    while(value<=p){
        coins.push_back(value);
        value*=10;
    }
    value=25;
    while(value<=p){
        coins.push_back(value);
        value*=100;
    }
    cout<<calc_res(p)<<endl;
return 0;
}