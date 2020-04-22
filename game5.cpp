#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXS=1e6+3,MAXN=203;
vector<int> candies[2];
bool dp[2][MAXS];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s,player;
    cin>>s>>player;
    --player;
    for(int i=0;i<2;++i){
        int n;
        cin>>n;
        while(n--){
            int curr;
            cin>>curr;
            candies[i].push_back(curr);
        }
    }

    for(int pile=1;pile<=s;++pile){
        for(int turn=0;turn<2;++turn){
            for(int curr : candies[turn]){
                if(curr<=pile and !dp[1-turn][pile-curr]){
                    dp[turn][pile]=true;
                    break;
                }
            }
        }
    }

    cout<<dp[player][s]<<endl;
return 0;
}