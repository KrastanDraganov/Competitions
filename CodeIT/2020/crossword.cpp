#include<iostream>
#include<string.h>
#include<fstream>
#include<queue>
#include<utility>
#define endl '\n'
using namespace std;
const int MAXN=1e4+3;
struct State {
    int orientation,ind;
};
string word[MAXN],crossword[MAXN][MAXN];
queue<pair<int,int>> available[27];
pair<int,int> pos[MAXN];
ifstream fin("/media/fif2205/Mined/Competitions/CodeIT/2020/crossword.in");
ofstream fout("/media/fif2205/Mined/Competitions/CodeIT/2020/crossword.out");
int main(){
    //ios::sync_with_stdio(false);
    //fin.tie(nullptr);
    int t,n;
    fin>>t>>n;
    int h=1,w=1;
    for(int i=0;i<n;++i){
        fin>>word[i];
        bool used=false;
        for(int i2=0;i2<word[i].size();++i2){
            char curr=word[i][i2];
            if(!available[curr-'a'].empty() and !used){
                pair<int,int> ind=available[curr-'a'].front();
                if(h<=word.size()){
                    h=word.size()+1;
                }
                used=true;
            }
        }
        if(!used){
            pos[i]={0,h++};
            for(int i2=0;i2<word[i].size();++i2){
                available[word[i][i2]-'a'].push({i,i2});
            }
        }
    }
    fout<<h<<" "<<w<<endl;
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