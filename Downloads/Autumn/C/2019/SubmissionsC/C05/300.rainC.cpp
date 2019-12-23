#include <iostream>
using namespace std;
long long sum;
int n,k;
void read()
{
    cin>>n;
    long long x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum+=x;
    }
    cin>>k;
    for(int i=1;i<=k;i++)
        cin>>x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    cout<<"0 "<<sum<<endl;
return 0;
}

