#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

void print_group(vector<int>& group){
    cout<<(int)group.size()<<endl;
    for(int num : group){
        cout<<num<<" ";
    }
    cout<<endl;
}

void divide_sum(int n){
    long long sum=(long long) n*(n+1)/2;
    
    if(sum & 1){
        cout<<"NO\n";
        return;
    }

    vector<int> group1,group2;
    sum/=2;

    while(n>0){
        if(n<=sum){
            group1.push_back(n);
            sum-=n;
        }else{
            group2.push_back(n);
        }
        --n;
    }

    cout<<"YES\n";
    print_group(group1);
    print_group(group2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    divide_sum(n);
return 0;
}