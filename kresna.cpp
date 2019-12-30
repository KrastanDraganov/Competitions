#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3,MAXY=3e4+3,BEGIN=1,END=-1;
struct Point {
    int x,y1,y2,z;
    Point(){
        x=0;
        y1=0;
        y2=0;
        z=0;
    }
    Point(int _x, int _y1, int _y2, int _z){
        x=_x;
        y1=_y1;
        y2=_y2;
        z=_z;
    }
    bool operator<(const Point& comp) const {
        return (x<comp.x or (x==comp.x and z<comp.z));
    }
} points[2*MAXN];
int tree[4*MAXY],lazy[4*MAXY];
void print_tree(int ind, int cl, int cr){
    if(cl>cr) return;
    cout<<ind<<": "<<cl<<" "<<cr<<" -> "<<tree[ind]<<" "<<lazy[ind]<<endl;
    if(cl==cr){
        return;
    }
    int mid=(cl+cr)/2;
    print_tree(2*ind,cl,mid);
    print_tree(2*ind+1,mid+1,cr);
}
void update(int ind, int cl, int cr, int l, int r, int change){
    if(cl>cr or cl>r or cr<l){
        return;
    }
    if(l==cl and r==cr){
        lazy[ind]+=change;
        if(change==1){
            tree[ind]=r-l+1;
        }else if(lazy[ind]==0){
            tree[ind]=tree[2*ind]+tree[2*ind+1];
        }
        return;
    }
    int mid=(cl+cr)/2;
    update(2*ind,cl,mid,l,min(mid,r),change);
    update(2*ind+1,mid+1,cr,max(mid+1,l),r,change);
    if(lazy[ind]==0){
        tree[ind]=tree[2*ind]+tree[2*ind+1];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int miny1=MAXY,maxy2=-1;
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        points[2*i]=Point(x1,y1,y2,BEGIN);
        points[2*i+1]=Point(x2,y1,y2,END);
        maxy2=max(maxy2,y2);
        miny1=min(miny1,y1);
    }
    sort(points,points+2*n);
    long long res=0;
    update(1,miny1,maxy2,points[0].y1,points[0].y2-1,points[0].z);
    for(int i=1;i<2*n;++i){
        res+=(long long) tree[1]*(points[i].x-points[i-1].x);
        if(i==2*n-1) cout<<tree[1]<<" "<<points[i-1].y1<<" "<<points[i-1].y2<<" "<<points[i-1].z<<endl;
        update(1,miny1,maxy2,points[i].y1,points[i].y2-1,points[i].z);
    }
    cout<<res<<endl;
return 0;
}