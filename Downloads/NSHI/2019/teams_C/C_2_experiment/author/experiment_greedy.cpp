#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,p;
int h[N],nx[N];
int t[N],sz[N];
void getsize(int u)
{
	if (!h[u])
		sz[u]++;
	for (int i=h[u];i;i=nx[i])
	{
		getsize(i);
		sz[u]+=sz[i];
	}
}
int getans(int u)
{
	if (!h[u])
		return 1;
	int ret=0,tmp;
	if (t[u])
	{
		for (int i=h[u];i;i=nx[i])
		{
			tmp=getans(i)+sz[u]-sz[i];
			if (tmp>ret)
				ret=tmp;
		}
		return ret;
	}
	for (int i=h[u];i;i=nx[i])
		ret+=getans(i)-1;
	return ret+1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&p);
		nx[i]=h[p];
		h[p]=i;
	}
	getsize(1);
	printf("%d\n",getans(1));
	return 0;
}
