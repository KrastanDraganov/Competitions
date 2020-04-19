#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=13;
int sudoku[MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin>>tests;
    while(tests--){
        for(int i=0;i<9;++i){
            for(int i2=0;i2<9;++i2){
                char curr;
                cin>>curr;
                sudoku[i][i2]=curr-'0';
            }
        }

        for(int blocks=0;blocks<3;++blocks){
            for(int x=blocks,y=blocks*3;y<(blocks+1)*3;x+=3,++y){
                sudoku[x][y]+=(sudoku[x][y]==9 ? -1 : 1);
            }
        }

        for(int i=0;i<9;++i){
            for(int i2=0;i2<9;++i2){
                cout<<sudoku[i][i2];
            }
            cout<<endl;
        }
    }
return 0;
}