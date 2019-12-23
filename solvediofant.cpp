#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
pair<long long,long long> euklid(long long x,long long y){
	if(y==0) return {1,0};
	pair<long long,long long> sol=euklid(y,x%y);
	return {sol.second,sol.first-sol.second*(x/y)};
}
pair<long long,long long> euklid2(long long a,long long b,long long c){\
	pair<long long,long long> sol=euklid(a,b);
	sol.first*=c;
	sol.second*=c;
	return sol;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	long long a,b,c,gd;
	cin>>a>>b>>c;
	gd=__gcd(a,b);
    if(c%gd!=0){
        cout<<"no\n";
        return 0;
    }
	a/=gd;
	b/=gd;
	c/=gd;
    pair<long long,long long> result=euklid2(a,b,c);
	cout<<result.first<<" "<<result.second<<endl;
return 0;
}