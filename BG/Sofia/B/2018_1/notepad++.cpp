#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e6+3;
const long long BASE=31,MOD=1e9+7;
long long hashS[MAXN],pow[MAXN];

bool check(int mid, int limit, int n, int m, vector<int>& endings){
    int counter=0,prev=1-m;

    for(int ind : endings){
        if(ind-prev>=n+mid){
            ++counter;
            prev=ind;
        }
    }

    return counter>=limit;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s,word;
    int k;
    cin>>s>>word>>k;
    
    int n=(int) word.size(),m=(int) s.size();
    pow[0]=1;
    for(int i=1;i<max(n,m);++i){
        pow[i]=(pow[i-1]*BASE)%MOD;
    }
    
    long long hash_word=0;
    for(int i=0;i<n;++i){
        hash_word=(hash_word+(word[i]-'a'+1)*pow[i])%MOD;
    }

    for(int i=0;i<m;++i){
        hashS[i+1]=(hashS[i]+(s[i]-'a'+1)*pow[i])%MOD;
    }
    
    vector<int> endings;
    for(int i=0;i+n-1<m;++i){
        long long curr_hash=(hashS[i+n]-hashS[i]+MOD)%MOD;
        if(curr_hash==(hash_word*pow[i])%MOD){
            endings.push_back(i+n-1);
        }
    }

    int left=0,right=(int)m-1;
    while(left<=right){
        int mid=(left+right)/2;
        
        if(check(mid,k,n,m,endings)){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    cout<<right<<endl;
return 0;
}