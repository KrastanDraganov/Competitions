#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int nulls=0,ones=0,res=0;
    for(char curr : s){
        if(curr=='0'){
            ++nulls;
        }else{
            ++ones;
        }

        if(nulls!=ones){
            continue;
        }

        ++res;
        nulls=ones=0;
    }

    cout<<res<<endl;
return 0;
}