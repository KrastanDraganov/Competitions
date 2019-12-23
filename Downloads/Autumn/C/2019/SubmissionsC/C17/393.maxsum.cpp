#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N,K;
long long chisla[1000000],hodove[1005];
pair<int,int> dvij;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a;
    cin>>N>>K;
    for(int i=0; i<N; i++)
    {
        cin>>a;
        chisla[i]=a;
    }
    for(int i=0; i<K; i++)
    {
        cin>>a;
        hodove[i]=a;
    }
    int l=0,r=N-1;
    sort(hodove,hodove+K);
    long long sum=chisla[l]+chisla[r];
    bool vlqzoh=false;

    for(int i=0;; i++)
    {
        dvij.first=l;
        dvij.second=hodove[0];
        vlqzoh=false;
        for(int j=0; j<K; j++)
        {
            if(chisla[l+hodove[j]]>chisla[dvij.first+dvij.second])
            {
                dvij.first=l;
                dvij.second=hodove[j];
            }
            if(chisla[r-hodove[j]]>chisla[dvij.first+dvij.second])
            {
                dvij.first=r;
                dvij.second=-hodove[j];
            }

        }
        if(l+hodove[0]>=r)
        {
            cout<<sum<<"\n";
            return 0;
        }
        if(dvij.first==l)
        {
            l+=dvij.second;
        }
        else
        {
            r+=dvij.second;
        }
        sum+=chisla[dvij.first+dvij.second];
    }
    cout<<sum<<"\n";
    return 0;

}
