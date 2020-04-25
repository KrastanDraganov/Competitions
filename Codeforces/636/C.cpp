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
        int counter=0;
        long long prev=0,max_num=-2e9,sum=0;
        for(int i=0;i<n;++i){
            long long curr;
            cin>>curr;
            if(i>0 and ((curr<0 and prev>0) or (curr>0 and prev<0))){
                sum+=max_num;
                counter=0;
                max_num=-2e9;
            }
            prev=curr;
            max_num=max(max_num,curr);
            ++counter;
        }
        sum+=max_num;
        cout<<sum<<endl;
    }
return 0;
}