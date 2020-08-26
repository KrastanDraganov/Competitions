#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=5e5+3;
bool check[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;

    int a=-1,b=-1;
    for(int i=0;i<n;i++){
         int num;
         cin>>num;
         if(check[num]){ 
            b=num;
         }
         check[num]=true;
    }

    for(int i=1;i<=n;i++){
         if(!check[i]){
             a=i;
             break;
         }
    }
    cout<<a<<" "<<b<<endl;
return 0;
}