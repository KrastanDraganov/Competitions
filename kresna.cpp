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

struct Tree_data {
    int counter,l,r;
    Tree_data(){
        counter=0;
        l=0;
        r=0;
    }
};

Point points[2*MAXN];
Tree_data tree[4*MAXXY];
int lazy[4*MAXXY];

Tree_data combine(Tree_data child1, Tree_data child2){
    Tree_data res;
    res.l=child1.l+child1.r;
    res.r=child2.l+child2.r;
    res.counter=child1.counter+child2.counter;
    return res;
}

void change(int ind, int val, int l, int r){
    tree[ind].l=max(tree[ind].l+val,0);
    tree[ind].r=max(tree[ind].r+val,0);
    if(l==r){
        tree[ind].counter=(tree[ind].l>0)*(r-l+1);
    }else{
        int mid=(l+r)/2;
        tree[ind].counter=(tree[ind].l>0)*(mid-l+1)+(tree[ind].r>0 ? 1 : 0)*(r-mid);
    }
}

void push(int ind, int tl, int tr){
    int mid=(tl+tr)/2;
    change(2*ind,lazy[ind],tl,mid);
    change(2*ind+1,lazy[ind],mid+1,tr);
    lazy[2*ind]+=lazy[ind];
    lazy[2*ind+1]+=lazy[ind];
    lazy[ind]=0;
}

void update(int ind, int tl, int tr, int l, int r, int val){
    if(l>tr or r<tl or l>r){
        return;
    }
    if(tl==l and tr==r){
        change(ind,val,l,r);
        lazy[ind]+=val;
        //cout<<"kzl: "<<l<<" "<<r<<" "<<tree[ind].counter<<" "<<tree[ind].l<<" "<<tree[ind].r<<endl;
    }else{
        if(tl!=tr and lazy[ind]!=0){
            push(ind,tl,tr);
        }else{
            lazy[ind]=0;
        }
        int mid=(tl+tr)/2;
        update(2*ind,tl,mid,l,min(mid,r),val);
        update(2*ind+1,mid+1,tr,max(l,mid+1),r,val);
        tree[ind]=combine(tree[2*ind],tree[2*ind+1]);
        //cout<<"cska: "<<tl<<" "<<tr<<" "<<tree[ind].counter<<" "<<tree[ind].l<<" "<<tree[ind].r<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    int max_y=0;
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        points[2*i]=Point(x1,y1,y2,BEGIN);
        points[2*i+1]=Point(x2,y1,y2,END);
        max_y=max(max_y,y2);
    }

    sort(points,points+2*n);
    update(1,0,max_y-1,points[0].y1,points[0].y2-1,1);
    long long res=0;
    for(int i=1;i<2*n;++i){
        //cout<<points[i].x<<" "<<tree[1].counter<<endl;
        res+=(long long) tree[1].counter*(points[i].x-points[i-1].x);
        int add=(points[i].type==BEGIN ? 1 : -1);
        update(1,0,max_y-1,points[i].y1,points[i].y2-1,add);
    }
    cout<<res<<endl;
return 0;
}