//Only 0/100 points

#include<iostream>

#define endl '\n'

using namespace std;

long long sum(long long num){
    return num*(num+1ll)/2ll;
}

void add_res(long long& res, long long counter, long long l){
    res+=sum(counter);
    if(counter>l){
        res-=sum(counter-l);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l;
    cin>>n>>l;
    long long res=0,counter=0;
    char prev='0';
    for(int i=0;i<n;++i){
        char hill;
        cin>>hill;
        if(i>0 and hill!=prev){
            add_res(res,counter,l);
            counter=0;
        }
        ++counter;
        prev=hill;
    }
    add_res(res,counter,l);
    cout<<res<<endl;
return 0;
}