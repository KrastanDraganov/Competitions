#include<bits/stdc++.h>
using namespace std;
int primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41},fractions[100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    unsigned long long number,nok,result=1;
    for(int i=0;i<n;i++){
        cin>>number;
        if(i==0){
            nok=number;
        }else{
            nok=(nok*number)/__gcd(nok,number);
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
    for(int i=0;i<13;i++){
        for(int i2=0;i2<fractions[i];i2++){
            result*=primes[i];
        }
    }
    cout<<result<<endl;
return 0;
}