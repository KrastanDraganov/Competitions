#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define endl '\n'
using namespace std;
vector<pair<long long,long long>> cords;
long long x0,y0,ax,ay,bx,by,startx,starty,timer;
long long val(long long num1, long long num2){
    return(num1>num2 ? num1-num2 : num2-num1);
}
long long dist(pair<long long,long long> x, pair<long long,long long> y){
    return val(x.first,y.first)+val(x.second,y.second);
}
int calc_res(int ind){
    pair<long long,long long> curr={startx,starty};
    int res=0;
    long long dub_timer=timer;
    for(int i=ind;i>=0 and dub_timer-dist(curr,cords[i])>=0;--i){
        dub_timer-=dist(curr,cords[i]);
        ++res;
        curr=cords[i];
    }
    if(dub_timer>0){
        for(int i=ind+1;i<cords.size() and dub_timer-dist(curr,cords[i])>=0;++i){
            dub_timer-=dist(curr,cords[i]);
            ++res;
            curr=cords[i];
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>x0>>y0>>ax>>ay>>bx>>by>>startx>>starty>>timer;
    cords.push_back({x0,y0});
    pair<long long,long long> startp={startx,starty};
    for(int i=0;true;++i){
        if(cords[i].first>startx and cords[i].second>starty and dist(cords[i],startp)>timer){
            break;
        }
        cords.push_back({ax*cords[i].first+bx,ay*cords[i].second+by});
    }
    int n=cords.size()-1,res=0;
    for(int i=0;i<=n;++i){
        res=max(res,calc_res(i));
    }
    cout<<res<<endl;
return 0;
}