#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const long long BORDER = 9876543210;

bool check(vector<int> digits, int counter, int used){
    int curr=10;
    for(int i=digits.size()-counter;i<digits.size();++i){
        --curr;
        while(curr>=0 and (used & (1<<curr))){
            --curr;
        }
        if(curr<0 or digits[i]>curr){
            return false;
        }
        if(digits[i]<curr){
            return true;
        }
        used |= (1<<curr);
    }
    return false;
}

long long next_num(long long x){
    if(x==0){
        return 1;
    }
    if(x>=BORDER){
        return -1;
    }
    vector<int> digits;
    for(long long i=x;i>0;i/=10){
        digits.push_back(i%10);
    }
    reverse(digits.begin(),digits.end());
    if(!check(digits,digits.size(),0)){
        long long res=10;
        for(int i=2;res<=x;++i){
            res=10*res+i;
        }
        return res;
    }
    int mask=0;
    for(int i=0;i<digits.size();++i){
        bool change=false;
        if((mask & (1<<digits[i])) or !check(digits,digits.size()-i-1,mask | (1<<digits[i]))){
            change=true;
        }
        if(change){
            ++digits[i];
            while(mask & (1<<digits[i])){
                ++digits[i];
            }
            mask |= (1<<digits[i]);
            for(int i2=i+1;i2<digits.size();++i2){
                digits[i2]=0;
                while(mask & (1<<digits[i2])){
                    ++digits[i2];
                }
                mask |= (1<<digits[i2]);
            }
            long long res=0;
            for(int i2=0;i2<digits.size();++i2){
                res=10*res+digits[i2];
            }
            return res;
        }else{
            mask |= (1<<digits[i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        long long num;
        cin>>num;
        cout<<next_num(num)<<endl;
    }
return 0;
}