#include<iostream>
#include<string>
#include<algorithm>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=1003;
pair<int,int> cords[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            cords[i]={x,y};
        }
        sort(cords,cords+n);
        string res="";
        bool check=true;
        int currx=0,curry=0;
        for(int i=0;i<n;++i){
            if(cords[i].first<currx or cords[i].second<curry){
                check=false;
                break;
            }
            while(currx<cords[i].first){
                ++currx;
                res+="R";
            }
            while(curry<cords[i].second){
                ++curry;
                res+="U";
            }
        }
        if(check){
            cout<<"YES\n"<<res<<endl;
        }else{
            cout<<"NO\n";
        }
    }
return 0;
}