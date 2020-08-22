#include<iostream>
#include<utility>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
pair<int,int> cords[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int l,r;
        cin>>l>>r;
        r+=l;
        cords[i]={l,r};
    }

    sort(cords,cords+n);
    int res=0;
    pair<int,int> prev=cords[0];
    for(int i=1;i<n;++i){
        if(cords[i].first>=prev.first and cords[i].second<=prev.second){
            continue;
        }
        ++res;
        prev=cords[i];
    }
    cout<<res<<endl;
return 0;
}