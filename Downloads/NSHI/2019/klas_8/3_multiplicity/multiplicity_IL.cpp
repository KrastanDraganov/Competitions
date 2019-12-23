#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
#define problem "multiplicity.01"

unsigned long long l,r,k,br0,br1,tbr1,tbr0,t,ans;
long long const c=1000000007;
long long int Div[1000001];
long long int pow (long long int val, long long int exp) {
              if (exp==1) return val;
              if (exp%2==0) {
                 long long int num=pow(val,exp/2);
                 return (num*num)%c;
                 }
              return (val*pow(val,exp-1))%c;
}
long long comb(long long n , long long m){
	unsigned long long i,j,p=1;
	vector <long long> v1,v2;
	if(m>n-m) m=n-m;
	for(i=n;i>=n-m+1;i--){
		v1.push_back(i);
		v2.push_back(i+m-n);
	}
	/*for(i=0;i<v1.size();i++){
		for(j=0;j<v2.size();j++){
			if(v1[i]%v2[j]==0){
				v1[i]/=v2[j];
				v2[j]=1;
			}
		}
	}
	for (i=0; i<v2.size(); i++) {
        cout << v2[i] << " ";
        }
    cout << endl ;*/
	for(i=0;i<v1.size();i++) {
       p=(p*v1[i])%c;
       p=(p*Div[v2[i]])%c;
       //cout << (4*div[2])%c << " " << endl ;
       }
	return p;
}
int main(){
	int i,j;
	int q;
//	freopen(problem".in", "r", stdin);
	scanf("%lld %lld %lld",&l,&r,&k);
	br0=r/3-(l-1)/3;
	br1=r-l+1-br0;
	for (i=1; i<=r-l+1; i++) {
        Div[i]=pow(i,c-2);
        }
	while(tbr1<=min(k,br1)){
		//pokazva che tbr1 chisla ot vsichkite k, koito izbirame davat ostatak 1 po mod 3
		tbr0=k-tbr1;
		if(tbr0<=br0){
			t=(comb(br1,tbr1)*comb(br0,tbr0))%c;
			ans=(ans+t)%c;
		}
		tbr1+=3;//tbr1 vinagi trqbva da se deli na 3
	}
	cout<<ans<<endl;
//	fclose(stdin);

return 0;
}
/*
*/

