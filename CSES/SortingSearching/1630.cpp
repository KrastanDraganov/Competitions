#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
pair<int,int> tasks[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        int duration,deadline;
        cin>>duration>>deadline;
        tasks[i]={duration,deadline};
    }
    sort(tasks,tasks+n);

    long long curr_time=0,reward=0;
    for(int i=0;i<n;++i){
        curr_time+=tasks[i].first;
        reward+=(tasks[i].second-curr_time);
    }

    cout<<reward<<endl;
return 0;
}