// Not solved - 23 points, wrong answer

#include<iostream>

#define endl '\n'

using namespace std;

const int MAXC=1e3+3;
int prefix[MAXC][MAXC];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,w,h;
    cin>>n>>w>>h;
    ++h;
    ++w;

    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        ++prefix[x][y];
    }

    int res=0;
    for(int i=1;i<MAXC;++i){
        for(int i2=1;i2<MAXC;++i2){
            prefix[i][i2]+=prefix[i-1][i2]+prefix[i][i2-1]-prefix[i-1][i2-1];

            int points=prefix[i][i2];
            if(i>=w and i2>=h){
                points=points-prefix[i-w][i2]-prefix[i][i2-h]+prefix[i-w][i2-h];
            }else if(i>=w){
                points-=prefix[i-w][i2];
            }else if(i2>=h){
                points-=prefix[i][i2-h];
            }

            res=max(res, points);
        }
    }

    cout<<res<<endl;
return 0;
}
