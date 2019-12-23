#include <iostream>
using namespace std;
const int maxn=100010;
int n,k,a[maxn],b[maxn];
void read()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=k;i++)
        cin>>b[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    cout<<n+b[1]<<endl;
return 0;
}

