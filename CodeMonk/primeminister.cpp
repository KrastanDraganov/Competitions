#include<iostream>
#define endl '\n'
#define MAXN 1000001
using namespace std;
bool not_prime[MAXN];
void erathosten(){
    for(int i=4;i<MAXN;i+=2){
        not_prime[i]=true;
    }
    for(long long i=3;i<MAXN;i+=2){
        if(!not_prime[i]){
            for(long long i2=i*i;i2<MAXN;i2+=i){
                not_prime[i2]=true;
            }
        }
    }
}
bool check(int num){
    int sum=0;
    while(num!=0){
        sum+=num%10;
        num/=10;
    }
    return !(not_prime[sum]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    erathosten();
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;++i){
        if(!not_prime[i] and check(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
return 0;
}