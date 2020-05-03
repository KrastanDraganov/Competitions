#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int res=0,counter=-1,prev=-1;
    for(int i=0;i<s.size();++i){
        if(i>0 and s[i]!=s[i-1]){
            cout<<counter<<" "<<prev<<" "<<res<<endl;
            if(prev==-1){
                prev=counter;
            }else{
                prev=abs(counter-prev);
                res+=prev;
            }
            counter=-1;
        }
        ++counter;
    }
    cout<<res<<endl;
return 0;
}