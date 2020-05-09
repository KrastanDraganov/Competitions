#include<iostream>

#define endl '\n'

using namespace std;

void repair(int& counter){
    if(counter>0){
        ++counter;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n0,n1,n2;
        cin>>n0>>n1>>n2;
        repair(n0);
        repair(n1);
        repair(n2);
        for(int i=0;i<n2;++i){
            cout<<"1";
        }
        if(n2>0 and n0>0){
            n1-=2;
        }
        for(int i=0;i<n0;++i){
            cout<<"0";
        }
        for(int i=0;i<n1;++i){
            if(i%2==0){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
return 0;
}