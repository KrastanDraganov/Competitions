#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
stack<int>st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    string s,result="";
    cin>>s>>k;
    int counter=k;
    st.push('a');
    for(int i=0;i<s.size();i++){
        while(s[i]>st.top() and counter>0){
            st.pop();
            counter--;
        }
        st.push(s[i]);
    }
    while(st.size()>s.size()+1-k){
        st.pop();
    }
    while(st.size()>1){
        result+=st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    cout<<result<<endl;
return 0;
}