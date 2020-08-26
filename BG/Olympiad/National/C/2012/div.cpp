#include<iostream>
#include<string>
#include<stack>

#define endl '\n'

using namespace std;

string is_div(string s, int divider){
    int num=0,rem=0,ind=0;
    string res="";
    
    while(ind<s.size() and num<divider){
        num=10*num+s[ind]-'0';
        ++ind;
    }
    
    res+=to_string(num/divider);
    rem=num%divider;
    
    while(ind<s.size()){
        num=10*rem+s[ind]-'0';
        res+=to_string(num/divider);
        rem=num%divider;
        ++ind;
    }
    return (rem==0 ? res : "-1");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    
    stack<int> divs;
    for(int i=2;i<2001;++i){
        string curr=is_div(s,i);
        if(curr!="-1"){
            cout<<i<<" "<<curr<<endl;
        }
    }
return 0;
}