#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3;
vector<int> waiting(2*MAXN);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	int sum=0,bus_size=0;
	for(int i=0;i<n;++i){
		int time,k;
		cin>>time>>k;
		
		vector<int> students(k);
		for(int i=0;i<k;++i){
			cin>>students[i];
			students[i]=(students[i]<sum ? 0 : students[i]-sum);
		}
		if(k>m){
			students.resize(m);
		}
		
		vector<int> duplicate(bus_size);
		for(int i=0;i<bus_size;++i){
			duplicate[i]=waiting[i];
		}
		merge(students.begin(),students.end(),duplicate.begin(),duplicate.end(),waiting.begin());
		
		bus_size+=k;
		bus_size=min(bus_size,m);
		sum+=time;
	}
	
	cout<<sum+waiting[bus_size-1]<<endl;
return 0;
}