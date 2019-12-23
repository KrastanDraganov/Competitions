#include<iostream>
#include<algorithm>
#define endl '\n'
#define MAXN (int)2e5+2
using namespace std;
int n,nums[MAXN];
bool check(int ind){
    int previ=0,nexti;
    if(ind==0) previ=1;
    for(int i=previ+1;i<n-1;++i){
        if(i+1==ind){
            nexti=i+2;
        }else{
            nexti=i+1;
        }
        if(i==ind){
            previ=i-1;
        }else if(nums[i]-nums[previ]!=nums[nexti]-nums[i]){
            return false;
        }
        previ=i;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    sort(nums,nums+n);
    int counter=0;
    for(int i=1;i<n-1;++i){
        if(nums[i]-nums[i-1]!=nums[i+1]-nums[i]){
            ++counter;
           if(check(i)){
                //cout<<"a ";
                cout<<i+1<<endl;
                return 0;
           }else if(check(i-1)){
                //cout<<"b ";
                cout<<i<<endl;
                return 0;
           }else if(check(i+1)){
                //cout<<"c ";
                cout<<i+2<<endl;
                return 0;
           }
        }
        //if(counter>2) break;
    }
    if(counter==0){
        cout<<1<<endl;
    }else{
        cout<<-1<<endl;
    }
return 0;
}