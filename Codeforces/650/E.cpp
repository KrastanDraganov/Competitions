#include<iostream>

#define endl '\n'

using namespace std;

int counter[27];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        string s;
        cin>>n>>k>>s;

        for(int i=0;i<26;++i){
            counter[i]=0;
        }
        for(char curr : s){
            ++counter[curr-'a'];
        }
        
        int res=0;
        for(int i=0;i<26;++i){
            res+=counter[i];
            if(counter[i]%2==1){
                --res;
            }
        }
        cout<<res<<endl;
    }
return 0;
}