#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long u,v;
    cin>>u>>v;
    if(u>v or (v-u)%2==1){
        cout<<-1<<endl;
    }else if(u==v){
        if(u==0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl<<u<<endl;
        }
    }else{
        long long half=(v-u)/2;
        if((half^(half+u))==u){
            cout<<2<<endl<<half<<" "<<half+u<<endl;
        }else{
            cout<<3<<endl<<u<<" "<<half<<" "<<half<<endl;
        }
    }
return 0;
}