#include<iostream>
#include<string>
#include<algorithm>
#define endl '\n'
using namespace std;
string find_best(string x, bool type){
    string res="";
    int n=x.size();
    for(int i=0;i<n;++i){
        if(x[0]=='0'){
            x=x.substr(1,n)+x[0];
            continue;
        }
        if(res==""){
            res=x;
        }else if(!type){
            res=max(res,x);
        }else{
            res=min(res,x);
        }
        x=x.substr(1,n)+x[0];
    }
    return res;
}
void print_diff(string x, string y){
    if(x.size()<y.size() or (x.size()==y.size() and x<y)){
        cout<<"-";
        swap(x,y);
    }
    if(y.size()<x.size()){
        string old=y;
        y.assign(x.size()-y.size(),'0');
        y+=old;
    }
    string res="";
    for(int i=x.size()-1;i>=0;--i){
        int xd=x[i]-'0',yd=y[i]-'0';
        if(yd>xd){
            xd+=10;
            --x[i-1];
        }
        if(i==0 and xd-yd==0) break;
        res+=(xd-yd+'0');
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t,maxs,mint;
    cin>>s>>t;
    maxs=find_best(s,false);
    mint=find_best(t,true);\
    print_diff(maxs,mint);
return 0;
}