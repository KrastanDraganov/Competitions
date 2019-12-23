#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<int>nums;
int main(){
    long long n,x,result=0,digits=0;
    cin>>n;
    x=n;
    while(x!=0){
        nums.push_back(x%10);
        x/=10;
        digits++;
    }
    long long curr;
    for(int i=1;i<digits;i++){
        curr=9;
        for(int i2=1;i2<(i/2);i2++){
            curr*=10;
        } 
        if(digits%2==1){
            curr*=10;
        }
        result+=curr;
    }
    curr=1;
    for(int i=nums.size()-1;i>=(digits/2);i--){
        if(i==(digits/2)
    }
    bool is_palindrome=true;
    int j=nums.size();
    for(int i=0;i<j;i++){
        if(nums[i]!=nums[j]){
            is_palindrome=false;
            break;
        }
        j--;
    }
    cout<<result+is_palindrome<<endl;
return 0;
}