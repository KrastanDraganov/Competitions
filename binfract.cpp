#include<iostream>
#include<cstring>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e7+3;
int used[MAXN];
int calc_digits(int num){
    int res=0;
    while(num){
        ++res;
        num/=10;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string fraction;
    cin>>fraction;
    int num[2]={0,0},counter=0,digits=0;
    for(int i=0;i<fraction.size();++i){
        if(fraction[i]=='.'){
            ++counter;
        }else{
            num[counter]=10*num[counter]+fraction[i]-'0';
            if(counter==1){
                ++digits;
            }
        }
    }
    string res1=(num[0] ? "" : "0"),res2="";
    while(num[0]){
        res1+=(num[0]%2)+'0';
        num[0]/=2;
    }
    reverse(res1.begin(),res1.end());
    int power10=1;
    for(int i=0;i<digits;++i){
        power10*=10;
    }
    int pos=-1,ind=0;
    memset(used,-1,sizeof(used));
    while(num[1]){
        if(used[num[1]]!=-1){
            pos=used[num[1]];
            break;
        }
        used[num[1]]=ind++;
        num[1]*=2;
        res2+=(num[1]/power10)+'0';
        num[1]%=power10;
    }
    cout<<res1<<".";
    for(int i=0;i<res2.size();++i){
        if(i==pos){
            cout<<"(";
        }
        cout<<res2[i];
    }
    if(pos>-1){
        cout<<")";
    }
    cout<<endl;
return 0;
}