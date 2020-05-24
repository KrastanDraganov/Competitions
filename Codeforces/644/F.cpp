#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=13;
string s[MAXN];

string find_res(int n, int m){
    if(n==1){
        return s[0];
    }
    for(int i=0;i<m;++i){
        string comp=s[0];
        for(int letter=0;letter<26;++letter){
            comp[i]=letter+'a';
            bool is_res=true;
            for(int i2=1;i2<n and is_res;++i2){
                bool is_diff=false,check=true;
                for(int i3=0;i3<m;++i3){
                    if(s[i2][i3]!=comp[i3]){
                        if(is_diff){
                            check=false;
                            break;
                        }
                        is_diff=true;
                    }
                }
                is_res=check;
            }
            if(is_res){
                return comp;
            }
        }
    }
    return "";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i){
            cin>>s[i];
        }

        string res=find_res(n,m);
        if(res.empty()){
            cout<<-1<<endl;
        }else{
            cout<<res<<endl;
        }
    }
return 0;
}