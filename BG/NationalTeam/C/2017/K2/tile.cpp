#include<iostream>

#define endl '\n'

using namespace std;

long long calc_tiles(long long days, long long a, long long k){
    return a*((days/k)*(k-1)+(days%k));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a,k,b,m,x;
    cin>>a>>k>>b>>m>>x;

    long long l=1,r=2*x/(a+b);
    while(l<=r){
        long long mid=(l+r)/2;
        long long person1=calc_tiles(mid,a,k);
        long long person2=calc_tiles(mid,b,m);
        if(person1+person2>=x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<r+1<<endl;
return 0;
}