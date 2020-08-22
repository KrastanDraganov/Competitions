#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char c;
    int counter=0,counter2=0,res=0,res2=0;
    while(cin>>c){
        if(c=='-'){
            res+=counter;
            res2+=2*counter2;
            counter++;
        }else{
            if(counter>0 or counter2>0){
                res2++;
            }
            res2+=counter+counter2;
            counter2++;
        }
    }
    
    cout<<res<<" "<<res2<<endl;
return 0;
}
