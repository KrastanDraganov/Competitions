#include <iostream>
using namespace std;
const int mod = 1000000007;
int n,m;
long long curr[1024],pr[1024];
bool el[1024];
int main(){
    cin>>n>>m;
    int masksize = 1<<(m-1);
    if (n==1){cout<<masksize<<endl;return 0;}
    for (int i=0; i<masksize; ++i){
        curr[i]=1;
    }
    for (int i=1; i<(n/2+n%2); ++i){
        swap(curr, pr);
        for (int j=0; j<masksize; ++j){
            int mask = j;
            for (int k=0; k<m-1; ++k){
                el[k] = mask&1;
                mask = mask>>1;
            }
            curr[j] = 0;
            int pow2;
            bool ok, c;
            for (int t=0; t<masksize; ++t){
                pow2=0;
                ok=1;
                mask=t;
                for (int k=0; k<m-1; ++k){
                    c = mask&1;
                    mask = mask>>1;
                    pow2 += ok && el[k] && c;
                    ok = (el[k] && c) || (ok&&(!el[k])&&(!c));
                }
                pow2+=ok;
                curr[j] += pr[t]<<pow2;
                curr[j] %= mod;
            }
        }
    }
    long long ans=0;
    for (int i=0; i<masksize; ++i){
        for (int j=0; j<masksize; ++j){
            int pow2=0, mask1=i, mask2=j;
            bool ok=1,c1,c2;
            for (int k=0; k<m-1; ++k){
                c1=mask1&1;
                c2=mask2&1;
                mask1 = mask1>>1;
                mask2 = mask2>>1;
                pow2 += ok && c1 && c2;
                ok = (c1&&c2) || (ok && !c1 && !c2);
            }
            pow2+=ok;
            if (n%2){
                //cout<<i<<" "<<j<<" "<<curr[i]<<" "<<pr[j]<<" "<<pow2<<" "<<(((curr[i]*pr[j])%mod)<<pow2)<<endl;
                ans += ((curr[i]*pr[j])%mod)<<pow2;
                ans %= mod;
            }else{
                //cout<<i<<" "<<j<<" "<<curr[i]<<" "<<curr[j]<<" "<<pow2<<" "<<(((curr[i]*curr[j])%mod)<<pow2)<<endl;
                ans += ((curr[i]*curr[j])%mod)<<pow2;
                ans %= mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
