#include<iostream>
#include<deque>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        deque<int> candies;
        for(int i=0;i<n;++i){
            int curr;
            cin>>curr;
            candies.push_back(curr);
        }

        int moves=0,alice=0,bob=0,prev=0;
        while(!candies.empty()){
            ++moves;
            int curr=0;
            if(moves%2==1){
                while(!candies.empty() and curr<=prev){
                    curr+=candies.front();
                    candies.pop_front();
                }
                alice+=curr;
            }else{
                while(!candies.empty() and curr<=prev){
                    curr+=candies.back();
                    candies.pop_back();
                }
                bob+=curr;
            }
            prev=curr;
        }
        cout<<moves<<" "<<alice<<" "<<bob<<endl;
    }
return 0;
}