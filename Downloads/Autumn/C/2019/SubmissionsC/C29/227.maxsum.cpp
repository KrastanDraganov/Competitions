#include<iostream>
#define endl '\n'
using namespace std;
int br=0,mbr=0,m[10005],poz[1005],s[10005][10005],n,k;

void zap(int l,int r)
{
    br+=m[l];
    br+=m[r];
    //cout<<l<<" "<<r<<" "<<br<<endl;
    if(l>=r) {br=br-m[l]-m[r];return;}

    if(s[l][r]>=br){br=br-m[l]-m[r];return;}
    s[l][r]=br;
    mbr=max(mbr,br);

    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==k && j==k) break;
            //if(l+poz[i]>=r-poz[j]) {continue;}

            if(i==k) br-=m[l+poz[i]];
            if(j==k) br-=m[r-poz[j]];

            zap(l+poz[i],r-poz[j]);
            if(i==k) br+=m[l+poz[i]];
            if(j==k) br+=m[r-poz[j]];

        }
    }
br=br-m[l]-m[r];
return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>m[i];
    }
    for(int i=0;i<k;i++)
    {
        cin>>poz[i];
    }
    zap(0,n-1);
    cout<<mbr<<endl;

}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/

