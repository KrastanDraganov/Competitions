#include<iostream>
#include<cstring>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int vote[MAXN][3],counter[55],original[55];
vector<int> winners;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        s+='S';
        int num=0,curr=0;
        for(int i2=0;i2<s.size();++i2){
            if(s[i2]>='0' and s[i2]<='9'){
                num=10*num+s[i2]-'0';
            }else if(i2>0){
                if(curr==0){
                    ++counter[num];
                    ++original[num];
                }
                vote[i][curr++]=num;
                num=0;
            }
        }
    }
    int is_winner=0;
    do{
        int min_vote=MAXN,max_vote=-1,max_song=-1,all_vote=0;
        vector<int> min_songs;
        for(int i=1;i<=52;++i){
            if(counter[i]>0){
                all_vote+=counter[i];
                if(counter[i]>max_vote){
                    max_vote=counter[i];
                    max_song=i;
                }
                if(counter[i]<min_vote){
                    min_vote=counter[i];
                    min_songs.clear();
                    min_songs.push_back(i);
                }else if(counter[i]==min_vote){
                    min_songs.push_back(i);
                }
            }
        }
        if(min_vote==max_vote){
            is_winner=2;
            for(int song : min_songs){
                winners.push_back(song);
            }
        }else if(max_vote>all_vote-max_vote){
            is_winner=1;
            winners.push_back(max_song);
        }else{
            for(int song : min_songs){
                for(int i=0;i<n;++i){
                    if(vote[i][0]>0){
                        for(int i2=0;i2<3;++i2){
                            if(vote[i][i2]==song){
                                vote[i][i2]=0;
                                for(int i3=i2+1;i3<3 and vote[i][i3]>0;++i3){
                                    swap(vote[i][i3],vote[i][i3-1]);
                                }
                                if(i2==0){
                                    --counter[song];
                                    if(vote[i][0]>0){
                                        ++counter[vote[i][0]];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }while(!is_winner);
    if(is_winner==1 or winners.size()==1){
        cout<<"S"<<winners[0]<<" "<<original[winners[0]]<<endl;
    }else{
        for(int song : winners){
            cout<<"S"<<song<<" ";
        }
        cout<<endl;
    }
return 0;
}