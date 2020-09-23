#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
const long long BASE=97,MOD=1e9+7;

bool rabin_karp(string p, string s){
    int n=(int) p.size(),m=(int) s.size();

    long long hashP=0,pow=1;
    for(int i=0;i<n;++i){
        hashP=(hashP*BASE+p[i])%MOD;
        pow=(pow*BASE)%MOD;
    }

    long long hashS=0;
    for(int i=0;i<m;++i){
        hashS=(hashS*BASE+s[i])%MOD;

        if(i>=n){
            hashS=(hashS-s[i-n]*pow+MOD*MOD)%MOD;
        }

        if(hashP==hashS){
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string p,s;
    cin>>p>>s;

    cout<<(rabin_karp(p,s) ? "yes" : "no")<<endl;
return 0;
}