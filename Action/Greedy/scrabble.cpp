#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,d;
    string tiles;
    cin>>n>>d>>tiles;

    string res="";
    for(int i=0;i<n;++i){
        int l=max(i-d,0),r=min(n-1,i+d);
        int curr_ind=-1;
        if(l==i-d and tiles[l]!='u'){
            curr_ind=l;
        }else{
            for(int i2=l;i2<=r;++i2){
                if(tiles[i2]!='u'){
                    if(curr_ind==-1 or tiles[i2]<tiles[curr_ind]){
                        curr_ind=i2;
                    }
                }
            }
        }
        res+=tiles[curr_ind];
        tiles[curr_ind]='u';
    }
    cout<<res<<endl;
return 0;
}