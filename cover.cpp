#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;
const int MAXN = 1e6+3;
int cover[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>cover[i];
    }
    int ind=n-1,border=1;
    while(ind>=0){
        int curr=cover[ind];
        cover[ind]+=border;
        stack<int> started;
        started.push(ind);
        for(int i=0;i<curr and ind>0;++i){
            if(curr[--ind]==0){
                cover[ind]=border++;
            }else{
                
            }
        }
        ++border;
        --ind;
    }
    for(int i=0;i<n;++i){
        cout<<cover[i]<<endl;
    }
return 0;
}