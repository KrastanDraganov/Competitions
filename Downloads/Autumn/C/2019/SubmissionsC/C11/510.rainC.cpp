#include<iostream>
using namespace std;
long long N;
long long gredi[1000001];
long long nai[1000001];
long long koi[1000001];
long long nai2[1000001];
long long koi2[1000001];
pair<bool,long long > pozwo[1000001];
int main(){
cin>>N;
for(long long i=0;i<N;i++){
    cin>>gredi[i];
}
long long a,b,K;
cin>>K;
for(long long i=0;i<K;i++){
    cin>>a>>b;
    pozwo[a].first=1;
    pozwo[a].second=b;
}
cout<<0<<" "<<min(gredi[0],gredi[N-1])*(N-1);
return 0;
}
