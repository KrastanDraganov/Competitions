#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
struct elem {
    int h;
    int ind;
};
elem a[1000001];
long long int ans[1000001];
vector <int> pr;
bool cmp (elem a, elem b) {
     if (a.h<b.h) return true;
     return false;
}
int main () {
    int n,min1=2000000,max1=-1,dif,dif1,i,j,min2,max2;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i].h);
        a[i].ind=i;
        }
    sort(a,a+n,cmp);
    for (i=0; i<n; i++) {
        min2=min1; max2=max1;
        for (j=i; j<n; j++) {
            if (a[j].h!=a[i].h) break;
            if (max1==-1) ans[a[j].ind]=-2;
            else { if (a[j].ind>min1) dif=a[j].ind-min1;
                   else dif=min1-a[j].ind;
                   if (a[j].ind>max1) dif1=a[j].ind-max1;
                   else dif1=max1-a[j].ind;
                   if (dif>=dif1) ans[a[j].ind]=min1;
                   else ans[a[j].ind]=max1; }
            if (a[j].ind<min2) min2=a[j].ind;
            if (a[j].ind>max2) max2=a[j].ind;
            }
        min1=min2; max1=max2; i=j-1;
        }
    printf("%d ",ans[0]+1);
    for (i=1; i<n; i++) {
        printf("%d ",ans[i]+1);
        }
    cout << endl ;
    return 0;
}


