#include<iostream>
#include<stack>
#include<utility>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char s;
    int num;
    stack<pair<int,int>> prev;
    cin>>s>>num;
    while(s!='='){
        if(s=='+'){
            prev.push({num,1});
        }else if(s=='-'){
            prev.push({-num,1});
        }else{
            prev.push({num,2});
        }
        cin>>s>>num;
    }
    
    while(!prev.empty()){
        pair<int,int> curr=prev.top();
        prev.pop();
        if(curr.second==1){
            num-=curr.first;
        }else{
            num/=curr.first;
        }
    }

    cout<<num<<endl;
return 0;
}