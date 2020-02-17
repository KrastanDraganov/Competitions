#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN=4e5+3;
int counter[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int queries,x,res=0;
    cin>>queries>>x;
    while(queries--){
        int added;
        cin>>added;
        ++counter[added%x];
        while(counter[res%x]>0){
            --counter[res%x];
            ++res;
        }
        cout<<res<<endl;
    }
return 0;
}