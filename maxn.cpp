#include<bits/stdc++.h>
using namespace std;
int dig[100];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>dig[i];
    for(int i=n;i<2*n;i++) dig[i]=dig[i-n];
    for(int i=2*n;i<3*n;i++) dig[i]=dig[i-2*n];
    long long maxn=-1,ch;
    for(int i=n;i<2*n;i++){
        ch=dig[i];
        for(int i2=i-1;i2>i-n;i2--) ch=10*ch+dig[i2];
        if(ch>maxn) maxn=ch;
        ch=dig[i];
        for(int i2=i+1;i2<i+n;i2++) ch=10*ch+dig[i2];
        if(ch>maxn) maxn=ch;
    }
    cout<<maxn<<endl;
return 0;
}