#include<iostream>
#include<map>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    map<int,pair<int,int>> inds;
    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            int target=x-nums[i]-nums[i2];
            if(inds.count(x-nums[i]-nums[i2])){
                pair<int,int> curr=inds[target];
                cout<<i+1<<" "<<i2+1<<" "<<curr.first<<" "<<curr.second<<endl;
                return 0;
            }
        }

        for(int i2=0;i2<i;++i2){
            inds[nums[i]+nums[i2]]={i+1,i2+1};
        }
    }

    cout<<"IMPOSSIBLE\n";
return 0;
}