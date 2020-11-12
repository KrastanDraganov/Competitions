#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n,x;
        cin>>n>>x;
        
        int floor=1;
        n-=2;
        if(n>0){
            floor+=(n/x);
            if(n%x!=0){
                ++floor;
            }
        }
        
        cout<<floor<<endl;
    }
return 0;
}