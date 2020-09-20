#include<iostream>
#include<stack>
#include<utility>
#include<climits>

#define endl '\n'

using namespace std;

struct MinQueue {
    stack<pair<long long, long long>> front,back;

    void push(long long num){
        if(front.empty()){
            front.push({num, num});
            return;
        }
        front.push({num, min(num, front.top().second)});
    }

    void pop(){
        if(!back.empty()){
            back.pop();
            return;
        }

        back.push({front.top().first, front.top().first});
        front.pop();

        while(!front.empty()){
            long long curr=front.top().first;
            back.push({curr, min(curr, back.top().second)});
            front.pop();
        }

        back.pop();
    }

    long long calc_min(){
        if(back.empty()){
            return front.top().second;
        }

        if(front.empty()){
            return back.top().second;
        }

        return min(front.top().second, back.top().second);
    }
};

const int MAXN=2e5+3;
long long prefix[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,a,b;
    cin>>n>>a>>b;

    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        prefix[i+1]=prefix[i]+curr;
    }

    MinQueue prev_sums;
    long long res=LONG_LONG_MIN;
    for(int i=a;i<=n;++i){
        if(i>b){
            prev_sums.pop();
        }
        prev_sums.push(prefix[i-a]);
        res=max(res,prefix[i]-prev_sums.calc_min());
    }

    cout<<res<<endl;
return 0;
}