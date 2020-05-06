#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=11;
char input[MAXN],res[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int counter=0;
    for(int i=0;i<n;++i){
        cin>>input;
        if(strcmp(input,res)==0){
            ++counter;
        }else if(counter==0){
            strcpy(res,input);
            counter=1;
        }else{
            --counter;
        }
    }
    cout<<res<<endl;
return 0;
}