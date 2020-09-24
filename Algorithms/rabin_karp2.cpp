#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
const long long BASE=31,MOD=1e9+7;
long long hashS[MAXN],pow[MAXN];

bool rabin_karp(string p, string s){
    int n=(int) p.size(),m=(int) s.size();

    pow[0]=1;
    for(int i=1;i<max(n,m);++i){
        pow[i]=(pow[i-1]*BASE)%MOD;
    }

    long long hashP=0;
    for(int i=0;i<n;++i){
        hashP=(hashP+(p[i]-'a'+1)*pow[i])%MOD;
    }

    for(int i=0;i<m;++i){
        hashS[i+1]=(hashS[i]+(s[i]-'a'+1)*pow[i])%MOD;
    }

    for(int i=0;i<m-n+1;++i){
        long long curr_hash=(hashS[i+n]-hashS[i]+MOD)%MOD;
        if(curr_hash==(hashP*pow[i])%MOD){
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