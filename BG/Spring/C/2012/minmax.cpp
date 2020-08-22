#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=20;
long long sub[MAXN],add[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    cin>>n>>c;
    for(int i=0;i<n;++i){
        cin>>sub[i];
    }
    for(int i=0;i<n;++i){
        cin>>add[i];
    }

    long long min_num=c,max_num=c;
    for(int i=n-1;i>=0;--i){
        min_num-=add[i];
        max_num-=add[i];
        min_num*=sub[i];
        max_num*=sub[i];
        max_num+=sub[i]-1;
    }
    cout<<min_num<<" "<<max_num<<endl;
return 0;
}