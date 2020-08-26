#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'
#define x first
#define y second

using namespace std;

const int MAXP=503,MAXN=103;
vector<int> points[MAXP][MAXP];
bool is_edge[MAXN][MAXN],visited[MAXN];

void print_cord(pair<int,int> curr){
    cout<<"("<<curr.x<<","<<curr.y<<")\n"<<endl;
}

void add_points(int ind, pair<int,int> startp, pair<int,int> endp){
    if(startp>endp){
        swap(startp,endp);
    }
    points[startp.x][startp.y].push_back(ind);
    points[endp.x][endp.y].push_back(ind);
    int diff1=abs(startp.x-endp.x),diff2=abs(startp.y-endp.y);
    if(diff1==0){
        for(int i=startp.y+1;i<endp.y;++i){
            points[startp.x][i].push_back(ind);
        }
    }else if(diff2==0){
        for(int i=startp.x+1;i<endp.x;++i){
            points[i][startp.y].push_back(ind);
        }
    }else if(diff1<diff2 and diff2%diff1==0){
        int step=diff2/diff1;
        if(startp.y<endp.y){
            for(int i=startp.y+step;i<endp.y;i+=step){
                points[startp.x+1][i].push_back(ind);
                ++startp.x;
            }
        }else{
            for(int i=startp.y-step;i>endp.y;i-=step){
                points[startp.x+1][i].push_back(ind);
                ++startp.x;
            }
        }
    }else if(diff2<=diff1 and diff1%diff2==0){
        int step=diff1/diff2;
        if(startp.y<endp.y){
            for(int i=startp.x+step;i<endp.x;i+=step){
                points[i][startp.y+1].push_back(ind);
                ++startp.y;
            }
        }else{
            for(int i=startp.x+step;i<endp.x;i+=step){
                points[i][startp.y-1].push_back(ind);
                --startp.y;
            }
        }
    }
}

int dfs(int currv, int n){
    visited[currv]=true;
    int res=1;
    for(int nextv=0;nextv<n;++nextv){
        if(nextv!=currv and is_edge[currv][nextv] and !visited[nextv]){
            res=max(res,dfs(nextv,n)+1);
        }
    }
    visited[currv]=false;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1+=250;
        y1+=250;
        x2+=250;
        y2+=250;
        pair<int,int> startp(x1,y1),endp(x2,y2);
        add_points(i,startp,endp);
    }

    for(int i=0;i<MAXP;++i){
        for(int i2=0;i2<MAXP;++i2){
            int m=(int)points[i][i2].size();
            for(int i3=0;i3<m;++i3){
                int from=points[i][i2][i3];
                for(int i4=i3+1;i4<m;++i4){
                    int to=points[i][i2][i4];
                    if(!is_edge[from][to]){
                        is_edge[from][to]=true;
                        is_edge[to][from]=true;
                    }
                }
            }
        }
    }

    int res=1;
    for(int i=0;i<n;++i){
        res=max(res,dfs(i,n));
    }
    cout<<res<<endl;
return 0;
}