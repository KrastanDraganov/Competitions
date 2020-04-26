#include<iostream>
#include<stack>
#include<utility>

#define endl '\n'

using namespace std;

stack<pair<int,int>> queue_push,queue_pop;

int queue_max(){
    int res=0;
    if(!queue_push.empty()){
        res=max(res,queue_push.top().second);
    }
    if(!queue_pop.empty()){
        res=max(res,queue_pop.top().second);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int queries;
    cin>>queries;
    int sum=0;
    while(queries--){
        int type;
        cin>>type;
        if(type==-1){
            if(queue_pop.empty()){
                while(!queue_push.empty()){
                    pair<int,int> curr=queue_push.top();
                    queue_push.pop();
                    int prev_max=(queue_pop.empty() ? 0 : queue_pop.top().second);
                    curr.second=max(curr.first,prev_max);
                    queue_pop.push(curr);
                }
            }
            queue_pop.pop();
        }else{
            int prev_max=(queue_push.empty() ? 0 : queue_push.top().second);
            queue_push.push({type,max(type,prev_max)});
        }
        sum+=queue_max();
    }
    cout<<sum<<endl;
return 0;
}