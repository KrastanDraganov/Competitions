#include<iostream>
#include<map>
#include<set>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,n;
    cin>>x>>n;

    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    map<int,int> intervals;
    intervals[x]=1;

    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;

        auto it=lights.lower_bound(curr);
        int r=*it;

        --it;
        int l=*it;

        --intervals[r-l];
        if(intervals[r-l]==0){
            intervals.erase(r-l);
        }

        ++intervals[r-curr];
        ++intervals[curr-l];
        lights.insert(curr);

        auto res=--intervals.end();
        cout<<(res->first)<<" ";
    }
    cout<<endl;
return 0;
}