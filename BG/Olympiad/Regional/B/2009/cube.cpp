//Only 70/100 points

#include<iostream>
#include<queue>
#include<utility>
#include<string>

#define endl '\n'

using namespace std;

const int MAXN=11;

struct Cube {
    int top,bottom,right,left,front,back;
    
    void read(){
        cin>>front>>back>>top>>right>>bottom>>left;
    }

    int move(int dir){
        int curr=bottom;
        switch(dir){
            case 0:
                bottom=left;
                left=top;
                top=right;
                right=curr;
                break;
            case 1:
                bottom=right;
                right=top;
                top=left;
                left=curr;
                break;
            case 2:
                bottom=back;
                back=top;
                top=front;
                front=curr;
                break;
            case 3:
                bottom=front;
                front=top;
                top=back;
                back=curr;
                break;
            default:
                cout<<"kzl\n";
                break;
        }
        return bottom;
    }
};

pair<int,int> dirs[4]={{0,-1},{0,1},{-1,0},{1,0}};
bool occupied[MAXN][MAXN];
int dist[MAXN][MAXN];
Cube start_cube;

int calc_res(int dir, pair<int,int> currp, pair<int,int> startp, Cube& moved_cube, int counter){
    int res=1e9;
    if(currp==startp){
        moved_cube=start_cube;
        res=start_cube.bottom;
    }else{
        for(int i=0;i<4;++i){
            int prevx=currp.first-dirs[i].first;
            int prevy=currp.second-dirs[i].second;
            if(prevx>=0 and prevx<8 and prevy>=0 and prevy<8){
                if(dist[prevx][prevy]+1==dist[currp.first][currp.second]){
                    Cube next_cube;
                    int sum=calc_res(i,{prevx,prevy},startp,next_cube,counter+1)+next_cube.bottom;
                    if(sum<res){
                        res=sum;
                        moved_cube=next_cube;
                    }
                }
            }
        }
    }
    moved_cube.move(dir);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cord1,cord2;
    cin>>cord1>>cord2;
    start_cube.read();
    pair<int,int> startp={8-cord1[1]+'0',cord1[0]-'a'};
    pair<int,int> endp={8-cord2[1]+'0',cord2[0]-'a'};
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string curr;
        cin>>curr;
        occupied[8-curr[1]+'0'][curr[0]-'a']=true;
    }

    queue<pair<int,int>> bfs;
    bfs.push(startp);
    dist[startp.first][startp.second]=1;
    while(!bfs.empty()){
        pair<int,int> currp=bfs.front();
        bfs.pop();
        if(currp==endp){
            break;
        }
        for(int i=0;i<4;++i){
            int nextx=currp.first+dirs[i].first;
            int nexty=currp.second+dirs[i].second;
            if(nextx>=0 and nextx<8 and nexty>=0 and nexty<8){
                if(dist[nextx][nexty]==0 and !occupied[nextx][nexty]){
                    dist[nextx][nexty]=dist[currp.first][currp.second]+1;
                    bfs.push({nextx,nexty});
                }
            }
        }
    }

    Cube nothing;
    cout<<calc_res(0,endp,startp,nothing,0)<<endl;
return 0;
}