#include<iostream>

#define endl '\n'

using namespace std;

int hexagon[7],rotations[2][7];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    bool is_res=true;
    int wrong=-1;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<6;++i2){
            cin>>hexagon[i2];
            rotations[1][i2]=1e9;
        }

        for(int i2=3;i2<6;++i2){
            int top=hexagon[i2],down=hexagon[i2-3];
            rotations[1][top]=min(rotations[1][top],rotations[0][down]+i2-3);
            rotations[1][down]=min(rotations[1][down],rotations[0][top]+6-i2);
        }

        bool check=true;
        for(int i2=0;i2<6;++i2){
            if(rotations[1][i2]!=1e9){
                check=false;
                break;
            }
        }
        if(check and is_res){
            is_res=false;
            wrong=i;
        }
        
        for(int i2=0;i2<6;++i2){
            rotations[0][i2]=rotations[1][i2];
        }
    }

    if(is_res){
        int res=1e9;
        for(int i=0;i<6;++i){
            res=min(res,rotations[0][i]);
        }
        cout<<res<<endl;
    }else{
        cout<<"NO "<<wrong+1<<endl;
    }
return 0;
}