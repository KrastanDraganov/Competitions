#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e6+3;
int nextv[MAXN];
bool in_degree[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=1;i<n;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        nextv[from]=to;
        in_degree[to]=true;
    }

    int currv=-1;
    for(int i=0;i<n;++i){
        if(!in_degree[i]){
            currv=i;
            break;
        }
    }

    for(int i=0;i<n;++i){
        cout<<currv+1<<" ";
        currv=nextv[currv];
    }
    cout<<endl;
return 0;
}