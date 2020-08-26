#include<iostream>
#include<stack>
#include<string>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int k;
    cin>>s>>k;
    
    int counter=k,n=(int)s.size();
    stack<int> st;
    st.push('a');
    for(int i=0;i<n;i++){
        while(s[i]>st.top() and counter>0){
            st.pop();
            counter--;
        }
        st.push(s[i]);
    }
    while((int)st.size()>n+1-k){
        st.pop();
    }

    string res="";
    while((int)st.size()>1){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
return 0;
}