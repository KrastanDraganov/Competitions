#include<iostream>
#include<math.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        cin>>n>>k;
        --k;
        int pos1=-1,pos2=-1;
        for(int i=n-2;i>=0;--i){
            if(k<n-i-1){
                pos1=i;
                pos2=n-k-1;
                break;
            }
            k-=n-i-1;
        }
        for(int i=0;i<n;++i){
            if(i!=pos1 and i!=pos2){
                cout<<"a";
            }else{
                cout<<"b";
            }
        }
        cout<<endl;
    }
return 0;
}