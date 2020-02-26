#include<iostream>
#include<math.h>
#define endl '\n'
using namespace std;
const int MAXN=11e3+1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int a,b,c;
        cin>>a>>b>>c;
        int min_steps=1e9,res1=-1,res2=-1,res3=-1;
        for(int i=1;i<MAXN;++i){
            for(int i2=i;i2<MAXN;i2+=i){
                for(int i3=i2;i3<MAXN;i3+=i2){
                    int curr=abs(a-i)+abs(b-i2)+abs(c-i3);
                    if(curr<min_steps){
                        min_steps=curr;
                        res1=i;
                        res2=i2;
                        res3=i3;
                    }
                }
            }
        }
        cout<<min_steps<<endl<<res1<<" "<<res2<<" "<<res3<<endl;
    }
return 0;
}