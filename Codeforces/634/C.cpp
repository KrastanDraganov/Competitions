#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int skills[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>skills[i];
        }

        sort(skills,skills+n);
        int prev=-1,different=0,max_same=0,curr=0;
        for(int i=0;i<n;++i){
            if(skills[i]!=prev){
                max_same=max(max_same,curr);
                ++different;
                curr=0;
            }
            ++curr;
            prev=skills[i];
        }
        max_same=max(max_same,curr);
        if(different==max_same){
            cout<<max_same-1<<endl;
        }else{
            cout<<min(different,max_same)<<endl;
        }
    }
return 0;
}