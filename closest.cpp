#include<iostream>

#define endl '\n'

using namespace std;

const long long BORDER=1e18;
long long primes[8]={2,3,5,7,11,13,17,19};

void calc_res(long long curr, int ind, long long target, long long& res){
    if(curr>=target or ind>7 or (BORDER/primes[ind])<curr){
        long long dist=abs(curr-target),comp=abs(target-res);
        if(dist==comp){
            res=min(res,curr);
        }else if(dist<comp){
            res=curr;
        }
        return;
    }
    calc_res(curr*primes[ind],ind,target,res);
    calc_res(curr,ind+1,target,res);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests=2;
    while(tests--){
        long long target;
        cin>>target;
        long long res=1;
        calc_res(1,0,target,res);
        cout<<res<<" ";
    }
    cout<<endl;
return 0;
}