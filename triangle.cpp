#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
vector<int> r,g,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        char color;
        int len;
        cin>>color>>len;
        switch(color){
            case 'r' : r.push_back(len); break;
            case 'g' : g.push_back(len); break;
            case 'b' : b.push_back(len); break;
            default : cout<<"kzl\n"; break;
        }
    }
    sort(b.begin(),b.end());
    long long counter=0;
    for(int x : r){
        for(int y : g){
            int mini=abs(x-y),maxi=x+y;
            int l=upper_bound(b.begin(),b.end(),mini)-b.begin(),r=lower_bound(b.begin(),b.end(),maxi)-b.begin();
            counter+=((long long)r-l);
        }
    }
    cout<<counter<<endl;
return 0;
}