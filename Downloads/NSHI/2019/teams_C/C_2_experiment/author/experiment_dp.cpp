#include<bits/stdc++.h>
using namespace std;
struct node{
	int to;
	node *next;
};
int i,j,m,n,a[1000005],f[1000005],dp[1000005],deg[1000005],k;
node *nd[1000005];
void addd(int u,int v){
	node *p=new node();
	p->to=v;
	p->next=nd[u];
	nd[u]=p;
}
void dfs(int u){
	node *p=nd[u];
	if ((u>1)&&(deg[u]==1)){//note that u>1
		dp[u]=1;
		k++;
		return;
	}
	if (a[u]) dp[u]=1000000000;
	else dp[u]=0;
	while(p){
		dfs(p->to);
		if (a[u]){
			if (dp[p->to]<dp[u]) dp[u]=dp[p->to];
		}else{
			dp[u]+=dp[p->to];
		}
		p=p->next;
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=2;i<=n;i++){
		scanf("%d",&f[i]);
		deg[i]++;
		deg[f[i]]++;
		addd(f[i],i);
	}
	dfs(1);
	printf("%d\n",k+1-dp[1]);
	return 0;
}
