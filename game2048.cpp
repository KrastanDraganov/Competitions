#include<iostream>
#include<utility>
#define endl '\n'
#define MAXN 5
using namespace std;
void display_table(int table[][MAXN]){
    for(int i=0;i<3;++i){
        for(int i2=0;i2<3;++i2){
            cout<<table[i][i2]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void get_value(int table[][MAXN], int dir, int x, int y){
    if(dir%2){
        swap(x,y);
    }
    
}
void change_value(int table[][MAXN], bool& change){

}
void make_dub(int dub_table[][MAXN], int table[][MAXN]){
    for(int i=0;i<3;++i){
        for(int i2=0;i2<3;++i2){
            dub_table[i][i2]=table[i][i2];
        }
    }
}
void calc_res(int table[][MAXN], int steps, int sum, int dir, int& res, int& steps_res){
    bool check=false;
    if(dir==0){ //right
        
    }else if(dir==1){ //down
        
    }else if(dir==2){ //left
        
    }else{ //up
        
    }
    for(int i=0;i<3;++i){

    }
    if(sum>res or (sum==res and steps<steps_res)){
        /*if(sum==60){
            cout<<steps<<" "<<dir<<" "<<boolalpha<<check<<endl;
            display_table(table);
        }*/
        res=sum;
        steps_res=steps;
    }
    if(!check or steps==10){
        return;
    }
    for(int i=0;i<4;++i){
        int dub_table[MAXN][MAXN];
        make_dub(dub_table,table);
        calc_res(dub_table,steps+1,sum,i,res,steps_res);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int table[MAXN][MAXN];
    for(int i=0;i<3;++i){
        for(int i2=0;i2<3;++i2){
            cin>>table[i][i2];
        }
    }
    int res=0,steps_res=0;
    for(int i=0;i<4;++i){
        int dub_table[MAXN][MAXN];
        make_dub(dub_table,table);
        calc_res(dub_table,1,0,i,res,steps_res);
        //cout<<"res: "<<i<<" "<<res<<" "<<steps_res<<endl;
    }
    cout<<res<<" "<<steps_res<<endl;
return 0;
}