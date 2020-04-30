#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    multiset<int> negative,positive;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        if(curr>0){
            positive.insert(curr);
        }else{
            negative.insert(curr);
        }
    }

    long long res=0;
    while(negative.size()>1){
        long long curr=1;
        for(int i=0;i<2;++i){
            auto it=negative.begin();
            curr*=(*it);
            negative.erase(it);
        }
        res+=curr;
    }
    if(!negative.empty()){
        res+=(*negative.begin());
    }
    while(!positive.empty() and (*positive.begin())==1){
        ++res;
        positive.erase(positive.begin());
    }
    while(positive.size()>1){
        long long curr=1;
        for(int i=0;i<2;++i){
            auto it=positive.end();
            --it;
            curr*=(*it);
            positive.erase(it);
        }
        res+=curr;
    }
    if(!positive.empty()){
        res+=(*positive.begin());
    }
    cout<<res<<endl;
return 0;
}