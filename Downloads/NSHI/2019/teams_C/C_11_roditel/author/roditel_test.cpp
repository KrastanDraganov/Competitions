#include <cstdio>
#include <iostream>
#include <time.h> 

using namespace std;

struct TVr{
	int p,l,r,n;
};
TVr v[100001];
int a[100001];
int n;
int fl[100001];
 
void Postr(){
int r, k=1,i,nn=1;
	r=(n+1)/4;
	while (1) {
		for (i=1; i<=k; i++){
			nn++;
			a[nn]=a[nn/2]-r; 
			nn++;
			a[nn]=a[nn/2]+r;
		}
		r=r/2;
		k=k*2;
		if (r==0) break;
	}
}

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

#define problem "path.20"

int main() {
int i,p,q,t,k;
int np, nq;
	srand (time(NULL));
	freopen(problem".in", "w", stdout);
		n=1024*64-1;
		a[1]=(n+1)/2;
		Postr();
		cout<<n<<endl;
		for (i=1; i<=n; i++) cout<<a[i]<<" ";
		cout<<endl;
		for (i=1; i<=n; i++){
			if (i<=n/2) cout<<i*2<<" "<<i*2+1<<endl;
			else cout<<"0 0"<<endl;
		}
//		p=rand()%(n/2)+rand()%(n/2)+1;
//		q=rand()%(n/2)+rand()%(n/2)+1;
		p=12; q=18098;
		cout<<p<<" "<<q<<endl;
	fclose(stdout);
//
	freopen(problem".in", "r", stdin);
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
	fclose(stdout);
//	
	freopen(problem".sol", "w", stdout);
		np=Tyrsi(p,false); 
		nq=Tyrsi(q,true);
		cout<<nq<<" "<<v[nq].n<<endl;	
	fclose(stdin);
//

	return 0;
}
