#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dna;
    cin>>dna;

    int res=1,curr=1;
    dna+="Z";
    for(int i=1;i<dna.size();++i){
        if(dna[i]!=dna[i-1]){
            res=max(res,curr);
            curr=0;
        }
        ++curr;
    }
    cout<<res<<endl;
return 0;
}