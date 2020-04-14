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
        int n;
        string s;
        cin>>n>>s;
        string res1="1",res2="1";
        for(int i=1;i<n;++i){
            if(s[i]=='0'){
                res1+="0";
                res2+="0";
            }else if(s[i]=='1'){
                if(res1==res2){
                    res1+="0";
                    res2+="1";
                    if(res1<res2){
                        swap(res1,res2);
                    }
                }else{
                    res1+="0";
                    res2+="1";
                }
            }else{
                if(res1==res2){
                    res1+="1";
                    res2+="1";
                }else{
                    res1+="0";
                    res2+="2";
                }
            }
        }
        cout<<res1<<endl<<res2<<endl;
    }
return 0;
}