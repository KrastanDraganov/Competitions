#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        string s;
        cin>>s;
        int counter=0,res=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='L'){
                ++counter;
            }else{
                res=max(res,counter);
                counter=0;
            }
        }
        res=max(res,counter);
        cout<<res+1<<endl;
    }
return 0;
}