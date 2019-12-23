#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long fibonachi[50];
pair<long long,long long> extended_euclid(int x,int y){
    if(y==0) return {1,0};
    pair<long long,long long> sol=extended_euclid(y,x%y);
    return {sol.second,sol.first-(x/y)*sol.second};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,s;
    cin>>n>>s;
    fibonachi[1]=1;
    fibonachi[2]=1;
    for(int i=3;i<=n;i++){
        fibonachi[i]=fibonachi[i-1]+fibonachi[i-2];
    }
    long long a=fibonachi[n-1],b=fibonachi[n-2],d;
    d=__gcd(a,b);
    if(s%d!=0){
        cout<<0<<endl;
    }else{
        a/=d;
        b/=d;
        s/=d;
        pair<long,long> ee=extended_euclid(a,b);
        ee.first*=s;
        ee.second*=s;
        long long res1,res2;
        if(ee.first%b==0){
            res1=(-1)*ee.first/b+1;
        }else{
            res1=(long long) ceil((-1.0)*ee.first/b);
        }
        if(ee.second%a==0){
            res2=ee.second/a-1;
        }else{
            res2=(long long) floor(1.0*ee.second/a);
        }
        //cout<<res1<<" "<<res2<<" "<<d<<" "<<ee.first<<" "<<ee.second<<endl;
        if(res1>res2){
            cout<<0<<endl;
        }else{
            cout<<res2-res1+1<<endl;
        }
    }
return 0;
}