#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
const long long BASE=31,MOD=1e9+7;
long long hashS[MAXN],pow[MAXN];

vector<int> rabin_karp(string p, string s){
    int n=(int) p.size(),m=(int) s.size();

    long long hashP=0;
    for(int i=0;i<n;++i){
        hashP=(hashP+(p[i]-'a'+1)*pow[i])%MOD;
    }

    for(int i=0;i<m;++i){
        hashS[i+1]=(hashS[i]+(s[i]-'a'+1)*pow[i])%MOD;
    }

    vector<int> res;
    for(int i=0;i<m-n+1;++i){
        long long curr_hash=(hashS[i+n]-hashS[i]+MOD)%MOD;
        if(curr_hash==(hashP*pow[i])%MOD){
            res.push_back(i);
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow[0]=1;
    for(int i=1;i<MAXN;++i){
        pow[i]=(pow[i-1]*BASE)%MOD;
    }

    int tests;
    cin>>tests;

    while(tests--){
        string s,p;
        cin>>s>>p;

        vector<int> res=rabin_karp(p,s);
        if(res.empty()){
            cout<<"Not Found\n";
        }else{
            cout<<(int)res.size()<<endl;
            for(int ind : res){
                cout<<ind+1<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
    }
return 0;
}