//Only 57/100 points

#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=5e5+3;
int perm[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string signs;
    cin>>n>>signs;
    
    int last_ind=-1,num=0;
    for(int i=0;i<n-1;++i){
        if(signs[i]=='<'){
            if(last_ind==-1){
                perm[i]=++num;
            }else{
                for(int i2=i;i2>=last_ind;--i2){
                    perm[i2]=++num;
                }
                last_ind=-1;
            }
        }else if(last_ind==-1){
            last_ind=i;
        }
    }
    
    if(signs[n-2]=='<'){
        perm[n-1]=n;
    }else if(last_ind!=-1){
        for(int i=n;i>=last_ind;--i){
            perm[i]=++num;
        }
    }
    
    for(int i=0;i<n;++i){
        cout<<perm[i]<<" ";
    }
    cout<<endl;
return 0;
}