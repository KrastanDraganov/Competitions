#include<iostream>
#include<vector>
#include<unordered_map>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
bool used[MAXN];
vector<int> primes;
unordered_map<long long,short> checker;

bool is_prime(long long x){
    if(x<MAXN){ 
        return !used[x];
    }
    for(int i=0;i<primes.size() and primes[i]*primes[i]<=x;i++){
        if(x%primes[i]==0){
            return false;
        }
    }
    return true;
}

int result(long long x){
    unordered_map<long long,short>::const_iterator it=checker.find(x);
    if(it!=checker.end()){
        return it->second;
    }
    
    int check=(int)is_prime(x);
    if(x<10){
        checker.insert({x,check});
        return check;
    }
    
    long long digit=1,xr=-1;
    int sol=check;
    
    while(digit<=x){
        long long next_num=digit*(x/(10*digit))+(x%digit);
        int next_res=result(next_num);
        sol=max(sol,next_res+check);
        digit*=10;
    }
    checker.insert({x,sol});
    return sol;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    used[0]=true;
    used[1]=true;
    for(long long i=2;i<MAXN;i++){
        if(!used[i]){
            primes.push_back(i);
            for(long long i2=i*i;i2<N;i2+=i){
                used[i2]=true;
            }
        }
    }

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long num;
        cin>>num;
        cout<<result(num)<<endl;
    }
return 0;
}