#include <cstdio>
#include <iostream>
#include <cassert>

using namespace std;



struct TVr{
	int p,l,r,n;
};
TVr v[100001];
int a[100001];
int n;
int fl[100001];
 
int Tyrsi(int pp, bool flag){
int k;
 
	k=1;
	while (1){
		fl[v[k].n]++;
		if (flag and fl[v[k].n]==1) {
			k=v[k].p;
			break;
		}
		if (v[k].n==pp) {
			break;
		}
		if (pp < v[k].n)
			k=v[k].l;
			else 
			k=v[k].r;
	}
	return k;
}

#define problem "path.12"

int main() {
int i,p,q,t,k;
int np, nq;
//	freopen(problem".in", "r", stdin);
		v[1].p=0;
		cin>>n;
		for (i=1; i<=n; i++) {
			cin>>v[i].n;
		}
		for (i=1; i<=n; i++) {
			cin>>v[i].l>>v[i].r;
			v[v[i].l].p=i;
			v[v[i].r].p=i;
		}
		cin>>p>>q;
		np=Tyrsi(p,false); 
		nq=Tyrsi(q,true);
		cout<<nq<<" "<<v[nq].n<<endl;	
//	fclose(stdin);
	return 0;
}
