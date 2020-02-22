#include<iostream>
#include<string>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=13;
char field[MAXN][MAXN];
void shift_row(int ind, int n){
    for(int i=n-1;i>0;--i){
        swap(field[ind][i],field[ind][i-1]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    pair<int,int> player;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>field[i][i2];
            if(field[i][i2]=='S'){
                player={i,i2};
            }
        }
    }
    int commands,jumps=0;
    cin>>commands;
    for(int i=0;i<commands;++i){
        int pos,steps;
        cin>>pos>>steps;
        for(int i=0;i<steps;++i){
            shift_row(pos,m);
        }
        if(player.first>0 and field[player.first-1][player.second]=='-'){
            --player.first;
            ++jumps;
        }
    }
    if(player.first==0){
        cout<<"Win\n";
    }else{
        cout<<"Lose\n";
    }
    cout<<"Total Jumps: "<<jumps<<endl;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            if(i2==player.second and i==player.first){
                cout<<"S";
            }else if(i2==player.second and i==n-1){
                cout<<"0";
            }else{
                cout<<field[i][i2];
            }
        }
        cout<<endl;
    }
return 0;
}