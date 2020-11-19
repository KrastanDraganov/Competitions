#include<iostream>
#include<unordered_map>

#define endl '\n'

using namespace std;

const int MAXK=1e3+3,MAXN=5e5+3,INF=1e9+3;
int nums_size[MAXK],counter[MAXN];
unordered_map<int, int> compressed;

int compress(int num, int& all_nums){
    if(!compressed.count(num)){
        compressed[num]=all_nums++;
    }
    return compressed[num];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin>>k;

    for(int i=0;i<k;++i){
        cin>>nums_size[i];
    }

    int all_nums=0;
    int res=INF;
    for(int i=0;i<nums_size[0];++i){
        int num;
        cin>>num;

        int new_num=compress(num, all_nums);
        if(counter[new_num]==0){
            ++counter[new_num];
            if(k==1){
                res=min(res, num);
            }
        }
    }

    for(int i=1;i<k;++i){
        for(int i2=0;i2<nums_size[i];++i2){
            int num;
            cin>>num;

            if(!compressed.count(num)){
                continue;
            }

            int new_num=compressed[num];
            if(counter[new_num]==i){
                ++counter[new_num];
                if(i==k-1){
                    res=min(res, num);
                }
            }
        }
    }

    if(res==INF){
        cout<<"x\n";
    }else{
        cout<<res<<endl;
    }
return 0;
}
