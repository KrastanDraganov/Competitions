#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int type[MAXN];
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

void sol(int monster, int mask, int n, int& answer){
	dp[monster][mask]=true;
	if(monster==0){
		answer=max(answer,decode_bits(mask));
		return;
	}
	for(int i=0;i<n;i++){
		if(mask | type[i]!=mask and !dp[monster-1][mask | type[i]]){
			sol(monster-1,mask | type[i],n,answer);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,k,t;
	cin>>n>>k>>t;
	for(int i=0;i<n;i++){
		for(int i2=0;i2<t;i2++){
			bool curr;
			cin>>curr;
			if(curr){
				type[i]=type[i] | (1<<i2);
			}
		}
	}

	int answer=0;
	sol(k,0,n,answer);
	cout<<answer<<endl;
return 0;
}
