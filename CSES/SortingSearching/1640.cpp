#include<iostream>
#include<map>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x;
    cin>>n>>x;

    map<int,int> ind;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        
        if(ind.count(x-curr)){
            cout<<ind[x-curr]<<" "<<i+1<<endl;
            return 0;
        }
        ind[curr]=i+1;
    }

    cout<<"IMPOSSIBLE\n";
return 0;
}