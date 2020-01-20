#include<iostream>
#include<string.h>
#include<fstream>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
string word[MAXN];
ifstream fin("crossword.in");
ofstream fout("crossword.out");
int main(){
    //ios::sync_with_stdio(false);
    //fin.tie(nullptr);
    int t,n;
    fin>>t>>n;
    int max_size=0;
    for(int i=0;i<n;++i){
        fin>>word[i];
        max_size=max(max_size,(int)word[i].size());
    }
    fout<<max_size<<" "<<n<<endl;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<max_size;++i2){
            if(i2<(int)word[i].size()){
                fout<<word[i][i2];
            }else{
                fout<<"#";
            }
        }
        fout<<endl;
    }
    for(int i=0;i<n;++i){
        fout<<0<<" "<<i<<" ";
        for(int i2=0;i2<(int)word[i].size()-1;++i2){
            fout<<"R";
        }
        fout<<endl;
    }
return 0;
}