#include<iostream>
using namespace std;
long long dp[10001];
long long dp2[10001];
long long mas[10001];
long long pozi2[10001];
long long pozi[1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
long long N,K;
cin>>N>>K;
for(long long i=0;i<N;i++){
 cin>>mas[i];
}
long long ko;
for(long long i=0;i<K;i++){
    cin>>ko;
    pozi2[ko]++;
}
long long broi=0;
for(long long i=1;broi<K;i++){
    if(pozi2[i]>0){
        pozi[broi]=i;
        broi++;
    }
}
K=broi;
dp[0]=mas[0];
for(long long i=1;i<N;i++){
    for(long long j=0;j<K;j++){
        if(i-pozi[j]<0){
            break;
        }
        dp[i]=max(dp[i],dp[i-pozi[j]]+mas[i]);
    }
}
dp2[N-1]=mas[N-1];
for(long long i=N-2;i>=0;i--){
    for(long long j=0;j<K;j++){
        if(i+pozi[j]>=N){
            break;
        }
        dp2[i]=max(dp2[i],dp2[i+pozi[j]]+mas[i]);
    }
}
long long nai=0;
for(long long i=0;i<N;i++){
    for(long long j=i+1;j<=i+pozi[0];j++){
        if(nai<dp[i]+dp2[j]){
            nai=dp[i]+dp2[j];
        }
    }
}
cout<<nai<<endl;
return 0;
}
