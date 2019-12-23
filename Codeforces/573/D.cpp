#include<iostream>
#include<algorithm>
#include<unordered_map>
#define endl '\n'
using namespace std;
const int MAXN = (int) 1e5+3;
int a[MAXN];
unordered_map<int,int> counter;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string first_player="sjfnb",second_player="cslnb";
    bool check=false;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        ++counter[a[i]];
        if(counter[a[i]]>2){
            check=true;
        }
    }
    int same=0;
    for(auto it : counter){
        if(it.second>1){
            ++same;
            if(counter[it.first-1]>0){
                check=true;
                break;
            }
        }
    }
    if(same>1 or counter[0]>1 or check){
        cout<<second_player<<endl;
        return 0;
    }
    long long sum=0;
    sort(a,a+n);
    for(int i=0;i<n;++i){
        if(a[i]<i){
            break;
        }
        sum+=a[i]-i+1;
    }
    cout<<sum<<endl;
    if(sum%2==0){
        cout<<first_player<<endl;
    }else{
        cout<<second_player<<endl;
    }
return 0;
}