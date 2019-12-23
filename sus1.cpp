#include<bits/stdc++.h>
using namespace std;
int numbers[10004],backpack[1005][200005];
int main(){
	int n,t,t2,time;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>t2;
		time=0;
		for(int i2=0;i2<t2;i2++){
			cin>>numbers[i2];
			time+=numbers[i2];
		}
		if(time<=t){
			cout<<1<<endl;
			continue;
		}else if(time>2*t){
			cout<<0<<endl;
			continue;
		}
		for(int i2=0;i2<t;i2++){
			if(numbers[0]<=i2+1){
				backpack[0][i2]=numbers[0];
			}
		}
		for(int i2=1;i2<t2;i2++){
			for(int i3=0;i3<t;i3++){
				if(i3-numbers[i2]+1>=0 and backpack[i2-1][i3]<backpack[i2-1][i3-numbers[i2]]+1){
					backpack[i2][i3]=numbers[i2]+backpack[i2-1][i3-numbers[i2]+1];
				}else{
					backpack[i2][i3]=backpack[i2-1][i3];
				}
				cout<<backpack[i2][i3]<<" ";
			}
			cout<<endl;
		}
		cout<<time<<" "<<backpack[t2-1][t-1]<<" ";
		if(time-backpack[t2-1][t-1]>t) cout<<0<<endl;
		else cout<<1<<endl;
	}
return 0;
}
