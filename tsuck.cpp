#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int d[]={2,3,5,7},counter[MAXN];
bool used[15];
int tsuck_counter(int num){
    int res=0,num2=num;
    while(num>0){
        res+=used[num%10];
        num/=10;
    }
    for(int i=0;i<4;++i){
        if(used[d[i]]){
            while(!(num2%d[i])){
                ++res;
                num2/=d[i];
            }
        }
    }
    return res;
}
bool check(int num, int n){
    for(int i=0;i<n;++i){
        if(tsuck_counter(num-i-1)!=counter[i]){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("tsuk.in","r",stdin);
    freopen("tsuk.out","w",stdout);
    int m;
    cin>>m;
    for(int i=0;i<m;++i){
        int num;
        cin>>num;
        used[num]=true;
    }
    int n;
    cin>>n;
    for(int i=n-1;i>=0;--i){
        cin>>counter[i];
    }
    for(int i=n+1;i<=1000000;++i){
        if(check(i,n)){
            cout<<tsuck_counter(i)<<endl;
            break;
        }
    }
return 0;
}