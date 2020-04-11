#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3,MAXXY=3e4+3,BEGIN=1,END=0;

struct Point {
    int x,y1,y2,type;
    
    Point(){
        x=0;
        y1=0;
        y2=0;
        type=0;
    }

    Point(int _x, int _y1, int _y2, int _type){
        x=_x;
        y1=_y1;
        y2=_y2;
        type=_type;
    }
    
    bool operator<(const Point& comp){
        if(x==comp.x){
            if(type==comp.type){
                return make_pair(y1,y2)<make_pair(comp.y1,comp.y2);
            }
            return type<comp.type;
        }
        return x<comp.x;
    }
};

Point points[2*MAXN];
int lazy[4*MAXXY],tree[4*MAXXY];

void update(int ind, int tl, int tr, int l, int r, int val){
    if(l>tr or r<tl or l>r){
        return;
    }
    if(tl==l and tr==r){
        lazy[ind]+=val;
        if(val==-1){
            if(lazy[ind]==0){
                tree[ind]=(l==r ? 0 : tree[2*ind]+tree[2*ind+1]);
            }else if(lazy[ind]<0){
                lazy[ind]=0;
            }
        }else{
            tree[ind]=(r-l+1);
        }
    }else{
        int mid=(tl+tr)/2;
        update(2*ind,tl,mid,l,min(mid,r),val);
        update(2*ind+1,mid+1,tr,max(l,mid+1),r,val);
        if(lazy[ind]==0){
            tree[ind]=tree[2*ind]+tree[2*ind+1];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int min_y=1e9,max_y=0;
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        points[2*i]=Point(x1,y1,y2,BEGIN);
        points[2*i+1]=Point(x2,y1,y2,END);
        max_y=max(max_y,y2);
        min_y=min(min_y,y1);
    }

    sort(points,points+2*n);
    update(1,min_y,max_y-1,points[0].y1,points[0].y2-1,1);
    long long res=0;
    for(int i=1;i<2*n;++i){
        res+=(long long) tree[1]*(points[i].x-points[i-1].x);
        int add=(points[i].type==BEGIN ? 1 : -1);
        update(1,min_y,max_y-1,points[i].y1,points[i].y2-1,add);
    }
    cout<<res<<endl;
return 0;
}