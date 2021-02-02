#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a;
    cin>>a;

    set<int> unique;
    int max_side=0;

    for(int x=1;x<=a;++x){
        for(int y=1;y<x;++y){
            int side1=2*x*y;
            if(side1>a){
                break;
            }

            int side2=x*x-y*y;
            if(side2>a){
                continue;
            }

            int side3=x*x+y*y;
            for(int i=1;i*side1<=a and i*side2<=a;++i){
                unique.insert(i*side3);
                max_side=max(max_side, i*side3);
            }
        }
    }

    cout<<max_side<<" "<<(int)unique.size()<<endl;
return 0;
}