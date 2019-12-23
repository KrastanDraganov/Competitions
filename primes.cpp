#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAXN=1e7+2;
pair<long long, long long> tree[MAXN];
//int used[MAXN];
bool not_prime[MAXN];
void erathosten(){
    not_prime[0]=true;
    not_prime[1]=true;
    for(long long i=4;i<MAXN;i+=2) not_prime[i]=true;
    for(long long i=3;i<MAXN;i+=2){
        if(!not_prime[i]){
            for(long long i2=i*i;i2<MAXN;i2+=i){
                not_prime[i2]=true;
            }
        }
    }
}
void update(int ind, int value, int value2){
    while(ind<=MAXN-2){
        tree[ind].first+=value2;
        tree[ind].second+=value;
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
pair<long long, long long> operator-(const pair<long long, long long> p1, const pair<long long, long long> p2){
    return {p1.first-p2.first,p1.second-p2.second};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    erathosten();
    char c;
    int x,y;
    while(cin>>c){
        if(c=='a'){
            cin>>x;
            if(!not_prime[x]){
                //cout<<x<<endl;
                //used[x]++;
                update(x,x,1);
            }
        }else if(c=='d'){
            cin>>x;
            if(!not_prime[x] and sol(x).first-sol(x-1).first>0){
                //cout<<x<<endl;
                //used[x]--;
                update(x,-x,-1);
            }
        }else{
            cin>>x>>y;
            pair<long long, long long> res=sol(y)-sol(x-1);
            cout<<res.first<<" "<<res.second<<endl;
        }
    }
return 0;
}