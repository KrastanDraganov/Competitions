// Not solved - wrong answer

#include<iostream>
 
#define endl '\n'
 
using namespace std;
 
const int MAXN=1e5+3,BASE=31;
unsigned long long pow_s[MAXN],hash_s[2][MAXN];

unsigned long long left_hash(int ind, int len){
    return hash_s[0][ind]-hash_s[0][ind-len];
}

unsigned long long right_hash(int ind, int len){
    return hash_s[1][ind]-hash_s[1][ind+len];
}
 
int calc_pal(int ind, int n, bool is_even){
    int rind=n-ind-1;
    ind-=is_even;
    // cout<<"state: "<<ind<<" "<<rind<<endl;
    // if(rind<ind){
    //     return 0;
    // }

    int l=0,r=min(ind, rind);
    while(l<=r){
        int mid=(l+r)/2;
        // cout<<"search: "<<l<<" "<<r<<" "<<mid+1<<endl;
        // cout<<"hashes: "<<left_hash(ind+1, mid+1)<<" "<<right_hash(rind+1, mid+1)<<endl;
        if(left_hash(ind+1, mid+1)==right_hash(rind+1, mid+1)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
 
    return (r<0 ? 0 : r);
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
        // cout<<"odd: "<<curr<<endl;
        res=max(res, curr);
        
        if(s[i]==s[i-1]){
            curr=2*calc_pal(i, n, true)+2;
            // cout<<"even: "<<curr<<endl;
            res=max(res, curr);
        }
    }
 
    cout<<res<<endl;
return 0;
}