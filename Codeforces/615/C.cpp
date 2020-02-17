#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int num;
        cin>>num;
        int res[3],counter=0;
        res[2]=num;
        for(int i=2;i*i<=num and counter<2;++i){
            if(num%i==0){
                res[counter++]=i;
                num/=i;
                res[2]/=i;
            }
        }
        if(counter<2 or res[2]<2 or res[2]==res[1] or res[2]==res[0]){
            cout<<"NO\n";
        }else{
            cout<<"YES\n"<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
        }
    }
return 0;
}