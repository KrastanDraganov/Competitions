#include<iostream>

#define endl '\n'

using namespace std;

long long make_pal(long long num){
    long long res=0;
    while(num){
        res=res*2+(num%2);
        num/=2;
    }
    return res;
}

long long sol(long long num){
    long long res=0,all_bits=0,dub=num;
    
    while(dub){
        ++all_bits;
        dub/=2;
    }
    if(all_bits==1){
        return 1;
    }
    
    for(int i=1;i<all_bits;++i){
        res+=(i%2 ? (1ll<<((i-1)/2)) : (1ll<<(i/2-1)));
    }
    
    long long curr=0;
    if(all_bits%2){
        curr=(num>>((all_bits+1)/2));
        res+=2*(curr-(1ll<<((all_bits-3)/2)));
        curr=make_pal(curr)+curr*(1ll<<((all_bits+1)/2));
        res+=(curr<=num)+((curr+(1ll<<((all_bits-1)/2)))<=num);
    }else{
        curr=(num>>(all_bits/2));
        res+=curr-(1ll<<((all_bits-1)/2));
        curr=make_pal(curr)+curr*(1ll<<(all_bits/2));
        res+=(curr<=num);
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long x,y;
    cin>>x>>y;
    
    cout<<sol(y)-sol(x-1)<<endl;
return 0;
}