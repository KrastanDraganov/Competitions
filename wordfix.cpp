#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=33;
int counter[MAXN];
vector<int> pos[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string wrong,correct;
    cin>>wrong>>correct;
    int n=(int)wrong.size();

    for(int i=0;i<n;++i){
        int curr=correct[i]-'a';
        pos[curr].push_back(i);
    }
    int res=0;
    for(int i=0;i<n;++i){
        int curr=wrong[i]-'a';
        int wanted=pos[curr][counter[curr]];
        if(i>wanted){
            res+=i-wanted;
        }
        ++counter[curr];
    }
    cout<<res<<endl;
return 0;
}