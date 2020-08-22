#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
int spoons[MAXN],forks[MAXN];

bool check(int wanted, int n, int m){
    if(wanted==0){
        return true;
    }
    if(2*wanted>m){
        return false;
    }
    int l=0,r=m-wanted,counter=0;
    for(int i=0;i<n and r<m;++i){
        if(spoons[i]>forks[l] and spoons[i]<forks[r]){
            ++counter;
            ++l;
            ++r;
        }
    }
    return counter>=wanted;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>spoons[i];
    }
    for(int i=0;i<m;++i){
        cin>>forks[i];
    }

    sort(spoons,spoons+n);
    sort(forks,forks+m);
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,n,m)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l-1<<endl;
return 0;
}