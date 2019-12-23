#include<bits/stdc++.h>
using namespace std;
int dist[1005];
int next(int a,int b,int con){
    while(a<con and dist[a]<=b){
        b-=dist[a];
        a++;
    }
    return a;
}
int sol(int a,int con){
    int i=1,rut=0;
    while(i<=con){
        i=next(i,a,con);
        i=next(i,a,con)+1;
        rut++;
    }
    return rut;
}
int main(){
    int n,k,x=-1,y=0;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>dist[i];
        y+=dist[i];
    }
    while(x+1<y){
        int z=(x+y)/2;
        if(sol(z,n)>k){
            x=z;
        }else{
            y=z;
        }
    }
    cout<<y<<endl;
return 0;
}