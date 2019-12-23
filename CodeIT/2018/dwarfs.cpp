#include<iostream>
#include<utility>
#include<algorithm>
#define endl '\n'
using namespace std;
pair<int,int> dirs[]={{0,-1},{0,1},{-1,0},{1,0}};
bool operator>(const pair<int,int> cord1, const pair<int,int> cord2){
    if(cord1.first!=cord2.first){
        return cord1.first>cord2.first;
    }else{
        return cord1.second>cord2.second;
    }
}
unsigned int manhattan_dist(pair<int,int> cord1, pair<int,int> cord2){
    return abs(cord1.first-cord2.first)+abs(cord1.second-cord2.second);
}
int main(){
    freopen("dwarfs.in","r",stdin);
    freopen("dwarfs.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<int,int> min_cord,max_cord;
    int n,miny,maxy;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        pair<int,int> cp = {x,y};
        if(i==0){
            min_cord=cp;
            max_cord=cp;
            miny=y;
            maxy=y;      
        }else{
            if(min_cord>cp){
                min_cord=cp;
            }
            if(cp>max_cord){
                max_cord=cp;
            }
            if(y<miny){
                miny=y;
            }
            if(y>maxy){
                maxy=y;
            }
        }
    }
    unsigned int result=2000000002,middle=(min_cord.first+max_cord.first)/2,middle2=(min_cord.second+max_cord.second)/2;
    //for(int i=min_cord.first;i<=max_cord.first;i++){
    unsigned int start,start2;
    if(middle2<1001){
        start=1;
    }else{
        start=middle2-1000;
    }
    if(middle<1001){
        start2=1;
    }else{
        start2=middle-1000;
    }
    //cout<<max_cord.first<<" "<<max_cord.second<<" "<<min_cord.first<<" "<<min_cord.second<<endl;
    for(unsigned int i=start2;i<=start2+1000;i++){
        for(unsigned int i2=start;i2<=middle2+1000;i2++){
            unsigned int curr = max(manhattan_dist({i,i2},min_cord),manhattan_dist({i,i2},max_cord));
            //cout<<i2<<" "<<curr<<" "<<result<<endl;
            if(curr<result){
                result=curr;
                /*if(result==5){
                 cout<<i<<" "<<i2<<endl;
                }*/
            }
        }
    }
    cout<<result<<endl;
return 0;
}