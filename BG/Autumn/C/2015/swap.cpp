#include<iostream>
#include<vector>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=103;
int nums[MAXN];
vector<pair<int,int>> swaps;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    
    for(int i=0;i<n;++i){
        if(nums[i]==(i+1)){
            continue;
        }
        
        int pos=0;
        for(int i2=i+1;i2<n;++i2){
            if(nums[i2]==(i+1)){
                pos=i2;
                break;
            }
        }
        
        while(pos>i){
            if(nums[pos-1]!=(pos+1)){
                swaps.push_back({pos,pos+1});
                swap(nums[pos],nums[pos-1]);
                --pos;
            }else{
                int prev=pos-1;
                while(prev>=i and nums[prev]==(prev+2)){
                    --prev;
                }
                if(prev<i){
                    for(int i2=pos-1;i2>=i;--i2){
                        swaps.push_back({i2+1,i2+2});
                        swap(nums[i2],nums[i2+1]);
                    }
                    pos=i;
                }else{
                    for(int i2=prev;i2<=pos-1;++i2){
                        swaps.push_back({i2+1,i2+2});
                        swap(nums[i2],nums[i2+1]);
                    }
                    --pos;
                }
            }
        }
    }
    
    cout<<(int)swaps.size()<<endl;
    for(pair<int,int> res : swaps){
        cout<<res.first<<" "<<res.second<<endl;
    }
return 0;
}