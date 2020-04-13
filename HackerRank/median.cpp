#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<iomanip>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    priority_queue<int> first_half;
    priority_queue<int,vector<int>,greater<int>> second_half;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        
        if(!first_half.empty() and curr>=first_half.top()){
            second_half.push(curr);
        }else{
            first_half.push(curr);
        }
        if(abs((int)first_half.size()-(int)second_half.size())>1){
            if(first_half.size()>second_half.size()){
                curr=first_half.top();
                first_half.pop();
                second_half.push(curr);
            }else{
                curr=second_half.top();
                second_half.pop();
                first_half.push(curr);
            }
        }
        
        double median=0.0;
        if(i%2==0){
            if(first_half.size()>second_half.size()){
                median=(double)first_half.top();
            }else{
                median=(double)second_half.top();
            }
        }else{
            median=((double)first_half.top()+(double)second_half.top())/2.0;
        }
        cout<<fixed<<setprecision(1)<<median<<endl;
    }
return 0;
}
