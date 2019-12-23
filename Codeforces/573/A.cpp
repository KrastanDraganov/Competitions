#include<iostream>
#define endl '\n'
using namespace std;
char set_val(int x){
    switch(x){
        case 0 : return 'D';
        case 1 : return 'A';
        case 3 : return 'B';
        case 2 : return 'C';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int hp,res=0;
    cin>>hp;
    char a = set_val(hp%4),curr;
    for(int i=1;i<=2;++i){
        ++hp;
        curr=set_val(hp%4);
        if(curr<a){
            a=curr;
            res=i;
        }
    }
    cout<<res<<" "<<a<<endl;
return 0;
}