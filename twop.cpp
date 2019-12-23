#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN = 5e6+3;
bool not_prime[MAXN];
vector<int> primes;
void erathosten(){
    not_prime[0]=true;
    not_prime[1]=true;
    primes.push_back(2);
    for(int i=4;i<MAXN-3;i+=2){
        not_prime[i]=true;
    }
    for(long long i=3;i<MAXN-3;i+=2){
        if(!not_prime[i]){
            primes.push_back((int)i);
            for(long long i2=i*i;i2<MAXN-3;i2+=i){
                not_prime[i2]=true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    erathosten();
    int n;
    cin>>n;
    int res=0;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        int counter=0;
        for(int i=0;i<primes.size() and primes[i]<num and (num-primes[i])>=primes[i];++i){
            if(!not_prime[num-primes[i]]){
                ++counter;
            }
        }
        res=max(res,counter);
    }
    cout<<res<<endl;
return 0;
}