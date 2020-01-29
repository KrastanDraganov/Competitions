#include<iostream>
#include<string.h>
#include<fstream>
#include<queue>
#include<utility>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=1e4+3,HORIZONTAL=0,VERTICAL=1;

struct State {
    int x,y,orientation;
    State(){}
    State(int _x, int _y, int _orientation){
        x=_x;
        y=_y;
        orientation=_orientation;
    }
};

string word[MAXN];
queue<pair<int,int>> available[27];
State pos[MAXN];
vector<int> floor[MAXN];
pair<int,int> dist[MAXN];

ifstream fin("/media/fif2205/Mined/Competitions/CodeIT/2020/crossword2.in");
ofstream fout("/media/fif2205/Mined/Competitions/CodeIT/2020/crossword.out");

int main(){
    int t,n;
    fin>>t>>n;
    int h=0,w=1,counter=0;
    for(int i=0;i<n;++i){
        fin>>word[i];
        bool used=false;
        for(int i2=0;i2<word[i].size();++i2){
            int curr=word[i][i2]-'a';
            if(!available[curr].empty()){
                pair<int,int> ind=available[curr].front();
                available[curr].pop();
                floor[ind.first].push_back(i);
                int add=0;
                if(i2>dist[ind.first].first){
                    add+=i2-dist[ind.first].first;
                    dist[ind.first].first=i2;
                    for(int i3=0;i3<floor[ind.first].size();++i3){
                        pos[floor[ind.first][i3]].y+=add;
                    }
                }
                if(word[i].size()-i2-1>dist[ind.first].second){
                    add+=word[i].size()-i2-1-dist[ind.first].second;
                    dist[ind.first].second=word[i].size()-i2-1;
                }
                for(int i3=ind.first+1;i3<counter;++i3){
                    for(int i4=0;i4<floor[i3].size();++i3){
                        pos[floor[i3][i4]].y+=add;
                    }
                }
                pos[i]=State(ind.second,dist[ind.first].first-i2,VERTICAL);
                h+=add;
                used=true;
                break;
            }
        }
        if(!used){
            pos[i]=State(0,h++,HORIZONTAL);
            for(int i2=0;i2<word[i].size();++i2){
                available[word[i][i2]-'a'].push({counter,i2});
            }
            floor[counter++].push_back(i);
            w=max(w,(int)word[i].size());
        }
    }
    vector<vector<char>> crossword(h,vector<char>(w,'#'));
    for(int i=0;i<counter;++i){
        for(int i2=0;i2<floor[i].size();++i2){
            int curr=floor[i][i2];
            if(i2==0){
                for(int i3=pos[curr].x;i3<word[curr].size()+pos[curr].x;++i3){
                    crossword[pos[curr].y][i3]=word[curr][i3-pos[curr].x];
                }
            }else{
                for(int i3=pos[curr].y;i3<word[curr].size()+pos[curr].y;++i3){
                    crossword[i3][pos[curr].x]=word[curr][i3-pos[curr].y];
                }
            }
        }
    }
    fout<<w<<" "<<h<<endl;
    for(int i=0;i<h;++i){
        for(int i2=0;i2<w;++i2){
            fout<<crossword[i][i2];
        }
        fout<<endl;
    }
    for(int i=0;i<n;++i){
        fout<<pos[i].x<<" "<<pos[i].y<<" ";
        for(int i2=0;i2<(int)word[i].size()-1;++i2){
            fout<<(pos[i].orientation==HORIZONTAL ? "R" : "D");
        }
        fout<<endl;
    }
return 0;
}