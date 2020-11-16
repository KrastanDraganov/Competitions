// Slow for first 26 numbers

#include<iostream>
#include<utility>
#include<set>

#define endl '\n'

using namespace std;

pair<int,int> dirs[4]={{0,-1}, {0,1}, {-1,0}, {1,0}};

long long sol(int counter, bool is_vertical_line, pair<int,int> curr, set<pair<int,int>>& used){
    if(counter==0){
        for(pair<int,int> add : dirs){
            int nextx=curr.first+add.first;
            int nexty=curr.second+add.second;
            if(!used.count({nextx, nexty})){
                return 0;
            }
        }
        return 1;
    }

    used.insert(curr);
    
    long long res=0;
    for(pair<int,int> add : dirs){
        int nextx=curr.first+add.first;
        int nexty=curr.second+add.second;
        
        if(used.count({nextx, nexty})){
            continue;
        }
        if(!is_vertical_line and nexty<curr.second){
            continue;
        }
        
        if(nexty>curr.second and !is_vertical_line){
            res+=sol(counter-1, true, {nextx, nexty}, used);
        }else{
            res+=sol(counter-1, is_vertical_line, {nextx, nexty}, used);
        }
    }

    used.erase(curr);

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout<<"{";
    for(int i=0;i<26;++i){
        set<pair<int,int>> used;
        used.insert({0, 0});
        
        if(i>0){
            cout<<",";
        }
        cout<<sol(i, false, {1, 0}, used);
    }
    cout<<"}\n";
return 0;
}