#include <iostream>
#include <algorithm>
using namespace std;

#define problem "kasi.01"

int a[100001],b[100001],n,br;

int main() {
int i,k;	
//	freopen(problem".in", "r", stdin);
	br=0;
	cin>>n;	
	for (i=1; i<=n; i++){
		cin>>a[i];
		b[i]=0;
	}
	for (i=1; i<=n; i++){
		if (b[i]==0){
			k=i; b[i]=i;
			while (1){
				k=a[k];
				if (b[k]==0){
					b[k]=i;
				}
				else {
					if (b[k]==i) br++;
					break;
				}
			}
		}
	}
	cout<<br<<endl;
	
//	fclose(stdin);
	
  return 0;
}

/*

8
4
6
2
1
5
4
8
7

*/   


