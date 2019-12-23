#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset <long long> ms;
multiset<long long>::iterator it;

struct TOts {
	long long x,x2,h,fl;
};

struct TObl {
	long long x1,x2,S,tip;
};
long long N, bOts1, bOts2, bObl;
TOts Ots1[200001], Ots2[200001];
TObl Obl[100001];
bool FlEnd;

void IztrMax(long long k){
	FlEnd=false;
	it=ms.find(k);
	if (it == ms.end()) {
//		cout<<"Iztr"<<endl;
		FlEnd=true;
	}
	else
	ms.erase(it);	
}

void PechatMs(){
	for (it=ms.begin(); it!=ms.end(); ++it)  cout<< *it << ' ' ;
	cout<<endl;	
}

void PechatObl(){
	for (long long i=1; i<=bObl; i++)  
		cout<<Obl[i].x1<<" "<<Obl[i].x2<<" "<<" "<<Obl[i].tip<<" "<<Obl[i].S<<endl;
	cout<<endl;
}

void PechatOts1(){
	for (long long i=1; i<=bOts1; i++)  cout<<Ots1[i].x<<Ots1[i].x2<<" "<<" "<<Ots1[i].h<<" "<<Ots1[i].fl<<endl;
	cout<<endl;	
}

void PechatOts2(){
	for (long long i=1; i<=bOts2; i++)  cout<<Ots2[i].x<<" "<<Ots2[i].x2<<" "<<Ots2[i].h<<" "<<Ots2[i].fl<<endl;
	cout<<endl;	
}

bool fff(TOts p, TOts q) {
	if (p.x>q.x) return false;
	else
	if (p.x<q.x) return true;	
	else {
		return (p.fl<q.fl);
	}
}

bool fffObl(TObl p, TObl q) {
	if (p.x1>q.x1) return false;
	else
	if (p.x1<q.x1) return true;	
	else {
		return (p.x2<q.x2);
	}
}

int main() {
long long i,Max,S,br,SMax,STek,nx1,maxX, brObl;

//	freopen("rect.09.in", "rt", stdin);	
//	freopen("rect.00", "wt", stdout);
	cin>>N;
	bOts1=0; bOts2=0;
	for (i=1; i<=N;i++) {
		long long x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2; 
		if (x2<x1) swap(x1,x2);
		if (y1>0 || y2>0) {
			bOts1++;
			Ots1[bOts1].x=x1; Ots1[bOts1].x2=x2; Ots1[bOts1].h=abs(y2-y1); Ots1[bOts1].fl=0;
			bOts1++;
			Ots1[bOts1].x=x2; Ots1[bOts1].x2=x2; Ots1[bOts1].h=abs(y2-y1); Ots1[bOts1].fl=1;
		}
		else{
			bOts2++;
			Ots2[bOts2].x=x1; Ots2[bOts2].x2=x2; Ots2[bOts2].h=abs(y2-y1); Ots2[bOts2].fl=0;
			bOts2++;
			Ots2[bOts2].x=x2; Ots2[bOts2].x2=x2; Ots2[bOts2].h=abs(y2-y1); Ots2[bOts2].fl=1;
		}
	}
// Отгоре 	
	bObl=br=S=0;
	if ( bOts1>0 ) {
		sort (Ots1+1, Ots1+bOts1+1,fff);
		ms.insert(Ots1[1].h);
		S=STek=br=0; nx1=Ots1[1].x;
		for (i=2; i<=bOts1; i++) {
			long long d;
			if (ms.empty()) {
				ms.insert(Ots1[i].h); nx1=Ots1[i].x;
				continue;
			}
			it=ms.end(); it--;
			Max=*it;
			d=Ots1[i].x-Ots1[i-1].x;
			STek=STek+d*Max;
			S=S+d*Max;
			if (Ots1[i].fl==1) 
			IztrMax(Ots1[i].h);
			else
			ms.insert(Ots1[i].h);
			if (ms.empty()) {
				br++;
				Obl[br].S=STek;
				Obl[br].tip=0;
				Obl[br].x1=nx1;
				Obl[br].x2=Ots1[i].x;
	//			if (SMax<STek) 
	//				SMax=STek;
				STek=0;
			}
		}
		bObl=br;
		
	}
//	
	if ( bOts2 > 0 ) {
		sort (Ots2+1, Ots2+bOts2+1,fff);
	//	PechatOts2();
		ms.insert(Ots2[1].h);
		STek=br=0; nx1=Ots2[1].x;
		int bms=1;
		for (i=2; i<=bOts2; i++) {
			long long d;
			if (ms.empty()) {
				ms.insert(Ots2[i].h); nx1=Ots2[i].x;
				continue;
			}
			if (ms.empty()) {
				cout<<"ms";
				return 0;
			}
			it=ms.end(); it--;
			Max=*it;
			d=Ots2[i].x-Ots2[i-1].x;
			STek=STek+d*Max;
			S=S+d*Max;
			if (Ots2[i].fl==1) {
				if (ms.empty()) {
					cout<<"Gr "<<i<<endl;
					return 0;
				}
				else {
					bms--;
//					PechatMs();
					IztrMax(Ots2[i].h);
					if (FlEnd) {
						cout<<"FlEnd "<<i<<" "<<Ots2[i].h<<endl;	
						return 0;
					}
				}
			}
				else{
					bms++;
					ms.insert(Ots2[i].h);
				}
//			cout<<bms<<" ";
			if (ms.empty()) {
				br++; bObl++;
				if (bObl>100000) {
					cout<<bObl;
					return 0;
				}
				Obl[bObl].S=STek;
				Obl[bObl].tip=1;
				Obl[bObl].x1=nx1;
				Obl[bObl].x2=Ots2[i].x;
	//			if (SMax<STek) 
	//				SMax=STek;
				STek=0;
			}
		}

	}
	sort(Obl+1,Obl+bObl+1,fffObl);
//	PechatObl();
// 
	brObl=1;
	SMax=Obl[1].S; STek=Obl[1].S; maxX=Obl[1].x2;
	for (i=2;i<=bObl;i++){
		if (Obl[i].x1 < maxX) {
			STek=STek+Obl[i].S;
			if (maxX < Obl[i].x2)
				maxX = Obl[i].x2;
		}
		else 
		if (Obl[i].x1 > maxX) {
			if (SMax < STek)
				SMax=STek;
			STek=Obl[i].S;
			maxX=Obl[i].x2;
			brObl++;
		}
		else {
			if (Obl[i].tip == Obl[i-1].tip)
				STek=STek+Obl[i].S;
				else {
				if (SMax < STek)
					SMax=STek;
				STek=Obl[i].S;
				maxX=Obl[i].x2;
				brObl++;
				}
		}
	}
	if (SMax < STek)
		SMax=STek;
// 
	cout<<brObl<<endl;
	cout<<S<<endl;
	cout<<SMax<<endl;

	return 0;
}
