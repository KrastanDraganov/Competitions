#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int weight[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,limit;
    cin>>n>>limit;

    for(int i=0;i<n;++i){
        cin>>weight[i];
    }
    sort(weight,weight+n);

    int l=0,r=n-1;
    int gondolas=0;
    while(l<=r){
        while(l<r and weight[l]+weight[r]>limit){
            ++gondolas;
            --r;
        }

        ++gondolas;
        ++l;
        --r;
    }

    cout<<gondolas<<endl;
return 0;
}