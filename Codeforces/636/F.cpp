#include<iostream>
#include<vector>
#include<set>

#define endl '\n'

using namespace std;

void erase_num(int target, vector<set<int>>& segments){
    for(set<int> &curr : segments){
        if(curr.count(target)>0){
            curr.erase(target);
        }
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
        vector<set<int>> segments;
        for(int i=1;i<n;++i){
            int k;
            cin>>k;
            set<int> input;
            while(k--){
                int curr;
                cin>>curr;
                --curr;
                input.insert(curr);
            }
            segments.push_back(input);
        }

        for(int i=0;i<n;++i){
            vector<int> res;
            res.push_back(i);
            bool check=true;
            vector<set<int>> copy_seg=segments;
            erase_num(i,copy_seg);

            for(int i2=1;i2<n;++i2){
                int counter=0,next_num=-1;
                for(set<int> curr : copy_seg){
                    if((int)curr.size()==1){
                        ++counter;
                        next_num=*(curr.begin());
                    }
                }
                if(counter!=1){
                    check=false;
                    break;
                }
                res.push_back(next_num);
                erase_num(next_num,copy_seg);
            }

            if(check){
                for(int i2=1;i2<n;++i2){
                    set<int> curr;
                    curr.insert(res[i2]);
                    set<set<int>> search_seg(segments.begin(),segments.end());
                    bool is_segment=false;
                    for(int i3=i2-1;i3>=0;--i3){
                        curr.insert(res[i3]);
                        if(search_seg.count(curr)>0){
                            is_segment=true;
                            search_seg.erase(curr);
                            break;
                        }
                    }
                    if(!is_segment){
                        check=false;
                        break;
                    }
                }
            }

            if(check){
                for(int curr : res){
                    cout<<curr+1<<" ";
                }
                cout<<endl;
                break;
            }
        }
    }
return 0;
}