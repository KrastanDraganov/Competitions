#include<iostream>
#include<algorithm>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=3e5+3,BEGIN=1,END=-1;

struct Circle {
    int x,type,radius,ind;
    
    Circle(){
        x=0;
        type=0;
        radius=0;
        ind=-1;
    }

    Circle(int _x, int _type, int _radius, int _ind){
        x=_x;
        type=_type;
        radius=_radius;
        ind=_ind;
    }

    bool operator<(Circle comp){
       if(x==comp.x){
           if(type==comp.type){
               if(type==BEGIN){
                   return radius>comp.radius;
               }else{
                   return radius<comp.radius;
               }
           }
           return type<comp.type;
       }
       return x<comp.x;
    }
};

Circle circles[2*MAXN];
int inside[MAXN];
vector<int> all_points[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x,r;
        cin>>x>>r;
        circles[2*i]=Circle(x-r,BEGIN,r,i);
        circles[2*i+1]=Circle(x+r,END,r,i);
        inside[i]=-1;
    }

    sort(circles,circles+2*n);
    int res=1;
    for(int i=0;i<2*n;++i){
        all_points[circles[i].ind].push_back(circles[i].x);
        if(circles[i].type==BEGIN){
            if(i>0 and circles[i].x==circles[i-1].x){
                if(circles[i-1].type==BEGIN){
                    inside[circles[i].ind]=circles[i-1].ind;
                }else{
                    inside[circles[i].ind]=inside[circles[i-1].ind];
                }
            }
        }else{
            bool check=true;
            for(int i2=1;i2<all_points[circles[i].ind].size();i2+=2){
                if(all_points[circles[i].ind][i2]!=all_points[circles[i].ind][i2-1]){
                    check=false;
                    break;
                }
            }
            res+=(check ? 2 : 1);
        }
        if(inside[circles[i].ind]!=-1){
            all_points[inside[circles[i].ind]].push_back(circles[i].x);
        }
    }
    cout<<res<<endl;
return 0;
}