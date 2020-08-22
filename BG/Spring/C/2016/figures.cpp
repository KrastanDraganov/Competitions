#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

struct Point {
    int x,y;
    
    Point(){
        x=-1;
        y=-1;
    }
    
    Point(int num){
        int sum=1,curr=2;
        x=0;
        while(sum<num){
            ++x;
            sum+=curr;
            ++curr;
        }
        sum-=(curr-1);
        y=num-sum-1;
    }

    bool operator<(Point& comp){
        if(x==comp.x){
            return y<comp.y;
        }
        return x<comp.x;
    }
};

void print_cords(vector<Point>& cords){
    for(Point curr : cords){
        cout<<"("<<curr.x<<" "<<curr.y<<") ";
    }
    cout<<endl;
}

bool same_line(Point& p1, Point& p2){
    return p1.x==p2.x or p1.y==p2.y or abs(p1.x-p2.x)==abs(p1.y-p2.y);
}

int dist(Point& p1, Point& p2){
    if(p1.x==p2.x){
        return abs(p1.y-p2.y);
    }
    return abs(p1.x-p2.x);
}

bool is_triangle(vector<Point> cords, int& side){
    if(!same_line(cords[0],cords[1]) or !same_line(cords[2],cords[1]) or !same_line(cords[0],cords[2])){
        return false;
    }
    side=dist(cords[0],cords[1]);
    if(dist(cords[0],cords[2])!=side or dist(cords[1],cords[2])!=side){
        return false;
    }
    return true;
}

bool is_rhombus(vector<Point>& cords, int& side){
    if(cords[0].x==cords[1].x){
        return is_triangle({cords[0],cords[2],cords[3]},side) and is_triangle({cords[0],cords[1],cords[3]},side);
    }
    return is_triangle({cords[0],cords[1],cords[2]},side) and is_triangle({cords[1],cords[2],cords[3]},side);
}

bool is_hexagon(vector<Point>& cords, int& side){
    if(!same_line(cords[0],cords[1]) or !same_line(cords[1],cords[3]) or !same_line(cords[3],cords[5]) 
        or !same_line(cords[5],cords[4]) or !same_line(cords[4],cords[2]) or !same_line(cords[2],cords[0])){
        return false;
    }
    side=dist(cords[0],cords[1]);
    if(dist(cords[1],cords[3])!=side or dist(cords[3],cords[5])!=side or dist(cords[5],cords[4])!=side 
        or dist(cords[4],cords[2])!=side or dist(cords[2],cords[0])!=side){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Point> cords;
    int curr;
    while(cin>>curr){
        cords.push_back(Point(curr));
    }
    sort(cords.begin(),cords.end());

    //print_cords(cords);
    int n=(int)cords.size(),side=-1;
    if(n==3 and is_triangle(cords,side)){
        cout<<"T "<<side<<endl;
    }else if(n==4 and is_rhombus(cords,side)){
        cout<<"R "<<side<<endl;
    }else if(n==6 and is_hexagon(cords,side)){
        cout<<"H "<<side<<endl;
    }else{
        cout<<"INCORRECT\n";
    }
return 0;
}