#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,prev;
    cin>>n>>prev;

    long long res=0;
    for(int i=1;i<n;++i){
        int curr;
        cin>>curr;
        
        if(curr<prev){
            res+=(long long) (prev-curr);
            curr=prev;
        }

        prev=curr;
    }
    cout<<res<<endl;
return 0;
}