#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#define endl '\n'
#define BEGIN 1
#define END 2
using namespace std;
vector<pair<long long,long long>> nums;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		char scobe1,scobe2;
		long long a,b,c,d,x,y;
		cin>>scobe1>>a>>b>>c>>d>>scobe2;
		x=a/b;
		a=a%b;
		y=c/d;
		c=c%d;
		if((scobe1=='(' and a>=0) or (scobe1=='[' and a>0)){
			++x;
		}
		if((scobe2==')' and c<=0) or (scobe2==']' and c<0)){
			--y;
		}
		if(y<x){
			continue;
		}
		nums.push_back({x,BEGIN});
		nums.push_back({y,END});
	}
	sort(nums.begin(),nums.end());
	int counter=1;
	long long startp,endp,res=0;
	startp=endp=nums[0].first;
	for(int i=1;i<nums.size();++i){
		if(counter==0){
			res+=(endp-startp+1);
			startp=nums[i].first;
		}
		if(nums[i].second==BEGIN){
			++counter;
		}else{
			--counter;
			endp=nums[i].first;
		}
	}
	cout<<res+endp-startp+1<<endl;
return 0;
}