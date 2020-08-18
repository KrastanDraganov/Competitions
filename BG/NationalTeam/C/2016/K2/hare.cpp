// 30/100 POINTS

#include<iostream>
#include<algorithm>
#include<utility>
#include<math.h>

#define endl '\n'

using namespace std;

pair<int,int> extended_euclid(int x, int y){
    if(y==0){
        return {1,0};
    }
    pair<int,int> next=extended_euclid(y,x%y);
    return {next.second,next.first-(x/y)*next.second};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a,b,c;
    cin>>a>>b>>c;
    
    int gd=__gcd(a,b);
    if(c%gd!=0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    a/=gd;
    b/=gd;
    c/=gd;
    pair<int,int> sol=extended_euclid(a,b);
    int resx=sol.first*c,resy=sol.second*c;
    
    int res=-1,xmin=(int)ceil(-1.0*resx/b),ymax=(int)floor(1.0*resy/a);
    if(ymax>=xmin){
        res=resx+xmin*b+resy-xmin*a;
    }
    if(res<0 or res>resx+max(xmin,ymax+1)*b-resy+max(xmin,ymax+1)*a){
        res=resx+max(xmin,ymax+1)*b-resy+max(xmin,ymax+1)*a;
    }
    if(res<0 or res>resy-a*min(xmin-1,ymax)-b*max(xmin-1,ymax)-resx){
        res=resy-a*min(xmin-1,ymax)-b*max(xmin-1,ymax)-resx;
    }
    cout<<res<<endl;
return 0;
}