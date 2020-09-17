#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    multiset<int> prices;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        prices.insert(curr);
    }

    for(int i=0;i<m;++i){
        int max_price;
        cin>>max_price;
        
        auto it=prices.upper_bound(max_price);
        if(it==prices.begin()){
            cout<<"-1\n";
        }else{
            --it;
            cout<<*it<<endl;
            prices.erase(it);
        }
    }
return 0;
}