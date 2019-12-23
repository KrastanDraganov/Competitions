#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;
const int MAXN = 1e5+3;
int money[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	stack<int> st;
	for(int i=0;i<n;++i){
		cin>>money[i];
		while(!st.empty() and money[st.top()]>=money[i]){
			st.pop();
		}
		cout<<(st.empty() ? 0 : st.top()+1)<<" ";
		st.push(i);
	}
	cout<<endl;
return 0;
}