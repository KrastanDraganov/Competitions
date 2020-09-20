#include<iostream>
#include<algorithm>
#include<utility>
#include<set>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
pair<int,int> movies[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    
    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        movies[i]={to,from};
    }
    sort(movies,movies+n);

    multiset<int> endings;
    for(int i=0;i<k;++i){
        endings.insert(0);
    }

    int res=0;
    for(int i=0;i<n;++i){
        auto it=endings.upper_bound(movies[i].second);
        if(it!=endings.begin()){
            endings.erase(--it);
            endings.insert(movies[i].first);
            ++res;
        }
    }

    cout<<res<<endl;
return 0;
}