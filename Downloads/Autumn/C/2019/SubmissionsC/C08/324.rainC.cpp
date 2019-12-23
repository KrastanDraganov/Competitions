#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

pair <int,int> maxN[100001][2],sused[100001],kon[100001];
int red[100001];

int main(){

ios_base::sync_with_stdio(false);
cin.tie();

long long n,k,sum=0,koi,kolko,otgovor=0;
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

for(int i=k-1;i>=0;i--){
        koi=kon[i].first;
        kolko=kon[i].second;

        if(sused[koi].first!=0 && sused[koi].second!=0 && red[koi]+kolko<red[sused[koi].first] && red[koi]+kolko<red[sused[koi].second]);
        else{
            red[koi]+=kolko;
            otgovor++;
    ///)))))))))))))))))))))))))))))))))))))))))))))

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
sum+=min(red[sused[i].second],red[i])*(sused[i].second-i);
i=sused[i].second;
}
}

cout<<otgovor<<" "<<sum<<endl;

return 0;
}
