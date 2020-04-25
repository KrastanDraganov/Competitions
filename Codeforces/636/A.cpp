#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        int power=4,sum=3;
        while(n%sum>0){
            sum+=power;
            power*=2;
        }
        cout<<(n/sum)<<endl;
    }
return 0;
}