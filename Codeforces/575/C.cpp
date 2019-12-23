#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    for(int qi=0;qi<q;++qi){
        int leftx=-100000,lefty=-100000,rightx=100000,righty=100000,n;
        cin>>n;
        for(int i=0;i<n;++i){
            int x,y;
            bool a,b,c,d;
            cin>>x>>y>>a>>b>>c>>d;
            if(!a){
                leftx=max(leftx,x);
            }
            if(!b){
                righty=min(righty,y);
            }
            if(!c){
                rightx=min(rightx,x);
            }
            if(!d){
                lefty=max(lefty,y);
            }
        }
        if(leftx<=rightx and lefty<=righty){
            cout<<1<<" "<<leftx<<" "<<lefty<<endl;
        }else{
            cout<<0<<endl;
        }
    }
return 0;
}