#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=4e4+3;
bool nums[2][MAXN];
long long counter[2][MAXN];

void calc_intervals(int ind, int n){
    int i=0;
    while(i<n){
        if(!nums[ind][i]){
            ++i;
        }else{
            int i2=i;
            while(i2<n and nums[ind][i2]){
                ++i2;
            }
            for(int i3=1;i3<=(i2-i);++i3){
                counter[ind][i3]+=i2-i3-i+1;
            }
            i=i2;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        cin>>nums[0][i];
    }
    calc_intervals(0,n);
    for(int i=0;i<m;++i){
        cin>>nums[1][i];
    }
    calc_intervals(1,m);
    long long res=0;
    for(int i=1;i<=min(n,k);++i){
        if(k%i==0 and (k/i)<=m){
            res+=counter[0][i]*counter[1][k/i];
        }
    }
    cout<<res<<endl;
return 0;
}