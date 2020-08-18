#include<iostream>

#define endl '\n'

using namespace std;

long long val(long long num){
    if(num%4==0){
        return num;
    }
    if(num%4==1){
        return 1;
    }
    if(num%4==2){
        return num+1;
    }
    return 0;
}

long long res(long long l, long long r){
    if((r-l)%2==0){
        return 0;
    }
    return val(l-1)^val(r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l,r;
    cin>>l>>r;
    
    cout<<res(l,r)<<endl;
return 0;
}