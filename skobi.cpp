#include<iostream>
#include<cstring>
#include<stack>
#define endl '\n'
using namespace std;
int converts(char c){
    if(c=='('){
        return 1;
    }else if(c==')'){
        return -1;
    }else if(c=='['){
        return 2;
    }else if(c==']'){
        return -2;
    }else if(c=='{'){
        return 3;
    }else if(c=='}'){
        return -3;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input;
    cin>>input;
    int res1=0;
    stack<int> open;
    for(int i=0;i<input.size();++i){
        int curr=converts(input[i]);
        if(curr>0){
            open.push(curr);
        }else{
            curr*=-1;
            while(!open.empty() and curr!=open.top()){
                ++res1;
                open.pop();
            }
            if(!open.empty()){
                open.pop();
            }else{
                ++res1;
            }
        }
    }
    res1+=open.size();
    cout<<res1<<endl;
return 0;
}