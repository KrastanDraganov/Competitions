#include<bits/stdc++.h>
using namespace std;
pair<int,int>ch[4];
int main(){
    int a,b,square=0;
    for(int i=0;i<4;i++){
        cin>>a>>b;
        ch[i]=make_pair(a,b);
        if(i>0){
            square+=((ch[i-1].first-ch[i].first)*(ch[i-1].second+ch[i].second)/2);
        }
        cout<<square<<endl;
    }
    cout<<square+((ch[3].first-ch[0].first)*(ch[3].second+ch[0].second)/2)<<endl;
return 0;
}
    