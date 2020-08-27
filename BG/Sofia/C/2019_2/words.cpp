#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=4e5+3;
bool is_word[MAXN];
long long counter[MAXN],dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s,w;
    cin>>s>>w;
    
    for(int i=0;i<=s.size()-w.size();++i){
        is_word[i+1]=true;
        for(int i2=0;i2<w.size();++i2){
            if(w[i2]!=s[i+i2]){
                is_word[i+1]=false;
                break;
            }
        }
    }
    
    for(int i=1;i<=s.size();++i){
        counter[i]=counter[i-1]+is_word[i];
    }
    
    for(int i=w.size();i<=s.size();++i){
        dp[i]=dp[i-1]+is_word[i]*counter[i-w.size()];
    }
    
    int q;
    cin>>q;
    for(int test=0;test<q;++test){
        int l,r;
        cin>>l>>r;
        long long res=0;
        if((r-l+1)>=2*w.size()){
            res=dp[r-w.size()+1]-dp[l+w.size()-1]-counter[l-1]*(counter[r-w.size()+1]-counter[l+w.size()-1]);
        }
        cout<<res<<endl;
    }
return 0;
}