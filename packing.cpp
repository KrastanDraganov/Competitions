#include<bits/stdc++.h>
using namespace std;
string in[130];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string rez="";
    for(int i=0;i<n;i++){
        cin>>in[i];
        if(i>0){
            int i2=0,first=0,last=-1;
            for(int i3=0;i3<in[i-1].size();i3++){
                if(i2<in[i].size()){
                    if(in[i-1][i3]==in[i][i2]){
                        if(i2==0) first=i3;
                        i2++;
                    }else{
                        if(i2==1 and in[i-1][i3]!=in[i][i2-1]) i2=0;
                    }
                }else{
                    i2=0;
                }
            }
            if(i2>0) last=i2;
            if(last!=-1 && last!=in[i-1].size() && in[i-1].size()-first!=in[i].size()){
                for(int i3=last;i3<in[i].size();i3++){
                    rez+=in[i][i3];
                }
            }else{
                for(int i3=0;i3<in[i].size();i3++){
                    rez+=in[i][i3];
                }
            }
        }else{
            rez=in[i];
        }
    }
    cout<<rez<<endl;
return 0;
}