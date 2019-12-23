#include<iostream>
#include<stack>
#define endl '\n'
using namespace std;
const int MAXN=1e6+3;
int height[MAXN],bonus[MAXN];
bool added[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>height[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;++i){
        int ind,value;
        cin>>ind>>value;
        bonus[ind]=value;
    }
    long long res=0;
    int counter=0,i=0;
    while(i<n){
        int i2=i+1;
        //cout<<"ind: "<<i<<endl;
        while(i2<n){
            //cout<<"state: "<<i2<<" "<<height[i]<<" "<<height[i2]<<endl;
            if(height[i2]>=height[i]){
                if(!added[i] and bonus[i]>0 and height[i]+bonus[i]>=height[i2]){
                    height[i]+=bonus[i];
                    added[i]=true;
                    ++counter;
                    if(height[i]==height[i2]){
                        res+=(long long)height[i]*(i2-i);
                    }
                }else{
                    res+=(long long)height[i]*(i2-i);
                    break;
                }
            }else if(!added[i2] and bonus[i2]>0 and height[i2]+bonus[i2]>=height[i]){
                height[i2]+=bonus[i2];
                added[i2]=true;
                ++counter;
                if(!added[i] and bonus[i]>0 and height[i]+bonus[i]>=height[i2]){
                    added[i]=true;
                    height[i]+=bonus[i];
                    ++counter;
                    if(height[i]==height[i2]){
                        res+=(long long)height[i]*(i2-i);
                    }
                }else{
                    res+=(long long)height[i]*(i2-i);
                    break;
                }
            }else if(i2==n-1){
                stack<int> prev;
                prev.push(i);
                for(int i3=i+1;i3<n;++i3){
                    if(!added[i3] and bonus[i3]>0){
                        height[i3]+=bonus[i3];
                        ++counter;
                        added[i3]=true;
                    }
                    while(!prev.empty() and height[prev.top()]<height[i3]){
                        res-=height[prev.top()];
                        if(added[prev.top()]){
                            added[prev.top()]=false;
                            --counter;
                        }
                        prev.pop();
                    }
                    res+=(long long)height[i3]*(i3-prev.top());
                    prev.push(i3);
                }
            }
            ++i2;
        }
        //cout<<"res: "<<res<<endl;
        i=i2;
    }
    cout<<counter<<" "<<res<<endl;
return 0;
}
/**
6
2 4 2 4 2 1
2
2 1
4 1
**/
