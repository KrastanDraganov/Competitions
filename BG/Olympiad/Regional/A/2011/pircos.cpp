#include<iostream>
#include<bitset>
#include<unordered_set>

#define endl '\n'

using namespace std;

int primes[10]={1009,1013,1019,1021,1031,1033,1039,1049,1051,1061};
bitset<1100> remainder[10];
unordered_set<long long> res;

bool is_digit(char c){
    return (c>='0' and c<='9');
}

long long read_num(){
    char c=getchar_unlocked();
    while(!is_digit(c)){
        c=getchar_unlocked();
    }
    long long res=0;
    while(is_digit(c)){
        res=10*res+c-'0';
        c=getchar_unlocked();
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n=read_num();
    
    for(int i=0;i<n;++i){
        long long num=read_num();
        for(int i2=0;i2<10;++i2){
            int curr=num%primes[i2];
            remainder[i2].flip(curr);
        }
    }
    
    cin.seekg(0);
    n=read_num();
    
    for(int i=0;i<n;++i){
        long long num=read_num();
        bool used=true;
        for(int i2=0;i2<10;++i2){
            if(remainder[i2].none()){
                continue;
            }
            int curr=num%primes[i2];
            if(!remainder[i2][curr]){
                used=false;
            }
        }
        if(used){
            if(res.find(num)!=res.end()){
                res.erase(num);
            }else{
                res.insert(num);
            }
        }
    }
    
    long long a=*(res.begin()),b=*(++res.begin());
    cout<<min(a,b)<<" "<<max(a,b)<<endl;
return 0;
}