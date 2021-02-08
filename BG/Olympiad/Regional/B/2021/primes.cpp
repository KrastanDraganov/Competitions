#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;

vector<int> sieve_erathosten(int n, vector<bool>& not_prime){
    not_prime[0]=not_prime[1]=true;
    for(int i=4;i<=n;i+=2){
        not_prime[i]=true;
    }

    vector<int> primes{2};
    for(int i=3;i<=n;i+=2){
        if(not_prime[i]){
            continue;
        }

        primes.push_back(i);

        for(long long j=1ll*i*i;j<=n;j+=i){
            not_prime[j]=true;
        }
    }

    return primes;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b;
    cin>>a>>b;

    vector<bool> not_prime(MAXN, false);
    vector<int> primes=sieve_erathosten(MAXN-3, not_prime);
    int n=(int)primes.size();

    int res=0,l=-1,r=-1,num=-1;
    for(int i=a;i<=b;++i){
        if(!not_prime[i]){
            res=1;
            num=i;
            break;
        }
    }

    int sum=0,limit=-1;
    for(int i=0;i<n;++i){
        if(i>0){
            sum-=primes[i-1];
        }

        while((sum<a or limit<i) and limit+1<n){
            ++limit;
            sum+=primes[limit];
        }

        if(sum<a or sum>b){
            break;
        }

        if(!not_prime[sum] and limit-i+1>res){
            res=limit-i+1;
            l=i;
            r=limit;
            num=sum;
        }

        int new_sum=sum;
        for(int j=limit+1;j<n and new_sum+primes[j]<=b;++j){
            new_sum+=primes[j];
            if(!not_prime[new_sum] and j-i+1>res){
                res=j-i+1;
                l=i;
                r=j;
                num=new_sum;
            }
        }
    }

    if(res==0){
        cout<<"no prime\n";
    }else{
        cout<<num<<" "<<res<<endl;
        if(res==1){
            cout<<num<<endl;
        }else{
            for(int i=l;i<=r;++i){
                cout<<primes[i]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}
