#include<iostream>
#include<queue>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;

struct Speech{
    int arrival,length;
    
    bool operator<(const Speech& s) const{
        if(arrival==s.arrival){
            return length>s.length;
        }else{
            return arrival<s.arrival;
        }
    }
} speeches[MAXN];

struct Microphone{
    int endtime,number;
    
    bool operator<(const Microphone& m) const{
        if(endtime==m.endtime){
            return number>m.number;
        }else{
            return endtime>m.endtime;
        }
    }
} microphones[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        microphones[i-1].number=i;
    }
    for(int i=0;i<m;i++){
        cin>>speeches[i].arrival>>speeches[i].length;
    }
    sort(speeches,speeches+m);
    
    priority_queue<Microphone> freemic(microphones,microphones+n),busymic;
    for(int i=0;i<m;i++){
        Microphone curr;
        while(!busymic.empty() and busymic.top().endtime<=speeches[i].arrival){
            curr=busymic.top();
            busymic.pop();
            curr.endtime=0;
            freemic.push(curr);
        }
        
        if(freemic.empty()){
            curr=busymic.top();
            busymic.pop();
            curr.endtime+=speeches[i].length;
        }else{
            curr=freemic.top();
            freemic.pop();
            curr.endtime=speeches[i].arrival+speeches[i].length;
        }
        
        busymic.push(curr);
    }
    
    while(busymic.size()>1){
        busymic.pop();
    }
    cout<<busymic.top().endtime<<" "<<busymic.top().number<<endl;
return 0;
}