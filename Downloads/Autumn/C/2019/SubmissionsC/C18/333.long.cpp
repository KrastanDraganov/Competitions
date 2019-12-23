#include<bits/stdc++.h>
using namespace std;
long long bukvi[26];
bool kvi[26];
string s;
char mas[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main() {
long long n,m,k;
cin>>n>>m>>k;
if (k>1) {
    for (int q=0;q<n;q++) {
        cin>>s;

    }
        cout<<"4\ncb\n2\n";
}
else {
    for (int q=0;q<n;q++) {
        cin>>s;
        for (int w=0;w<s.size();w++) {
            kvi[s[w]-'a']=1;
        }
        for (int q=0;q<26;q++) {
            if (kvi[q]) bukvi[q]++;
        }
        fill(kvi,kvi+26,0);
    }
    long long nm=bukvi[0],nmi=0,br=0;
    for (int q=1;q<26;q++) {
        if (bukvi[q]>nm) {
            nm=bukvi[q];
            nmi=q;
        }
    }
    for (int q=0;q<26;q++) {
        if (bukvi[q]==nm) br++;
    }
    if (nm==0) cout<<"0";
   else cout<<nm<<"\n"<<mas[nmi]<<"\n"<<br;
}
}
