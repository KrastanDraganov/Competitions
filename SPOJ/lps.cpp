#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=1e5+3,BASE=31;
uint64_t pow_s[MAXN],hash_s[2][MAXN];
 
uint64_t left_hash(int ind, int len, int n){
    return pow_s[n-ind+len]*(hash_s[0][ind]-hash_s[0][ind-len]);
}
 
uint64_t right_hash(int ind, int len, int n){
    return pow_s[ind+len-1]*(hash_s[1][ind]-hash_s[1][ind+len]);
}
 
int calc_pal(int ind, int n, bool is_even){
    int rind=n-ind-1-is_even;
    int l=0,r=min(ind, rind);
 
    while(l<=r){
        int mid=(l+r)/2;
        if(left_hash(ind+1, mid+1, n)==right_hash(ind+is_even+1, mid+1, n)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
 
    return (l<1 ? 0 : l-1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    string s;
    cin>>n>>s;
 
    pow_s[0]=1;
    for(int i=1;i<MAXN;++i){
        pow_s[i]=pow_s[i-1]*BASE;
    }
 
    for(int i=0;i<n;++i){
        hash_s[0][i+1]=hash_s[0][i]+(s[i]-'a'+1)*pow_s[i];
        hash_s[1][n-i]=hash_s[1][n-i+1]+(s[n-i-1]-'a'+1)*pow_s[i];
    }
 
    int res=1;
    for(int i=1;i<n;++i){
        int curr=2*calc_pal(i, n, false)+1;
        res=max(res, curr);
        if(s[i]==s[i-1]){
            curr=2*calc_pal(i-1, n, true)+2;
            res=max(res, curr);
        }
    }
 
    cout<<res<<endl;
return 0;
}