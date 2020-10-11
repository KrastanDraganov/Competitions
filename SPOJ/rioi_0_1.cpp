#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=103;
int nums[MAXN];vector<int> swaps;

void print_swaps(vector<int>& swaps){
    int n=(int) swaps.size();
    if(n<2){
        return;
    }

    cout<<"swaps are: \n";
    for(int i=n-1;i>0;--i){
        int prev=(i==n-1 ? 0 : i-1);
        cout<<swaps[i]<<" "<<swaps[prev]<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        
        int cycles=0;
        for(int i=0;i<n;++i){
            vector<int> swaps;
            
            while(i>=0 and nums[i]!=-1){
                swaps.push_back(i);
                int curr=nums[i];
                nums[i]=-1;
                i=curr-1;
            }

            cycles+=(!swaps.empty());
            // print_swaps(swaps);
        }

        cout<<n-cycles<<endl;
    }
return 0;
}