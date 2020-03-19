#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long u,v;
    cin>>u>>v;
    if(u>v){
        cout<<-1<<endl;
    }else if(u==v){
        if(u==0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl<<u<<endl;
        }
    }else if((v-u)%2==0){
        v-=u;
        cout<<3<<endl<<u<<" "<<(v/2)<<" "<<(v/2)<<endl;
    }else{
        
    }
return 0;
}