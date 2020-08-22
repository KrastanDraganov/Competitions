#include<iostream>
#include<string>
#include<algorithm>

#define endl '\n'

using namespace std;

string find_best(string x, bool type){
    string res="";
    int n=(int)x.size();
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
    int n=(int)x.size(),m=(int)y.size();

    if(n<m or (n==m and x<y)){
        cout<<"-";
        swap(x,y);
        swap(n,m);
    }
    
    if(m<n){
        string old=y;
        y.assign(n-m,'0');
        y+=old;
    }
    
    string res="";
    for(int i=n-1;i>=0;--i){
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
    
    string s,t;
    cin>>s>>t;
    
    string maxs=find_best(s,false);
    string mint=find_best(t,true);
    
    print_diff(maxs,mint);
return 0;
}