#include<bits/stdc++.h>
using namespace std;
const long long MOD=10e9+7;
long long br[10000005],dp[80000005],pr[80000005];
vector<long long>ch;
int factorial(int x){
	if(x<2) return 1;
	if(dp[x]!=0) return dp[x];
	dp[x]=((x%MOD)*(factorial(x-1)%MOD))%MOD;
	return dp[x];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,k,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(br[a]==0) ch.push_back(a);
		br[a]++;
		pr[a]=br[a];
	}
	long long rez1=factorial(n);
	long long proiz=1;
	dp[1]=1;
	for(int i=0;i<ch.size();i++){
		proiz=(proiz%MOD*(factorial(pr[ch[i]]))%MOD)%MOD;
	}
	cout<<rez1%MOD/(proiz%MOD)<<endl;
return 0;
}
