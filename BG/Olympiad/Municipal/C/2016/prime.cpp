#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
bool not_prime[MAXN];
vector<long long> primes;

void erathosten(){
    not_prime[0]=true;
    not_prime[1]=true;
    primes.push_back(2);
    for(long long i=3;i<MAXN-3;i+=2){
        if(!not_prime[i]){
            primes.push_back(i);
            for(long long i2=i*i;i2<MAXN;i2+=i){
                not_prime[i2]=true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    erathosten();
    
    string s;
    cin>>s;
    
    long long res=0;
    for(int i=0;i<s.size();++i){
        res+=(s[i]-'0')*primes[i];
    }
    cout<<res<<endl;
return 0;
}