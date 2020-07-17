#include<iostream>

#define endl '\n'

using namespace std;

int winner(string num){
    if((int)num.size()%2){
        for(int i=0;i<num.size();i+=2){
            if(num[i]<'9'){
                return 1;
            }
            if(num[i+1]>'0'){
                return 2;
            }
        }
        return 1;
    }
    if(num[0]>'1'){
        return 1;
    }
    for(int i=1;i<num.size();i+=2){
        if(num[i]<'9'){
            return 2;
        }
        if(num[i+1]>'0'){
            return 1;
        }
    }
    return 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin>>q;
    while(q--){
        string num;
        cin>>num;
        cout<<winner(num)<<endl;
    }
return 0;
}