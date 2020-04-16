#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

string s;
vector<pair<char,bool>> letters;
int what_ind[27],res,val[7];

void calc_digits(int ind, int mask){
    if(ind==(int)letters.size()){
        vector<int> nums(3,0);
        int counter=0;
        for(int i=0;i<s.size();++i){
            if(s[i]>='A' and s[i]<='Z'){
                int curr=s[i]-'A';
                nums[counter]=10*nums[counter]+val[what_ind[curr]];
            }else if(s[i]>='0' and s[i]<='9'){
                nums[counter]=10*nums[counter]+s[i]-'0';
            }else{
                ++counter;
            }
        }
        res+=(nums[0]+nums[1]==nums[2]);
        return;
    }
    pair<char,bool> curr=letters[ind];
    for(int digit=(letters[ind].second ? 1 : 0);digit<10;++digit){
        if(!(mask & (1<<digit))){
            val[ind]=digit;
            calc_digits(ind+1,mask | (1<<digit));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>s;

    for(int i=0;i<26;++i){
        what_ind[i]=-1;
    }
    for(int i=0;i<s.size();++i){
        if(s[i]>='A' and s[i]<='Z'){
            int curr=s[i]-'A';
            if(what_ind[curr]==-1){
                letters.push_back({s[i],false});
                what_ind[curr]=letters.size()-1;
            }
            if(i==0 or s[i-1]=='=' or s[i-1]=='+'){
                letters[what_ind[curr]].second=true;
            }
        }
    }

    calc_digits(0,0);

    cout<<res<<endl;
return 0;
}