#include<iostream>
#include<vector>
#include<set>

#define endl '\n'

using namespace std;

const int MAX_DICES=1e4;

bool is_compatible(int num1, int num2){
    int same_digits=0;
    
    while(num1>0 and num2>0){
        if(num1%10==num2%10){
            ++same_digits;
        }
        num1/=10;
        num2/=10;
    }

    return num1==0 and num2==0 and same_digits==1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<vector<int>> rolls(n, vector<int>(2));
    for(int i=0;i<n;++i){
        cin>>rolls[i][0]>>rolls[i][1];
    }

    set<int> possible;
    for(int dices=1;dices<=MAX_DICES;++dices){
        possible.insert(dices);
    }

    for(int i=0;i<n;++i){
        auto it=possible.begin();

        while(it!=possible.end()){
            int dices=*it;
            int real_sum=dices*7-rolls[i][0];

            if(rolls[i][0]<dices or real_sum<=0 or real_sum<dices or real_sum>6*dices or !is_compatible(real_sum, rolls[i][1])){
                it=possible.erase(it);
            }else{
                ++it;
            }
        }
    }

    cout<<(int)possible.size()<<endl;
    for(int dices : possible){
        cout<<dices<<" ";
    }
    cout<<endl;
return 0;
}