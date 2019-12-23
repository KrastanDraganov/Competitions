#include<bits/stdc++.h>
using namespace std;
const double INF=1<<30;
struct Point{
    double x,y;
    Point() {}
    Point(double _x,double _y){
        x=_x;
        y=_y;
    }
    Point (Point& A, Point& B, double k){
        Point X = A + (B-A)*k;
        x = X.x;
        y = X.y;
    }
    Point operator+ (const Point& o) const{
        return Point(x + o.x, y + o.y);
    }
    Point operator- (const Point& o) const{
        return Point(x - o.x, y - o.y);
    }
    Point operator* (const double k) const{
        return Point(x*k, y*k);
    }
    Point operator/ (const double k) const{
        return Point(x/k, y/k);
    }
};
double S(Point& A,Point& B){
    return (A.x-B.x)*(A.y+B.y)/2.0;
}
double Sv(Point& A,Point& B,Point& C){
    return S(A,B)+S(B,C)+S(C,A);
}
Point intersection(Point& A,Point& B,Point& C,Point& D){
    double k=Sv(A,C,D)/(Sv(A,B,D)+Sv(B,A,C));
    return Point(A,B,k);
}
const double EPS=0.001;
bool collinear(Point& A, Point& B,Point& C){
    return abs(Sv(A, B, C)) < EPS;
}
int main(){
    Point a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    Point result=intersection(a,b,c,d);
    cout<<fixed<<setprecision(5);
    if(Sv(a,c,d)<0)
        cout<<"overlap\n";
    else if(collinear(a,b,c) and collinear(a,b,d))
        cout<<"no\n";
    else
        cout<<result.x<<" "<<result.y<<endl;
    return 0;
}