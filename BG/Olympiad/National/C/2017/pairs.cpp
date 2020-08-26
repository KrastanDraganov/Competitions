#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=2e3+3;
long long nums[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    
    vector<long long> mult;
    for(int i=0;i<n;++i){
        for(int i2=i+1;i2<n;++i2){
            mult.push_back(nums[i]*nums[i2]);
        }
    }
    sort(mult.begin(),mult.end());

    int max_pairs=0,curr=1;
    vector<int> ind;
    for(int i=1;i<=mult.size();++i){
        if(i<mult.size() and mult[i]==mult[i-1]){
            ++curr;
        }else{
            if(curr>max_pairs){
                max_pairs=curr;
                ind.clear();
                ind.push_back(i-1);
            }else if(curr==max_pairs){
                ind.push_back(i-1);
            }
            curr=1;
        }
    }

    cout<<max_pairs<<endl<<(int)ind.size()<<endl;
    for(int i=0;i<min((int)ind.size(),100);++i){
        cout<<mult[ind[i]]<<" ";
        for(int i2=0;i2<n;++i2){
            bool check=false;
            for(int i3=i2+1;i3<n;++i3){
                if(nums[i2]*nums[i3]==mult[ind[i]]){
                    cout<<i2+1<<" "<<i3+1<<endl;
                    check=true;
                    break;
                }
            }
            if(check){
                break;
            }
        }
    }
return 0;
}