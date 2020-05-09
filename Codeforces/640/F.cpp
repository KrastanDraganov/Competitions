#include<iostream>
#include<string>

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
        repair(n2);
        
        string res="";
        for(int i=0;i<n2;++i){
            res+="1";
        }
        if(n2>0 and n0>0){
            --n1;
        }
        for(int i=0;i<n0;++i){
            res+="0";
        }
        if(res.empty()){
            res+="1";
        }
        char curr=(res.back()=='0' ? '1' : '0');
        for(int i=0;i<n1;++i){
            res+=curr;
            curr=(curr=='1' ? '0' : '1');
        }
        cout<<res<<endl;
    }
return 0;
}