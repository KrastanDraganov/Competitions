#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
int tiles[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=0;i<3;++i){
        int num;
        char suit;
        cin>>num>>suit;
        switch(suit){
            case 's' : tiles[i]=num+10; break;
            case 'm' : tiles[i]=num+40; break;
            case 'p' : tiles[i]=num+70; break;  
        }
    }
    sort(tiles,tiles+3);
    int best1=1,best2=1,curr1=1,curr2=1;
    for(int i=1;i<3;++i){
        if(tiles[i]==tiles[i-1]){
            ++curr1;
            best2=max(best2,curr2);
        }else if(tiles[i]==1+tiles[i-1]){
            ++curr2;
            best1=max(best1,curr1);
        }else if(tiles[i]==2+tiles[i-1]){
            best2=max(best2,curr2);
            curr2=2;
            best2=max(best2,curr2);
            curr2=1;
        }else{
            best1=max(best1,curr1);
            best2=max(best2,curr2);
            curr1=1;
            curr2=1;
        }
    }
    best1=max(best1,curr1);
    best2=max(best2,curr2);
    cout<<min(3-best1,3-best2)<<endl;
return 0;
}