#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=53;
int diff[MAXN];
char res[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        string s;
        int m;
        cin>>s>>m;
        for(int i=0;i<m;++i){
            cin>>diff[i];
        }

        sort(s.begin(),s.end());
        int n=(int)s.size()-1;
        bool check=true;
        while(check){
            check=false;
            vector<int> ind;
            for(int i=0;i<m;++i){
                if(diff[i]==0){
                    check=true;
                    ind.push_back(i);
                }
            }
            while(n>=0 and count(s.begin(),s.end(),s[n])<(int)ind.size()){
                --n;
            }
            for(int curr : ind){
                res[curr]=s[n];
            }
            --n;
            while(n>=0 and s[n]==s[n+1]){
                --n;
            }
            for(int i=0;i<m;++i){
                if(diff[i]==0){
                    diff[i]=-1;
                }else if(diff[i]>0){
                    for(int curr : ind){
                        diff[i]-=abs(i-curr);
                    }
                }
            }
        }
        res[m]='\0';
        cout<<res<<endl;
    }
return 0;
}