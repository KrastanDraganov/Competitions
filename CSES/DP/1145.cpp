#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> dp;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;

        auto it=lower_bound(dp.begin(),dp.end(),num);
        if(it==dp.end()){
            dp.push_back(num);
        }else{
            *it=num;
        }
    }

    cout<<(int)dp.size()<<endl;
return 0;
}