// Not solved - wrong answer, 0 points

#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

struct Point {
    long long v1,v2;
    int ind;

    bool operator<(const Point& comp) const {
        if(v1==comp.v1){
            return v2>comp.v2;
        }
        return v1>comp.v1;
    }

    bool operator==(const Point& comp) const {
        return v1==comp.v1 and v2==comp.v2;
    }
};

long long signed_area(Point& a, Point& b, Point& c){
    return a.v1*a.v2*c.v1*b.v2
         + a.v1*b.v1*b.v2*c.v2
         + a.v2*b.v1*c.v1*c.v2
         - a.v1*b.v2*c.v1*c.v2
         - a.v2*b.v1*b.v2*c.v1
         - a.v1*b.v1*b.v2*c.v2;
}

int main(){
    int n;
    cin>>n;

    vector<Point> points(n);
    for(int i=0;i<n;++i){
        cin>>points[i].v1>>points[i].v2;
        points[i].ind=i;
    }

    sort(points.begin(), points.end());

    vector<Point> convex_hull;
    int ch_size=0;

    for(int i=n-1;i>=0;--i){
        while(ch_size>=2 and signed_area(convex_hull[ch_size-2], convex_hull[ch_size-1], points[i])<=0){
            convex_hull.pop_back();
            --ch_size;
        }

        convex_hull.push_back(points[i]);
        ++ch_size;
    }

    int west_point=0;
    for(int i=1;i<ch_size;++i){
        if(convex_hull[i].v2>convex_hull[west_point].v2){
            west_point=i;
        }
    }

    vector<bool> same_point(n, false);
    for(int i=1;i<n;++i){
        if(points[i]==points[i-1]){
            same_point[i]=same_point[i-1]=true;
        }
    }

    vector<int> res;
    for(int i=0;i<=west_point;++i){
        if(!same_point[convex_hull[i].ind]){
            res.push_back(convex_hull[i].ind);
        }
    }

    sort(res.begin(), res.end());
    for(int curr : res){
        cout<<curr<<" ";
    }
    cout<<endl;
return 0;
}