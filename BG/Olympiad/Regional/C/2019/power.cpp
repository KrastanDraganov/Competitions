#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=103;
int fractions[MAXN];
int primes[]={2,3,5,7,11,13,17,19,23, 29,31,37,41};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    
    unsigned long long nok=-1;
    for(int i=0;i<n;i++){
        unsigned long long num;
        cin>>num;
        if(i==0){
            nok=num;
        }else{
            nok=(nok*num)/__gcd(nok,num);
        }
    }

    for(int i=0;i<13;i++){
        while(nok%primes[i]==0){
            fractions[i]++;
            nok/=primes[i];
        }
    }

    for(int i=0;i<13;i++){
        if(fractions[i]>0){
            if(fractions[i]%k!=0){
                fractions[i]+=(k-fractions[i]%k);
            }
            fractions[i]/=k;
        }
    }

    unsigned long long result=1;
    for(int i=0;i<13;i++){
        for(int i2=0;i2<fractions[i];i2++){
            result*=primes[i];
        }
    }
    cout<<result<<endl;
return 0;
}