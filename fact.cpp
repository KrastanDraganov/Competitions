#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    int n;
    cin>>n;
    int counter=0;
    for(int i=2;i<=n;++i){
        int num=i;
        for(int i2=2;i2*i2<=i;++i2){
            if(num%i2==0){
                while(num%i2==0){
                    ++counter;
                    num/=i2;
                }
            }
        }
        if(num>1){
            ++counter;
        }
    }
    cout<<counter<<endl;
return 0;
}