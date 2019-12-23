#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
pair<long long,long long> uvelichenie[1000000];
long long n,k;
long long slMaxNum=-1;
long long maxNum=-1;
long long indexW;
bool edinstvenost;
long long f(){
    long long ans=0;
    long long i=0;
    long long j=1;
        while(i<indexW){
           if(a[i]<=a[j]){
            ans=ans+(j-i)*a[i];
            i=j;
            j++;
           }else{
            j++;
           }
        }
        i=n-1;
        j=n-2;
        while(i>indexW){
            if(a[i]<=a[j]){
                ans=ans+(i-j)*a[i];
                i=j;
                j--;
            }else{
                j--;
            }
        }
        return ans;
}
int main(){
cin>>n;
for(long long i=0;i<n;i++){
    cin>>a[i];
    if(maxNum<a[i]){
        maxNum=a[i];
        edinstvenost=1;
        indexW=i;
        continue;
    }
    if(maxNum==a[i]){
        edinstvenost=0;
        //cout<<"/";
    }
    //cout<<maxNum;
}
cin>>k;
long long x,y;
for(long long i=0;i<k;i++){
    cin>>x>>y;
    uvelichenie[i]=make_pair(x,y);
    a[x]=a[x]+y;
}
long long maxVoda=f();
long long vadim=0;
for(long long i=0;i<k;i++){
    a[uvelichenie[i].first]=a[uvelichenie[i].first]-uvelichenie[i].second;
    if(maxVoda==f()){
     vadim++;
    }
    a[uvelichenie[i].first]=a[uvelichenie[i].first]+uvelichenie[i].second;
}
//cout<<k-vadim<<" "<<f();
cout<<f();
//cout<<edinstvenost;
//cout<<index;
//cout<<slMaxNum;
//cout<<f();

return 0;
}
