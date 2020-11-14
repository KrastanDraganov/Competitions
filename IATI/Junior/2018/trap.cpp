#include<iostream>
#include<utility>
#include<set>

#define endl '\n'

using namespace std;

pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};

long long sol(int counter, bool check, pair<int,int> curr, set<pair<int,int>> used){
    used.insert(curr);
    
    if(counter==0){
        for(pair<int,int> add : dirs){
            int nextx=curr.first+add.first,nexty=curr.second+add.second;
            if(used.find(make_pair(nextx,nexty))==used.end()){
                return 0;
            }
        }
        return 1;
    }
    
    long long res=0;
    for(pair<int,int> add : dirs){
        int nextx=curr.first+add.first,nexty=curr.second+add.second;
        if(used.find(make_pair(nextx,nexty))==used.end()){
            if(nexty<curr.second and !check){
                continue;
            }else if(nexty>curr.second and !check){
                res+=sol(counter-1,true,make_pair(nextx,nexty),used);
            }else{
                res+=sol(counter-1,check,make_pair(nextx,nexty),used);
            }
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"{";
    for(int i=1;i<20;++i){
        set<pair<int,int>> used;
        used.insert(make_pair(0,0));
        if(i>1 and i<26){
            cout<<",";
        }
        cout<<sol(i-1,false,make_pair(1,0),used);
    }
    cout<<"}\n";
return 0;
}