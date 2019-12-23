#include<bits/stdc++.h>
using namespace std;
int a[1<<1][1<<10][1<<10];
int main(){
    int n,m,x,y,z,h,h2=0;
    cin>>n>>m>>x>>y>>z;
    n*=1000;
    a[1][1][1]=n;
    for(int f=1;f<=x;f++){
        h2=0;
        for(int i=1;i<=f;i++){
            for(int j=1;j<=f;j++){
                if(a[f%2][i][j]>=m){
                    h=a[f%2][i][j]-m;
                    a[f%2][i][j]=m;
                    h/=4;
                    a[(f+1)%2][i][j]+=h;
                    a[(f+1)%2][i+1][j]+=h;
                    a[(f+1)%2][i][j+1]+=h;
                    a[(f+1)%2][i+1][j+1]+=h;
                }else{
                    h2++;
                }
                if(f==x && i==y && j==z){
                    cout<<a[f%2][i][j]<<endl;
                    return 0;
                }
                a[f%2][i][j]=0;
            }
        }
        if(h2==f*f){
            cout<<0<<endl;
            return 0;
        }
    }
    return 0;
}