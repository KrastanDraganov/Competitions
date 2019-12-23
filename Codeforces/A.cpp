#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,result=0;
    cin>>n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='-'){
            if(result==0){
                result=0;
            }else{
                --result;
            }
        }else{
            result++;
        }
    }
    cout<<result<<endl;
return 0;
}