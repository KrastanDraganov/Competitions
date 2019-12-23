#include<iostream>
using namespace std;
int primes[]={2,3,5,7,11};
long long counter=0;
unsigned int pow2(int power){
    unsigned int res=1;
    for(int i=0;i<power;++i){
        ++counter;
        res*=2;
    }
    return res;
}
bool is_prime(unsigned int num){
    for(unsigned int i=2;i*i<=num;++i){
        ++counter;
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int p : primes){
        ++counter;
        unsigned int curr=pow2(p)-1;
        if(is_prime(curr)){
            cout<<curr<<" ";
        }
    }
    cout<<endl<<counter<<endl;
return 0;
}