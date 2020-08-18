#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=30;
int counter[MAXN][MAXN];
bool added[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;

    for(int i=1;i<s1.size();++i){
        ++counter[s1[i-1]-'A'][s1[i]-'A'];
    }

    int res=0;
    for(int i=1;i<s2.size();++i){
        int ind1=s2[i-1]-'A',ind2=s2[i]-'A';
        if(!added[ind1][ind2]){
            res+=counter[ind1][ind2];
            added[ind1][ind2]=true;
        }
    }
    cout<<res<<endl;
return 0;
}