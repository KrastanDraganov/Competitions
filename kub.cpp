#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
vector<int> piles[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        if(i>0){
            piles[i]=piles[i-1];
        }
        char type;
        cin>>type;
        if(type=='+'){
            int num;
            cin>>num;
            piles[i].push_back(num);
        }else{
            piles[i].pop_back();
        }
    }

    int q;
    cin>>q;
    while(q--){
        int child;
        cin>>child;
        --child;
        for(int curr : piles[child]){
            cout<<curr<<" ";
        }
        cout<<endl;
    }
return 0;
}