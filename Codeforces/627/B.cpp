#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=5003;
int pos[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        memset(pos,-1,sizeof(pos));
        bool check=false;
        for(int i=0;i<n;++i){
            int num;
            cin>>num;
            if(pos[num]==-1){
                pos[num]=i;
            }else if(pos[num]+1<i){
                check=true;
            }
        }
        cout<<(check ? "YES" : "NO")<<endl;
    }
return 0;
}