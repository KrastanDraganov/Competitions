#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
const int MAXN=153;
bool check[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int pos=0;
    for(int i=0;i<n+(n/2);++i){
        for(int i2=0;i2<n;++i2){
            if(i2%4==pos){
                cout<<"#";
            }else{
                cout<<".";
            }
        }
        if(pos==0){
            pos=3;
        }else{
            --pos;
        }
        cout<<endl;
    }
return 0;
}