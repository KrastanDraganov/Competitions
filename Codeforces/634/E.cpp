#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5,LIMIT=200;
int prefix[MAXN+3][LIMIT+3];
vector<int> pos[LIMIT+3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;

        for(int i=0;i<LIMIT;++i){
            pos[i].clear();
            prefix[0][i]=0;
        }

        for(int i=0;i<n;++i){
            int curr;
            cin>>curr;
            --curr;
            for(int i2=0;i2<LIMIT;++i2){
                prefix[i+1][i2]=prefix[i][i2];
            }
            ++prefix[i+1][curr];
            pos[curr].push_back(i);
        }

        int res=0;
        for(int i=0;i<LIMIT;++i){
            int m=(int)pos[i].size();
            res=max(res,m);
            for(int i2=0;i2<m/2;++i2){
                int l=pos[i][i2]+1,r=pos[i][m-i2-1]-1;
                for(int mid=0;mid<LIMIT;++mid){
                    if(mid!=i){
                        res=max(res,2*(i2+1)+prefix[r+1][mid]-prefix[l][mid]);
                    }
                }
            }
        }
        cout<<res<<endl;
    }
return 0;
}