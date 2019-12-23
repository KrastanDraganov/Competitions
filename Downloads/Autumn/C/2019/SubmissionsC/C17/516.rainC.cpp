#include<iostream>
using namespace std;
int N,K,sum,a,b,ng,dob;
int visochina[1000008],dobavqne[1000008];
int main()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>visochina[i];
    }
    cin>>K;
    for(int i=0; i<K; i++)
    {
        cin>>a>>b;
        dobavqne[a]=b;
    }

    for(int i=0; i<N;)
    {
        ng=i+1;
        for(int j=i+1; j<N; j++)
        {
            if(visochina[i]<=visochina[j])
            {
                ng=j;
                break;
            }
            if(visochina[j]>visochina[ng])
            {
                ng=j;
            }
        }
        if(visochina[i]<visochina[ng])
        {
            if(dobavqne[i]>0)
            {
                dob++;
                visochina[i]+=dobavqne[i];
            }
        }
        if(visochina[i]>visochina[ng])
        {
            if(dobavqne[ng]>0)
            {
                dob++;
                visochina[ng]+=dobavqne[ng];
            }
        }
        sum+=(ng-i)*min(visochina[i],visochina[ng]);
        i++;
    }
    cout<<dob<<" "<<sum<<"\n";
    return 0;
}
