#include<iostream>
#include<utility>
#include<algorithm>

#define endl '\n'
#define x first
#define y second

using namespace std;

const int MAXN=1e3+3;
pair<int,int> points[MAXN];

bool fixed(pair<int,int>& curr){
    if(curr.x%2 or curr.y%2){
        return false;
    }
    curr.x/=2;
    curr.y/=2;
    return true;
}

bool is_point(pair<int,int> target, int n){
    int l=0,r=n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(points[mid]==target){
            return true;
        }else if(points[mid]>target){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>points[i].x>>points[i].y;
        
    }

    sort(points,points+n);
    int res=0;
    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            pair<int,int> comp1,comp2;
            comp1.x=points[i].x+points[i2].x+points[i2].y-points[i].y;
            comp1.y=points[i].y+points[i2].y+points[i].x-points[i2].x;
            comp2.x=points[i].x+points[i2].x+points[i].y-points[i2].y;
            comp2.y=points[i].y+points[i2].y+points[i2].x-points[i].x;
            if(!fixed(comp1) or !fixed(comp2)){
                continue;
            }
            if(is_point(comp1,n) and is_point(comp2,n)){
                ++res;
            }
        }
    }
    res/=2;
    cout<<res<<endl;
return 0;
}