#include<bits/stdc++.h>
using namespace std;
long long n,k,num[100002],kk[1002],maxsum=0,sum1=0,seq[100002],maxseq[100002],maxl=0,seq1[100002],maxsum2=0,sum=0,len,a,indd=0;

void cpy_seq(int q)
{
 for(int i=0;i<=q;i++)maxseq[i]=seq[i];
}

void btr(bool a,int pos,int l)
{
  sum1+=num[pos];
  seq[l]=pos;
  if(a==0)
  {
  for(int i=0;i<k;i++)
  {
   if(pos+kk[i]<n-1)btr(0,pos+kk[i],l+1);
   else break;
  }
   if(sum1>maxsum){maxsum=sum1;cpy_seq(l);maxl=l;}
   sum1-=num[pos];
   seq[l]=0;
  }
  else
    {
        for(int i=0;i<k;i++)
  {
        if(pos-kk[i]>0)btr(1,pos-kk[i],l+1);
        else break;
  }
        if(sum1>maxsum){maxsum=sum1;cpy_seq(l);maxl=l;}
        sum1-=num[pos];
        seq[l]=0;
    }
}

void bsearch(long long ind, long long ss)
{
    int l=0,r=maxl,mid;
    long long m;
    m=ss;
    mid=(l+r)/2;
    while(l<r)
        {
            if(r==l+1 && ind<maxseq[mid] && ind<maxseq[mid+1])break;
            else if(r==l+1 && ind<maxseq[mid]){r--;break;}
            else if(ind<maxseq[mid])l=mid;
            else r=mid;
            //else if(r=l+1){r=l;break;}
            mid=(l+r)/2;
        }
  for(int i=0;i<=r;i++)m+=num[maxseq[i]];
  if(m>maxsum2)maxsum2=m;
}

void check(int x, int mk)
{
    for(int c=0;c<mk;c++)if(x%kk[c]==0)break;
    kk[mk]=x;
    indd++;
}

int main()
{
 cin>>n>>k;
 for(int i=0;i<n;i++)cin>>num[i];
 for(int i=0;i<k;i++){cin>>a;check(a,indd);}
 sort(kk,kk+k);
 btr(0,0,0);
  for(int i=0;i<maxl+1;i++)seq1[i]=maxseq[i];
  len=maxl+1;
  maxl=0;
 btr(1,n-1,0);

 for(int i=0;i<len;i++)
    {
      sum+=num[seq1[i]];
      bsearch(seq1[i],sum);
    }
 cout<<maxsum2<<endl;
 return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/
