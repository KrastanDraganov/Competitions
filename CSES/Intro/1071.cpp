#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    
    while(tests--){
        int x,y;
        cin>>x>>y;

        long long target=max(x,y);
        long long limit=target*target;
        long long res=limit;

        if(target & 1){
            if(target==x){
                limit-=(target-1);
                res=limit-(target-y);
            }else{
                res=limit-x+1;
            }
        }else{
            if(target==y){
                limit-=(target-1);
                res=limit-(target-x);
            }else{
                res=limit-y+1;
            }
        }

        cout<<res<<endl;
    }
return 0;
}