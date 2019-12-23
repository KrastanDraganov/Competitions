#include<bits/stdc++.h>
using namespace std;
int ch[10005],backpack[10005][100005];
int main(){
	int n,t,t2,time;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t>>t2;
		time=0;
		for(int i2=0;i2<t2;i2++){
			cin>>ch[i2];
			time+=ch[i2];
		}
		if(time<=t){
			cout<<1<<endl;
			continue;
		}else if(time>2*t){
			cout<<0<<endl;
			continue;
		}
		for(int i2=0;i2<t;i2++){
			if(ch[0]<=i2){
				backpack[0][i2]=ch[0];
			}
		}
		for(int i2=1;i2<t2;i2++){
			for(int i3=0;i3<t;i3++){
				backpack[i2][i3]=backpack[i2-1][i3];
				if(i3-ch[i2]>=0 and backpack[i2-1][i3]<backpack[i2-1][i3-ch[i2]]){
					backpack[i2][i3]=ch[i2]+backpack[i2-1][i3-ch[i2]];
				}else{
					backpack[i2][i3]=backpack[i2-1][i3];
				}
			}
		}
		if(time-backpack[t2][t]>t) cout<<0<<endl;
		else cout<<1<<endl;
	}
return 0;
}

