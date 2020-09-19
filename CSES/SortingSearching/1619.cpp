#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,BEGIN=0,END=1;
pair<int,int> customer[2*MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        customer[2*i]={from,BEGIN};
        customer[2*i+1]={to,END};
    }
    sort(customer,customer+2*n);

    int balance=0,res=0;
    for(int i=0;i<2*n;++i){
        if(customer[i].second==BEGIN){
            ++balance;
            res=max(res,balance);
        }else{
            --balance;
        }
    }

    cout<<res<<endl;
return 0;
}