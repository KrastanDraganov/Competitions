#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

pair <int,int> maxN[10001][2],sused[10001],kon[10001];
int red[10001];

int main(){

ios_base::sync_with_stdio(false);
cin.tie();

int n,k,sum=0,koi,kolko,otgovor=0;
cin>>n;
for(int i=0;i<n;i++)cin>>red[i];
///))))))))))))))))))))))))))))))))))))))))))
maxN[0][0]=make_pair(red[0],0);
for(int i=1;i<n;i++){
if(maxN[i-1][0].first<=red[i]){
    if(maxN[i-1][0].first==red[i])sused[i].first=maxN[i-1][0].second;
    maxN[i][0]=make_pair(red[i],i);
}else{
    sused[i].first=maxN[i-1][0].second;
    maxN[i][0]=maxN[i-1][0];
}
}

maxN[n-1][1]=make_pair(red[n-1],0);
for(int i=n-2;i>=0;i--){
if(maxN[i+1][1].first<=red[i]){
    if(maxN[i+1][1].first==red[i])sused[i].second=maxN[i+1][1].second;
    maxN[i][1]=make_pair(red[i],i);
}else{
    sused[i].second=maxN[i+1][1].second;
    maxN[i][1]=maxN[i+1][1];
}
}
///))))))))))))))))))))))))))))))))))))))))))))))))))))

cin>>k;

for(int i=0;i<k;i++){
            cin>>koi>>kolko;
            kon[i]=make_pair(koi,kolko);
}
sort(kon,kon+k);

for(int l=k-1;l>=0;l--){
        koi=kon[l].first;
        kolko=kon[l].second;
        if(sused[koi].first!=0 && sused[koi].second!=0 && red[koi]+kolko<red[sused[koi].first] && red[koi]+kolko<red[sused[koi].second]);
        else{
            red[koi]+=kolko;
            otgovor++;
    ///)))))))))))))))))))))))))))))))))))))))))))))
for(int i=0;i<n;i++){
    maxN[i][0]=make_pair(0,0);
    maxN[i][1]=make_pair(0,0);
    sused[i]=make_pair(0,0);
}
maxN[0][0]=make_pair(red[0],0);
for(int i=1;i<n;i++){
if(maxN[i-1][0].first<=red[i]){
    if(maxN[i-1][0].first==red[i])sused[i].first=maxN[i-1][0].second;
    maxN[i][0]=make_pair(red[i],i);
}else{
    sused[i].first=maxN[i-1][0].second;
    maxN[i][0]=maxN[i-1][0];
}
}

maxN[n-1][1]=make_pair(red[n-1],0);
for(int i=n-2;i>=0;i--){
if(maxN[i+1][1].first<=red[i]){
    if(maxN[i+1][1].first==red[i])sused[i].second=maxN[i+1][1].second;
    maxN[i][1]=make_pair(red[i],i);
}else{
    sused[i].second=maxN[i+1][1].second;
    maxN[i][1]=maxN[i+1][1];
}
}
    ///)))))))))))))))))))))))))))))))))))))))))))))
    }

}

for(int i=0;i<n-1;){
if(sused[i].second==0){
    sum+=red[i+1];
    i++;
}else{
    int K;
    for( K=i+1;K<=sused[i].second;K++){
        if(red[K]>=red[i]){
            break;
        }
    }
sum+=min(red[K],red[i])*(K-i);
i=K;
}
}

cout<<otgovor<<" "<<sum<<endl;

return 0;
}
