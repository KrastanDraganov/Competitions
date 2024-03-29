#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN];
multiset<int> first_half,second_half;

void make_equal(){
    int n=(int) first_half.size();
    int m=(int) second_half.size();

    if(abs(n-m)>1 or n==0){
        if(n>m){
            auto it=--first_half.end();
            second_half.insert(*it);
            first_half.erase(it);
        }else if(m>0){
            auto it=second_half.begin();
            first_half.insert(*it);
            second_half.erase(it);
        }
    }
}

void remove_num(int num){
    if(first_half.count(num)){
        first_half.erase(first_half.find(num));
    }else{
        second_half.erase(second_half.find(num));
    }

    make_equal();
}

void add_num(int num){
    if(!first_half.empty() and num>=(*--first_half.end())){
        second_half.insert(num);
    }else{
        first_half.insert(num);
    }

    make_equal();
}

int calc_median(){
    int n=(int) first_half.size(),m=(int) second_half.size();

    if(m>n){
        auto it=second_half.begin();
        return *it;
    }

    auto it=--first_half.end();
    return *it;
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