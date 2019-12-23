#include<iostream>
#include<string>
#include<unordered_map>
#define endl '\n'
using namespace std;
unordered_map<string,int> counter;
unordered_map<string,bool> used;
void make_sub(int ind, string curr, int k, string s, bool visited){
    if(curr.size()>k or ind>=s.size()){
        return;
    }
    if(curr.size()==k and !used[curr]){
        ++counter[curr];
        used[curr]=true;
        return;
    }
    if(!visited){
        make_sub(ind,curr+s[ind],k,s,true);
    }
    make_sub(ind+1,curr,k,s,false);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        make_sub(0,"",k,s,false);
        used.clear();
    }
    if(counter.size()==0){
        cout<<0<<endl;
        return 0;
    }
    int max_counter=0,max_counter2=0;
    string res="";
    for(pair<string,int> curr : counter){
        if(curr.second>max_counter){
            max_counter=curr.second;
            res=curr.first;
            max_counter2=1;
        }else if(max_counter==curr.second){
            ++max_counter2;
            if(curr.first<res){
                res=curr.first;
            }
        }
    }
    cout<<max_counter<<endl<<res<<endl<<max_counter2<<endl;
return 0;
}
/**
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
**/
