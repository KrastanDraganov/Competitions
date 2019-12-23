#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    bool res1,res2,res3,res4;
    if(x1<=y1){
        res1=(x1<=x2) and (x2<=y1);
        res2=(x1<=y2) and (y2<=y1);
    }else{
        res1=(x1<=x2) or (x2<=y1);
        res2=(x1<=y2) or (y2<=y1);
    }
    if(x2<=y2){
        res3=(x1>=x2) and (x1<=y2);
        res4=(x2<=y1) and (y2>=y1);
    }else{
        res3=(x1>=x2) or (x1<=y2);
        res4=(x2<=y1) or (y2>=y1);
    }
    cout<<(res1 or res2 or res3 or res4)<<endl;
return 0;
}