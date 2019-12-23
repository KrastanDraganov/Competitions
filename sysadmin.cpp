#include<iostream>
#include<string.h>
#include<bitset>
#define endl '\n'
using namespace std;
unsigned int decode_ip(string ip, int shift){
    unsigned int mask=0,num=0;
    ip+='.';
    for(int i=0;i<ip.size();++i){
        if(ip[i]=='.'){
            mask<<=8;
            mask|=num;
            num=0;
            continue;
        }
        num=10*num+(ip[i]-'0');
    }
    num=mask>>(32-shift);
    mask<<=shift;
    mask|=num;
    return mask;
}
string display(unsigned int message){
    string res="";
    for(int i=0;i<4;++i){
        unsigned int ind=(message>>24);
        res+=(char)ind;
        message<<=8;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;
    string ip;
    cin.ignore();
    while(getline(cin,ip)){
        unsigned int message=decode_ip(ip,k);
        cout<<display(message);
    }
    cout<<endl;
return 0;
}