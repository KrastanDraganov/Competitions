#include<iostream>
#define endl '\n'
using namespace std;
void print_component(int b, int w){
    int add=(int) (b<w),x=0,y=0;
    for(int i=1;i<=2*min(b,w)+1;++i){
        cout<<i+add<<" "<<2<<endl;
        if((i+add)%2==1-add){
            ++x;
        }
        if((i+add)%2==add){
            ++y;
        }
        if(x==max(b,w) and y==min(b,w)){
            return;
        }
    }
    for(int i=1;i<=min(b,w);++i){
        cout<<2*i+add<<" "<<1<<endl;
        ++x;
        if(x==max(b,w)){
            return;
        }
    }
    for(int i=1;i<=min(b,w);++i){
        cout<<2*i+add<<" "<<3<<endl;
        ++x;
        if(x==max(b,w)){
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    for(int iq=0;iq<q;++iq){
        int b,w;
        cin>>b>>w;
        if(3*min(b,w)+1>=max(b,w)){
            cout<<"YES\n";
            print_component(b,w);
        }else{
            cout<<"NO\n";
        }
    }
return 0;
}