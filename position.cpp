#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin>>k;

    int counter=0,res;
    long long num=1;
    while(counter<k){
        long long curr=num*num;
        while(curr){
            ++counter;
            curr/=10;
        }
        if(counter>=k){
            curr=num*num;
            while(curr and counter>k){
                --counter;
                curr/=10;
            }
            res=curr%10;
        }
        ++num;
    }
    cout<<res<<endl;
return 0;
}