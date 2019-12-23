#include<iostream>
#define endl '\n'
#define MAXN 1005
using namespace std;
int type[MAXN],n,k,t,answer;
bool dp[MAXN][5*MAXN];
int decode_bits(int mask){
	int result=0;
	for(int i=0;i<12;i++){
		if(mask & (1<<i)){
			result++;
		}
	}
	return result;
}
void sol(int monster, int mask){
	dp[monster][mask]=true;
	if(monster==0){
		answer=max(answer,decode_bits(mask));
		return;
	}
	for(int i=0;i<n;i++){
		if(mask | type[i]!=mask and !dp[monster-1][mask | type[i]]){
			sol(monster-1,mask | type[i]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k>>t;
	for(int i=0;i<n;i++){
		for(int i2=0;i2<t;i2++){
			bool b;
			cin>>b;
			if(b){
				type[i]=type[i] | (1<<i2);
			}
		}
	}
	sol(k,0);
	cout<<answer<<endl;
return 0;
}
