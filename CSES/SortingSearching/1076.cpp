// Not finished yet - the idea doesn't work optimally

#include<iostream>
#include<queue>
#include<functional>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN];
priority_queue<int> first_half;
priority_queue<int, vector<int>, greater<int>> second_half;

void make_equal(){
    int n=(int) first_half.size();
    int m=(int) second_half.size();

    if(abs(n-m)>1){
        if(n>m){
            second_half.push(first_half.top());
            first_half.pop();
        }else{
            first_half.push(second_half.top());
            second_half.pop();
        }
    }
}

void remove_num(int num){
    if(!first_half.empty())
}

void add_num(int num){
    if(!first_half.empty() and num>=first_half.top()){
        second_half.push(num);
    }else{
        first_half.push(num);
    }

    make_equal();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    for(int i=0;i<k;++i){
        cin>>nums[i];
        add_num(nums[i]);
    }
    cout<<calc_median()<<" ";

    for(int i=k;i<n;++i){
        cin>>nums[i];
        
        remove_num(nums[i-k]);
        add_num(nums[i]);

        cout<<calc_median()<<" ";
    }
    cout<<endl;
return 0;
}