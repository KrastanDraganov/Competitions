#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        int counter=0,ind[2]={-1,-1};
        bool check=false;
        for(int i=0;i<n;++i){
            int num;
            cin>>num;
            if(!check){
                if(num%2==0){
                    check=true;
                    counter=1;
                    ind[0]=i;
                }else{
                    ind[counter++]=i;
                    if(counter==2){
                        check=true;
                    }
                }
            }
        }
        if(check){
            cout<<counter<<endl;
            for(int i=0;i<counter;++i){
                cout<<ind[i]+1<<" ";
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
return 0;
}