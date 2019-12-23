#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define taskname "merlin"

int n, ans;
long long sum;
vector<long long> p;
vector<long long> s;
bool fl;
int main()
{
//    freopen(taskname".in", "r", stdin);
//    freopen(taskname".out", "w", stdout);
    cin >> n;
    vector<long long> a(n+1);
    p.resize(n+1); 
    fl=true;
    a[0]=0;
    cin>>a[1];
    sum=p[1]=a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        sum+=a[i];
        if (a[i]!=a[i-1]) {
        	fl=false;
		}
	}
	if (fl) {
		cout<<0<<endl;
		return 0;
	}
    sort(a.begin(), a.end());
    for (int i = n; i >=1; i--)  {
        if ( sum/(i-1) >= a[i-1]) {
        	ans=i;
        	break;
		}
    }
    cout << n-ans+1 << endl;
    return 0;
}
/*
7
2 3 3 4 5 6 7

4 
3 3 3 3

*/
