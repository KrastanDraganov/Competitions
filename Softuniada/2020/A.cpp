#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n,m,x,y;
    long long t;
    cin>>n>>m>>x>>y>>t;
    double sum=((t*(t-1))/2)*x+t*n-t*m;
    if(sum>=y){
        cout<<"Have a nice ride!\n";
    }else{
        cout<<"Work harder!\n";
    }
return 0;
}