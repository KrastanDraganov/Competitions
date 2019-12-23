#include<bits/stdc++.h>
using namespace std;
stack<char>st;
int main(){
    string s,rez="";
    getline(cin,s);
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(st.empty() or s[i]!=st.top()){
            st.push(s[i]);
        }else{
            st.pop();
        }
    }
    while(!st.empty()){
        rez+=st.top();
        st.pop();
    }
    reverse(rez.begin(),rez.end());
    cout<<rez<<endl;
return 0;
}