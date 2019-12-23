#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string comp="RGB";
    int q;
    cin>>q;
    for(int iq=0;iq<q;++iq){
        int n,k;
        string s;
        cin>>n>>k>>s;
        int currr=0,currg=0,currb=0;
        for(int i=0;i<k;++i){
            currr+=(s[i]!=comp[i%3]);
            currg+=(s[i]!=comp[(i+1)%3]);
            currb+=(s[i]!=comp[(i+2)%3]);
        }
        int minr=currr,minb=currb,ming=currg;
        for(int i=k;i<n;++i){
            currr-=(s[i-k]!=comp[(i-k)%3]);
            currg-=(s[i-k]!=comp[(i-k+1)%3]);
            currb-=(s[i-k]!=comp[(i-k+2)%3]);
            currr+=(s[i]!=comp[i%3]);
            currg+=(s[i]!=comp[(i+1)%3]);
            currb+=(s[i]!=comp[(i+2)%3]);
            minr=min(minr,currr);
            ming=min(ming,currg);
            minb=min(minb,currb);
        }
        cout<<min(minr,min(minb,ming))<<endl;
    }
return 0;
}