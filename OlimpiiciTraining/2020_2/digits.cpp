#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i=0;i<3;++i){
        int k;
        string s;
        cin>>k>>s;
        
        int curr_pos=0;
        for(int i=2;i<=s.size();++i){
            curr_pos=(curr_pos+k)%i;
        }
        
        cout<<s[curr_pos]<<endl;
    }
return 0;
}