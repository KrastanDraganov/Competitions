#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    while(n!=1){
        cout<<n<<" ";
        if(n & 1){
            n=3*n+1;
        }else{
            n/=2;
        }
    }
    cout<<"1\n";
return 0;
}