#include<iostream>
#define endl '\n'
using namespace std;
bool is_prime(int num){
    for(int i=2;i*i<=num;++i){
        if(num%i==0){
            return false;
        }
    }
    return num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b;
    cin>>a>>b;
    bool check=false;
    for(int i=a;i<=b;++i){
        int sum=0,num=i;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        if(sum>9 and is_prime(sum) and is_prime(i)){
            cout<<i<<" ";
            check=true;
        }
    }
    if(!check){
        cout<<0;
    }
    cout<<endl;
return 0;
}