#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000000],br,ngd[100000],otg;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    int g,h;
    for(int i=0;i<k;i++){
        cin>>g>>h;
        if((a[g]+h<=a[g+1] and a[g]+h>a[g-1]) or (a[g]+h<=a[g-1] and a[g]+h>a[g+1])){
            br++;
            a[g]+=h;
        }
    }
    /*int ng=0;
    for(int i=n-1;i>-0;i--){
        ngd[i]=ng;
        if(a[i]>ng){
            ng=a[i];
        }
    }*/
    for(int i=0;i<n;i++){
        otg+=a[i];
    }
    cout<<br<<" "<<otg;
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
