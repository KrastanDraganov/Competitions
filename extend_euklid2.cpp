#include<bits/stdc++.h>
using namespace std;
//map<pair<long long,long long>,pair<long long,long long>> dp;
pair<long long,int> euklid(long long x,long long y){
	//if(dp[make_pair(x,y)]!=make_pair(0,0)) return dp[make_pair(x,y)];
	if(x<y){
		//dp[make_pair(x,y)]=euklid(y,x);
		pair<long long,long long> sol=euklid(y,x);
		return {sol.second,sol.first};
	}
	if(y==0){
		//dp[make_pair(x,y)]=make_pair(1,0);
	       	return {1,0};
	}
	//dp[make_pair(x,y)]=euklid(y,x%y);
	pair<long long,long long> sol=euklid(y,x%y);
	return {sol.second,sol.first-sol.second*(x/y)};
}
pair<long long,long long> euklid2(long long a,long long b,long long c){
	if(c%__gcd(a,b)!=0){
		cout<<"no";
		exit(1);
	}
	long long d=c/__gcd(a,b);
	pair<long long,long long> sol=euklid(a,b);
	sol.first*=d;
	sol.second*=d;
	return sol;
}
int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<euklid2(a,b,c).first<<" "<<euklid2(a,b,c).second<<endl;
return 0;
}
