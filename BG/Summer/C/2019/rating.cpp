#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int counter=0,res=-1;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(x==res){
            ++counter;
        }else{
            --counter;
            if(counter==-1){
                res=x;
                counter=1;
            }
        }
    }
    cout<<res<<endl;
return 0;
}