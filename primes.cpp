#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e7+3;
pair<long long, long long> tree[MAXN];
bool not_prime[MAXN];

void calc_erathosten(){
    not_prime[0]=true;
    not_prime[1]=true;
    for(int i=4;i<MAXN;i+=2){ 
        not_prime[i]=true;
    }
    for(long long i=3;i<MAXN;i+=2){
        if(!not_prime[i]){
            for(long long i2=i*i;i2<MAXN;i2+=i){
                not_prime[i2]=true;
            }
        }
    }
}

void update(int ind, int val, int val2){
    while(ind<MAXN){
        tree[ind].first+=val;
        tree[ind].second+=val2;
        ind+=(ind & (-ind));
    }
}

pair<long long, long long> sol(int ind){
    long long counter=0,sum=0;
    while(ind>0){
        counter+=tree[ind].first;
        sum+=tree[ind].second;
        ind-=(ind & (-ind));
    }
    return {counter,sum};
}

pair<long long, long long> operator-(const pair<long long, long long>& p1, const pair<long long, long long>& p2){
    return {p1.first-p2.first,p1.second-p2.second};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    calc_erathosten();
    
    char type;
    while(cin>>type){
        int x;
        cin>>x;
        if(type=='a'){
            if(!not_prime[x]){
                update(x,1,x);
            }
        }else if(type=='d'){
            if(!not_prime[x] and sol(x).first-sol(x-1).first>0){
                update(x,-1,-x);
            }
        }else{
            int y;
            cin>>y;
            pair<long long, long long> res=sol(y)-sol(x-1);
            cout<<res.first<<" "<<res.second<<endl;
        }
    }
return 0;
}