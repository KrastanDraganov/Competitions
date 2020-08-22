#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a,b,c;
	cin>>a>>b>>c;
	
	cout<<__gcd(a-1,b-1)-1<<endl;
return 0;
}
