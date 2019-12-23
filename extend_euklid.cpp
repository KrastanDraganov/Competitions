#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> euklid(long long x,long long y){
	if(x<y){
		pair<long long,long long> sol=euklid(y,x);
		return {sol.second,sol.first};
	}
	if(y==0) return {1,0};
	pair<long long,long long> sol=euklid(y,x%y);
	return {sol.second,sol.first-sol.second*(x/y)};
}
int main(){
	long long a,b;
	cin>>a>>b;
	cout<<euklid(a,b).first<<" "<<euklid(a,b).second<<endl;
return 0;
}
