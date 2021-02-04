#include<iostream>
#include<vector>
#include<climits>

#define endl '\n'

using namespace std;

int query(int l, int r, vector<vector<int>>& rmq, vector<int>& log2){
    int range=log2[r-l+1];
    return min(rmq[l][range], rmq[r-(1<<range)+1][range]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    vector<int> log2(n+1, 0);
    for(int i=2;i<=n;++i){
        log2[i]=log2[i/2]+1;
    }

    vector<vector<int>> rmq(n, vector<int>(log2[n]+3, INT_MAX));
    for(int i=0;i<n;++i){
        rmq[i][0]=nums[i];
    }

    for(int len=1;len<=log2[n];++len){
        for(int i=0;i+(1<<len)<=n;++i){
            int j=i+(1<<(len-1));
            rmq[i][len]=min(rmq[i][len-1], rmq[j][len-1]);
        }
    }

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;

        cout<<query(l, r, rmq, log2)<<endl;
    }
return 0;
}