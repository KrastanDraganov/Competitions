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
        for(int div=1;div<=k;++div){
            if(k%div!=0){
                continue;
            }
            for(int groups=1;true;++groups){
                int curr=0;
                for(int i=0;i<26;++i){
                    curr+=(counter[i]/groups);
                }
                if(curr<div){
                    break;
                }
                res=max(res,groups*div);
            }
        }
        cout<<res<<endl;
    }
return 0;
}