#include<iostream>

#define endl '\n'

using namespace std;

const long long INF=1e17+3;
long long res[12];

int persistance(long long num){
	int ans=0;
	while(num>=10){
		long long next=1;
		while(num>0){
			next*=(num%10);
			num/=10;
		}
		num=next;
		++ans;
	}
	return ans;
}

void compute(long long num){
	if(num>=INF){
		return;
	}
	int counter=persistance(num);
	res[counter]=min(num,res[counter]);
	for(long long i=max(1ll,num%10);i<=9;++i){
		compute(num*10+i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	res[0]=0;
	res[1]=10;
	for(int i=2;i<12;++i){
		res[i]=INF;
	}
	compute(0);
	
	int p;
	cin>>p;
	cout<<res[p]<<endl;
return 0;
}