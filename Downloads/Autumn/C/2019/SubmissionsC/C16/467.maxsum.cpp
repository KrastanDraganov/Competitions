#include <bits/stdc++.h>
using namespace std;
int a[100000],kk[1000000],py[100000],wt[100000];
int n,k;
int f(int j){
    int max_d=0;
    for(int i=0;i<k;i++){
        if(kk[i]<=j){
            if(max_d<py[j-kk[i]]){
                max_d=py[j-kk[i]];
            }
        }
    }
    return max_d+a[j];
}
int f2(int j){
    int max_d=0;
    for(int i=0;i<k;i++){
        if(kk[i]+j<n){
            if(max_d<wt[j+kk[i]]){
                max_d=wt[j+kk[i]];
            }
        }
    }
    return max_d+a[j];
}
int main(){
    cin>>n>>k;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        cin>>kk[i];
    }
    sort(kk,kk+k);
    for(int i=kk[0];i<n;i++){
        py[i]=f(i);
    }
    for(int i=n-1-kk[0];i>0;i--){
        wt[i]=f2(i);
    }
    int max_otg=0;
    for(int i=0;i<n;i++){
        if(py[i]>0){
            for(int j=i;j<n;j++){
                if(wt[j]>0){
                    max_otg=max(max_otg,py[i]+wt[j]);
                }
            }
        }
    }


    /*for(int i=0;i<n;i++){
        cout<<py[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<wt[i]<<" ";
    }
    cout<<endl;

*/
    cout<<max_otg;
    return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2
*/

