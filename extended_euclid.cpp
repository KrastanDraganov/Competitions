#include<iostream>

#define endl '\n'

using namespace std;

pair<long long, long long> euclid(long long x,long long y){
	if(x<y){
		pair<long long,long long> sol=euclid(y,x);
		return {sol.second,sol.first};
	}
	if(y==0){
		return {1,0};
	}
	pair<long long,long long> sol=euclid(y,x%y);
	return {sol.second,sol.first-sol.second*(x/y)};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a,b;
	cin>>a>>b;

	pair<long long, long long> res=euclid(a,b);
	cout<<res.first<<" "<<res.second<<endl;
return 0;
}
