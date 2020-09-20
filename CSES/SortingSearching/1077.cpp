#include<iostream>
#include<set>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int nums[MAXN];
multiset<int> first_half,second_half;

void make_equal(long long& sum1, long long& sum2){
    int n=(int) first_half.size();
    int m=(int) second_half.size();

    if(abs(n-m)>1 or n==0){
        if(n>m){
            auto it=--first_half.end();

            sum1-=*it;
            sum2+=*it;

            second_half.insert(*it);
            first_half.erase(it);
        }else if(m>0){
            auto it=second_half.begin();

            sum1+=*it;
            sum2-=*it;

            first_half.insert(*it);
            second_half.erase(it);
        }
    }
}

void remove_num(int num, long long& sum1, long long& sum2){
    if(first_half.count(num)){
        first_half.erase(first_half.find(num));
        sum1-=num;
    }else{
        second_half.erase(second_half.find(num));
        sum2-=num;
    }

    make_equal(sum1, sum2);
}

void add_num(int num, long long& sum1, long long& sum2){
    if(!first_half.empty() and num>=(*--first_half.end())){
        second_half.insert(num);
        sum2+=num;
    }else{
        first_half.insert(num);
        sum1+=num;
    }

    make_equal(sum1, sum2);
}

long long calc_cost(long long& sum1, long long& sum2){
    int n=(int) first_half.size(),m=(int) second_half.size();
    long long res=sum2-sum1;
    
    if(m>n){
        res-=*second_half.begin();
    }else if(n>m){
        res+=*(--first_half.end());
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    
    long long sum1=0,sum2=0;
    for(int i=0;i<k;++i){
        cin>>nums[i];
        add_num(nums[i], sum1, sum2);
    }
    cout<<calc_cost(sum1, sum2)<<" ";

    for(int i=k;i<n;++i){
        cin>>nums[i];
        
        remove_num(nums[i-k], sum1, sum2);
        add_num(nums[i], sum1, sum2);

        cout<<calc_cost(sum1, sum2)<<" ";
    }
    cout<<endl;
return 0;
}