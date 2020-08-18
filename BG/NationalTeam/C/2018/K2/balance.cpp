#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e6+3,STEP=1e6;
int counter[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int curr=0;
    long long res=0;
    counter[STEP]=1;
    for(int i=0;i<s.size();++i){
        if(s[i]=='1'){
            ++curr;
        }else{
            --curr;
        }
        int ind=curr+STEP;
        res+=(long long) counter[ind];
        ++counter[ind];
    }
    cout<<res<<endl;
return 0;
}