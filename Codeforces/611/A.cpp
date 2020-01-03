#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        cout<<(23-x)*60+60-y<<endl;
    }
return 0;
}