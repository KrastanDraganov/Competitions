//Only 60/100 points

#include<iostream>
#include<algorithm>
#include<math.h>

#define endl '\n'

using namespace std;

const int MAXN=33;
struct Point {
    char letter;
    int x,y;
    
    Point(){

    }
    
    Point(char _letter, int _x, int _y){
        letter=_letter;
        x=_x;
        y=_y;
    }
} points[MAXN];

double side(int x, int y, int x2, int y2){
    return (double) sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
}

bool is_triangle(double a, double b, double c){
    return ((a+b>c) and (b+c>a) and (a+c>b));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        char a;
        int b,c;
        cin>>a>>b>>c;
        points[i]=Point(a,b,c);
    }
    
    bool check=false;
    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            for(int i3=i2+1;i3<n;++i3){
                int side1=side(points[i].x,points[i].y,points[i2].x,points[i2].y);
                int side2=side(points[i3].x,points[i3].y,points[i2].x,points[i2].y);
                int side3=side(points[i3].x,points[i3].y,points[i].x,points[i].y);
                if(is_triangle(side1,side2,side3)){
                    check=true;
                    cout<<points[i].letter<<" "<<points[i2].letter<<" "<<points[i3].letter<<endl;
                }
            }
        }
    }
    if(!check){
        cout<<"No triangles."<<endl;
    }
return 0;
}