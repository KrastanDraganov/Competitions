#include<iostream>

#define endl '\n'

using namespace std;

long long bit_counter(long long num){
    return __builtin_popcount(num);
}

long long calc(long long ind){
    if(ind<0){
        return 0;
    }
    long long res=(ind/2)+(bit_counter(ind)%2);
    if(ind%2){
        res+=(bit_counter(ind-1)%2);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long f,a,b,m;
    cin>>n>>f>>a>>b>>m;
    
    long long curr=f,curr2=0,res=0;
    for(int i=1;i<2*n;++i){
        if(i%2){
            curr2=(curr*a+b)%m;
            res^=(calc(max(curr,curr2))-calc(min(curr,curr2)-1));
        }else{
            curr=(curr2*a+b)%m;
        }
    }
    cout<<res<<endl;
return 0;
}