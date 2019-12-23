#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,p,x,ch,pb,i=2;
    cin>>n>>p;
    bool j;
    cout<<1<<endl;
    while(true){
        x=i;
        ch=0;
        pb=1;
        while(x>0){
            ch+=(x&1)*pb;
            x>>=1;
            pb*=p;
        }
        if(ch<=n) cout<<ch<<endl;
        else break;
        i++;
    }
return 0;
}