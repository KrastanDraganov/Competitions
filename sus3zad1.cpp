#include<bits/stdc++.h>
using namespace std;
struct Point{
    long long x,y;
    Point(){}
    Point(long long _x,long long _y){
        x=_x;
        y=_y;
    }
    Point operator+ (const Point& z) const {
        return Point(x+z.x,y+z.y);
    }
    Point operator- (const Point& z) const {
        return Point(x-z.x,y-z.y);
    }
    Point operator* (const long long br) const {
        return Point(x*br,y*br);
    }
    Point(const Point& A,const Point& B, const long long br) {
        Point X=A+(B-A)*br;
        x=X.x;
        y=X.y;
    }
};
long long S(const Point& A,const Point& B){
    return (A.x-B.x)*(B.y+A.y);
}
long long S(const Point& A,const Point& B,const Point& C){
    return S(A,B)+S(C,A)+S(B,C);
}
pair<Point,long long> pres(const Point& A,const Point& B,const Point& C,const Point& D) {
    long long k = S(A,C,D)/(S(A,B,D)+S(B,A,C));
    return {Point(A,B,k),k};
}
int main(){
    int n;
    cin>>n;
    Point cor[n],a,b;
    long long area=0,mincorx=102,maxcorx=-102,mincory=102,maxcory=-102;
    for(int i=0;i<n;i++){
        cin>>cor[i].x>>cor[i].y;
    }
    cin>>a.x>>a.y>>b.x>>b.y;
    int px=-291,py=-291,rez1=-300,rez2=-300;
    if(a.x==b.x) px=-200;
    else if(a.y==b.y) py=-200;
    for(int i=0;i<n;i++){
        if(i<n-1){
            area+=S(cor[i],cor[i+1]);
            if(pres(cor[i],cor[i+1],a,b).second>0){
                Point p=pres(cor[i],cor[i+1],a,b).first;
                if(px==-200 and rez1==-300) rez1=p.y;
                else if(px==-200 and rez1!=-300) rez2=p.y;
                else if(py==-200 and rez1==-300) rez1=p.x;
                else if(py==-200 and rez1!=-300) rez2=p.x;
            }
        }
    }
    if(rez1!=-300 and rez2!=-300){
        area+=S(cor[n-1],cor[0]);
        area=abs(area);
        cout<<area/2;
        if(area%2==1) cout<<".5";
        cout<<endl;
    }else{
        
    }
return 0;
}