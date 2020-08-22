#include<iostream>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

long long fibonacci[50];

pair<long long,long long> extended_euclid(long long x, long long y){
    if(y==0){
        return {1,0};
    }
    pair<long long,long long> sol=extended_euclid(y,x%y);
    return {sol.second,sol.first-(x/y)*sol.second};
}

long long calc_res(long long a, long long b, long long s, long long d){
    if(s%d!=0){
        return 0;
    }
    a/=d;
    b/=d;
    s/=d;
    pair<long long,long long> ee=extended_euclid(a,b);
    ee.first*=s;
    ee.second*=s;
    long long res1=-ee.first/b+1,res2=ee.second/a;
    if(ee.second%a==0){
        --res2;
    }
    if(res1>res2){
        return 0;
    }
    return res2-res1+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n,s;
    cin>>n>>s;
    
    fibonacci[1]=1;
    fibonacci[2]=1;
    for(int i=3;i<=n;i++){
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    }
    
    long long a=fibonacci[n-2],b=fibonacci[n-1];
    long long d=__gcd(a,b);
    cout<<calc_res(a,b,s,d)<<endl;
return 0;
}