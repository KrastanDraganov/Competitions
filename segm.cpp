#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3;
bool marked[MAXN],painted[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b,c;
    cin>>n>>a>>b>>c;

    for(int i=0;i<=n;i+=a){
        marked[i]=true;
    }
    for(int i=n;i>=0;i-=b){
        marked[i]=true;
    }
    for(int i=0;i<=(n-c);++i){
        if(marked[i] and marked[i+c]){
            for(int i2=i;i2<(i+c);++i2){
                painted[i2]=true;
            }
        }
    }
    
    int res=0;
    for(int i=0;i<n;++i){
        res+=!painted[i];
    }
    cout<<res<<endl;
return 0;
}