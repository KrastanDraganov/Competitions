#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
long long counter[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string seq;
    for(int i=1;i<=n;++i){
        seq+=to_string(i);
    }
    for(int i=0;i<seq.size();++i){
        switch(seq[i]){
            case '2' : ++counter[0]; break;
            case '0' : counter[1]+=counter[0]; break;
            case '1' : counter[2]+=counter[1]; break;
            case '4' : counter[3]+=counter[2]; break;
        }
    }
    cout<<counter[3]<<endl;
return 0;
}