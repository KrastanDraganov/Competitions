#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

long long red[1000001];

int main(){

ios_base::sync_with_stdio(false);
cin.tie();

long long n,r,koi,kolko;
cin>>n;
for(int i=0;i<n;i++)cin>>red[i];
cin>>r;
for(int i=0;i<r;i++){
    cin>>koi>>kolko;
}
red[koi-1]+=kolko;

int sum=0;
if(r==1){
        for(int i=0;i<n-1;){
            int k,lol=0;
            for(k=i+1;k<n && lol==0;k++){
                if(red[k]>=red[i])lol=1;
            }
            if(lol==0){
                sum+=min(red[i-1],red[i]);
                i++;
            }else{
            sum+=min(red[k],red[i])*(k-i+1);
            i=k;
            }
        }
cout<<"1 "<<sum<<endl;
}else{
    for(int i=0;i<n-1;){
            int k,lol=0;
            for(k=i+1;k<n && lol==0;k++){
                if(red[k]>=red[i])lol=1;
            }
            if(lol==0){
                sum+=min(red[i-1],red[i]);
                i++;
            }else{
            sum+=min(red[k],red[i])*(k-i+1);
            i=k;
            }
        }
cout<<"0 "<<sum<<endl;
}

return 0;
}
