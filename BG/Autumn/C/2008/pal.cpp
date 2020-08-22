#include<iostream>
#include<string>
#include<algorithm>

#define endl '\n'

using namespace std;

int possible[]={10,1,2,5};
int counter[11];

bool comp(string s1, string s2){
    int n=(int)s1.size(),m=(int)s2.size();
    if(n==m){
        return s2<s1;
    }
    return n<m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    bool is_one=false;
    for(int i=0;i<n;++i){
        int input;
        cin>>input;
        if(input==1){
            is_one=true;
        }
        ++counter[input];
    }

    bool middle=false;
    string res="",add="";
    for(int num : possible){
        if(num==10 and counter[10]/2>0 and counter[1]>1){
            counter[1]-=2;
            for(int i=0;i<counter[10]/2;++i){
                res+="10";
            }
            res+="1";
            if(counter[10]%2==1 and counter[1]%2==0 and counter[2]%2==0 and counter[5]%2==0 and !middle){
                --counter[1];
                middle=true;
                add="10";
            }
        }else if(num==10 and counter[10]>0 and counter[1]==1 and !middle){
            --counter[1];
            middle=true;
            for(int i=0;i<=counter[10]/2;++i){
                add+="10";
            }
        }else if(num!=10){
            for(int i=0;i<counter[num]/2;++i){
                res+=to_string(num);
            }
            if(counter[num]%2==1 and !middle){
                middle=true;
                add=to_string(num);
            }
        }
    }
    
    if(res=="" and !middle){
        cout<<"No"<<endl;
        return 0;
    }
    if(middle){
        res+=add;
    }
    
    string rv=res;
    reverse(rv.begin(),rv.end());
    if(middle){
        res.erase(res.end()-1); 
        if((int)add.size()>2){
            res.erase(res.end()-3,res.end()-1);
        }
    }
    res+=rv;
    
    if(is_one){
        string res2="";
        for(int i=0;i<counter[10];++i){
            res2+="10";
        }
        res2+="1";
        if(comp(res,res2)){
            res=res2;
        }
    }
    cout<<res<<endl;
return 0;
}