#include<iostream>
#include<cstring>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int vote[MAXN][3],counter[55],original[55];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        s+='S';
        int num=0,curr=0;
        for(int i2=0;i2<s.size();++i2){
            if(s[i2]>='0' and s[i2]<='9'){
                num=10*num+s[i2]-'0';
            }else if(i2>0){
                if(curr==0){
                    ++counter[num];
                    ++original[num];
                }
                vote[i][curr++]=num;
            }
        }
    }
    bool two_max=
    do{

    }while();
return 0;
}