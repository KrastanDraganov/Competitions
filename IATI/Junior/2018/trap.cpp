#include<iostream>
#include<utility>

#define endl '\n'

using namespace std;

const int MAX_LINES=26,LIMIT=50,MAXN=103;
int counter[MAX_LINES];
bool used[MAXN][MAXN];
pair<int,int> dirs[4]={{0,-1}, {0,1}, {-1,0}, {1,0}};

void calc_solutions(int lines, bool is_vertical_line, int currx, int curry){
    if(lines>MAX_LINES){
        return;
    }

    used[currx+LIMIT][curry+LIMIT]=true;
    
    long long already_used=0;
    for(pair<int,int> add : dirs){
        int nextx=currx+add.first;
        int nexty=curry+add.second;
        
        if(used[nextx+LIMIT][nexty+LIMIT]){
            ++already_used;
            continue;
        }
        if(!is_vertical_line and nexty<curry){
            continue;
        }
        
        if(nexty>curry and !is_vertical_line){
            calc_solutions(lines+1, true, nextx, nexty);
        }else{
            calc_solutions(lines+1, is_vertical_line, nextx, nexty);
        }
    }

    if(already_used==4){
        ++counter[lines-1];
    }

    used[currx+LIMIT][curry+LIMIT]=false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    used[LIMIT][LIMIT]=true;
    calc_solutions(1, false, 1, 0);

    cout<<"{";
    for(int i=0;i<MAX_LINES;++i){
        if(i>0){
            cout<<",";
        }
        cout<<counter[i];
    }
    cout<<"}";
return 0;
}