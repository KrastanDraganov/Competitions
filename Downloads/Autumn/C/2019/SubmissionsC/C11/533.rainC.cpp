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
ios_base::sync_with_stdio(0);
cin.tie(NULL);
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
nai[0]=gredi[0]+pozwo[0].second;
koi[0]=1;
for(long long i=1;i<N;i++){
    if(nai[i-1]<=gredi[i]+pozwo[i].second){
        nai[i]=gredi[i]+pozwo[i].second;
        koi[i]=i;
    }else{
        nai[i]=nai[i-1];
        koi[i]=koi[i-1];
    }
}
nai2[N-1]=gredi[N-1]+pozwo[N-1].second;
koi2[N-1]=N-1;
for(long long i=N-2;i>=0;i--){
        if(nai2[i+1]<=gredi[i]+pozwo[i].second){
        nai2[i]=gredi[i]+pozwo[i].second;
        koi2[i]=i;
    }else{
        nai2[i]=nai2[i+1];
        koi2[i]=koi2[i+1];
    }
}
long long broi=0;
for(long long i=0;i<N;i++){
    if(pozwo[i].first){
        if(koi2[i]!=i && koi[i]==i){
            broi++;
            gredi[i]+=pozwo[i].second;
            continue;
        }if(koi2[i]==i && koi[i]!=i){
            broi++;
            gredi[i]+=pozwo[i].second;
        }
    }
}
long long obem=0;
for(long long i=1;i<N;i++){
    if(koi2[i]!=i && koi[i]!=i){
        obem+=min(nai2[i],nai[i]);
    }if(koi2[i]!=i && koi[i]==i){
        obem+=nai[i-1];
    }if(koi2[i]==i && koi[i]==i){
        obem+=nai[i-1];
    }if(koi2[i]==i && koi[i]!=i){
        obem+=gredi[i];
    }
}
cout<<broi<<" "<<obem<<endl;
return 0;
}
