#include<bits/stdc++.h>
using namespace std;
int br[25005];
vector<int>num;
int main(){
    int n,k,ch,br2=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ch;
        if(br[ch]==0){
            num.push_back(ch);
            br2++;
        }
        br[ch]++;
    }
    sort(num.begin(),num.end());
    int br3=0;
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
        br3++;
        if(br3==k) break;
        for(int i2=0;i2<br[num[i]]-1 and br2<k;i2++){
            cout<<num[i]<<" ";
            br2++;
            br3++;
            if(br3==k) break;
        }
    }
    cout<<endl;
return 0;
}