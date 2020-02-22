#include<iostream>
#include<string>
#include<vector>
#define endl '\n'
using namespace std;
vector<int> pos;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string map;
    cin>>map;
    int counter=0,curr=-1;
    string res=map;
    for(int i=0;i<map.size();++i){
        if(map[i]=='*'){
            pos.push_back(i);
            res[i]='L';
            ++counter;
        }
    }
    int all=1;
    for(int i=0;i<counter;++i){
        all*=3;
    }
    curr=((int)pos.size()==0 ? -1 : pos[pos.size()-1]);
    cout<<all<<endl;
    for(int i=0;i<all;++i){
        cout<<res<<endl;
        if(res[curr]=='L'){
            res[curr]='R';
        }else if(res[curr]=='R'){
            res[curr]='S';
        }else{
            res[curr]='L';
            for(int i2=pos.size()-2;i2>=0;--i2){
                if(res[pos[i2]]=='L'){
                    res[pos[i2]]='R';
                    break;
                }else if(res[pos[i2]]=='R'){
                    res[pos[i2]]='S';
                    break;
                }else{
                    res[pos[i2]]='L';
                }
            }
        }
    }
return 0;
}