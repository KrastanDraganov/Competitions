#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=5e3+3;
int parent[MAXN];
vector<int> tree[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,d;
        cin>>n>>d;
        tree[1].clear();
        tree[1].push_back(1);
        for(int i=2;i<=n;++i){
            parent[i]=i-1;
            tree[i].clear();
            tree[i].push_back(i);
        }
        int curr_depth=n*(n-1)/2,floor=1,vertex=n,limit=2,counter=1;
        while(curr_depth>d and vertex>1){
            int diff=vertex-1-floor;
            if(curr_depth-diff<d){
                int new_diff=curr_depth-d;
                floor+=(diff-new_diff);
                parent[vertex]=floor;
                curr_depth=d;
            }else{
                parent[vertex]=tree[floor][counter/2];
                tree[floor+1].push_back(vertex);
                ++counter;
                curr_depth-=diff;
                if(counter==limit){
                    limit*=2;
                    counter=1;
                    ++floor;
                }
                --vertex;
            }
        }
        if(curr_depth>d or curr_depth<d){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            for(int i=2;i<=n;++i){
                cout<<parent[i]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}
//10 46