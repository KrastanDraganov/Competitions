#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

vector<pair<pair<int,int>,int>> paths; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;++i){
        int from,to,price;
        cin>>from>>to>>price;
        paths.push_back({{from,to},price});
    }
    
    sort(paths.begin(),paths.end());
    int startp=-1,endp=-1;
    for(int i=0;i<n;++i){
        if(paths[i].first.first<=a and a<=paths[i].first.second){
            startp=i;
        }
        if(paths[i].first.first<=b and b<=paths[i].first.second){
            endp=i;
        }
    }
    
    if(startp==endp){
        cout<<b-a<<endl;
        return 0;
    }
    
    int sum=min(paths[startp].first.second-a,paths[startp].second)
            +min(b-paths[endp].first.first,paths[endp].second);
    for(int i=startp+1;i<endp;++i){
        sum+=paths[i].second;
    }
    cout<<sum<<endl;
return 0;
}