#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    getline(cin,s);
    
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(st.empty() or s[i]!=st.top()){
            st.push(s[i]);
        }else{
            st.pop();
        }
    }

    string res="";
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
return 0;
}