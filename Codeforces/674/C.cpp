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
        int n;
        cin>>n;
        
        int div1=sqrt(n);
        int div2=n/div1;
        if(n%div1!=0){
            ++div2;
        }

        cout<<div1-1+div2-1<<endl;
    }
return 0;
}