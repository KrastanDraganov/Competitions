#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
bool used[30];
int counter[30];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        for(int i=0;i<30;++i){
            used[i]=false;
        }
        for(int i=0;i<s.size();++i){
            if(!used[s[i]-'a']){
                used[s[i]-'a']=true;
                ++counter[s[i]-'a'];
            }
        }
    }
    int max_counter=0,max_counter2=0;
    char res;
    for(int i=0;i<26;++i){
        if(counter[i]>max_counter){
            max_counter=counter[i];
            res=i+'a';
            max_counter2=1;
        }else if(counter[i]==max_counter){
            ++max_counter2;
            if((i+'a')<res){
                res=i+'a';
            }
        }
    }
    cout<<max_counter<<endl<<res<<endl<<max_counter2<<endl;
return 0;
}
