#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

#define endl '\n'
typedef unsigned long long ull;

using namespace std;

int g_seed;

unsigned int fastrand(){
    g_seed=214013*g_seed+2531011;
    return (g_seed>>16) & 0x7FFF;
}

int next(int prev){
    return 1+prev+(fastrand() & 0b111);
}

ull calc_limit(ull curr){
    ull div=30ULL;
    ull res=curr/div;
    if(res%div!=0ULL){
        ++res;
    }
    return res;
}

int main(){
    //freopen("justsort.in","r",stdin);
    //freopen("justsort.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,curr;
    cin>>n>>curr>>g_seed;

    ull changed=curr-(curr%3ULL)*(curr%5ULL);
    ull res=0,power=1ULL,closest_next=calc_limit(changed);
    vector<ull> between;
    between.push_back(curr-(curr%3ULL)*(curr%5ULL));
    for(int i=1;i<n;++i){
        curr=next(curr);
        changed=(curr)-(curr%3ULL)*(curr%5ULL);
        ull id=calc_limit(changed);
        if(id>closest_next){
            sort(between.begin(),between.end());
            for(ull num : between){
                res+=num*power;
                power*=139ULL;
            }
            between.clear();
            closest_next=id;
        }
        between.push_back(changed);
    }
    if(!between.empty()){
        sort(between.begin(),between.end());
        for(ull num : between){
            res+=num*power;
            power*=139ULL;
        }
    }
    cout<<res<<endl;
return 0;
}