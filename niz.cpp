#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
bool check(string x){
    int curr=0,counter1=0,counter0=0,nulls[2]={-1,-1};
    for(int i=1;i<x.size();++i){
        if(x[i]=='1' and x[i-1]=='1'){
            return false;
        }else if(x[i]=='1'){
            ++counter1;
            if(nulls[0]==-1){
                nulls[0]=curr;
            }else if(nulls[1]==-1){
                nulls[1]=curr;
            }else if(curr!=nulls[1] and curr!=nulls[0]){
                return false;
            }
            curr=0;
        }else{
            ++counter0;
            ++curr;
        }
    }
    if(curr>0){
        if(nulls[0]==-1){
            nulls[0]=curr;
        }else if(nulls[1]==-1){
            nulls[1]=curr;
        }else if(curr!=nulls[1] and curr!=nulls[0]){
            return false;
        }
    }
    if(nulls[1]==-1){
        nulls[1]=nulls[0];
    }
    if(nulls[1]<nulls[0]){
        swap(nulls[1],nulls[0]);
    }
    return (x.size()>0 and x[0]=='1' and counter1<=counter0 and (nulls[1]-nulls[0]==1 or nulls[1]-nulls[0]==0));
}
string reduce(string x){
    string res="";
    int curr=0,a=-1,acounter=1,b=-1,bcounter=1;
    for(int i=1;i<x.size();++i){
        if(x[i]=='0'){
            ++curr;
        }else{
            if(a==-1){
                a=curr;
            }else if(curr==a){
                ++acounter;
            }else if(b==-1){
                b=curr;
            }else if(curr==b){
                ++bcounter;
            }
            curr=0;
        }
        //cout<<i<<" "<<x[i]<<" "<<curr<<" "<<a<<" "<<acounter<<" "<<b<<" "<<bcounter<<endl;
    }
    if(curr>0){
        if(a==-1){
            a=curr;
        }else if(curr==a){
            ++acounter;
        }else if(b==-1){
            b=curr;
        }else if(curr==b){
            ++bcounter;
        }
    }
    int comp;
    if(acounter<bcounter){
        comp=a;
    }else if(bcounter<acounter){
        comp=b;
    }else{
        comp=min(a,b);
    }
    //cout<<comp<<" "<<acounter<<" "<<bcounter<<endl;
    curr=0;
    for(int i=1;i<x.size();++i){
        if(x[i]=='0'){
            ++curr;
        }else if(curr==comp){
            res+='1';
            curr=0;
        }else{
            res+='0';
            curr=0;
        }
    }
    if(curr>0){
        if(curr==comp){
            res+='1';
            curr=0;
        }else{
            res+='0';
            curr=0;
        }
    }
    return res;
}
string shift(string x){
    string res="";
    int counter0=0;
    bool check=false;
    for(int i=0;i<x.size();++i){
        if(!check and x[i]=='0'){
            ++counter0;
        }else if(!check and x[i]=='1'){
            check=true;
            res+='1';
        }else if(check){
            res+=x[i];
        }
    }
    for(int i=0;i<counter0;++i){
        res+='0';
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int counter=0;
    while(check(s)){
        ++counter;
        //cout<<s<<" ";
        s=reduce(s);
        //cout<<s<<" ";
        if(s[0]=='0'){
            s=shift(s);
        }
        //cout<<s<<endl;
    }
    cout<<counter<<" ";
    if(s.size()>50){
        for(int i=0;i<50;++i){
            cout<<s[i];
        }
        cout<<endl;
    }else{
        cout<<s<<endl;
    }
return 0;
}