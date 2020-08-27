#include<iostream>
#include<string>
#include<vector>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s,word;
    int k;
    cin>>s>>word>>k;
    
    unsigned long long word_code=0,curr_code=0;
    for(int i=0;i<word.size();++i){
        if(word[i]=='b'){
            word_code=word_code | (1LL<<i);
        }
        if(s[i]=='b'){
            curr_code=curr_code | (1LL<<i);
        }
    }
    
    vector<int> start_ind;
    if(curr_code==word_code){
        start_ind.push_back((int)word.size()-1);
    }
    for(int i=word.size();i<s.size();++i){
        curr_code>>=1;
        if(s[i]=='b'){
            curr_code=curr_code | (1LL<<((int)word.size()-1));
        }
        if(curr_code==word_code){
            start_ind.push_back(i);
        }
    }

    int left=0,right=(int)s.size();
    while(left+1<right){
        int mid=(left+right)/2,counter=0,prev=1-(int)s.size();
        for(int ind : start_ind){
            if(ind-prev>=(int)word.size()+mid){
                ++counter;
                prev=ind;
            }
        }
        if(counter>=k){
            left=mid;
        }else{
            right=mid;
        }
    }
    cout<<left<<endl;
return 0;
}