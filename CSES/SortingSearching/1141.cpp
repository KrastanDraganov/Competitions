#include<iostream>
#include<map>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int startp=0,res=0;
    map<int,int> ind;

    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;

        if(ind.count(curr)){
            startp=max(startp,ind[curr]+1);
        }

        res=max(res,i-startp+1);
        ind[curr]=i;
    }

    cout<<res<<endl;
return 0;
}