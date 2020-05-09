#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    while(n--){
        int curr;
        cin>>curr;

        vector<int> res;
        int mul=1;
        while(curr){
            if(curr%10!=0){
                res.push_back(mul*(curr%10));
            }
            curr/=10;
            mul*=10;    
        }
        cout<<(int)res.size()<<endl;
        for(int num : res){
            cout<<num<<" ";
        }
        cout<<endl;
    }
return 0;
}