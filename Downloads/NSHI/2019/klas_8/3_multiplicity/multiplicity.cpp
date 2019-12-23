#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
unsigned long long l,r,k,br0,br1,tbr1,tbr0,t,ans,nod,c;
long long const c1=1000000007;
unsigned long long nodd(long long a, long long b){
	while(a!=0 && b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	return a+b;
}


long long comb(long long n , long long m){
	unsigned long long i,j,p=1;
	vector <unsigned long long> v1,v2;
	if(m>n-m) m=n-m;
	for(i=n;i>=n-m+1;i--){
		v1.push_back(i);
		v2.push_back(i+m-n);
	}
	for(i=0;i<v1.size();i++){
		for(j=0;j<v2.size();j++){
			nod=nodd(v1[i],v2[j]);
			v1[i]/=nod;
			v2[j]/=nod;
		}
	}
	for(i=0;i<v1.size();i++) p=(p*v1[i])%c1;
	return p;
}
int main(){
	int i,j;
	int q;
	scanf("%lld %lld %lld",&l,&r,&k);
	br0=r/3-(l-1)/3;
	br1=r-l+1-br0;
	while(tbr1<=min(k,br1)){
		//pokazva che tbr1 chisla ot vsichkite k, koito izbirame davat ostatak 1 po mod 3
		tbr0=k-tbr1;
		if(tbr0<=br0){
			t=(comb(br1,tbr1)*comb(br0,tbr0))%c1;
			ans=(ans+t)%c1;
		}
		tbr1+=3;//tbr1 vinagi trqbva da se deli na 3
		//cout<<tbr1<<endl;
	}
	cout<<ans<<endl;
	//3451268790 2314876509967845 1000
return 0;
}
/*
*/

