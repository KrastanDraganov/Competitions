#include<iostream>
#include<utility>
#define endl '\n'
using namespace std;
pair<int,int> dirs[4]={{0,0},{1,0},{0,1},{1,1}};
int capacity[2][1003][1003];
int sol(int n, int m, int a, int b, int c){
    capacity[1][1][1]=n;
    for(int floor=1;floor<=a;++floor){
        int counter=0;
        bool state=(floor%2);
        for(int i=1;i<=floor;++i){
            for(int i2=1;i2<=floor;++i2){
                if(capacity[state][i][i2]>m){
                    int curr=(capacity[state][i][i2]-m)/4;
                    capacity[state][i][i2]=m;
                    for(pair<int,int> next : dirs){
                        capacity[!state][i+next.first][i2+next.second]+=curr;
                    }
                }else{
                    ++counter;
                }
                if(floor==a and i==b and i2==c){
                    return capacity[state][i][i2];
                }
                capacity[state][i][i2]=0;
            }
        }
        if(counter==floor*floor){
            return 0;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;
    cout<<sol(n*1000,m,a,b,c)<<endl;
return 0;
}