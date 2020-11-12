#include<iostream>
#include<unordered_set>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    unordered_set<long long> prev_sums;
    prev_sums.insert(0);

    int res=0;
    long long sum=0;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        sum+=curr;
        
        if(prev_sums.count(sum)){
            ++res;
            prev_sums.clear();
            prev_sums.insert(0);
            sum=curr;
        }

        prev_sums.insert(sum);
    }

    cout<<res<<endl;
return 0;
}