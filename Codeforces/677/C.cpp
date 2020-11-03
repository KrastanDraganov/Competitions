#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=3e5+3;
int fish[MAXN];

int find_dominant(int max_fish, int n){
    for(int i=0;i<n;++i){
        if(fish[i]!=max_fish){
            continue;
        }

        if(i>0 and fish[i-1]!=fish[i]){
            return i+1;
        }

        if(i<n-1 and fish[i+1]!=fish[i]){
            return i+1;
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        int max_fish=0;
        for(int i=0;i<n;++i){
            cin>>fish[i];
            max_fish=max(max_fish, fish[i]);
        }

        cout<<find_dominant(max_fish, n)<<endl;
    }
return 0;
}