#include<iostream>
#include<stack>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    stack<int> first_row,second_row;
    int elf=0;
    for(int i=0;i<2*n;++i){
        char curr;
        cin>>curr;
        if(curr=='1'){
            first_row.push(elf++);
            cout<<"1\n";
        }else{
            if(second_row.empty()){
               while(!first_row.empty()){
                   int curr=first_row.top();
                   first_row.pop();
                   second_row.push(curr);
                   cout<<"1 2\n";
               } 
            }
            second_row.pop();
            cout<<"2\n";
        }
    }
return 0;
}