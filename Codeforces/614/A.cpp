#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXK=1003;
int closed[MAXK];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,s,k;
        cin>>n>>s>>k;
        for(int i=0;i<k;++i){
            cin>>closed[i];
        }
        sort(closed,closed+k);
        for(int i=0;i<=k;++i){
            if((s-i>=1 and !binary_search(closed,closed+k,s-i)) or (s+i<=n and !binary_search(closed,closed+k,s+i))){
                cout<<i<<endl;
                break;
            }
        }
    }
return 0;
}