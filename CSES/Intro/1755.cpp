#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

string make_pal(string s){
    vector<int> counter(26,0);
    for(char curr : s){
        int ind=curr-'A';
        ++counter[ind];
    }

    string half1="",mid="";
    for(int i=0;i<26;++i){
        int letter=i+'A';
        
        if(counter[i] & 1){
            if(!mid.empty()){
                return "";
            }
            mid=letter;
        }

        for(int i2=0;i2<(counter[i]/2);++i2){
            half1+=letter;
        }
    }

    string half2=half1;
    reverse(half2.begin(), half2.end());

    return half1+mid+half2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin>>input;

    string res=make_pal(input);
    cout<<(res.empty() ? "NO SOLUTION" : res)<<endl;
return 0;
}