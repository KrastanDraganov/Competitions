#include<iostream>
#include<algorithm>
#include<vector>

#define endl '\n'

using namespace std;

struct Room {
    int time,type,ind;

    Room(){
        time=type=ind=-1;
    }

    Room(int _time, int _type, int _ind){
        time=_time;
        type=_type;
        ind=_ind;
    }

    bool operator<(const Room comp) const {
        if(time==comp.time){
            return type<comp.type;
        }
        return time<comp.time;
    }
};

const int MAXN=2e5+3,BEGIN=0,END=1;
Room rooms[2*MAXN];
int res[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        int from,to;
        cin>>from>>to;
        rooms[2*i]=Room(from,BEGIN,i);
        rooms[2*i+1]=Room(to,END,i);
    }
    sort(rooms,rooms+2*n);

    int free_room=0,max_room=0;
    vector<int> vacant;
    for(int i=0;i<2*n;++i){
        if(rooms[i].type==END){
            vacant.push_back(res[rooms[i].ind]);
        }else if(free_room==(int)vacant.size()){
            res[rooms[i].ind]=++max_room;
        }else{
            res[rooms[i].ind]=vacant[free_room++];
        }
    }

    cout<<max_room<<endl;
    for(int i=0;i<n;++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}