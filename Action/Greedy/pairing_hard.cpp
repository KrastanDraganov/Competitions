#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=51;
int c[MAXN],f[MAXN],a[MAXN],b[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>c[i]>>f[i]>>a[i]>>b[i];
    }

    int most=-1,curr=-1,counter=0,all=0;
    for(int i=0;i<n;++i){
        all+=c[i];
        curr=f[i];
        for(int i2=0;i2<c[i];++i2){
            if(curr==most){
                ++counter;
            }else if(counter==0){
                most=curr;
                counter=1;
            }else{
                --counter;
            }
            if(i2<c[i]-1){
                curr=(curr*a[i]+b[i]) & (m-1);
            }
        }
    }

    counter=0;
    for(int i=0;i<n;++i){
        curr=f[i];
        for(int i2=0;i2<c[i];++i2){
            if(curr==most){
                ++counter;
            }
            if(i2<c[i]-1){
                curr=(curr*a[i]+b[i]) & (m-1);
            }
        }
    }
    int res=all/2;
    if(all%2==1){
        --counter;
    }
    if(counter>res){
        counter-=res;
        res-=counter;
    }
    cout<<res<<endl;
return 0;
}