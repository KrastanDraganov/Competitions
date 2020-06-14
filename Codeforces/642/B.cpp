#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=33;
int a[MAXN],b[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i=0;i<n;++i){
            cin>>b[i];
        }

        sort(a,a+n);
        sort(b,b+n);
        for(int i=0;i<k and a[i]<b[n-i-1];++i){
            swap(a[i],b[n-i-1]);
        }

        int sum=0;
        for(int i=0;i<n;++i){
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
return 0;
}