#include<iostream>
#include<set>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=7;
pair<int,int> dirs[8]={{1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
set<set<int>> all;

void make_comb(int x, int y, int ind, int startp, int endp, set<int>& curr){
    if(ind==6){
        bool check=false;
        for(int i=0;i<8;++i){
            int nextx=x+dirs[i].first;
            int nexty=y+dirs[i].second;
            if(nextx==startp and nexty==endp){
                check=true;
                break;
            }
        }
        if(!all.count(curr) and check){
            all.insert(curr);
        }
        return;
    }
    for(int i=0;i<8;++i){
        int nextx=x+dirs[i].first;
        int nexty=y+dirs[i].second;
        if(nextx>=0 and nextx<MAXN and nexty>=0 and nexty<MAXN){
            int num=nextx*MAXN+nexty;
            if(!curr.count(num)){
                set<int> dub=curr;
                dub.insert(num);
                make_comb(nextx,nexty,ind+1,startp,endp,dub);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0;i<MAXN;++i){
        for(int i2=0;i2<MAXN;++i2){
            int curr=i*MAXN+i2;
            set<int> emptys;
            emptys.insert(curr);
            make_comb(i,i2,1,i,i2,emptys);
        }
    }

    int k;
    cin>>k;
    int counter=1;
    for(set<int> res : all){
        if(counter==k){
            for(int curr : res){
                cout<<curr+1<<" ";
            }
            cout<<endl;
            break;
        }
        ++counter;
    }
return 0;
}