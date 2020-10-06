#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
bool forest[MAXN][MAXN];
int fenwick[MAXN][MAXN];

void update_tree(int x, int y, int val){
    while(x<MAXN){
        int y1=y;
        while(y1<MAXN){
            fenwick[x][y1]+=val;
            y1+=(y1 & -y1);
        }
        x+=(x & -x);
    }
}

int sum(int x, int y){
    int res=0;

    while(x>0){
        int y1=y;
        while(y1>0){
            res+=fenwick[x][y1];
            y1-=(y1 & -y1);
        }
        x-=(x & -x);
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            char curr;
            cin>>curr;
            
            forest[i][i2]=(curr=='*');
            if(forest[i][i2]){
                update_tree(i+1, i2+1, 1);
            }
        }
    }

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int x,y;
            cin>>x>>y;
            
            int prev=!forest[x-1][y-1];
            update_tree(x, y, prev-forest[x-1][y-1]);
            forest[x-1][y-1]=prev;
        }else{
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;

            cout<<sum(x2, y2)-sum(x2, y1-1)-sum(x1-1, y2)+sum(x1-1, y1-1)<<endl;
        }
    }
return 0;
}