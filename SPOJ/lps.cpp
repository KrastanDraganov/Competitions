// Not solved - wrong answer

#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3,BASE=31;
unsigned long long pow_s[MAXN],hash_s[2][MAXN];

bool check(int len, string& s){
    if(len==1){
        return true;
    }

    int n=(int) s.size(),mid=len/2;
    bool check=(len & 1);

    // cout<<len<<" "<<check<<endl;

    for(int i=len;i<=n;++i){
        unsigned long long half1=hash_s[1][i-mid+1]-hash_s[1][i+1];
        unsigned long long half2=hash_s[0][i-mid-check]-hash_s[0][i-len];

        // cout<<"kzl: "<<half1<<" "<<half2<<endl;
        // cout<<"interval 1: "<<i-mid+1<<" "<<i<<endl;
        // cout<<"interval 2: "<<i-len+1<<" "<<i-mid-check<<endl;
        // cout<<"pow: "<<i<<" "<<n-i+len-1<<endl;

        if(half1*pow_s[i]==half2*pow_s[n-i+len]){
            return true;
        }
    }

    return false;
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

    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid, s)){
            l=mid+2;
        }else{
            r=mid-1;
        }
    }

    cout<<r<<endl;
return 0;
}