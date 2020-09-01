#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define endl '\n'

using namespace std;

struct Point {
    long long x,y,z;
    
    Point(long long _x, long long _y, long long _z){
        x=_x;
        y=_y;
        z=_z;
    }
    
    bool operator<(const Point& comp){
        return (x==comp.x ? (z<comp.z or (z==comp.z and y<comp.y)) : (x<comp.x));
    }
};

const int BEGIN=1,END=2;
vector<Point> up_points,down_points,all_segments;

void add_points(long long x1, long long x2, long long y, vector<Point>& curr){
    curr.push_back(Point(x1,y,BEGIN));
    curr.push_back(Point(x2,y,END));
}

void combine_points(vector<Point> points){
    if(points.empty()){
        return;
    }
    sort(points.begin(),points.end());
    multiset<long long> visited;
    Point curr_segment(points[0].x,points[0].x,0);
    for(int i=0;i<points.size();++i){
        if(visited.empty()){
            curr_segment.x=points[i].x;
        }else{
            curr_segment.z+=(points[i].x-points[i-1].x)*(-1)*(*visited.begin());
        }
        if(points[i].z==1){
            visited.insert(points[i].y);
        }else{
            multiset<long long>::iterator it=visited.lower_bound(points[i].y);
            visited.erase(it);
        }
        if(visited.empty()){
            curr_segment.y=points[i].x;
            all_segments.push_back(curr_segment);
            curr_segment.z=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        long long x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(y2==0){
            swap(y1,y2);
        }
        if(x1>x2){
            swap(x1,x2);
        }
        add_points(x1,x2,-abs(y2),y2>0 ? up_points : down_points);
    }

    combine_points(up_points);
    combine_points(down_points);
    sort(all_segments.begin(),all_segments.end());
    
    int counter=0;
    long long curr=0,sum=0,max_area=0,max_y=-1e9;
    for(int i=0;i<all_segments.size();++i){
        if(all_segments[i].x>=max_y){
            ++counter;
            curr=0;
        }
        curr+=all_segments[i].z;
        sum+=all_segments[i].z;
        max_area=max(max_area,curr);
        max_y=max(max_y,all_segments[i].y);
    }
    cout<<counter<<endl<<sum<<endl<<max_area<<endl;
return 0;
}