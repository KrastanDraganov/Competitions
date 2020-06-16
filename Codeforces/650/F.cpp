#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=3e3+3;
int nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }

        int state=0,steps=0;
        while(state<2){
            
            ++steps;
        }
        cout<<steps<<endl;
    }
return 0;
}