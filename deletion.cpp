#include<iostream>
#define endl '\n'
using namespace std;
const int MOD=1e9;
int digits[16],curr[32];
long long dp[16][1024],sum[16];
int do_mod(long long x){
    if(x<MOD){
        return x;
    }else{
        return x%MOD;
    }
}
void add(int x){
    if(sum[x]==0){
        sum[x]=sum[x-1];
        for(int i=0;i<sum[x];++i){
            dp[x][i]=dp[x-1][i];
        }
        return;
    }
    long long right,left,num;
    bool d=false;
    for(int i=0;i<max(sum[x],sum[x-1]);++i){
        if(i>=sum[x]){
            left=0;
        }else{
            left=dp[x][i];
        }
        if(i>=sum[x-1]){
            right=0;
        }else{
            right=dp[x-1][i];
        }
        num=right+left+d;
        d=(num>=MOD);
        dp[x][i]=do_mod(num);
    }
    sum[x]=max(sum[x],sum[x-1]);
    if(d){
        dp[x][sum[x]]=d;
        sum[x]++;
    }
}
void add_one(int x){
    if(sum[x]==0){
        dp[x][0]=1;
        sum[x]=1;
        return;
    }
    long long y=dp[x][0]+1;
    bool d=(y==MOD);
    dp[x][0]=do_mod(y);
    for(int i=1;i<sum[x];++i){
        if(!d) break;
        y=dp[x][i]+d;
        d=(y>=MOD);
        dp[x][i]=do_mod(y);
    }
    if(d){
        dp[x][sum[x]]=d;
        sum[x]++;
    }
}
void print_digits(long long x, int len){
    int counter=0;
    while(x!=0){
        curr[counter++]=x%10;
        x/=10;
    }
    if(len>0){
        while(counter<9){
            curr[counter]=0;
            ++counter;
        }
    }
    for(int i=counter-1;i>=0;--i){
        cout<<curr[i];
    }
}
void result(int x){
    if(sum[x]==0){
        cout<<0;
        return;
    }
    for(int i=sum[x]-1;i>=0;--i){
        print_digits(dp[x][i],sum[x]-i-1);
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;++i){
        cin>>digits[i];
    }
    int dub,counter;
    for(int i=1;i<=n;++i){
        dub=i;
        counter=0;
        while(dub!=0){
            curr[counter++]=dub%10;
            dub/=10;
        }
        --counter;
        while(counter>=0){
            for(int i2=k-1;i2>=0;--i2){
                if(curr[counter]==digits[i2]){
                    if(i2>0 and dp[i2-1]>0){
                        add(i2);
                    }
                    if(i2==0){
                        add_one(i2);
                    }
                }
            }
            --counter;
        }
    }
    result(k-1);
return 0;
}