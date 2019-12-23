#include<iostream>
using namespace std;
long long counter=1;
unsigned long long pow2(int power){
    unsigned long long res=1;
    for(int i=0;i<power;++i){
        ++counter;
        res*=2;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<"3 ";
    unsigned long long e=14;
    for(int p=3;p<12;++p){
        ++counter;
        if(p%2==1){
            unsigned long long curr=pow2(p)-1;
            if(e%curr==0){
                cout<<curr<<" ";
            }
        }
        e=e*e-2;
    }
    cout<<endl<<counter<<endl;
return 0;
}