#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin>>s;
    
    int milk=0,hazelnut=0,raisin=0;
    for(int i=3;i<s.size();i+=8){
        int num=0;
        for(int i2=i;i2<i+4;++i2){
            num=10*num+(s[i2]-'0');
        }
        if(num%2==0){
            ++milk;
        }else if(num%3==0){
            ++hazelnut;
        }else{
            ++raisin;
        }
    }
    
    cout<<milk<<" "<<hazelnut<<" "<<raisin<<endl;
return 0;
}