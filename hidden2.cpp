#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin>>m;
    while(m--){
        int f,g,k;
        string text,message;
        cin>>f>>g>>k>>text>>message;
        
        bool check=(text[0]==message[0]);
        int pos=k;
        for(int i=1;i<g and check;++i){
            while(pos<f and text[pos]!=message[i]){
                ++pos;
            }
            pos+=k;
            if(pos>f){
                check=false;
            }
        }
        cout<<(check ? "Yes" : "No")<<endl;
    }
return 0;
}