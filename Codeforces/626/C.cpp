#include<iostream>
#include<stack>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string brackets;
    cin>>n>>brackets;
    int balance=0,res=0,start_ind=0,counter=0;
    bool check=true;
    for(int i=0;i<n;++i){
        if(brackets[i]=='('){
            ++balance;
            ++counter;
        }else{
            if(counter<=0){
                check=false;
            }
            --counter;
            --balance;
        }
        if(balance==0){
            if(!check){
                res+=(i-start_ind+1);
            }
            check=true;
            counter=0;
            start_ind=i+1;
        }
    }
    cout<<(balance==0 ? res : -1)<<endl;
return 0;
}