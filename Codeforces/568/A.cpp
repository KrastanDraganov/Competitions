#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long newa=min(a,min(b,c)),newc=max(a,max(b,c)),newb;
    if(newa!=a and newc!=a) newb=a;
    else if(newa!=b and newc!=b) newb=b;
    else newb=c;
    long long newa2=newa,newb2=newb,newc2=newc;
    long long res=0;
    if(newb-newa<d){
        res+=(d-newb+newa);
        newb+=d-newb+newa;
    }
    if(newb>newc and newb-newc<d){
        res+=(d-newb+newc);
        newb+=d-newb+newc;
    }else if(newc>newb and newc-newb<d){
        res+=(d-newc+newb);
        newc+=d-newc+newb;
    }
    if(newc-newa<d){
        res+=(d-newc+newa);
        newc+=d-newc+newa;
    }
    long long res2=0;
    if(newb2-newa2<d){
        res2+=(d-newb2+newa2);
        newa2-=d-newb2+newa2;
    }
    if(newc2-newb2<d){
        res2+=(d-newc2+newb2);
        newc2+=d-newc2+newb2;
    }
    if(newc2-newa2<d){
        res2+=(d-newc2+newa2);
        newc2+=d-newc2+newa2;
    }
    cout<<min(res,res2)<<endl;
return 0;
}