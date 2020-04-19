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
        int n,a,b;
        cin>>n>>a>>b;
        
        string res="";
        for(int i=0;i<a;++i){
            if(i<b){
                res+=(i+'a');
            }else{
                res+=res[res.size()-1];
            }
        }

        int counter=0;
        for(int i=0;i<n;++i){
            cout<<res[counter++];
            if(counter==a){
                counter=0;
            }
        }
        cout<<endl;
    }
return 0;
}