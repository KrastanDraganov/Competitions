#include<iostream>

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

        string res="";
        res+=s[0];
        for(int i=1;i<s.size();i+=2){
            res+=s[i];
        }
        cout<<res<<endl;
    }
return 0;
}