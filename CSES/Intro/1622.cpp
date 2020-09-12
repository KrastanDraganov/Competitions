#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin>>input;

    sort(input.begin(), input.end());
    vector<string> res;
    do{
        res.push_back(input);
    } while(next_permutation(input.begin(), input.end()));

    cout<<(int) res.size()<<endl;
    for(string curr : res){
        cout<<curr<<endl;
    }
return 0;
}