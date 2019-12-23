#include<bits/stdc++.h>
using namespace std;
const int BEGIN=0,END=1,MAXN=1000006;
pair<int,pair<int,int>> ch[2*MAXN];
pair<int,int> ch2[MAXN];
int rez[2*MAXN],rez2[2*MAXN];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,a,b,c,i2=0,intv=0,intv2=0,i3=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ch[i2++]=make_pair(a,make_pair(BEGIN,i));
		ch[i2++]=make_pair(b,make_pair(END,i));
	}
	sort(ch,ch+i2);
	for(int i=0;i<i2;i++){
		rez[i]=intv;
		if(ch[i].second.first==BEGIN){
			intv++;
		}else{
			intv--;
		}
		if(ch[i].second.first==BEGIN){
			intv2++;
		}
		rez2[i]=intv2;
		if(ch[i].second.first==BEGIN){
			ch2[ch[i].second.second].first=i;
		}else{
			ch2[ch[i].second.second].second=i;
		}
	}
	for(int i=0;i<n;i++){
		a=ch2[i].first;
		b=ch2[i].second;
		c=rez[a]+rez2[b]-1;
		if(a>0) c-=rez2[a-1];
		cout<<c<<" ";
	}
	cout<<endl;
return 0;
}
