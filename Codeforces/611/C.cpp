#include<iostream>
#include<deque>
#define endl '\n'
using namespace std;
const int MAXN=2e5+4;
int friends[MAXN];
bool received[MAXN];
deque<int> not_received;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>friends[i];
        if(friends[i]){
            received[friends[i]]=true;
        }
    }
    for(int i=1;i<=n;++i){
        if(!received[i]){
            not_received.push_back(i);
        }
    }
    for(int i=1;i<=n;++i){
        if(!friends[i] and !received[i]){
            if(not_received.front()==i){
                not_received.pop_front();
                friends[i]=not_received.front();
                received[not_received.front()]=true;
                not_received.pop_front();
                not_received.push_front(i);
            }else{
                friends[i]=not_received.front();
                received[not_received.front()]=true;
                not_received.pop_front();
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(!friends[i]){
            friends[i]=not_received.front();
            received[not_received.front()]=true;
            not_received.pop_front();
        }
        cout<<friends[i];
        if(i<n){
            cout<<" ";
        }
    }
    cout<<endl;
return 0;
}