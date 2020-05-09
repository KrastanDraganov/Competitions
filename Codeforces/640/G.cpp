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
        
        deque<int> res;
        res.push_back(3);
        res.push_back(1);
        res.push_back(4);
        res.push_back(2);
        for(int i=5;i<=n;++i){
            if(i%2==0){
                res.push_front(i);
            }else{
                res.push_back(i);
            }
        }
        
        if(n<4){
            cout<<"-1\n";
        }else{
            while(!res.empty()){
                cout<<res.front()<<" ";
                res.pop_front();
            }
            cout<<endl;
        }
    }
return 0;
}