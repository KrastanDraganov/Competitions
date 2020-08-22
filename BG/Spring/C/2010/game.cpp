#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=(1<<18)+3;
int tree[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    n*=2;
    int limit=(1<<n);
    for(int i=0;i<limit;++i){
        cin>>tree[i];
    }

    while(limit>1){
        limit/=2;
        for(int i=0;i<limit;++i){
            tree[i]=min(tree[2*i],tree[2*i+1]);
        }
        limit/=2;
        for(int i=0;i<limit;++i){
            tree[i]=max(tree[2*i],tree[2*i+1]);
        }
    }
    cout<<tree[0]<<endl;
return 0;
}