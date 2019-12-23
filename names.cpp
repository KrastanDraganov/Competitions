#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string input,res;
    cin>>input;
    res=input;
    int counter=1;
    for(int i=1;i<n;++i){
        cin>>input;
        if(input==res){
            ++counter;
        }else{
            --counter;
            if(counter==0){
                res=input;
                counter=1;
            }
        }
    }
    cout<<res<<endl;
return 0;
}