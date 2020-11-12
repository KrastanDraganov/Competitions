#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,MOD=1e9+7;
// dp[x][y][z] - subsequences ending in pos <= #x that have
// first #y letters from string "abc" and has #z question marks
int dp[MAXN][4][4],power3[MAXN];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int mul_mod(int x, int y){
    return (long long) x*y%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin>>n>>s;

    int unknown=0;
    for(char curr : s){
        if(curr=='?'){
            ++unknown;
        }
    }

    power3[0]=1;
    for(int i=1;i<=unknown;++i){
        power3[i]=mul_mod(power3[i-1], 3);
    }

    dp[0][0][0]=1;
    for(int i=0;i<n;++i){
        for(int pos=0;pos<=3;++pos){
            for(int questions=0;questions<=3;++questions){
                add_mod(dp[i+1][pos][questions], dp[i][pos][questions]);
                if(pos<3 and (s[i]=='?' or s[i]-'a'==pos)){
                    add_mod(dp[i+1][pos+1][questions+(s[i]=='?')], dp[i][pos][questions]);
                }
            }
        }
    }

    int res=0;
    for(int i=0;i<=3 and i<=unknown;++i){
        add_mod(res, mul_mod(dp[n][3][i], power3[unknown-i]));
    }

    cout<<res<<endl;
return 0;
}