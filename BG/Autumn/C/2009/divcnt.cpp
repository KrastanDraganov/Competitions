#include<iostream>
#include<math.h>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        int counter=0;
        for(int div=1;div*div<=curr;++div){
            if(curr%div==0){
                ++counter;
                if((curr/div)!=div){
                    ++counter;
                }
            }
        }
        cout<<counter<<" ";
    }
    cout<<endl;
return 0;
}