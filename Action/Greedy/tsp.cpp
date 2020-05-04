#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin>>s;

    int villages=0,cities=0;
    for(char curr : s){
        if(curr=='V'){
            ++villages;
        }else{
            ++cities;
        }
    }

    int res=2*min(villages,cities);
    if(villages!=cities){
        ++res;
    }
    cout<<res<<endl;
return 0;
}